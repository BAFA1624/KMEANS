cmake_minimum_required(VERSION 3.16)
project(KMEANS)

add_compile_options(-Wall -Wextra -pedantic -O3)

add_library(DataStructs STATIC DataStructs.h)
add_library(ErrorHandle STATIC ErrorHandle.h)
add_library(LoadData STATIC ParseFile.h ProcessFile.h)

add_executable(
	test
	test.c
)

set_target_properties(DataStructs PROPERTIES LINKER_LANGUAGE C)
set_target_properties(ErrorHandle PROPERTIES LINKER_LANGUAGE C)
set_target_properties(LoadData PROPERTIES LINKER_LANGUAGE C)

target_link_libraries(test DataStructs LoadData)

