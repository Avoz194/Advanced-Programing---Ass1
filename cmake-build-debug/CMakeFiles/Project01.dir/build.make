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
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rs/Desktop/Assignments

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rs/Desktop/Assignments/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Project01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project01.dir/flags.make

CMakeFiles/Project01.dir/src/main.cpp.o: CMakeFiles/Project01.dir/flags.make
CMakeFiles/Project01.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rs/Desktop/Assignments/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project01.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project01.dir/src/main.cpp.o -c /home/rs/Desktop/Assignments/src/main.cpp

CMakeFiles/Project01.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project01.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rs/Desktop/Assignments/src/main.cpp > CMakeFiles/Project01.dir/src/main.cpp.i

CMakeFiles/Project01.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project01.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rs/Desktop/Assignments/src/main.cpp -o CMakeFiles/Project01.dir/src/main.cpp.s

CMakeFiles/Project01.dir/src/Session.cpp.o: CMakeFiles/Project01.dir/flags.make
CMakeFiles/Project01.dir/src/Session.cpp.o: ../src/Session.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rs/Desktop/Assignments/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project01.dir/src/Session.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project01.dir/src/Session.cpp.o -c /home/rs/Desktop/Assignments/src/Session.cpp

CMakeFiles/Project01.dir/src/Session.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project01.dir/src/Session.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rs/Desktop/Assignments/src/Session.cpp > CMakeFiles/Project01.dir/src/Session.cpp.i

CMakeFiles/Project01.dir/src/Session.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project01.dir/src/Session.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rs/Desktop/Assignments/src/Session.cpp -o CMakeFiles/Project01.dir/src/Session.cpp.s

CMakeFiles/Project01.dir/src/Agent.cpp.o: CMakeFiles/Project01.dir/flags.make
CMakeFiles/Project01.dir/src/Agent.cpp.o: ../src/Agent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rs/Desktop/Assignments/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Project01.dir/src/Agent.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project01.dir/src/Agent.cpp.o -c /home/rs/Desktop/Assignments/src/Agent.cpp

CMakeFiles/Project01.dir/src/Agent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project01.dir/src/Agent.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rs/Desktop/Assignments/src/Agent.cpp > CMakeFiles/Project01.dir/src/Agent.cpp.i

CMakeFiles/Project01.dir/src/Agent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project01.dir/src/Agent.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rs/Desktop/Assignments/src/Agent.cpp -o CMakeFiles/Project01.dir/src/Agent.cpp.s

CMakeFiles/Project01.dir/src/Graph.cpp.o: CMakeFiles/Project01.dir/flags.make
CMakeFiles/Project01.dir/src/Graph.cpp.o: ../src/Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rs/Desktop/Assignments/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Project01.dir/src/Graph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project01.dir/src/Graph.cpp.o -c /home/rs/Desktop/Assignments/src/Graph.cpp

CMakeFiles/Project01.dir/src/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project01.dir/src/Graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rs/Desktop/Assignments/src/Graph.cpp > CMakeFiles/Project01.dir/src/Graph.cpp.i

CMakeFiles/Project01.dir/src/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project01.dir/src/Graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rs/Desktop/Assignments/src/Graph.cpp -o CMakeFiles/Project01.dir/src/Graph.cpp.s

CMakeFiles/Project01.dir/src/Tree.cpp.o: CMakeFiles/Project01.dir/flags.make
CMakeFiles/Project01.dir/src/Tree.cpp.o: ../src/Tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rs/Desktop/Assignments/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Project01.dir/src/Tree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Project01.dir/src/Tree.cpp.o -c /home/rs/Desktop/Assignments/src/Tree.cpp

CMakeFiles/Project01.dir/src/Tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project01.dir/src/Tree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rs/Desktop/Assignments/src/Tree.cpp > CMakeFiles/Project01.dir/src/Tree.cpp.i

CMakeFiles/Project01.dir/src/Tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project01.dir/src/Tree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rs/Desktop/Assignments/src/Tree.cpp -o CMakeFiles/Project01.dir/src/Tree.cpp.s

# Object files for target Project01
Project01_OBJECTS = \
"CMakeFiles/Project01.dir/src/main.cpp.o" \
"CMakeFiles/Project01.dir/src/Session.cpp.o" \
"CMakeFiles/Project01.dir/src/Agent.cpp.o" \
"CMakeFiles/Project01.dir/src/Graph.cpp.o" \
"CMakeFiles/Project01.dir/src/Tree.cpp.o"

# External object files for target Project01
Project01_EXTERNAL_OBJECTS =

Project01: CMakeFiles/Project01.dir/src/main.cpp.o
Project01: CMakeFiles/Project01.dir/src/Session.cpp.o
Project01: CMakeFiles/Project01.dir/src/Agent.cpp.o
Project01: CMakeFiles/Project01.dir/src/Graph.cpp.o
Project01: CMakeFiles/Project01.dir/src/Tree.cpp.o
Project01: CMakeFiles/Project01.dir/build.make
Project01: CMakeFiles/Project01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rs/Desktop/Assignments/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Project01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project01.dir/build: Project01

.PHONY : CMakeFiles/Project01.dir/build

CMakeFiles/Project01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project01.dir/clean

CMakeFiles/Project01.dir/depend:
	cd /home/rs/Desktop/Assignments/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rs/Desktop/Assignments /home/rs/Desktop/Assignments /home/rs/Desktop/Assignments/cmake-build-debug /home/rs/Desktop/Assignments/cmake-build-debug /home/rs/Desktop/Assignments/cmake-build-debug/CMakeFiles/Project01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project01.dir/depend

