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
CMAKE_COMMAND = /home/sebastian/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.5981.166/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/sebastian/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.5981.166/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sebastian/Programmierung/algorithms_and_data_structures

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sebastian/Programmierung/algorithms_and_data_structures/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/i2a.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/i2a.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/i2a.dir/flags.make

src/CMakeFiles/i2a.dir/main.cpp.o: src/CMakeFiles/i2a.dir/flags.make
src/CMakeFiles/i2a.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sebastian/Programmierung/algorithms_and_data_structures/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/i2a.dir/main.cpp.o"
	cd /home/sebastian/Programmierung/algorithms_and_data_structures/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/i2a.dir/main.cpp.o -c /home/sebastian/Programmierung/algorithms_and_data_structures/src/main.cpp

src/CMakeFiles/i2a.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/i2a.dir/main.cpp.i"
	cd /home/sebastian/Programmierung/algorithms_and_data_structures/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sebastian/Programmierung/algorithms_and_data_structures/src/main.cpp > CMakeFiles/i2a.dir/main.cpp.i

src/CMakeFiles/i2a.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/i2a.dir/main.cpp.s"
	cd /home/sebastian/Programmierung/algorithms_and_data_structures/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sebastian/Programmierung/algorithms_and_data_structures/src/main.cpp -o CMakeFiles/i2a.dir/main.cpp.s

# Object files for target i2a
i2a_OBJECTS = \
"CMakeFiles/i2a.dir/main.cpp.o"

# External object files for target i2a
i2a_EXTERNAL_OBJECTS =

src/i2a: src/CMakeFiles/i2a.dir/main.cpp.o
src/i2a: src/CMakeFiles/i2a.dir/build.make
src/i2a: src/CMakeFiles/i2a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sebastian/Programmierung/algorithms_and_data_structures/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable i2a"
	cd /home/sebastian/Programmierung/algorithms_and_data_structures/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/i2a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/i2a.dir/build: src/i2a

.PHONY : src/CMakeFiles/i2a.dir/build

src/CMakeFiles/i2a.dir/clean:
	cd /home/sebastian/Programmierung/algorithms_and_data_structures/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/i2a.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/i2a.dir/clean

src/CMakeFiles/i2a.dir/depend:
	cd /home/sebastian/Programmierung/algorithms_and_data_structures/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sebastian/Programmierung/algorithms_and_data_structures /home/sebastian/Programmierung/algorithms_and_data_structures/src /home/sebastian/Programmierung/algorithms_and_data_structures/cmake-build-debug /home/sebastian/Programmierung/algorithms_and_data_structures/cmake-build-debug/src /home/sebastian/Programmierung/algorithms_and_data_structures/cmake-build-debug/src/CMakeFiles/i2a.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/i2a.dir/depend
