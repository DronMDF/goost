CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(goost)

INCLUDE(CTest)

INCLUDE_DIRECTORIES(
	"${PROJECT_SOURCE_DIR}"
	"${PROJECT_SOURCE_DIR}/test"
)

ADD_COMPILE_OPTIONS(-std=c++11 -O2 -g0 -Wall -Wextra -Weffc++ -Werror)

ADD_LIBRARY(goost
	magma/Block.cpp
	magma/DataImit.cpp
	magma/DecryptedBlock.cpp
	magma/EncryptedBlock.cpp
	magma/ImitedBlock.cpp
	magma/Key.cpp
	magma/KeyDataNative.cpp
	magma/KeyDataString.cpp
	magma/SboxNibble.cpp
	magma/SboxByte.cpp
	magma/SboxR3412.cpp
	magma/SboxTwisted.cpp
)

ADD_EXECUTABLE(test_runner
	test/main.cpp
	test/magma/DataImitTest.cpp
	test/magma/DecryptedBlockTest.cpp
	test/magma/EncryptedBlockTest.cpp
	test/magma/KeyDataNativeTest.cpp
	test/magma/KeyDataStringTest.cpp
	test/magma/SboxNibbleTest.cpp
	test/magma/SboxTwistedTest.cpp
)
TARGET_LINK_LIBRARIES(test_runner goost)
ADD_TEST(unittest test_runner)
