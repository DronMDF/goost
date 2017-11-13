CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

INCLUDE_DIRECTORIES(
	"${PROJECT_SOURCE_DIR}/2out"
)

ADD_EXECUTABLE(
	test2o
	test2o.cpp
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
	test2o
	goost
	2out
)

ADD_CUSTOM_COMMAND(
	TARGET test2o
	PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/shippable/testresults
)

# @todo #122:15min Hardcoded shippable path
ADD_TEST(
	NAME test2o
	COMMAND sh -c "./test2o > ${CMAKE_BINARY_DIR}/shippable/testresults/test2o.xml"
)
