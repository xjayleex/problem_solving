# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ijaehyeon/Desktop/MyDocuments/gitblog/samsungsds_algorithm/number_theory/boj1722

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ijaehyeon/Desktop/MyDocuments/gitblog/samsungsds_algorithm/number_theory/boj1722/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/boj1722.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/boj1722.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/boj1722.dir/flags.make

CMakeFiles/boj1722.dir/main.cpp.o: CMakeFiles/boj1722.dir/flags.make
CMakeFiles/boj1722.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ijaehyeon/Desktop/MyDocuments/gitblog/samsungsds_algorithm/number_theory/boj1722/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/boj1722.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boj1722.dir/main.cpp.o -c /Users/ijaehyeon/Desktop/MyDocuments/gitblog/samsungsds_algorithm/number_theory/boj1722/main.cpp

CMakeFiles/boj1722.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boj1722.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ijaehyeon/Desktop/MyDocuments/gitblog/samsungsds_algorithm/number_theory/boj1722/main.cpp > CMakeFiles/boj1722.dir/main.cpp.i

CMakeFiles/boj1722.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boj1722.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ijaehyeon/Desktop/MyDocuments/gitblog/samsungsds_algorithm/number_theory/boj1722/main.cpp -o CMakeFiles/boj1722.dir/main.cpp.s

# Object files for target boj1722
boj1722_OBJECTS = \
"CMakeFiles/boj1722.dir/main.cpp.o"

# External object files for target boj1722
boj1722_EXTERNAL_OBJECTS =

boj1722: CMakeFiles/boj1722.dir/main.cpp.o
boj1722: CMakeFiles/boj1722.dir/build.make
boj1722: CMakeFiles/boj1722.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ijaehyeon/Desktop/MyDocuments/gitblog/samsungsds_algorithm/number_theory/boj1722/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable boj1722"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boj1722.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/boj1722.dir/build: boj1722

.PHONY : CMakeFiles/boj1722.dir/build

CMakeFiles/boj1722.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/boj1722.dir/cmake_clean.cmake
.PHONY : CMakeFiles/boj1722.dir/clean

CMakeFiles/boj1722.dir/depend:
	cd /Users/ijaehyeon/Desktop/MyDocuments/gitblog/samsungsds_algorithm/number_theory/boj1722/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ijaehyeon/Desktop/MyDocuments/gitblog/samsungsds_algorithm/number_theory/boj1722 /Users/ijaehyeon/Desktop/MyDocuments/gitblog/samsungsds_algorithm/number_theory/boj1722 /Users/ijaehyeon/Desktop/MyDocuments/gitblog/samsungsds_algorithm/number_theory/boj1722/cmake-build-debug /Users/ijaehyeon/Desktop/MyDocuments/gitblog/samsungsds_algorithm/number_theory/boj1722/cmake-build-debug /Users/ijaehyeon/Desktop/MyDocuments/gitblog/samsungsds_algorithm/number_theory/boj1722/cmake-build-debug/CMakeFiles/boj1722.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/boj1722.dir/depend

