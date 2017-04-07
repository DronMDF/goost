#!/usr/bin/env python3

import sys
import re
import subprocess
import getopt


class Options:
	''' test_report -o report.xml runner'''
	def __init__(self, args):
		self.args = args

	def runner(self):
		_, args = getopt.getopt(self.args, "o:")
		return args[0]

	def outfile(self):
		opts, _ = getopt.getopt(self.args, "o:")
		return next((a for o, a in opts if o == '-o'), 'test_report.xml')


class Main:
	def __init__(self, args):
		self.options = Options(args)
		self.returncode = 0

	def isTest(self, l):
		return re.match('^.* \(\d+us\): (SUCCESS|FAIL)$', l.decode('utf8'))

	def split(self, l):
		r = re.match('^(.*) \((\d+)us\): (SUCCESS|FAIL)$', l.decode('utf8'))
		return (r.group(1), int(r.group(2)), r.group(3))

	def log(self):
		try:
			out = subprocess.check_output([self.options.runner(), '-t'])
		except subprocess.CalledProcessError as e:
			self.returncode = e.returncode
			out = e.output
		return [self.split(l) for l in out.split(b'\n') if self.isTest(l)]

	# @todo #63 test_result hide detailes of test failure.
	#  This may be a problem if build machine have specific environment.
	#  Shippable should display failure details in log
	def text(self, log):
		return '\n'.join(sorted(('%s (%dus): %s' % l for l in log)))

	# @todo #63 Failures in xml file without details
	#  Details should be stored in <system-out/> tag
	def xml(self, log):
		result = '\n'.join((
			'<testcase name="%s" time="%f">%s%</testcase>' % (
				n.translate(str.maketrans("<>", "{}")),
				t / 1000000,
				"" if s == "SUCCESS" else "<failure/>"
			) for n, t, s in log
		))
		return '\n'.join((
			'<?xml version="1.0" encoding="UTF-8"?>',
			'<testsuites name="all">',
				'<testsuite name="goost">',
					result,
				'</testsuite>',
			'</testsuites>'
		))

	def run(self):
		log = self.log()
		open(self.options.outfile(), 'w').write(self.xml(log))
		print(self.text(log))
		return self.returncode


sys.exit(
	Main(sys.argv[1:]).run()
)
