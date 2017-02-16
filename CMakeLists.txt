CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(goost)

INCLUDE(CTest)

INCLUDE_DIRECTORIES(
	"${PROJECT_SOURCE_DIR}"
	"${PROJECT_SOURCE_DIR}/test"
)

ADD_COMPILE_OPTIONS(-O2 -g0)

ADD_LIBRARY(goost
	magma/DataImit.cpp
	magma/Key.cpp
	magma/KeyDataString.cpp
	magma/Sbox.cpp
)

ADD_EXECUTABLE(test_runner
	test/main.cpp
	test/magma/DataImitTest.cpp
	test/magma/KeyDataStringTest.cpp
)
TARGET_LINK_LIBRARIES(test_runner goost)
ADD_TEST(unittest test_runner)
