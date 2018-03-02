cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set (GRAMMAR_FILE ../Expr.g4)

set (ANTLR4_CMD "./../antlr/antlr4.sh")
set (ANTLR4_ARG "-visitor;-no-listener;-Dlanguage=Cpp;${GRAMMAR_FILE}")

execute_process(COMMAND ${ANTLR4_CMD} ${ANTLR4_ARG}
        RESULT_VARIABLE result
        OUTPUT_VARIABLE output)



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
