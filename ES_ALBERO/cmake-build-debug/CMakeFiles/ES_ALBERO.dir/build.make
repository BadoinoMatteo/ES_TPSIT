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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Matteo\Documents\SCUOLA\QUARTA\TPSIT\ES_ALBERO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Matteo\Documents\SCUOLA\QUARTA\TPSIT\ES_ALBERO\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ES_ALBERO.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ES_ALBERO.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ES_ALBERO.dir/flags.make

CMakeFiles/ES_ALBERO.dir/main.c.obj: CMakeFiles/ES_ALBERO.dir/flags.make
CMakeFiles/ES_ALBERO.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Matteo\Documents\SCUOLA\QUARTA\TPSIT\ES_ALBERO\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ES_ALBERO.dir/main.c.obj"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ES_ALBERO.dir\main.c.obj   -c C:\Users\Matteo\Documents\SCUOLA\QUARTA\TPSIT\ES_ALBERO\main.c

CMakeFiles/ES_ALBERO.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ES_ALBERO.dir/main.c.i"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Matteo\Documents\SCUOLA\QUARTA\TPSIT\ES_ALBERO\main.c > CMakeFiles\ES_ALBERO.dir\main.c.i

CMakeFiles/ES_ALBERO.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ES_ALBERO.dir/main.c.s"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Matteo\Documents\SCUOLA\QUARTA\TPSIT\ES_ALBERO\main.c -o CMakeFiles\ES_ALBERO.dir\main.c.s

# Object files for target ES_ALBERO
ES_ALBERO_OBJECTS = \
"CMakeFiles/ES_ALBERO.dir/main.c.obj"

# External object files for target ES_ALBERO
ES_ALBERO_EXTERNAL_OBJECTS =

ES_ALBERO.exe: CMakeFiles/ES_ALBERO.dir/main.c.obj
ES_ALBERO.exe: CMakeFiles/ES_ALBERO.dir/build.make
ES_ALBERO.exe: CMakeFiles/ES_ALBERO.dir/linklibs.rsp
ES_ALBERO.exe: CMakeFiles/ES_ALBERO.dir/objects1.rsp
ES_ALBERO.exe: CMakeFiles/ES_ALBERO.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Matteo\Documents\SCUOLA\QUARTA\TPSIT\ES_ALBERO\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ES_ALBERO.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ES_ALBERO.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ES_ALBERO.dir/build: ES_ALBERO.exe

.PHONY : CMakeFiles/ES_ALBERO.dir/build

CMakeFiles/ES_ALBERO.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ES_ALBERO.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ES_ALBERO.dir/clean

CMakeFiles/ES_ALBERO.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Matteo\Documents\SCUOLA\QUARTA\TPSIT\ES_ALBERO C:\Users\Matteo\Documents\SCUOLA\QUARTA\TPSIT\ES_ALBERO C:\Users\Matteo\Documents\SCUOLA\QUARTA\TPSIT\ES_ALBERO\cmake-build-debug C:\Users\Matteo\Documents\SCUOLA\QUARTA\TPSIT\ES_ALBERO\cmake-build-debug C:\Users\Matteo\Documents\SCUOLA\QUARTA\TPSIT\ES_ALBERO\cmake-build-debug\CMakeFiles\ES_ALBERO.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ES_ALBERO.dir/depend

