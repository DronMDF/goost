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
ADD_COMPILE_OPTIONS(-std=c++17 -O2 -fomit-frame-pointer -g0
	-Wall -Wextra -Weffc++ -Wpedantic -Werror
	-Wno-non-virtual-dtor)

ADD_LIBRARY(goost
	goost/gost89/DataImit.cpp
	goost/gost89/ImitedBlock.cpp
	goost/kuznyechik/BlkCached.cpp
	goost/kuznyechik/BlkEncrypted.cpp
	goost/kuznyechik/BlkIncremented.cpp
	goost/kuznyechik/BlkIterKey.cpp
	goost/kuznyechik/BlkL.cpp
	goost/kuznyechik/BlkRaw.cpp
	goost/kuznyechik/BlkR.cpp
	goost/kuznyechik/BlkS.cpp
	goost/kuznyechik/BlkShifted.cpp
	goost/kuznyechik/BlkString.cpp
	goost/kuznyechik/BlkXored.cpp
	goost/kuznyechik/Imit.cpp
	goost/kuznyechik/Key.cpp
	goost/kuznyechik/KeyDataString.cpp
	goost/kuznyechik/StCTREncrypted.cpp
	goost/kuznyechik/StMemory.cpp
	goost/magma/BlkBackwarded.cpp
	goost/magma/BlkDecrypted.cpp
	goost/magma/BlkEncrypted.cpp
	goost/magma/BlkForwarded.cpp
	goost/magma/BlkRaw.cpp
	goost/magma/BlkShifted.cpp
	goost/magma/BlkString.cpp
	goost/magma/BlkSwapped.cpp
	goost/magma/BlkXored.cpp
	goost/magma/CFBSink.cpp
	goost/magma/Imit.cpp
	goost/magma/KeyCachedData.cpp
	goost/magma/Key.cpp
	goost/magma/KeyDataNative.cpp
	goost/magma/KeyDataString.cpp
	goost/magma/SboxByte64Tab.cpp
	goost/magma/SboxByte.cpp
	goost/magma/SboxNibble.cpp
	goost/magma/SboxR3412.cpp
	goost/magma/SboxTwisted.cpp
	goost/magma/StMemory.cpp
)

ADD_SUBDIRECTORY(test)

add_custom_target(
	style
	COMMAND ${CMAKE_SOURCE_DIR}/style.sh
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
