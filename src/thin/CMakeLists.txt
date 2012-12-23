project(thin)

cmake_minimum_required(VERSION 2.4.0)
if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

add_library(Carbon SHARED)
target_link_libraries(Carbon CoreServices)
SET_TARGET_PROPERTIES(Carbon PROPERTIES LINKER_LANGUAGE C)

install(TARGETS Carbon DESTINATION "lib${SUFFIX}/darling")

