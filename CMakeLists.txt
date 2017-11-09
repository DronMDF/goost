CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(goost)

INCLUDE(CTest)

INCLUDE_DIRECTORIES(
	"${PROJECT_SOURCE_DIR}"
	"${PROJECT_SOURCE_DIR}/test"
)

# @todo #104:15min -Wno-non-virtual-dtor cause from boost::enable_shared_trom_this class
#  How resolve this? Avois shared_from_this?
ADD_COMPILE_OPTIONS(-std=c++14 -O2 -fomit-frame-pointer -g0
	-Wall -Wextra -Weffc++ -Wpedantic -Werror
	-Wno-non-virtual-dtor)

ADD_LIBRARY(goost
	gost89/DataImit.cpp
	gost89/ImitedBlock.cpp
	kuznyechik/BlkCached.cpp
	kuznyechik/BlkEncrypted.cpp
	kuznyechik/BlkIncremented.cpp
	kuznyechik/BlkIterKey.cpp
	kuznyechik/BlkL.cpp
	kuznyechik/BlkRaw.cpp
	kuznyechik/BlkR.cpp
	kuznyechik/BlkS.cpp
	kuznyechik/BlkShifted.cpp
	kuznyechik/BlkString.cpp
	kuznyechik/BlkXored.cpp
	kuznyechik/Imit.cpp
	kuznyechik/Key.cpp
	kuznyechik/KeyDataString.cpp
	kuznyechik/StCTREncrypted.cpp
	kuznyechik/StMemory.cpp
	magma/BlkDecrypted.cpp
	magma/BlkEncrypted.cpp
	magma/BlkRaw.cpp
	magma/BlkString.cpp
	magma/Imit.cpp
	magma/KeyCachedData.cpp
	magma/Key.cpp
	magma/KeyDataNative.cpp
	magma/KeyDataString.cpp
	magma/SboxByte64Tab.cpp
	magma/SboxByte.cpp
	magma/SboxNibble.cpp
	magma/SboxR3412.cpp
	magma/SboxTwisted.cpp
	magma/StMemory.cpp
)

ADD_EXECUTABLE(test_goost
	test/gost89/DataImitTest.cpp
	test/gost89/ProceduralImitTest.cpp
	test/magma/SboxTwistedTest.cpp
	test/main.cpp
)
TARGET_LINK_LIBRARIES(test_goost goost)
ADD_TEST(unittest test_goost)

ADD_SUBDIRECTORY(2out)
ADD_SUBDIRECTORY(test2o)
