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
include CMakeFiles/PAT_A_1003_bellman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PAT_A_1003_bellman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PAT_A_1003_bellman.dir/flags.make

CMakeFiles/PAT_A_1003_bellman.dir/pat_a/PAT_A_1003_bellman.cpp.o: CMakeFiles/PAT_A_1003_bellman.dir/flags.make
CMakeFiles/PAT_A_1003_bellman.dir/pat_a/PAT_A_1003_bellman.cpp.o: ../pat_a/PAT_A_1003_bellman.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhangchenxu/C++/Basic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PAT_A_1003_bellman.dir/pat_a/PAT_A_1003_bellman.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PAT_A_1003_bellman.dir/pat_a/PAT_A_1003_bellman.cpp.o -c /Users/zhangchenxu/C++/Basic/pat_a/PAT_A_1003_bellman.cpp

CMakeFiles/PAT_A_1003_bellman.dir/pat_a/PAT_A_1003_bellman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PAT_A_1003_bellman.dir/pat_a/PAT_A_1003_bellman.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangchenxu/C++/Basic/pat_a/PAT_A_1003_bellman.cpp > CMakeFiles/PAT_A_1003_bellman.dir/pat_a/PAT_A_1003_bellman.cpp.i

CMakeFiles/PAT_A_1003_bellman.dir/pat_a/PAT_A_1003_bellman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PAT_A_1003_bellman.dir/pat_a/PAT_A_1003_bellman.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangchenxu/C++/Basic/pat_a/PAT_A_1003_bellman.cpp -o CMakeFiles/PAT_A_1003_bellman.dir/pat_a/PAT_A_1003_bellman.cpp.s

# Object files for target PAT_A_1003_bellman
PAT_A_1003_bellman_OBJECTS = \
"CMakeFiles/PAT_A_1003_bellman.dir/pat_a/PAT_A_1003_bellman.cpp.o"

# External object files for target PAT_A_1003_bellman
PAT_A_1003_bellman_EXTERNAL_OBJECTS =

PAT_A_1003_bellman: CMakeFiles/PAT_A_1003_bellman.dir/pat_a/PAT_A_1003_bellman.cpp.o
PAT_A_1003_bellman: CMakeFiles/PAT_A_1003_bellman.dir/build.make
PAT_A_1003_bellman: CMakeFiles/PAT_A_1003_bellman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhangchenxu/C++/Basic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PAT_A_1003_bellman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PAT_A_1003_bellman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PAT_A_1003_bellman.dir/build: PAT_A_1003_bellman

.PHONY : CMakeFiles/PAT_A_1003_bellman.dir/build

CMakeFiles/PAT_A_1003_bellman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PAT_A_1003_bellman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PAT_A_1003_bellman.dir/clean

CMakeFiles/PAT_A_1003_bellman.dir/depend:
	cd /Users/zhangchenxu/C++/Basic/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhangchenxu/C++/Basic /Users/zhangchenxu/C++/Basic /Users/zhangchenxu/C++/Basic/cmake-build-debug /Users/zhangchenxu/C++/Basic/cmake-build-debug /Users/zhangchenxu/C++/Basic/cmake-build-debug/CMakeFiles/PAT_A_1003_bellman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PAT_A_1003_bellman.dir/depend

