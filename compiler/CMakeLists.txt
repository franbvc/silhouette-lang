cmake_minimum_required(VERSION 3.12)
project(MyProject)

# Flex and Bison dependencies
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

# Flex target
flex_target(TokenizerFlex ./tokenizer-flex/tokens.l ${CMAKE_CURRENT_BINARY_DIR}/tokens.cpp)

# Bison target
bison_target(ParserBison ./parser-bison/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp COMPILE_FLAGS "-d")

# Executable target
add_executable(parser
    ${BISON_ParserBison_OUTPUTS}
    ${FLEX_TokenizerFlex_OUTPUTS}
    codegen.cpp
    main.cpp
)

# Include directories
target_include_directories(parser PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

# LLVM library
find_package(LLVM REQUIRED CONFIG)

# Linking options for Clang++
target_link_libraries(parser PRIVATE
    LLVM
)

# Debugging options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

# Print Flex output files
foreach(outputFile ${FLEX_TokenizerFlex_OUTPUTS})
	message(STATUS "Flex output file: ${outputFile}")
endforeach()

 # Print Bison output files
foreach(outputFile ${BISON_ParserBison_OUTPUTS})
    message(STATUS "Bison output file: ${outputFile}")
endforeach()

