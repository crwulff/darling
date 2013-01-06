project(dyld)

cmake_minimum_required(VERSION 2.4.0)

MACRO(STRING_TRIM var str)
	SET(_var_1 "\r${str}\r")
	STRING(REPLACE  "\r[ \t]*" "" _var_2 "${_var_1}" )
	STRING(REGEX REPLACE  "[ \t\r\n]*\r" "" ${var} "${_var_2}" )
    ENDMACRO(STRING_TRIM var str)
MACRO(COMMAND_OUTPUT_TO_VARIABLE var cmd)
	EXECUTE_PROCESS(
	    COMMAND ${cmd} ${ARGN}
	    OUTPUT_VARIABLE _cmd_output
	    )
	IF(_cmd_output)
	    STRING_TRIM(${var} ${_cmd_output})
	ELSE(_cmd_output)
	    SET(var "${var}-NOVALUE")
	ENDIF(_cmd_output)
	# MESSAGE("var=${var} _cmd_output=${_cmd_output}")
    ENDMACRO(COMMAND_OUTPUT_TO_VARIABLE var cmd)

SET(LLVM_CXXFLAGS "ERR")
SET(LLVM_LDFLAGS "ERR")
COMMAND_OUTPUT_TO_VARIABLE(LLVM_CXXFLAGS bash -c "llvm-config --cxxflags | tr -d '\n'")
COMMAND_OUTPUT_TO_VARIABLE(LLVM_LDFLAGS  bash -c "llvm-config --libs all --ldflags | tr -d '\n'")
MESSAGE("LLVM_CXXFLAGS: ${LLVM_CXXFLAGS}")
MESSAGE("LLVM_LDFLAGS: ${LLVM_LDFLAGS}")

if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

set(dyld_SRCS
	eh/DwarfPointer.cpp
	eh/BufWriter.cpp
	eh/BufReader.cpp
	eh/EHSection.cpp
	FileMap.cpp
	MachOLoader.cpp
	Trampoline.cpp
	trampoline_helper.nasm
	dyld_stub_binder.nasm
	ld.cpp
	dyld.cpp
	public.cpp
	binfmt_misc.cpp
	GDBInterface.cpp
	ELFBlock.cpp
	DWARFProducer.cpp
)

if (DEBUG)
	set(dyld_SRCS
		${dyld_SRCS}
		UndefinedFunction.cpp
	)

endif (DEBUG)

SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib${SUFFIX}/darling")
#SET(CMAKE_EXE_LINKER_FLAGS "-Wl,--enable-new-dtags")
SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE) 
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_library(undef_func_llvm STATIC UndefinedFunction.cpp )
add_executable(dyld${SUFFIX} ${dyld_SRCS})
set_source_files_properties(UndefinedFunction.cpp PROPERTIES COMPILE_FLAGS "${LLVM_CXXFLAGS}")
target_link_libraries(dyld${SUFFIX} -ldl -lpthread mach-o util undef_func_llvm ${LLVM_LDFLAGS} -lobjc -ldwarf)


install(TARGETS dyld${SUFFIX} DESTINATION bin)

