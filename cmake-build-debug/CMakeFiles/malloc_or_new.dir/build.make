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
include CMakeFiles/malloc_or_new.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/malloc_or_new.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/malloc_or_new.dir/flags.make

CMakeFiles/malloc_or_new.dir/data_strcut/malloc_or_new.cpp.o: CMakeFiles/malloc_or_new.dir/flags.make
CMakeFiles/malloc_or_new.dir/data_strcut/malloc_or_new.cpp.o: ../data_strcut/malloc_or_new.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zhangchenxu/C++/Basic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/malloc_or_new.dir/data_strcut/malloc_or_new.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/malloc_or_new.dir/data_strcut/malloc_or_new.cpp.o -c /Users/zhangchenxu/C++/Basic/data_strcut/malloc_or_new.cpp

CMakeFiles/malloc_or_new.dir/data_strcut/malloc_or_new.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/malloc_or_new.dir/data_strcut/malloc_or_new.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangchenxu/C++/Basic/data_strcut/malloc_or_new.cpp > CMakeFiles/malloc_or_new.dir/data_strcut/malloc_or_new.cpp.i

CMakeFiles/malloc_or_new.dir/data_strcut/malloc_or_new.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/malloc_or_new.dir/data_strcut/malloc_or_new.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangchenxu/C++/Basic/data_strcut/malloc_or_new.cpp -o CMakeFiles/malloc_or_new.dir/data_strcut/malloc_or_new.cpp.s

# Object files for target malloc_or_new
malloc_or_new_OBJECTS = \
"CMakeFiles/malloc_or_new.dir/data_strcut/malloc_or_new.cpp.o"

# External object files for target malloc_or_new
malloc_or_new_EXTERNAL_OBJECTS =

malloc_or_new: CMakeFiles/malloc_or_new.dir/data_strcut/malloc_or_new.cpp.o
malloc_or_new: CMakeFiles/malloc_or_new.dir/build.make
malloc_or_new: CMakeFiles/malloc_or_new.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zhangchenxu/C++/Basic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable malloc_or_new"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/malloc_or_new.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/malloc_or_new.dir/build: malloc_or_new

.PHONY : CMakeFiles/malloc_or_new.dir/build

CMakeFiles/malloc_or_new.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/malloc_or_new.dir/cmake_clean.cmake
.PHONY : CMakeFiles/malloc_or_new.dir/clean

CMakeFiles/malloc_or_new.dir/depend:
	cd /Users/zhangchenxu/C++/Basic/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhangchenxu/C++/Basic /Users/zhangchenxu/C++/Basic /Users/zhangchenxu/C++/Basic/cmake-build-debug /Users/zhangchenxu/C++/Basic/cmake-build-debug /Users/zhangchenxu/C++/Basic/cmake-build-debug/CMakeFiles/malloc_or_new.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/malloc_or_new.dir/depend

