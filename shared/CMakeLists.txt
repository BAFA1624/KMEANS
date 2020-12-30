cmake_minimum_required(VERSION 3.16)
project(KMEANS)

add_library(DataStructs SHARED DataStructs.h)

add_library(LoadData SHARED LoadData.h)


add_executable(
	test
	test.c
)

set_target_properties(DataStructs PROPERTIES LINKER_LANGUAGE C)
set_target_properties(LoadData PROPERTIES LINKER_LANGUAGE C)

target_link_libraries(test DataStructs LoadData)

