# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/114/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/114/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lorenzo/CLionProjects/Alienator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lorenzo/CLionProjects/Alienator/cmake-build-release

# Include any dependencies generated for this target.
include test/lib/googletest/googlemock/CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include test/lib/googletest/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include test/lib/googletest/googlemock/CMakeFiles/gmock.dir/flags.make

test/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: test/lib/googletest/googlemock/CMakeFiles/gmock.dir/flags.make
test/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: ../test/lib/googletest/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lorenzo/CLionProjects/Alienator/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	cd /home/lorenzo/CLionProjects/Alienator/cmake-build-release/test/lib/googletest/googlemock && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c /home/lorenzo/CLionProjects/Alienator/test/lib/googletest/googlemock/src/gmock-all.cc

test/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /home/lorenzo/CLionProjects/Alienator/cmake-build-release/test/lib/googletest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lorenzo/CLionProjects/Alienator/test/lib/googletest/googlemock/src/gmock-all.cc > CMakeFiles/gmock.dir/src/gmock-all.cc.i

test/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /home/lorenzo/CLionProjects/Alienator/cmake-build-release/test/lib/googletest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lorenzo/CLionProjects/Alienator/test/lib/googletest/googlemock/src/gmock-all.cc -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

lib/libgmock.a: test/lib/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
lib/libgmock.a: test/lib/googletest/googlemock/CMakeFiles/gmock.dir/build.make
lib/libgmock.a: test/lib/googletest/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lorenzo/CLionProjects/Alienator/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../../lib/libgmock.a"
	cd /home/lorenzo/CLionProjects/Alienator/cmake-build-release/test/lib/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean_target.cmake
	cd /home/lorenzo/CLionProjects/Alienator/cmake-build-release/test/lib/googletest/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/lib/googletest/googlemock/CMakeFiles/gmock.dir/build: lib/libgmock.a

.PHONY : test/lib/googletest/googlemock/CMakeFiles/gmock.dir/build

test/lib/googletest/googlemock/CMakeFiles/gmock.dir/clean:
	cd /home/lorenzo/CLionProjects/Alienator/cmake-build-release/test/lib/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : test/lib/googletest/googlemock/CMakeFiles/gmock.dir/clean

test/lib/googletest/googlemock/CMakeFiles/gmock.dir/depend:
	cd /home/lorenzo/CLionProjects/Alienator/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lorenzo/CLionProjects/Alienator /home/lorenzo/CLionProjects/Alienator/test/lib/googletest/googlemock /home/lorenzo/CLionProjects/Alienator/cmake-build-release /home/lorenzo/CLionProjects/Alienator/cmake-build-release/test/lib/googletest/googlemock /home/lorenzo/CLionProjects/Alienator/cmake-build-release/test/lib/googletest/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/lib/googletest/googlemock/CMakeFiles/gmock.dir/depend

