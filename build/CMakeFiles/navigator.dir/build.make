# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/navigator-lib/examples/cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/navigator-lib/examples/cpp/build

# Utility rule file for navigator.

# Include the progress variables for this target.
include CMakeFiles/navigator.dir/progress.make

CMakeFiles/navigator:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/pi/navigator-lib/examples/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "C binds generated: /home/pi/navigator-lib/examples/cpp/../../target/debug"
	cargo build

navigator: CMakeFiles/navigator
navigator: CMakeFiles/navigator.dir/build.make

.PHONY : navigator

# Rule to build all files generated by this target.
CMakeFiles/navigator.dir/build: navigator

.PHONY : CMakeFiles/navigator.dir/build

CMakeFiles/navigator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/navigator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/navigator.dir/clean

CMakeFiles/navigator.dir/depend:
	cd /home/pi/navigator-lib/examples/cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/navigator-lib/examples/cpp /home/pi/navigator-lib/examples/cpp /home/pi/navigator-lib/examples/cpp/build /home/pi/navigator-lib/examples/cpp/build /home/pi/navigator-lib/examples/cpp/build/CMakeFiles/navigator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/navigator.dir/depend

