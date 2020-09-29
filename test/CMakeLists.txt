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
	gost89/BlkEncryptedTest.cpp
	gost89/CFBSinkTest.cpp
	gost89/Test.cpp
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
	magma/ImitTest.cpp
	magma/KeyCachedDataTest.cpp
	magma/KeyDataNativeTest.cpp
	magma/KeyDataStringTest.cpp
	magma/ReprBlock.cpp
	magma/ReprKeyData.cpp
	magma/ReprStream.cpp
	magma/ReprStreamTest.cpp
	magma/ReprTransformed.cpp
	magma/SboxNibbleTest.cpp
	magma/SboxTwistedTest.cpp
	magma/StMemoryTest.cpp
	magma/TestBlockEqual.cpp
	magma/Test.cpp
)

TARGET_LINK_LIBRARIES(
	goost_test
	goost
	${CONAN_LIBS}
)

ADD_CUSTOM_COMMAND(
	TARGET goost_test
	PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/shippable/testresults
)

# @todo #122:15min Hardcoded shippable path
ADD_TEST(
	NAME goost_test
	COMMAND sh -c "$<TARGET_FILE:goost_test> > ${CMAKE_BINARY_DIR}/shippable/testresults/goost_test.xml"
)
