cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(EXECUTABLE_OUTPUT_PATH ../bin/)
set(CMAKE_CXX_STANDARD 11)

project(app)

add_subdirectory(antlr/runtime_src_linux)

# get all files
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB HEADER_FILES ${PROJECT_SOURCE_DIR}/*.h)

add_executable(app ${SRC_FILES} ${HEADER_FILES})

target_include_directories(app PRIVATE antlr/runtime_src_linux/runtime/src)
target_link_libraries(app antlr4_shared)
