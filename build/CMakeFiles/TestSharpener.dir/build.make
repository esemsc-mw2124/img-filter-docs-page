# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build

# Include any dependencies generated for this target.
include CMakeFiles/TestSharpener.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TestSharpener.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TestSharpener.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestSharpener.dir/flags.make

CMakeFiles/TestSharpener.dir/codegen:
.PHONY : CMakeFiles/TestSharpener.dir/codegen

CMakeFiles/TestSharpener.dir/tests/2D/TestSharpener.cpp.o: CMakeFiles/TestSharpener.dir/flags.make
CMakeFiles/TestSharpener.dir/tests/2D/TestSharpener.cpp.o: /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/tests/2D/TestSharpener.cpp
CMakeFiles/TestSharpener.dir/tests/2D/TestSharpener.cpp.o: CMakeFiles/TestSharpener.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestSharpener.dir/tests/2D/TestSharpener.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSharpener.dir/tests/2D/TestSharpener.cpp.o -MF CMakeFiles/TestSharpener.dir/tests/2D/TestSharpener.cpp.o.d -o CMakeFiles/TestSharpener.dir/tests/2D/TestSharpener.cpp.o -c /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/tests/2D/TestSharpener.cpp

CMakeFiles/TestSharpener.dir/tests/2D/TestSharpener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestSharpener.dir/tests/2D/TestSharpener.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/tests/2D/TestSharpener.cpp > CMakeFiles/TestSharpener.dir/tests/2D/TestSharpener.cpp.i

CMakeFiles/TestSharpener.dir/tests/2D/TestSharpener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestSharpener.dir/tests/2D/TestSharpener.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/tests/2D/TestSharpener.cpp -o CMakeFiles/TestSharpener.dir/tests/2D/TestSharpener.cpp.s

CMakeFiles/TestSharpener.dir/src/2D/Blur.cpp.o: CMakeFiles/TestSharpener.dir/flags.make
CMakeFiles/TestSharpener.dir/src/2D/Blur.cpp.o: /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/2D/Blur.cpp
CMakeFiles/TestSharpener.dir/src/2D/Blur.cpp.o: CMakeFiles/TestSharpener.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TestSharpener.dir/src/2D/Blur.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSharpener.dir/src/2D/Blur.cpp.o -MF CMakeFiles/TestSharpener.dir/src/2D/Blur.cpp.o.d -o CMakeFiles/TestSharpener.dir/src/2D/Blur.cpp.o -c /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/2D/Blur.cpp

CMakeFiles/TestSharpener.dir/src/2D/Blur.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestSharpener.dir/src/2D/Blur.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/2D/Blur.cpp > CMakeFiles/TestSharpener.dir/src/2D/Blur.cpp.i

CMakeFiles/TestSharpener.dir/src/2D/Blur.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestSharpener.dir/src/2D/Blur.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/2D/Blur.cpp -o CMakeFiles/TestSharpener.dir/src/2D/Blur.cpp.s

CMakeFiles/TestSharpener.dir/src/2D/EdgeDetector.cpp.o: CMakeFiles/TestSharpener.dir/flags.make
CMakeFiles/TestSharpener.dir/src/2D/EdgeDetector.cpp.o: /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/2D/EdgeDetector.cpp
CMakeFiles/TestSharpener.dir/src/2D/EdgeDetector.cpp.o: CMakeFiles/TestSharpener.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TestSharpener.dir/src/2D/EdgeDetector.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSharpener.dir/src/2D/EdgeDetector.cpp.o -MF CMakeFiles/TestSharpener.dir/src/2D/EdgeDetector.cpp.o.d -o CMakeFiles/TestSharpener.dir/src/2D/EdgeDetector.cpp.o -c /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/2D/EdgeDetector.cpp

CMakeFiles/TestSharpener.dir/src/2D/EdgeDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestSharpener.dir/src/2D/EdgeDetector.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/2D/EdgeDetector.cpp > CMakeFiles/TestSharpener.dir/src/2D/EdgeDetector.cpp.i

CMakeFiles/TestSharpener.dir/src/2D/EdgeDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestSharpener.dir/src/2D/EdgeDetector.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/2D/EdgeDetector.cpp -o CMakeFiles/TestSharpener.dir/src/2D/EdgeDetector.cpp.s

CMakeFiles/TestSharpener.dir/src/2D/Sharpener.cpp.o: CMakeFiles/TestSharpener.dir/flags.make
CMakeFiles/TestSharpener.dir/src/2D/Sharpener.cpp.o: /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/2D/Sharpener.cpp
CMakeFiles/TestSharpener.dir/src/2D/Sharpener.cpp.o: CMakeFiles/TestSharpener.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TestSharpener.dir/src/2D/Sharpener.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSharpener.dir/src/2D/Sharpener.cpp.o -MF CMakeFiles/TestSharpener.dir/src/2D/Sharpener.cpp.o.d -o CMakeFiles/TestSharpener.dir/src/2D/Sharpener.cpp.o -c /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/2D/Sharpener.cpp

CMakeFiles/TestSharpener.dir/src/2D/Sharpener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestSharpener.dir/src/2D/Sharpener.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/2D/Sharpener.cpp > CMakeFiles/TestSharpener.dir/src/2D/Sharpener.cpp.i

CMakeFiles/TestSharpener.dir/src/2D/Sharpener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestSharpener.dir/src/2D/Sharpener.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/2D/Sharpener.cpp -o CMakeFiles/TestSharpener.dir/src/2D/Sharpener.cpp.s

CMakeFiles/TestSharpener.dir/src/2D/SimpleFilter.cpp.o: CMakeFiles/TestSharpener.dir/flags.make
CMakeFiles/TestSharpener.dir/src/2D/SimpleFilter.cpp.o: /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/2D/SimpleFilter.cpp
CMakeFiles/TestSharpener.dir/src/2D/SimpleFilter.cpp.o: CMakeFiles/TestSharpener.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TestSharpener.dir/src/2D/SimpleFilter.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSharpener.dir/src/2D/SimpleFilter.cpp.o -MF CMakeFiles/TestSharpener.dir/src/2D/SimpleFilter.cpp.o.d -o CMakeFiles/TestSharpener.dir/src/2D/SimpleFilter.cpp.o -c /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/2D/SimpleFilter.cpp

CMakeFiles/TestSharpener.dir/src/2D/SimpleFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestSharpener.dir/src/2D/SimpleFilter.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/2D/SimpleFilter.cpp > CMakeFiles/TestSharpener.dir/src/2D/SimpleFilter.cpp.i

CMakeFiles/TestSharpener.dir/src/2D/SimpleFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestSharpener.dir/src/2D/SimpleFilter.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/2D/SimpleFilter.cpp -o CMakeFiles/TestSharpener.dir/src/2D/SimpleFilter.cpp.s

CMakeFiles/TestSharpener.dir/src/3D/BlurFilter3D.cpp.o: CMakeFiles/TestSharpener.dir/flags.make
CMakeFiles/TestSharpener.dir/src/3D/BlurFilter3D.cpp.o: /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/3D/BlurFilter3D.cpp
CMakeFiles/TestSharpener.dir/src/3D/BlurFilter3D.cpp.o: CMakeFiles/TestSharpener.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TestSharpener.dir/src/3D/BlurFilter3D.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSharpener.dir/src/3D/BlurFilter3D.cpp.o -MF CMakeFiles/TestSharpener.dir/src/3D/BlurFilter3D.cpp.o.d -o CMakeFiles/TestSharpener.dir/src/3D/BlurFilter3D.cpp.o -c /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/3D/BlurFilter3D.cpp

CMakeFiles/TestSharpener.dir/src/3D/BlurFilter3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestSharpener.dir/src/3D/BlurFilter3D.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/3D/BlurFilter3D.cpp > CMakeFiles/TestSharpener.dir/src/3D/BlurFilter3D.cpp.i

CMakeFiles/TestSharpener.dir/src/3D/BlurFilter3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestSharpener.dir/src/3D/BlurFilter3D.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/3D/BlurFilter3D.cpp -o CMakeFiles/TestSharpener.dir/src/3D/BlurFilter3D.cpp.s

CMakeFiles/TestSharpener.dir/src/Image.cpp.o: CMakeFiles/TestSharpener.dir/flags.make
CMakeFiles/TestSharpener.dir/src/Image.cpp.o: /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/Image.cpp
CMakeFiles/TestSharpener.dir/src/Image.cpp.o: CMakeFiles/TestSharpener.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/TestSharpener.dir/src/Image.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSharpener.dir/src/Image.cpp.o -MF CMakeFiles/TestSharpener.dir/src/Image.cpp.o.d -o CMakeFiles/TestSharpener.dir/src/Image.cpp.o -c /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/Image.cpp

CMakeFiles/TestSharpener.dir/src/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestSharpener.dir/src/Image.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/Image.cpp > CMakeFiles/TestSharpener.dir/src/Image.cpp.i

CMakeFiles/TestSharpener.dir/src/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestSharpener.dir/src/Image.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/Image.cpp -o CMakeFiles/TestSharpener.dir/src/Image.cpp.s

CMakeFiles/TestSharpener.dir/src/Projection.cpp.o: CMakeFiles/TestSharpener.dir/flags.make
CMakeFiles/TestSharpener.dir/src/Projection.cpp.o: /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/Projection.cpp
CMakeFiles/TestSharpener.dir/src/Projection.cpp.o: CMakeFiles/TestSharpener.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/TestSharpener.dir/src/Projection.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSharpener.dir/src/Projection.cpp.o -MF CMakeFiles/TestSharpener.dir/src/Projection.cpp.o.d -o CMakeFiles/TestSharpener.dir/src/Projection.cpp.o -c /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/Projection.cpp

CMakeFiles/TestSharpener.dir/src/Projection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestSharpener.dir/src/Projection.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/Projection.cpp > CMakeFiles/TestSharpener.dir/src/Projection.cpp.i

CMakeFiles/TestSharpener.dir/src/Projection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestSharpener.dir/src/Projection.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/Projection.cpp -o CMakeFiles/TestSharpener.dir/src/Projection.cpp.s

CMakeFiles/TestSharpener.dir/src/Slice.cpp.o: CMakeFiles/TestSharpener.dir/flags.make
CMakeFiles/TestSharpener.dir/src/Slice.cpp.o: /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/Slice.cpp
CMakeFiles/TestSharpener.dir/src/Slice.cpp.o: CMakeFiles/TestSharpener.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/TestSharpener.dir/src/Slice.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSharpener.dir/src/Slice.cpp.o -MF CMakeFiles/TestSharpener.dir/src/Slice.cpp.o.d -o CMakeFiles/TestSharpener.dir/src/Slice.cpp.o -c /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/Slice.cpp

CMakeFiles/TestSharpener.dir/src/Slice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestSharpener.dir/src/Slice.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/Slice.cpp > CMakeFiles/TestSharpener.dir/src/Slice.cpp.i

CMakeFiles/TestSharpener.dir/src/Slice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestSharpener.dir/src/Slice.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/Slice.cpp -o CMakeFiles/TestSharpener.dir/src/Slice.cpp.s

CMakeFiles/TestSharpener.dir/src/Volume.cpp.o: CMakeFiles/TestSharpener.dir/flags.make
CMakeFiles/TestSharpener.dir/src/Volume.cpp.o: /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/Volume.cpp
CMakeFiles/TestSharpener.dir/src/Volume.cpp.o: CMakeFiles/TestSharpener.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/TestSharpener.dir/src/Volume.cpp.o"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TestSharpener.dir/src/Volume.cpp.o -MF CMakeFiles/TestSharpener.dir/src/Volume.cpp.o.d -o CMakeFiles/TestSharpener.dir/src/Volume.cpp.o -c /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/Volume.cpp

CMakeFiles/TestSharpener.dir/src/Volume.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestSharpener.dir/src/Volume.cpp.i"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/Volume.cpp > CMakeFiles/TestSharpener.dir/src/Volume.cpp.i

CMakeFiles/TestSharpener.dir/src/Volume.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestSharpener.dir/src/Volume.cpp.s"
	/opt/homebrew/bin/g++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/src/Volume.cpp -o CMakeFiles/TestSharpener.dir/src/Volume.cpp.s

# Object files for target TestSharpener
TestSharpener_OBJECTS = \
"CMakeFiles/TestSharpener.dir/tests/2D/TestSharpener.cpp.o" \
"CMakeFiles/TestSharpener.dir/src/2D/Blur.cpp.o" \
"CMakeFiles/TestSharpener.dir/src/2D/EdgeDetector.cpp.o" \
"CMakeFiles/TestSharpener.dir/src/2D/Sharpener.cpp.o" \
"CMakeFiles/TestSharpener.dir/src/2D/SimpleFilter.cpp.o" \
"CMakeFiles/TestSharpener.dir/src/3D/BlurFilter3D.cpp.o" \
"CMakeFiles/TestSharpener.dir/src/Image.cpp.o" \
"CMakeFiles/TestSharpener.dir/src/Projection.cpp.o" \
"CMakeFiles/TestSharpener.dir/src/Slice.cpp.o" \
"CMakeFiles/TestSharpener.dir/src/Volume.cpp.o"

# External object files for target TestSharpener
TestSharpener_EXTERNAL_OBJECTS =

TestSharpener: CMakeFiles/TestSharpener.dir/tests/2D/TestSharpener.cpp.o
TestSharpener: CMakeFiles/TestSharpener.dir/src/2D/Blur.cpp.o
TestSharpener: CMakeFiles/TestSharpener.dir/src/2D/EdgeDetector.cpp.o
TestSharpener: CMakeFiles/TestSharpener.dir/src/2D/Sharpener.cpp.o
TestSharpener: CMakeFiles/TestSharpener.dir/src/2D/SimpleFilter.cpp.o
TestSharpener: CMakeFiles/TestSharpener.dir/src/3D/BlurFilter3D.cpp.o
TestSharpener: CMakeFiles/TestSharpener.dir/src/Image.cpp.o
TestSharpener: CMakeFiles/TestSharpener.dir/src/Projection.cpp.o
TestSharpener: CMakeFiles/TestSharpener.dir/src/Slice.cpp.o
TestSharpener: CMakeFiles/TestSharpener.dir/src/Volume.cpp.o
TestSharpener: CMakeFiles/TestSharpener.dir/build.make
TestSharpener: CMakeFiles/TestSharpener.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable TestSharpener"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestSharpener.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestSharpener.dir/build: TestSharpener
.PHONY : CMakeFiles/TestSharpener.dir/build

CMakeFiles/TestSharpener.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestSharpener.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestSharpener.dir/clean

CMakeFiles/TestSharpener.dir/depend:
	cd /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build /Users/mw2124/Desktop/Assessments/advanced-programming-group-bisection/build/CMakeFiles/TestSharpener.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TestSharpener.dir/depend

