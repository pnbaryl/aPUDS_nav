cmake_minimum_required(VERSION 3.10)
project(example)

include(ExternalProject)

set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/Rust)
set(RUST_PROJ_DIR "${CMAKE_SOURCE_DIR}/../..")
set(RUST_OUT_DIR "${RUST_PROJ_DIR}/target/debug")

add_custom_target(navigator
    COMMAND cargo build
    COMMENT "C binds generated: ${RUST_OUT_DIR}"
)

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(LIB_EXT "dylib")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(LIB_EXT "dll")
else()
    set(LIB_EXT "so")
endif()

# List of binaries
set(BINARIES APUDS)

foreach(BINARY ${BINARIES})
    add_executable(${BINARY} ${BINARY}.cpp)
    add_dependencies(${BINARY} navigator)

    target_link_libraries(
        ${BINARY}
            "${RUST_OUT_DIR}/libbluerobotics_navigator.${LIB_EXT}"
    )

    set_target_properties(${BINARY} PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON)
    target_include_directories(${BINARY} PRIVATE "${RUST_OUT_DIR}")
endforeach()
