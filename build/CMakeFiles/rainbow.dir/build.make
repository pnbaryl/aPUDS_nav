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

# Include any dependencies generated for this target.
include CMakeFiles/rainbow.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rainbow.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rainbow.dir/flags.make

CMakeFiles/rainbow.dir/rainbow.cpp.o: CMakeFiles/rainbow.dir/flags.make
CMakeFiles/rainbow.dir/rainbow.cpp.o: ../rainbow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/navigator-lib/examples/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rainbow.dir/rainbow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rainbow.dir/rainbow.cpp.o -c /home/pi/navigator-lib/examples/cpp/rainbow.cpp

CMakeFiles/rainbow.dir/rainbow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rainbow.dir/rainbow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/navigator-lib/examples/cpp/rainbow.cpp > CMakeFiles/rainbow.dir/rainbow.cpp.i

CMakeFiles/rainbow.dir/rainbow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rainbow.dir/rainbow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/navigator-lib/examples/cpp/rainbow.cpp -o CMakeFiles/rainbow.dir/rainbow.cpp.s

# Object files for target rainbow
rainbow_OBJECTS = \
"CMakeFiles/rainbow.dir/rainbow.cpp.o"

# External object files for target rainbow
rainbow_EXTERNAL_OBJECTS =

rainbow: CMakeFiles/rainbow.dir/rainbow.cpp.o
rainbow: CMakeFiles/rainbow.dir/build.make
rainbow: ../../../target/debug/libbluerobotics_navigator.so
rainbow: CMakeFiles/rainbow.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/navigator-lib/examples/cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rainbow"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rainbow.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rainbow.dir/build: rainbow

.PHONY : CMakeFiles/rainbow.dir/build

CMakeFiles/rainbow.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rainbow.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rainbow.dir/clean

CMakeFiles/rainbow.dir/depend:
	cd /home/pi/navigator-lib/examples/cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/navigator-lib/examples/cpp /home/pi/navigator-lib/examples/cpp /home/pi/navigator-lib/examples/cpp/build /home/pi/navigator-lib/examples/cpp/build /home/pi/navigator-lib/examples/cpp/build/CMakeFiles/rainbow.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rainbow.dir/depend

