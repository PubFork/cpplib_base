cmake_minimum_required(VERSION 3.8)

project(base)

message("-- system arch:  ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "current platform: ${CMAKE_SYSTEM_NAME} ")

add_definitions(-DOS_ARCH=${CMAKE_SYSTEM_NAME})

IF (CMAKE_BUILD_TYPE STREQUAL Debug)
    add_definitions(-DDEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
    message(STATUS "Compile Debug")
ELSE()
    add_definitions(-DRELEASE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -pthread")
    message(STATUS "Compile Release")
ENDIF()

IF (WIN32)
    add_definitions(-DOS_WIN=1)
ELSEIF (APPLE)
    add_definitions(-DOS_UNIX=1)
ELSEIF (UNIX)
    add_definitions(-DOS_UNIX=1)
ENDIF ()

set(PROJECT_OUTPUT_DIR ${PROJECT_BINARY_DIR}/${CMAKE_SYSTEM_PROCESSOR})
message("-- output path:  ${PROJECT_OUTPUT_DIR} ")

file(MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR}/lib)
file(MAKE_DIRECTORY ${PROJECT_OUTPUT_DIR}/bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_OUTPUT_DIR}/lib)

set(
    ProgrameSrc
    ${PROJECT_SOURCE_DIR}/src/base/base_export.h
    ${PROJECT_SOURCE_DIR}/src/base/macros.h
    ${PROJECT_SOURCE_DIR}/src/base/singleton.h
    ${PROJECT_SOURCE_DIR}/src/base/thread/closure.cc
    ${PROJECT_SOURCE_DIR}/src/base/thread/closure.h
    ${PROJECT_SOURCE_DIR}/src/base/thread/task_queue.cc
    ${PROJECT_SOURCE_DIR}/src/base/thread/task_queue.h
    ${PROJECT_SOURCE_DIR}/src/base/thread/thread.cc
    ${PROJECT_SOURCE_DIR}/src/base/thread/thread.h
    ${PROJECT_SOURCE_DIR}/src/base/thread/message_loop.cc
    ${PROJECT_SOURCE_DIR}/src/base/thread/message_loop.h
    ${PROJECT_SOURCE_DIR}/src/base/thread/message_loop_manager.cc
    ${PROJECT_SOURCE_DIR}/src/base/thread/message_loop_manager.h
    ${PROJECT_SOURCE_DIR}/src/base/thread/utils.cc
    ${PROJECT_SOURCE_DIR}/src/base/thread/utils.h
)
include_directories(${PROJECT_SOURCE_DIR})

add_library(
        ${PROJECT_NAME}
        STATIC
        ${ProgrameSrc})



# compile demo
set(
    demoSrc
    ${PROJECT_SOURCE_DIR}/src/demo/thread_test.cc
)

add_executable(demo ${demoSrc})
target_link_libraries(demo base)