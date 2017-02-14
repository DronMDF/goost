env = Environment(
	CCFLAGS='-O2',
	LIBPATH='.'
)

env.Library(
	'goost',
	[
		'MagmaDataImit.cpp',
		'MagmaKey.cpp',
		'MagmaSbox.cpp',
		'MagmaStringIsKeyData.cpp'
	]
)

test = env.Program(
	'test',
	[
		'TestMagmaDataImit.cpp',
		'TestMagmaStringIsKeyData.cpp',
		'main.cpp'
	],
	LIBS='goost'
)

alias = Alias('test', [test], test[0].abspath + ' -t')
AlwaysBuild(alias)
