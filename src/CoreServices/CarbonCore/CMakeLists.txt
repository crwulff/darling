project(CarbonCore)

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

set(CarbonCore_SRCS
	FSEvents.cpp
	Gestalt.cpp
	Services.cpp
	ThreadSupport.cpp
)

add_library(CarbonCore SHARED ${CarbonCore_SRCS})
target_link_libraries(CarbonCore -Wl,--no-as-needed CoreFoundation)

install(TARGETS CarbonCore DESTINATION "lib${SUFFIX}/darling")

