include(${CMAKE_CURRENT_LIST_DIR}/ccache.cmake)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(TOOLCHAIN_PREFIX arm-none-eabi-)

set(CMAKE_C_COMPILER    ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_CXX_COMPILER  ${TOOLCHAIN_PREFIX}g++)
set(CMAKE_ASM_COMPILER  ${CMAKE_C_COMPILER})
set(CMAKE_OBJCOPY       ${TOOLCHAIN_PREFIX}objcopy)
set(CMAKE_SIZE          ${TOOLCHAIN_PREFIX}size)

set(CMAKE_EXECUTABLE_SUFFIX_C   ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_CXX ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_ASM ".elf")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_FLAGS "")
set(CMAKE_ASM_FLAGS "")
set(CMAKE_EXE_LINKER_FLAGS "")
set(CMAKE_C_FLAGS_DEBUG "")
set(CMAKE_CXX_FLAGS_DEBUG "")
set(CMAKE_ASM_FLAGS_DEBUG "")
set(CMAKE_C_FLAGS_RELEASE "")
set(CMAKE_CXX_FLAGS_RELEASE "")
set(CMAKE_ASM_FLAGS_RELEASE "")

add_compile_options(
    -Wall
    -fdata-sections
    -ffunction-sections
    -fmessage-length=0
    -fno-strict-aliasing
    -fshort-enums
    -Wno-unused-function
    -mthumb
    -mno-unaligned-access
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_compile_options(-Og -g -gdwarf-2)
  add_link_options(-g -gdwarf-2)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
  add_compile_options(-Os)
endif()

set(CMAKE_CXX_FLAGS
    "-std=c++17 \
    -fno-rtti \
    -fno-exceptions \
    -fpermissive \
    -fno-threadsafe-statics"
)

set(CMAKE_C_FLAGS
    "-std=gnu11 \
    -Wno-parentheses-equality \
    -Wno-unused-value \
    -Wno-implicit-function-declaration \
    -Wno-array-bounds"
)

set(CMAKE_ASM_FLAGS
    "-x assembler-with-cpp"
)

set(CMAKE_EXE_LINKER_FLAGS
    "-Wl,--gc-sections \
    -Wl,--print-memory-usage"
)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)