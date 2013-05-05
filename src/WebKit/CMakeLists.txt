project(WebKit)

cmake_minimum_required(VERSION 2.4.0)
if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

#if (NOT "${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_ARG1}" MATCHES ".*clang")
#	message(FATAL_ERROR "Clang is the only supported compiler.")
#endif (NOT "${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_ARG1}" MATCHES ".*clang")

#configure_file(config.h.in config.h)

# CMake is broken and uses C++ flags for ObjC
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../util)

set(WebKit_SRCS
	WebArchive.m
)

add_library(WebKit SHARED ${WebKit_SRCS})
target_link_libraries(WebKit -Wl,--no-as-needed -lwebkitgtk-3.0 Cocoa AppKit
	CoreFoundation)

install(TARGETS WebKit DESTINATION "lib${SUFFIX}/darling")

