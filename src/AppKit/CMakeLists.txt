project(AppKit)

cmake_minimum_required(VERSION 2.4.0)
if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

#if (NOT "${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_ARG1}" MATCHES ".*clang")
#	message(FATAL_ERROR "Clang is the only supported compiler.")
#endif (NOT "${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_ARG1}" MATCHES ".*clang")

#configure_file(config.h.in config.h)

# CMake is broken and uses C++ flags for ObjC
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -fblocks")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fconstant-string-class=NSConstantString")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../util)

set(AppKit_SRCS
	NSAnimationContext.mm
	NSAnimationManager.mm
	NSDocumentController.mm
	NSImage.mm
	NSKeyValueBinding.mm
	NSLayoutConstraint.mm
	NSPasteboard.mm
	NSTableCellView.mm
)

add_library(AppKit SHARED ${AppKit_SRCS})
target_link_libraries(AppKit -Wl,--no-as-needed CoreFoundation
	CoreImage # via QuartzCore
	ApplicationServices)
SET_TARGET_PROPERTIES(AppKit PROPERTIES LINKER_LANGUAGE C)

install(TARGETS AppKit DESTINATION "lib${SUFFIX}/darling")

