CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(goost_test)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

ADD_EXECUTABLE(
	goost_test
	goost_test.cpp
	Hex64Source.cpp
	Hex64SourceTest.cpp
	HexMatch.cpp
	SourceMatch.cpp
	SourceText.cpp
	TestSink.cpp
	TestSinkText.cpp
	gost89/BlkEncryptedTest.cpp
	gost89/CFBSinkTest.cpp
	gost89/CFBSourceTest.cpp
	gost89/Test.cpp
	gost89/TestSbox.cpp
	kuznyechik/BlkCachedTest.cpp
	kuznyechik/BlkEncryptedTest.cpp
	kuznyechik/BlkIncrementedTest.cpp
	kuznyechik/BlkIterKeyTest.cpp
	kuznyechik/BlkKeyData.cpp
	kuznyechik/BlkLTest.cpp
	kuznyechik/BlkRawTest.cpp
	kuznyechik/BlkRTest.cpp
	kuznyechik/BlkShiftedTest.cpp
	kuznyechik/BlkSTest.cpp
	kuznyechik/BlkXoredTest.cpp
	kuznyechik/ImitTest.cpp
	kuznyechik/KeyDataStringTest.cpp
	kuznyechik/ReprBlock.cpp
	kuznyechik/StCTREncryptedTest.cpp
	kuznyechik/TestBlockEqual.cpp
	kuznyechik/Test.cpp
	magma/BlkDecryptedTest.cpp
	magma/BlkEncryptedTest.cpp
	magma/BlkStringTest.cpp
	magma/BlkSwappedTest.cpp
	magma/CFBSinkTest.cpp
	magma/CFBSourceTest.cpp
	magma/ECBSinkTest.cpp
	magma/ECBSourceTest.cpp
	magma/EncryptionBaseTest.cpp
	magma/ImitTest.cpp
	magma/KeyCachedDataTest.cpp
	magma/KeyDataNativeTest.cpp
	magma/KeyDataStringTest.cpp
	magma/ReprBlock.cpp
	magma/ReprKeyData.cpp
	magma/ReprTransformed.cpp
	magma/SboxNibbleTest.cpp
	magma/SboxTwistedTest.cpp
	magma/TestBlockEqual.cpp
	magma/Test.cpp
)

TARGET_LINK_LIBRARIES(
	goost_test
	goost
	${CONAN_LIBS}
)

ADD_TEST(
	NAME goost_test
	COMMAND sh -c "$<TARGET_FILE:goost_test>"
)
