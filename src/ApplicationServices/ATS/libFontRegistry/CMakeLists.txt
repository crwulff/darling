project(libFontRegistry)

cmake_minimum_required(VERSION 2.4.0)
if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

#if (NOT "${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_ARG1}" MATCHES ".*clang")
#	message(FATAL_ERROR "Clang is the only supported compiler.")
#endif (NOT "${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_ARG1}" MATCHES ".*clang")

#configure_file(config.h.in config.h)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fblocks")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(libFontRegistry_SRCS
	FontProperties.cpp
)

add_library(libFontRegistry SHARED ${libFontRegistry_SRCS})
target_link_libraries(libFontRegistry -lgnustep-corebase objcdarwin)

install(TARGETS libFontRegistry DESTINATION "lib${SUFFIX}/darling")

