CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(goost)

INCLUDE(CTest)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

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
	magma/BlkBackwarded.cpp
	magma/BlkDecrypted.cpp
	magma/BlkEncrypted.cpp
	magma/BlkForwarded.cpp
	magma/BlkRaw.cpp
	magma/BlkShifted.cpp
	magma/BlkString.cpp
	magma/BlkSwapped.cpp
	magma/BlkXored.cpp
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

ADD_SUBDIRECTORY(test)

add_custom_target(
	style
	COMMAND ${CMAKE_SOURCE_DIR}/style.sh
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
