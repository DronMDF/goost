CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(goost)

INCLUDE(CTest)

INCLUDE_DIRECTORIES(
	"${PROJECT_SOURCE_DIR}"
	"${PROJECT_SOURCE_DIR}/test"
)

ADD_COMPILE_OPTIONS(-std=c++14 -O2 -fomit-frame-pointer -g0 -Wall -Wextra -Werror)

ADD_LIBRARY(goost
	gost89/DataImit.cpp
	gost89/ImitedBlock.cpp
	kuznyechik/Block.cpp
	kuznyechik/CTREncryptedStream.cpp
	kuznyechik/DataStream.cpp
	kuznyechik/EncryptedBlock.cpp
	kuznyechik/Imit.cpp
	kuznyechik/Key.cpp
	kuznyechik/KeyDataString.cpp
	kuznyechik/KeyIter.cpp
	kuznyechik/LBlock.cpp
	kuznyechik/RBlock.cpp
	kuznyechik/SBlock.cpp
	magma/Block.cpp
	magma/DataStream.cpp
	magma/DecryptedBlock.cpp
	magma/EncryptedBlock.cpp
	magma/Imit.cpp
	magma/KeyCachedData.cpp
	magma/Key.cpp
	magma/KeyDataNative.cpp
	magma/KeyDataString.cpp
	magma/SboxByte.cpp
	magma/SboxByte64Tab.cpp
	magma/SboxNibble.cpp
	magma/SboxR3412.cpp
	magma/SboxTwisted.cpp
)

ADD_EXECUTABLE(test_runner
	test/gost89/DataImitTest.cpp
	test/gost89/ProceduralImitTest.cpp
	test/kuznyechik/BlockTest.cpp
	test/kuznyechik/CTREncryptedStreamTest.cpp
	test/kuznyechik/EncryptedBlockTest.cpp
	test/kuznyechik/ImitTest.cpp
	test/kuznyechik/KeyDataStringTest.cpp
	test/kuznyechik/KeyIterTest.cpp
	test/kuznyechik/LBlockTest.cpp
	test/kuznyechik/RBlockTest.cpp
	test/kuznyechik/SBlockTest.cpp
	test/magma/DataStreamTest.cpp
	test/magma/DecryptedBlockTest.cpp
	test/magma/EncryptedBlockTest.cpp
	test/magma/ImitTest.cpp
	test/magma/KeyCachedDataTest.cpp
	test/magma/KeyDataNativeTest.cpp
	test/magma/KeyDataStringTest.cpp
	test/magma/SboxNibbleTest.cpp
	test/magma/SboxTwistedTest.cpp
	test/main.cpp
)
TARGET_LINK_LIBRARIES(test_runner goost)
ADD_TEST(unittest test_runner)
