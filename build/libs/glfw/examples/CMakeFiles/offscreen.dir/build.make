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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/george/Desktop/Programming/SudokuSolver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/george/Desktop/Programming/SudokuSolver/build

# Include any dependencies generated for this target.
include libs/glfw/examples/CMakeFiles/offscreen.dir/depend.make

# Include the progress variables for this target.
include libs/glfw/examples/CMakeFiles/offscreen.dir/progress.make

# Include the compile flags for this target's objects.
include libs/glfw/examples/CMakeFiles/offscreen.dir/flags.make

libs/glfw/examples/CMakeFiles/offscreen.dir/offscreen.c.o: libs/glfw/examples/CMakeFiles/offscreen.dir/flags.make
libs/glfw/examples/CMakeFiles/offscreen.dir/offscreen.c.o: ../libs/glfw/examples/offscreen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/george/Desktop/Programming/SudokuSolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/glfw/examples/CMakeFiles/offscreen.dir/offscreen.c.o"
	cd /Users/george/Desktop/Programming/SudokuSolver/build/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/offscreen.dir/offscreen.c.o -c /Users/george/Desktop/Programming/SudokuSolver/libs/glfw/examples/offscreen.c

libs/glfw/examples/CMakeFiles/offscreen.dir/offscreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/offscreen.dir/offscreen.c.i"
	cd /Users/george/Desktop/Programming/SudokuSolver/build/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/george/Desktop/Programming/SudokuSolver/libs/glfw/examples/offscreen.c > CMakeFiles/offscreen.dir/offscreen.c.i

libs/glfw/examples/CMakeFiles/offscreen.dir/offscreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/offscreen.dir/offscreen.c.s"
	cd /Users/george/Desktop/Programming/SudokuSolver/build/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/george/Desktop/Programming/SudokuSolver/libs/glfw/examples/offscreen.c -o CMakeFiles/offscreen.dir/offscreen.c.s

libs/glfw/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o: libs/glfw/examples/CMakeFiles/offscreen.dir/flags.make
libs/glfw/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o: ../libs/glfw/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/george/Desktop/Programming/SudokuSolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object libs/glfw/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o"
	cd /Users/george/Desktop/Programming/SudokuSolver/build/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o -c /Users/george/Desktop/Programming/SudokuSolver/libs/glfw/deps/glad_gl.c

libs/glfw/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i"
	cd /Users/george/Desktop/Programming/SudokuSolver/build/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/george/Desktop/Programming/SudokuSolver/libs/glfw/deps/glad_gl.c > CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i

libs/glfw/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s"
	cd /Users/george/Desktop/Programming/SudokuSolver/build/libs/glfw/examples && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/george/Desktop/Programming/SudokuSolver/libs/glfw/deps/glad_gl.c -o CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s

# Object files for target offscreen
offscreen_OBJECTS = \
"CMakeFiles/offscreen.dir/offscreen.c.o" \
"CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o"

# External object files for target offscreen
offscreen_EXTERNAL_OBJECTS =

libs/glfw/examples/offscreen: libs/glfw/examples/CMakeFiles/offscreen.dir/offscreen.c.o
libs/glfw/examples/offscreen: libs/glfw/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.o
libs/glfw/examples/offscreen: libs/glfw/examples/CMakeFiles/offscreen.dir/build.make
libs/glfw/examples/offscreen: libs/glfw/src/libglfw3.a
libs/glfw/examples/offscreen: libs/glfw/examples/CMakeFiles/offscreen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/george/Desktop/Programming/SudokuSolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable offscreen"
	cd /Users/george/Desktop/Programming/SudokuSolver/build/libs/glfw/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/offscreen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/glfw/examples/CMakeFiles/offscreen.dir/build: libs/glfw/examples/offscreen

.PHONY : libs/glfw/examples/CMakeFiles/offscreen.dir/build

libs/glfw/examples/CMakeFiles/offscreen.dir/clean:
	cd /Users/george/Desktop/Programming/SudokuSolver/build/libs/glfw/examples && $(CMAKE_COMMAND) -P CMakeFiles/offscreen.dir/cmake_clean.cmake
.PHONY : libs/glfw/examples/CMakeFiles/offscreen.dir/clean

libs/glfw/examples/CMakeFiles/offscreen.dir/depend:
	cd /Users/george/Desktop/Programming/SudokuSolver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/george/Desktop/Programming/SudokuSolver /Users/george/Desktop/Programming/SudokuSolver/libs/glfw/examples /Users/george/Desktop/Programming/SudokuSolver/build /Users/george/Desktop/Programming/SudokuSolver/build/libs/glfw/examples /Users/george/Desktop/Programming/SudokuSolver/build/libs/glfw/examples/CMakeFiles/offscreen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/glfw/examples/CMakeFiles/offscreen.dir/depend

