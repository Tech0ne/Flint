# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/clementp/Documents/CppLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/clementp/Documents/CppLib/build

# Include any dependencies generated for this target.
include CMakeFiles/flint.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/flint.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/flint.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/flint.dir/flags.make

CMakeFiles/flint.dir/src/Colors.cpp.o: CMakeFiles/flint.dir/flags.make
CMakeFiles/flint.dir/src/Colors.cpp.o: ../src/Colors.cpp
CMakeFiles/flint.dir/src/Colors.cpp.o: CMakeFiles/flint.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clementp/Documents/CppLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/flint.dir/src/Colors.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/flint.dir/src/Colors.cpp.o -MF CMakeFiles/flint.dir/src/Colors.cpp.o.d -o CMakeFiles/flint.dir/src/Colors.cpp.o -c /home/clementp/Documents/CppLib/src/Colors.cpp

CMakeFiles/flint.dir/src/Colors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flint.dir/src/Colors.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clementp/Documents/CppLib/src/Colors.cpp > CMakeFiles/flint.dir/src/Colors.cpp.i

CMakeFiles/flint.dir/src/Colors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flint.dir/src/Colors.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clementp/Documents/CppLib/src/Colors.cpp -o CMakeFiles/flint.dir/src/Colors.cpp.s

CMakeFiles/flint.dir/src/CxxABI.cpp.o: CMakeFiles/flint.dir/flags.make
CMakeFiles/flint.dir/src/CxxABI.cpp.o: ../src/CxxABI.cpp
CMakeFiles/flint.dir/src/CxxABI.cpp.o: CMakeFiles/flint.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clementp/Documents/CppLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/flint.dir/src/CxxABI.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/flint.dir/src/CxxABI.cpp.o -MF CMakeFiles/flint.dir/src/CxxABI.cpp.o.d -o CMakeFiles/flint.dir/src/CxxABI.cpp.o -c /home/clementp/Documents/CppLib/src/CxxABI.cpp

CMakeFiles/flint.dir/src/CxxABI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flint.dir/src/CxxABI.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clementp/Documents/CppLib/src/CxxABI.cpp > CMakeFiles/flint.dir/src/CxxABI.cpp.i

CMakeFiles/flint.dir/src/CxxABI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flint.dir/src/CxxABI.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clementp/Documents/CppLib/src/CxxABI.cpp -o CMakeFiles/flint.dir/src/CxxABI.cpp.s

CMakeFiles/flint.dir/src/Exceptions.cpp.o: CMakeFiles/flint.dir/flags.make
CMakeFiles/flint.dir/src/Exceptions.cpp.o: ../src/Exceptions.cpp
CMakeFiles/flint.dir/src/Exceptions.cpp.o: CMakeFiles/flint.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clementp/Documents/CppLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/flint.dir/src/Exceptions.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/flint.dir/src/Exceptions.cpp.o -MF CMakeFiles/flint.dir/src/Exceptions.cpp.o.d -o CMakeFiles/flint.dir/src/Exceptions.cpp.o -c /home/clementp/Documents/CppLib/src/Exceptions.cpp

CMakeFiles/flint.dir/src/Exceptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flint.dir/src/Exceptions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clementp/Documents/CppLib/src/Exceptions.cpp > CMakeFiles/flint.dir/src/Exceptions.cpp.i

CMakeFiles/flint.dir/src/Exceptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flint.dir/src/Exceptions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clementp/Documents/CppLib/src/Exceptions.cpp -o CMakeFiles/flint.dir/src/Exceptions.cpp.s

CMakeFiles/flint.dir/src/main.cpp.o: CMakeFiles/flint.dir/flags.make
CMakeFiles/flint.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/flint.dir/src/main.cpp.o: CMakeFiles/flint.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clementp/Documents/CppLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/flint.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/flint.dir/src/main.cpp.o -MF CMakeFiles/flint.dir/src/main.cpp.o.d -o CMakeFiles/flint.dir/src/main.cpp.o -c /home/clementp/Documents/CppLib/src/main.cpp

CMakeFiles/flint.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flint.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clementp/Documents/CppLib/src/main.cpp > CMakeFiles/flint.dir/src/main.cpp.i

CMakeFiles/flint.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flint.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clementp/Documents/CppLib/src/main.cpp -o CMakeFiles/flint.dir/src/main.cpp.s

# Object files for target flint
flint_OBJECTS = \
"CMakeFiles/flint.dir/src/Colors.cpp.o" \
"CMakeFiles/flint.dir/src/CxxABI.cpp.o" \
"CMakeFiles/flint.dir/src/Exceptions.cpp.o" \
"CMakeFiles/flint.dir/src/main.cpp.o"

# External object files for target flint
flint_EXTERNAL_OBJECTS =

flint: CMakeFiles/flint.dir/src/Colors.cpp.o
flint: CMakeFiles/flint.dir/src/CxxABI.cpp.o
flint: CMakeFiles/flint.dir/src/Exceptions.cpp.o
flint: CMakeFiles/flint.dir/src/main.cpp.o
flint: CMakeFiles/flint.dir/build.make
flint: CMakeFiles/flint.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/clementp/Documents/CppLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable flint"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/flint.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/flint.dir/build: flint
.PHONY : CMakeFiles/flint.dir/build

CMakeFiles/flint.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/flint.dir/cmake_clean.cmake
.PHONY : CMakeFiles/flint.dir/clean

CMakeFiles/flint.dir/depend:
	cd /home/clementp/Documents/CppLib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/clementp/Documents/CppLib /home/clementp/Documents/CppLib /home/clementp/Documents/CppLib/build /home/clementp/Documents/CppLib/build /home/clementp/Documents/CppLib/build/CMakeFiles/flint.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/flint.dir/depend

