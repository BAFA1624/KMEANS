# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ben/c/KMEANS/shared

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ben/c/KMEANS/shared

# Include any dependencies generated for this target.
include CMakeFiles/DataStructs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DataStructs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DataStructs.dir/flags.make

# Object files for target DataStructs
DataStructs_OBJECTS =

# External object files for target DataStructs
DataStructs_EXTERNAL_OBJECTS =

libDataStructs.so: CMakeFiles/DataStructs.dir/build.make
libDataStructs.so: CMakeFiles/DataStructs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ben/c/KMEANS/shared/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking C shared library libDataStructs.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataStructs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DataStructs.dir/build: libDataStructs.so

.PHONY : CMakeFiles/DataStructs.dir/build

CMakeFiles/DataStructs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DataStructs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DataStructs.dir/clean

CMakeFiles/DataStructs.dir/depend:
	cd /home/ben/c/KMEANS/shared && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ben/c/KMEANS/shared /home/ben/c/KMEANS/shared /home/ben/c/KMEANS/shared /home/ben/c/KMEANS/shared /home/ben/c/KMEANS/shared/CMakeFiles/DataStructs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DataStructs.dir/depend

