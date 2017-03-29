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

	def isTest(self, l):
		return re.match('^.* \(\d+us\): (SUCCESS|FAILURE)$', l.decode('utf8'))

	def split(self, l):
		r = re.match('^(.*) \((\d)+us\): (SUCCESS|FAILURE)$', l.decode('utf8'))
		return (r.group(1), int(r.group(2)), r.group(3))

	def log(self):
		out = subprocess.check_output([self.options.runner(), '-t'])
		return [self.split(l) for l in out.split(b'\n') if self.isTest(l)]

	def text(self, log):
		return '\n'.join(sorted(('%s (%dus): %s' % l for l in log)))

	def xml(self, log):
		result = ''.join((
			'<testcase name="%s" time="%f" status="%s"/>' % (n, t / 1000000, s)
				for n, t, s in log
		))
		return ''.join((
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


Main(sys.argv[1:]).run()
