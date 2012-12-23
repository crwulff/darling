project(Cocoa)

cmake_minimum_required(VERSION 2.4.0)
if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

add_library(Cocoa SHARED zero.c)
target_link_libraries(Cocoa  -Wl,--no-as-needed
	-lgnustep-gui -lopal crashhandler CoreFoundation
	Foundation -lobjc)

install(TARGETS Cocoa DESTINATION "lib${SUFFIX}/darling")

