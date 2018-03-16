cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(app)

set (GRAMMAR_FILE ../grammar/Prog.g4)
set (ANTLR4_CMD "./../antlr/antlr4.sh")
set (ANTLR4_ARG "-visitor;-no-listener;-Dlanguage=Cpp;${GRAMMAR_FILE}")
set(ANTLR4_INSTALL_CMD "./../antlr/antlr_installer.sh")

find_library(ANTLR_LIBRARY antlr4-runtime PATHS ${PROJECT_SOURCE_DIR}/antlr/install/usr/local/lib)
if(ANTLR_LIBRARY)
    message("Antlr library found")
    link_directories(${PROJECT_SOURCE_DIR}/antlr/install/usr/local/lib)
    include_directories(${PROJECT_SOURCE_DIR}/antlr/install/usr/local/include/antlr4-runtime)
    else()
    message("Antlr library not found")
    execute_process(COMMAND ${ANTLR4_INSTALL_CMD}
            RESULT_VARIABLE result
            OUTPUT_VARIABLE output)
    # Until I find better        
    find_library(ANTLR_LIBRARY antlr4-runtime PATHS ${PROJECT_SOURCE_DIR}/antlr/install/usr/local/lib)
    link_directories(${PROJECT_SOURCE_DIR}/antlr/install/usr/local/lib)
    include_directories(${PROJECT_SOURCE_DIR}/antlr/install/usr/local/include/antlr4-runtime)
endif()

execute_process(COMMAND ${ANTLR4_CMD} ${ANTLR4_ARG}
        RESULT_VARIABLE result
        OUTPUT_VARIABLE output)


set(EXECUTABLE_OUTPUT_PATH ../bin/)
set(CMAKE_CXX_STANDARD 11)


# get all files
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/grammar/*.cpp ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB HEADER_FILES ${PROJECT_SOURCE_DIR}/grammar/*.h ${PROJECT_SOURCE_DIR}/src/*.h ${PROJECT_SOURCE_DIR}/*.h)

add_executable(app ${SRC_FILES} ${HEADER_FILES})

target_link_libraries(app ${ANTLR_LIBRARY})
target_compile_options(app PRIVATE -Wno-attributes)
