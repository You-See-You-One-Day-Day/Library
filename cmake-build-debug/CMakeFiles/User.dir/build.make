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
CMAKE_SOURCE_DIR = /Users/wuqiquan/CLionProjects/Library

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wuqiquan/CLionProjects/Library/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/User.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/User.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/User.dir/flags.make

CMakeFiles/User.dir/User.cpp.o: CMakeFiles/User.dir/flags.make
CMakeFiles/User.dir/User.cpp.o: ../User.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wuqiquan/CLionProjects/Library/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/User.dir/User.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/User.dir/User.cpp.o -c /Users/wuqiquan/CLionProjects/Library/User.cpp

CMakeFiles/User.dir/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/User.dir/User.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wuqiquan/CLionProjects/Library/User.cpp > CMakeFiles/User.dir/User.cpp.i

CMakeFiles/User.dir/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/User.dir/User.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wuqiquan/CLionProjects/Library/User.cpp -o CMakeFiles/User.dir/User.cpp.s

# Object files for target User
User_OBJECTS = \
"CMakeFiles/User.dir/User.cpp.o"

# External object files for target User
User_EXTERNAL_OBJECTS =

User: CMakeFiles/User.dir/User.cpp.o
User: CMakeFiles/User.dir/build.make
User: CMakeFiles/User.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wuqiquan/CLionProjects/Library/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable User"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/User.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/User.dir/build: User

.PHONY : CMakeFiles/User.dir/build

CMakeFiles/User.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/User.dir/cmake_clean.cmake
.PHONY : CMakeFiles/User.dir/clean

CMakeFiles/User.dir/depend:
	cd /Users/wuqiquan/CLionProjects/Library/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wuqiquan/CLionProjects/Library /Users/wuqiquan/CLionProjects/Library /Users/wuqiquan/CLionProjects/Library/cmake-build-debug /Users/wuqiquan/CLionProjects/Library/cmake-build-debug /Users/wuqiquan/CLionProjects/Library/cmake-build-debug/CMakeFiles/User.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/User.dir/depend

