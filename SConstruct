env = Environment(
	CCFLAGS='-O2',
	CPPPATH=['.', 'test'],
	LIBPATH='.'
)

env.Library(
	'goost',
	[
		'magma/DataImit.cpp',
		'magma/Key.cpp',
		'magma/Sbox.cpp',
		'magma/StringIsKeyData.cpp'
	]
)

test = env.Program(
	'test_runner',
	[
		'test/magma/DataImitTest.cpp',
		'test/magma/StringIsKeyDataTest.cpp',
		'test/main.cpp'
	],
	LIBS='goost'
)

alias = Alias('test', [test], test[0].abspath + ' -t')
AlwaysBuild(alias)
