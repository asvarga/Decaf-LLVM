cmake_minimum_required(VERSION 3.10)

project(Decaf)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_COMPILER ${CMAKE_CXX_COMPILER})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -ldl -lfl")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_FLEX_BISON_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lexer_parser_output)

# Create the directory for flex and bison outputs
file(MAKE_DIRECTORY ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY})

# Setup the required Libraries
# find_package(LLVM REQUIRED CONFIG)
# message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
# message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
find_package(BISON)
find_package(FLEX)

# Add directories which have source filesc
include_directories(src)

# Make Lexical analyser and parser using flex and bison
#BISON_TARGET(Parser src/decaf_parser.ypp ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY}/decaf.tab.cpp)
FLEX_TARGET(Lexer src/decaf_lexer.l ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY}/lex.yy.cc)

# Add the main executable
add_executable(decafCompiler
        ${FLEX_Lexer_OUTPUTS}
        ${BISON_Parser_OUTPUTS})
target_include_directories(decafCompiler PRIVATE
        ${CMAKE_FLEX_BISON_OUTPUT_DIRECTORY})
target_link_libraries(decafCompiler coreLibrary)
