# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zhangchenxu/C++/Basic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhangchenxu/C++/Basic/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/simple_calculator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simple_calculator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simple_calculator.dir/flags.make

CMakeFiles/simple_calculator.dir/threshold/simple_calculator.cpp.o: CMakeFiles/simple_calculator.dir/flags.make
CMakeFiles/simple_calculator.dir/threshold/simple_calculator.cpp.o: ../threshold/simple_calculator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhangchenxu/C++/Basic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/simple_calculator.dir/threshold/simple_calculator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_calculator.dir/threshold/simple_calculator.cpp.o -c /Users/zhangchenxu/C++/Basic/threshold/simple_calculator.cpp

CMakeFiles/simple_calculator.dir/threshold/simple_calculator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_calculator.dir/threshold/simple_calculator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangchenxu/C++/Basic/threshold/simple_calculator.cpp > CMakeFiles/simple_calculator.dir/threshold/simple_calculator.cpp.i

CMakeFiles/simple_calculator.dir/threshold/simple_calculator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_calculator.dir/threshold/simple_calculator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangchenxu/C++/Basic/threshold/simple_calculator.cpp -o CMakeFiles/simple_calculator.dir/threshold/simple_calculator.cpp.s

# Object files for target simple_calculator
simple_calculator_OBJECTS = \
"CMakeFiles/simple_calculator.dir/threshold/simple_calculator.cpp.o"

# External object files for target simple_calculator
simple_calculator_EXTERNAL_OBJECTS =

simple_calculator: CMakeFiles/simple_calculator.dir/threshold/simple_calculator.cpp.o
simple_calculator: CMakeFiles/simple_calculator.dir/build.make
simple_calculator: CMakeFiles/simple_calculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhangchenxu/C++/Basic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable simple_calculator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple_calculator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simple_calculator.dir/build: simple_calculator

.PHONY : CMakeFiles/simple_calculator.dir/build

CMakeFiles/simple_calculator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simple_calculator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simple_calculator.dir/clean

CMakeFiles/simple_calculator.dir/depend:
	cd /Users/zhangchenxu/C++/Basic/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhangchenxu/C++/Basic /Users/zhangchenxu/C++/Basic /Users/zhangchenxu/C++/Basic/cmake-build-debug /Users/zhangchenxu/C++/Basic/cmake-build-debug /Users/zhangchenxu/C++/Basic/cmake-build-debug/CMakeFiles/simple_calculator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simple_calculator.dir/depend

