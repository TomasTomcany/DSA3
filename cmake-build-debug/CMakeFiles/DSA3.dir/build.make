# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\tomca\CLionProjects\DSA3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\tomca\CLionProjects\DSA3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DSA3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DSA3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DSA3.dir/flags.make

CMakeFiles/DSA3.dir/main.c.obj: CMakeFiles/DSA3.dir/flags.make
CMakeFiles/DSA3.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\tomca\CLionProjects\DSA3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DSA3.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\DSA3.dir\main.c.obj -c C:\Users\tomca\CLionProjects\DSA3\main.c

CMakeFiles/DSA3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DSA3.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\tomca\CLionProjects\DSA3\main.c > CMakeFiles\DSA3.dir\main.c.i

CMakeFiles/DSA3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DSA3.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\tomca\CLionProjects\DSA3\main.c -o CMakeFiles\DSA3.dir\main.c.s

CMakeFiles/DSA3.dir/BDD_script.c.obj: CMakeFiles/DSA3.dir/flags.make
CMakeFiles/DSA3.dir/BDD_script.c.obj: ../BDD_script.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\tomca\CLionProjects\DSA3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/DSA3.dir/BDD_script.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\DSA3.dir\BDD_script.c.obj -c C:\Users\tomca\CLionProjects\DSA3\BDD_script.c

CMakeFiles/DSA3.dir/BDD_script.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/DSA3.dir/BDD_script.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\tomca\CLionProjects\DSA3\BDD_script.c > CMakeFiles\DSA3.dir\BDD_script.c.i

CMakeFiles/DSA3.dir/BDD_script.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/DSA3.dir/BDD_script.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\tomca\CLionProjects\DSA3\BDD_script.c -o CMakeFiles\DSA3.dir\BDD_script.c.s

# Object files for target DSA3
DSA3_OBJECTS = \
"CMakeFiles/DSA3.dir/main.c.obj" \
"CMakeFiles/DSA3.dir/BDD_script.c.obj"

# External object files for target DSA3
DSA3_EXTERNAL_OBJECTS =

DSA3.exe: CMakeFiles/DSA3.dir/main.c.obj
DSA3.exe: CMakeFiles/DSA3.dir/BDD_script.c.obj
DSA3.exe: CMakeFiles/DSA3.dir/build.make
DSA3.exe: CMakeFiles/DSA3.dir/linklibs.rsp
DSA3.exe: CMakeFiles/DSA3.dir/objects1.rsp
DSA3.exe: CMakeFiles/DSA3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\tomca\CLionProjects\DSA3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable DSA3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DSA3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DSA3.dir/build: DSA3.exe

.PHONY : CMakeFiles/DSA3.dir/build

CMakeFiles/DSA3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DSA3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DSA3.dir/clean

CMakeFiles/DSA3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\tomca\CLionProjects\DSA3 C:\Users\tomca\CLionProjects\DSA3 C:\Users\tomca\CLionProjects\DSA3\cmake-build-debug C:\Users\tomca\CLionProjects\DSA3\cmake-build-debug C:\Users\tomca\CLionProjects\DSA3\cmake-build-debug\CMakeFiles\DSA3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DSA3.dir/depend

