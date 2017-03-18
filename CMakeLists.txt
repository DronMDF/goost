CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(goost)

INCLUDE(CTest)

INCLUDE_DIRECTORIES(
	"${PROJECT_SOURCE_DIR}"
	"${PROJECT_SOURCE_DIR}/test"
)

ADD_COMPILE_OPTIONS(-std=c++14 -O2 -fomit-frame-pointer -g0 -Wall -Wextra -Werror)

ADD_LIBRARY(goost
	magma/Block.cpp
	magma/DataImit.cpp
	magma/DataStream.cpp
	magma/DecryptedBlock.cpp
	magma/EncryptedBlock.cpp
	magma/Imit.cpp
	magma/ImitedBlock.cpp
	magma/Key.cpp
	magma/KeyDataNative.cpp
	magma/KeyDataString.cpp
	magma/SboxByte.cpp
	magma/SboxExpanded.cpp
	magma/SboxExpandedCachedTab.cpp
	magma/SboxExpandedNibbleTab.cpp
	magma/SboxNibble.cpp
	magma/SboxR3412.cpp
	magma/SboxTwisted.cpp
)

ADD_EXECUTABLE(test_runner
	test/magma/DataImitTest.cpp
	test/magma/DataStreamTest.cpp
	test/magma/DecryptedBlockTest.cpp
	test/magma/EncryptedBlockTest.cpp
	test/magma/ImitTest.cpp
	test/magma/KeyDataNativeTest.cpp
	test/magma/KeyDataStringTest.cpp
	test/magma/SboxExpandedCachedTabTest.cpp
	test/magma/SboxExpandedTest.cpp
	test/magma/SboxNibbleTest.cpp
	test/magma/SboxTwistedTest.cpp
	test/main.cpp
)
TARGET_LINK_LIBRARIES(test_runner goost)
ADD_TEST(unittest test_runner)
