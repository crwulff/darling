project(xpc)

cmake_minimum_required(VERSION 2.4.0)
if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

#if (NOT "${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_ARG1}" MATCHES ".*clang")
#	message(FATAL_ERROR "Clang is the only supported compiler.")
#endif (NOT "${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_ARG1}" MATCHES ".*clang")

#configure_file(config.h.in config.h)

# CMake is broken and uses C++ flags for ObjC
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -fPIC -fvisibility=hidden")

set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fPIC -fvisibility=hidden")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_base=_OBJC_CLASS_OS_xpc_object")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_null=_OBJC_CLASS_OS_xpc_null")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_bool=_OBJC_CLASS_OS_xpc_bool")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_int64=_OBJC_CLASS_OS_xpc_int64")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_uint64=_OBJC_CLASS_OS_xpc_uint64")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_double=_OBJC_CLASS_OS_xpc_double")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_pointer=_OBJC_CLASS_OS_xpc_pointer")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_date=_OBJC_CLASS_OS_xpc_date")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_data=_OBJC_CLASS_OS_xpc_data")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_string=_OBJC_CLASS_OS_xpc_string")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_uuid=_OBJC_CLASS_OS_xpc_uuid")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_fd=_OBJC_CLASS_OS_xpc_fd")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_shmem=_OBJC_CLASS_OS_xpc_shmem")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_mach_send=_OBJC_CLASS_OS_xpc_mach_send")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_array=_OBJC_CLASS_OS_xpc_array")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_dictionary=_OBJC_CLASS_OS_xpc_dictionary")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_error=_OBJC_CLASS_OS_xpc_error")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_domain=_OBJC_CLASS_OS_xpc_domain")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_connection=_OBJC_CLASS_OS_xpc_connection")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_endpoint=_OBJC_CLASS_OS_xpc_endpoint")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_serializer=_OBJC_CLASS_OS_xpc_serializer")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_barrier=_OBJC_CLASS_OS_xpc_barrier")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_pipe=_OBJC_CLASS_OS_xpc_pipe")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_mach_recv=_OBJC_CLASS_OS_xpc_mach_recv")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--defsym -Wl,_xpc_type_bundle=_OBJC_CLASS_OS_xpc_bundle")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../util)

set(xpc_SRCS
	xpc.m
)

add_library(xpc SHARED ${xpc_SRCS})
target_link_libraries(xpc -Wl,--no-as-needed -lobjc)
SET_TARGET_PROPERTIES(xpc PROPERTIES LINKER_LANGUAGE C)

install(TARGETS xpc DESTINATION "lib${SUFFIX}/darling")

