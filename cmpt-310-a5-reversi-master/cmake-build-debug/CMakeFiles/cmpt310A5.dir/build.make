# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\bsing\Desktop\a5\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\bsing\Desktop\a5\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cmpt310A5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cmpt310A5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cmpt310A5.dir/flags.make

CMakeFiles/cmpt310A5.dir/main.cpp.obj: CMakeFiles/cmpt310A5.dir/flags.make
CMakeFiles/cmpt310A5.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\bsing\Desktop\a5\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cmpt310A5.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\cmpt310A5.dir\main.cpp.obj -c C:\Users\bsing\Desktop\a5\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\main.cpp

CMakeFiles/cmpt310A5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cmpt310A5.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\bsing\Desktop\a5\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\main.cpp > CMakeFiles\cmpt310A5.dir\main.cpp.i

CMakeFiles/cmpt310A5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cmpt310A5.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\bsing\Desktop\a5\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\main.cpp -o CMakeFiles\cmpt310A5.dir\main.cpp.s

# Object files for target cmpt310A5
cmpt310A5_OBJECTS = \
"CMakeFiles/cmpt310A5.dir/main.cpp.obj"

# External object files for target cmpt310A5
cmpt310A5_EXTERNAL_OBJECTS =

cmpt310A5.exe: CMakeFiles/cmpt310A5.dir/main.cpp.obj
cmpt310A5.exe: CMakeFiles/cmpt310A5.dir/build.make
cmpt310A5.exe: CMakeFiles/cmpt310A5.dir/linklibs.rsp
cmpt310A5.exe: CMakeFiles/cmpt310A5.dir/objects1.rsp
cmpt310A5.exe: CMakeFiles/cmpt310A5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\bsing\Desktop\a5\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cmpt310A5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cmpt310A5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cmpt310A5.dir/build: cmpt310A5.exe

.PHONY : CMakeFiles/cmpt310A5.dir/build

CMakeFiles/cmpt310A5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cmpt310A5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cmpt310A5.dir/clean

CMakeFiles/cmpt310A5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\bsing\Desktop\a5\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master C:\Users\bsing\Desktop\a5\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master C:\Users\bsing\Desktop\a5\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmake-build-debug C:\Users\bsing\Desktop\a5\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmake-build-debug C:\Users\bsing\Desktop\a5\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmpt-310-a5-reversi-master\cmake-build-debug\CMakeFiles\cmpt310A5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cmpt310A5.dir/depend

