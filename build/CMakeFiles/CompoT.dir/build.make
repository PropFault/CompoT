# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Users\MoustacheSpy\Documents\MEGA\gamedev\CompoT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Users\MoustacheSpy\Documents\MEGA\gamedev\CompoT\build

# Include any dependencies generated for this target.
include CMakeFiles/CompoT.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CompoT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CompoT.dir/flags.make

CMakeFiles/CompoT.dir/CompoT.cpp.obj: CMakeFiles/CompoT.dir/flags.make
CMakeFiles/CompoT.dir/CompoT.cpp.obj: ../CompoT.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Users\MoustacheSpy\Documents\MEGA\gamedev\CompoT\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CompoT.dir/CompoT.cpp.obj"
	E:\Qt\Tools\mingw810_64\bin\x86_64-w64-mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CompoT.dir\CompoT.cpp.obj -c E:\Users\MoustacheSpy\Documents\MEGA\gamedev\CompoT\CompoT.cpp

CMakeFiles/CompoT.dir/CompoT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CompoT.dir/CompoT.cpp.i"
	E:\Qt\Tools\mingw810_64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Users\MoustacheSpy\Documents\MEGA\gamedev\CompoT\CompoT.cpp > CMakeFiles\CompoT.dir\CompoT.cpp.i

CMakeFiles/CompoT.dir/CompoT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CompoT.dir/CompoT.cpp.s"
	E:\Qt\Tools\mingw810_64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Users\MoustacheSpy\Documents\MEGA\gamedev\CompoT\CompoT.cpp -o CMakeFiles\CompoT.dir\CompoT.cpp.s

# Object files for target CompoT
CompoT_OBJECTS = \
"CMakeFiles/CompoT.dir/CompoT.cpp.obj"

# External object files for target CompoT
CompoT_EXTERNAL_OBJECTS =

bin/CompoT.exe: CMakeFiles/CompoT.dir/CompoT.cpp.obj
bin/CompoT.exe: CMakeFiles/CompoT.dir/build.make
bin/CompoT.exe: CMakeFiles/CompoT.dir/linklibs.rsp
bin/CompoT.exe: CMakeFiles/CompoT.dir/objects1.rsp
bin/CompoT.exe: CMakeFiles/CompoT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Users\MoustacheSpy\Documents\MEGA\gamedev\CompoT\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin\CompoT.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CompoT.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CompoT.dir/build: bin/CompoT.exe

.PHONY : CMakeFiles/CompoT.dir/build

CMakeFiles/CompoT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CompoT.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CompoT.dir/clean

CMakeFiles/CompoT.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Users\MoustacheSpy\Documents\MEGA\gamedev\CompoT E:\Users\MoustacheSpy\Documents\MEGA\gamedev\CompoT E:\Users\MoustacheSpy\Documents\MEGA\gamedev\CompoT\build E:\Users\MoustacheSpy\Documents\MEGA\gamedev\CompoT\build E:\Users\MoustacheSpy\Documents\MEGA\gamedev\CompoT\build\CMakeFiles\CompoT.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CompoT.dir/depend

