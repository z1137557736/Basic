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
include CMakeFiles/complete_knapsack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/complete_knapsack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/complete_knapsack.dir/flags.make

CMakeFiles/complete_knapsack.dir/dp/knapsack/complete_knapsack.cpp.o: CMakeFiles/complete_knapsack.dir/flags.make
CMakeFiles/complete_knapsack.dir/dp/knapsack/complete_knapsack.cpp.o: ../dp/knapsack/complete_knapsack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhangchenxu/C++/Basic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/complete_knapsack.dir/dp/knapsack/complete_knapsack.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/complete_knapsack.dir/dp/knapsack/complete_knapsack.cpp.o -c /Users/zhangchenxu/C++/Basic/dp/knapsack/complete_knapsack.cpp

CMakeFiles/complete_knapsack.dir/dp/knapsack/complete_knapsack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/complete_knapsack.dir/dp/knapsack/complete_knapsack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangchenxu/C++/Basic/dp/knapsack/complete_knapsack.cpp > CMakeFiles/complete_knapsack.dir/dp/knapsack/complete_knapsack.cpp.i

CMakeFiles/complete_knapsack.dir/dp/knapsack/complete_knapsack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/complete_knapsack.dir/dp/knapsack/complete_knapsack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangchenxu/C++/Basic/dp/knapsack/complete_knapsack.cpp -o CMakeFiles/complete_knapsack.dir/dp/knapsack/complete_knapsack.cpp.s

# Object files for target complete_knapsack
complete_knapsack_OBJECTS = \
"CMakeFiles/complete_knapsack.dir/dp/knapsack/complete_knapsack.cpp.o"

# External object files for target complete_knapsack
complete_knapsack_EXTERNAL_OBJECTS =

complete_knapsack: CMakeFiles/complete_knapsack.dir/dp/knapsack/complete_knapsack.cpp.o
complete_knapsack: CMakeFiles/complete_knapsack.dir/build.make
complete_knapsack: CMakeFiles/complete_knapsack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhangchenxu/C++/Basic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable complete_knapsack"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/complete_knapsack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/complete_knapsack.dir/build: complete_knapsack

.PHONY : CMakeFiles/complete_knapsack.dir/build

CMakeFiles/complete_knapsack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/complete_knapsack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/complete_knapsack.dir/clean

CMakeFiles/complete_knapsack.dir/depend:
	cd /Users/zhangchenxu/C++/Basic/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhangchenxu/C++/Basic /Users/zhangchenxu/C++/Basic /Users/zhangchenxu/C++/Basic/cmake-build-debug /Users/zhangchenxu/C++/Basic/cmake-build-debug /Users/zhangchenxu/C++/Basic/cmake-build-debug/CMakeFiles/complete_knapsack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/complete_knapsack.dir/depend

