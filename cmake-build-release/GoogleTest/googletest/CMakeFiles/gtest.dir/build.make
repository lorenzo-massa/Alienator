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
CMAKE_COMMAND = "D:\Programmi\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programmi\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator\cmake-build-release"

# Include any dependencies generated for this target.
include GoogleTest/googletest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include GoogleTest/googletest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include GoogleTest/googletest/CMakeFiles/gtest.dir/flags.make

GoogleTest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: GoogleTest/googletest/CMakeFiles/gtest.dir/flags.make
GoogleTest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: GoogleTest/googletest/CMakeFiles/gtest.dir/includes_CXX.rsp
GoogleTest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj: ../GoogleTest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator\cmake-build-release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object GoogleTest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj"
	cd /d "D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator\cmake-build-release\GoogleTest\googletest" && D:\Programmi\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\gtest.dir\src\gtest-all.cc.obj -c "D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator\GoogleTest\googletest\src\gtest-all.cc"

GoogleTest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /d "D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator\cmake-build-release\GoogleTest\googletest" && D:\Programmi\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator\GoogleTest\googletest\src\gtest-all.cc" > CMakeFiles\gtest.dir\src\gtest-all.cc.i

GoogleTest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /d "D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator\cmake-build-release\GoogleTest\googletest" && D:\Programmi\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator\GoogleTest\googletest\src\gtest-all.cc" -o CMakeFiles\gtest.dir\src\gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.obj"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtest.a: GoogleTest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.obj
lib/libgtest.a: GoogleTest/googletest/CMakeFiles/gtest.dir/build.make
lib/libgtest.a: GoogleTest/googletest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator\cmake-build-release\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ..\..\lib\libgtest.a"
	cd /d "D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator\cmake-build-release\GoogleTest\googletest" && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean_target.cmake
	cd /d "D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator\cmake-build-release\GoogleTest\googletest" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gtest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
GoogleTest/googletest/CMakeFiles/gtest.dir/build: lib/libgtest.a

.PHONY : GoogleTest/googletest/CMakeFiles/gtest.dir/build

GoogleTest/googletest/CMakeFiles/gtest.dir/clean:
	cd /d "D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator\cmake-build-release\GoogleTest\googletest" && $(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean.cmake
.PHONY : GoogleTest/googletest/CMakeFiles/gtest.dir/clean

GoogleTest/googletest/CMakeFiles/gtest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator" "D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator\GoogleTest\googletest" "D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator\cmake-build-release" "D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator\cmake-build-release\GoogleTest\googletest" "D:\Documenti\UniFi\2019-20 2 semestre\Programmazione\Alienator\cmake-build-release\GoogleTest\googletest\CMakeFiles\gtest.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : GoogleTest/googletest/CMakeFiles/gtest.dir/depend

