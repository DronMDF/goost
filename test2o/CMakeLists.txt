CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

INCLUDE_DIRECTORIES(
	"${PROJECT_SOURCE_DIR}/2out"
)

ADD_EXECUTABLE(
	test2o
	test2o.cpp
	kuznyechik/BlkEncryptedTest.cpp
	kuznyechik/BlkRTest.cpp
	kuznyechik/BlkShiftedTest.cpp
	kuznyechik/BlkSTest.cpp
	kuznyechik/BlkXoredTest.cpp
	kuznyechik/BlockTest.cpp
	kuznyechik/ImitTest.cpp
	kuznyechik/KeyDataStringTest.cpp
	kuznyechik/KeyIterTest.cpp
	kuznyechik/LBlockTest.cpp
	kuznyechik/ReprBlock.cpp
	kuznyechik/ReprKeyData.cpp
	kuznyechik/StCTREncryptedTest.cpp
	kuznyechik/Test.cpp
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
