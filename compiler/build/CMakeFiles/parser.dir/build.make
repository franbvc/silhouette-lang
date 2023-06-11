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
CMAKE_SOURCE_DIR = /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build

# Include any dependencies generated for this target.
include CMakeFiles/parser.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/parser.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/parser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parser.dir/flags.make

parser.cpp: ../parser-bison/parser.y
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BISON][ParserBison] Building parser with bison 3.8.2"
	cd /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm && /usr/bin/bison -d -d -o /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build/parser.cpp ./parser-bison/parser.y

parser.hpp: parser.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate parser.hpp

tokens.cpp: ../tokenizer-flex/tokens.l
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[FLEX][TokenizerFlex] Building scanner with flex 2.6.4"
	cd /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm && /usr/bin/flex -o/home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build/tokens.cpp ./tokenizer-flex/tokens.l

CMakeFiles/parser.dir/parser.cpp.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/parser.cpp.o: parser.cpp
CMakeFiles/parser.dir/parser.cpp.o: CMakeFiles/parser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/parser.dir/parser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/parser.dir/parser.cpp.o -MF CMakeFiles/parser.dir/parser.cpp.o.d -o CMakeFiles/parser.dir/parser.cpp.o -c /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build/parser.cpp

CMakeFiles/parser.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser.dir/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build/parser.cpp > CMakeFiles/parser.dir/parser.cpp.i

CMakeFiles/parser.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser.dir/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build/parser.cpp -o CMakeFiles/parser.dir/parser.cpp.s

CMakeFiles/parser.dir/tokens.cpp.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/tokens.cpp.o: tokens.cpp
CMakeFiles/parser.dir/tokens.cpp.o: CMakeFiles/parser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/parser.dir/tokens.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/parser.dir/tokens.cpp.o -MF CMakeFiles/parser.dir/tokens.cpp.o.d -o CMakeFiles/parser.dir/tokens.cpp.o -c /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build/tokens.cpp

CMakeFiles/parser.dir/tokens.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser.dir/tokens.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build/tokens.cpp > CMakeFiles/parser.dir/tokens.cpp.i

CMakeFiles/parser.dir/tokens.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser.dir/tokens.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build/tokens.cpp -o CMakeFiles/parser.dir/tokens.cpp.s

CMakeFiles/parser.dir/codegen.cpp.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/codegen.cpp.o: ../codegen.cpp
CMakeFiles/parser.dir/codegen.cpp.o: CMakeFiles/parser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/parser.dir/codegen.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/parser.dir/codegen.cpp.o -MF CMakeFiles/parser.dir/codegen.cpp.o.d -o CMakeFiles/parser.dir/codegen.cpp.o -c /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/codegen.cpp

CMakeFiles/parser.dir/codegen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser.dir/codegen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/codegen.cpp > CMakeFiles/parser.dir/codegen.cpp.i

CMakeFiles/parser.dir/codegen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser.dir/codegen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/codegen.cpp -o CMakeFiles/parser.dir/codegen.cpp.s

CMakeFiles/parser.dir/main.cpp.o: CMakeFiles/parser.dir/flags.make
CMakeFiles/parser.dir/main.cpp.o: ../main.cpp
CMakeFiles/parser.dir/main.cpp.o: CMakeFiles/parser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/parser.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/parser.dir/main.cpp.o -MF CMakeFiles/parser.dir/main.cpp.o.d -o CMakeFiles/parser.dir/main.cpp.o -c /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/main.cpp

CMakeFiles/parser.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parser.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/main.cpp > CMakeFiles/parser.dir/main.cpp.i

CMakeFiles/parser.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parser.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/main.cpp -o CMakeFiles/parser.dir/main.cpp.s

# Object files for target parser
parser_OBJECTS = \
"CMakeFiles/parser.dir/parser.cpp.o" \
"CMakeFiles/parser.dir/tokens.cpp.o" \
"CMakeFiles/parser.dir/codegen.cpp.o" \
"CMakeFiles/parser.dir/main.cpp.o"

# External object files for target parser
parser_EXTERNAL_OBJECTS =

parser: CMakeFiles/parser.dir/parser.cpp.o
parser: CMakeFiles/parser.dir/tokens.cpp.o
parser: CMakeFiles/parser.dir/codegen.cpp.o
parser: CMakeFiles/parser.dir/main.cpp.o
parser: CMakeFiles/parser.dir/build.make
parser: /usr/lib/llvm-14/lib/libLLVM-14.so.1
parser: CMakeFiles/parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable parser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parser.dir/build: parser
.PHONY : CMakeFiles/parser.dir/build

CMakeFiles/parser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/parser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/parser.dir/clean

CMakeFiles/parser.dir/depend: parser.cpp
CMakeFiles/parser.dir/depend: parser.hpp
CMakeFiles/parser.dir/depend: tokens.cpp
	cd /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build /home/franbvc/Insper/LogComp/lang/silhouette-lang/test-llvm/build/CMakeFiles/parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parser.dir/depend
