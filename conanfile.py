from conans import ConanFile, CMake, tools

class GoostConan(ConanFile):
	name = 'goost'
	version = '0.4'
	description = 'Object oriented gost algs library'
	license = 'MIT'
	url = 'https://github.com/DronMDF/goost/'

	settings = 'os', 'compiler', 'build_type', 'arch'
	options = {'shared': [True, False]}
	default_options = 'shared=False'
	requires = '2out/0.10@dronmdf/stable'
	generators = 'cmake'

	def source(self):
		git = tools.Git()
		git.clone('https://github.com/DronMDF/goost.git')
		git.checkout('v' + self.version)

	def build(self):
		cmake = CMake(self)
		cmake.configure()
		cmake.build()

	def package(self):
		self.copy('*.h', dst='include/goost/gost89', src='goost/gost89')
		self.copy('*.h', dst='include/goost/kuznyechik', src='goost/kuznyechik')
		self.copy('*.h', dst='include/goost/magma', src='goost/magma')
		self.copy('*.h', dst='include/goost', src='goost')
		self.copy('*.so', dst='lib', keep_path=False)
		self.copy('*.a', dst='lib', keep_path=False)

	def package_info(self):
		self.cpp_info.libs = ['goost']
