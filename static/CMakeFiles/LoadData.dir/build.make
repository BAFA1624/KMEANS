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
CMAKE_SOURCE_DIR = /home/ben/c/KMEANS/static

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ben/c/KMEANS/static

# Include any dependencies generated for this target.
include CMakeFiles/LoadData.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LoadData.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LoadData.dir/flags.make

# Object files for target LoadData
LoadData_OBJECTS =

# External object files for target LoadData
LoadData_EXTERNAL_OBJECTS =

libLoadData.a: CMakeFiles/LoadData.dir/build.make
libLoadData.a: CMakeFiles/LoadData.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ben/c/KMEANS/static/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking C static library libLoadData.a"
	$(CMAKE_COMMAND) -P CMakeFiles/LoadData.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LoadData.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LoadData.dir/build: libLoadData.a

.PHONY : CMakeFiles/LoadData.dir/build

CMakeFiles/LoadData.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LoadData.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LoadData.dir/clean

CMakeFiles/LoadData.dir/depend:
	cd /home/ben/c/KMEANS/static && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ben/c/KMEANS/static /home/ben/c/KMEANS/static /home/ben/c/KMEANS/static /home/ben/c/KMEANS/static /home/ben/c/KMEANS/static/CMakeFiles/LoadData.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LoadData.dir/depend

