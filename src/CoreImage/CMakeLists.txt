project(CoreImage)

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

set(CoreImage_SRCS
	CIFilter.m
	CIImage.m
	CISampler.m
)

add_library(CoreImage SHARED ${CoreImage_SRCS})
target_link_libraries(CoreImage -lgnustep-base objc.A.dylib)

install(TARGETS CoreImage DESTINATION "lib${SUFFIX}/darling")

