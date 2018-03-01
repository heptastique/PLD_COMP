cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(EXECUTABLE_OUTPUT_PATH ../bin/)
set(CMAKE_CXX_STANDARD 11)

project(app)

add_subdirectory(antlr/runtime_src_linux)

# get all *.cpp files
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(compilatif ${SRC_FILES} Calc.h)

target_include_directories(compilatif PRIVATE antlr/runtime_src/runtime/src)
target_link_libraries(compilatif antlr4_shared)