CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

INCLUDE_DIRECTORIES(
	"${PROJECT_SOURCE_DIR}/2out"
)

# @todo #134:15min move kuznyechik/ImitTest.cpp to 2out
# @todo #134:15min Move kuznyechik/EncryptedBlockTest.cpp to 2out

ADD_EXECUTABLE(
	test2o
	test2o.cpp
	kuznyechik/BlockTest.cpp
	kuznyechik/KeyDataStringTest.cpp
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
