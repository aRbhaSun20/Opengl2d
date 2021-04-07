# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arb/Arb/Proj/Opengl/OpenGl-Demo-Pro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arb/Arb/Proj/Opengl/OpenGl-Demo-Pro

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/arb/Arb/Proj/Opengl/OpenGl-Demo-Pro/CMakeFiles /home/arb/Arb/Proj/Opengl/OpenGl-Demo-Pro/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/arb/Arb/Proj/Opengl/OpenGl-Demo-Pro/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named STB_IMAGE

# Build rule for target.
STB_IMAGE: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 STB_IMAGE
.PHONY : STB_IMAGE

# fast build rule for target.
STB_IMAGE/fast:
	$(MAKE) -f CMakeFiles/STB_IMAGE.dir/build.make CMakeFiles/STB_IMAGE.dir/build
.PHONY : STB_IMAGE/fast

#=============================================================================
# Target rules for targets named glad

# Build rule for target.
glad: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 glad
.PHONY : glad

# fast build rule for target.
glad/fast:
	$(MAKE) -f CMakeFiles/glad.dir/build.make CMakeFiles/glad.dir/build
.PHONY : glad/fast

#=============================================================================
# Target rules for targets named OpenGL

# Build rule for target.
OpenGL: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 OpenGL
.PHONY : OpenGL

# fast build rule for target.
OpenGL/fast:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/build
.PHONY : OpenGL/fast

#=============================================================================
# Target rules for targets named glfw

# Build rule for target.
glfw: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 glfw
.PHONY : glfw

# fast build rule for target.
glfw/fast:
	$(MAKE) -f libraries/glfw/src/CMakeFiles/glfw.dir/build.make libraries/glfw/src/CMakeFiles/glfw.dir/build
.PHONY : glfw/fast

libraries/StdImage/stb_image.o: libraries/StdImage/stb_image.cpp.o

.PHONY : libraries/StdImage/stb_image.o

# target to build an object file
libraries/StdImage/stb_image.cpp.o:
	$(MAKE) -f CMakeFiles/STB_IMAGE.dir/build.make CMakeFiles/STB_IMAGE.dir/libraries/StdImage/stb_image.cpp.o
.PHONY : libraries/StdImage/stb_image.cpp.o

libraries/StdImage/stb_image.i: libraries/StdImage/stb_image.cpp.i

.PHONY : libraries/StdImage/stb_image.i

# target to preprocess a source file
libraries/StdImage/stb_image.cpp.i:
	$(MAKE) -f CMakeFiles/STB_IMAGE.dir/build.make CMakeFiles/STB_IMAGE.dir/libraries/StdImage/stb_image.cpp.i
.PHONY : libraries/StdImage/stb_image.cpp.i

libraries/StdImage/stb_image.s: libraries/StdImage/stb_image.cpp.s

.PHONY : libraries/StdImage/stb_image.s

# target to generate assembly for a file
libraries/StdImage/stb_image.cpp.s:
	$(MAKE) -f CMakeFiles/STB_IMAGE.dir/build.make CMakeFiles/STB_IMAGE.dir/libraries/StdImage/stb_image.cpp.s
.PHONY : libraries/StdImage/stb_image.cpp.s

libraries/glad/src/glad.o: libraries/glad/src/glad.c.o

.PHONY : libraries/glad/src/glad.o

# target to build an object file
libraries/glad/src/glad.c.o:
	$(MAKE) -f CMakeFiles/glad.dir/build.make CMakeFiles/glad.dir/libraries/glad/src/glad.c.o
.PHONY : libraries/glad/src/glad.c.o

libraries/glad/src/glad.i: libraries/glad/src/glad.c.i

.PHONY : libraries/glad/src/glad.i

# target to preprocess a source file
libraries/glad/src/glad.c.i:
	$(MAKE) -f CMakeFiles/glad.dir/build.make CMakeFiles/glad.dir/libraries/glad/src/glad.c.i
.PHONY : libraries/glad/src/glad.c.i

libraries/glad/src/glad.s: libraries/glad/src/glad.c.s

.PHONY : libraries/glad/src/glad.s

# target to generate assembly for a file
libraries/glad/src/glad.c.s:
	$(MAKE) -f CMakeFiles/glad.dir/build.make CMakeFiles/glad.dir/libraries/glad/src/glad.c.s
.PHONY : libraries/glad/src/glad.c.s

libraries/imgui/imgui.o: libraries/imgui/imgui.cpp.o

.PHONY : libraries/imgui/imgui.o

# target to build an object file
libraries/imgui/imgui.cpp.o:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui.cpp.o
.PHONY : libraries/imgui/imgui.cpp.o

libraries/imgui/imgui.i: libraries/imgui/imgui.cpp.i

.PHONY : libraries/imgui/imgui.i

# target to preprocess a source file
libraries/imgui/imgui.cpp.i:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui.cpp.i
.PHONY : libraries/imgui/imgui.cpp.i

libraries/imgui/imgui.s: libraries/imgui/imgui.cpp.s

.PHONY : libraries/imgui/imgui.s

# target to generate assembly for a file
libraries/imgui/imgui.cpp.s:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui.cpp.s
.PHONY : libraries/imgui/imgui.cpp.s

libraries/imgui/imgui_demo.o: libraries/imgui/imgui_demo.cpp.o

.PHONY : libraries/imgui/imgui_demo.o

# target to build an object file
libraries/imgui/imgui_demo.cpp.o:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui_demo.cpp.o
.PHONY : libraries/imgui/imgui_demo.cpp.o

libraries/imgui/imgui_demo.i: libraries/imgui/imgui_demo.cpp.i

.PHONY : libraries/imgui/imgui_demo.i

# target to preprocess a source file
libraries/imgui/imgui_demo.cpp.i:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui_demo.cpp.i
.PHONY : libraries/imgui/imgui_demo.cpp.i

libraries/imgui/imgui_demo.s: libraries/imgui/imgui_demo.cpp.s

.PHONY : libraries/imgui/imgui_demo.s

# target to generate assembly for a file
libraries/imgui/imgui_demo.cpp.s:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui_demo.cpp.s
.PHONY : libraries/imgui/imgui_demo.cpp.s

libraries/imgui/imgui_draw.o: libraries/imgui/imgui_draw.cpp.o

.PHONY : libraries/imgui/imgui_draw.o

# target to build an object file
libraries/imgui/imgui_draw.cpp.o:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui_draw.cpp.o
.PHONY : libraries/imgui/imgui_draw.cpp.o

libraries/imgui/imgui_draw.i: libraries/imgui/imgui_draw.cpp.i

.PHONY : libraries/imgui/imgui_draw.i

# target to preprocess a source file
libraries/imgui/imgui_draw.cpp.i:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui_draw.cpp.i
.PHONY : libraries/imgui/imgui_draw.cpp.i

libraries/imgui/imgui_draw.s: libraries/imgui/imgui_draw.cpp.s

.PHONY : libraries/imgui/imgui_draw.s

# target to generate assembly for a file
libraries/imgui/imgui_draw.cpp.s:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui_draw.cpp.s
.PHONY : libraries/imgui/imgui_draw.cpp.s

libraries/imgui/imgui_impl_glfw.o: libraries/imgui/imgui_impl_glfw.cpp.o

.PHONY : libraries/imgui/imgui_impl_glfw.o

# target to build an object file
libraries/imgui/imgui_impl_glfw.cpp.o:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui_impl_glfw.cpp.o
.PHONY : libraries/imgui/imgui_impl_glfw.cpp.o

libraries/imgui/imgui_impl_glfw.i: libraries/imgui/imgui_impl_glfw.cpp.i

.PHONY : libraries/imgui/imgui_impl_glfw.i

# target to preprocess a source file
libraries/imgui/imgui_impl_glfw.cpp.i:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui_impl_glfw.cpp.i
.PHONY : libraries/imgui/imgui_impl_glfw.cpp.i

libraries/imgui/imgui_impl_glfw.s: libraries/imgui/imgui_impl_glfw.cpp.s

.PHONY : libraries/imgui/imgui_impl_glfw.s

# target to generate assembly for a file
libraries/imgui/imgui_impl_glfw.cpp.s:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui_impl_glfw.cpp.s
.PHONY : libraries/imgui/imgui_impl_glfw.cpp.s

libraries/imgui/imgui_impl_opengl3.o: libraries/imgui/imgui_impl_opengl3.cpp.o

.PHONY : libraries/imgui/imgui_impl_opengl3.o

# target to build an object file
libraries/imgui/imgui_impl_opengl3.cpp.o:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui_impl_opengl3.cpp.o
.PHONY : libraries/imgui/imgui_impl_opengl3.cpp.o

libraries/imgui/imgui_impl_opengl3.i: libraries/imgui/imgui_impl_opengl3.cpp.i

.PHONY : libraries/imgui/imgui_impl_opengl3.i

# target to preprocess a source file
libraries/imgui/imgui_impl_opengl3.cpp.i:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui_impl_opengl3.cpp.i
.PHONY : libraries/imgui/imgui_impl_opengl3.cpp.i

libraries/imgui/imgui_impl_opengl3.s: libraries/imgui/imgui_impl_opengl3.cpp.s

.PHONY : libraries/imgui/imgui_impl_opengl3.s

# target to generate assembly for a file
libraries/imgui/imgui_impl_opengl3.cpp.s:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui_impl_opengl3.cpp.s
.PHONY : libraries/imgui/imgui_impl_opengl3.cpp.s

libraries/imgui/imgui_widgets.o: libraries/imgui/imgui_widgets.cpp.o

.PHONY : libraries/imgui/imgui_widgets.o

# target to build an object file
libraries/imgui/imgui_widgets.cpp.o:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui_widgets.cpp.o
.PHONY : libraries/imgui/imgui_widgets.cpp.o

libraries/imgui/imgui_widgets.i: libraries/imgui/imgui_widgets.cpp.i

.PHONY : libraries/imgui/imgui_widgets.i

# target to preprocess a source file
libraries/imgui/imgui_widgets.cpp.i:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui_widgets.cpp.i
.PHONY : libraries/imgui/imgui_widgets.cpp.i

libraries/imgui/imgui_widgets.s: libraries/imgui/imgui_widgets.cpp.s

.PHONY : libraries/imgui/imgui_widgets.s

# target to generate assembly for a file
libraries/imgui/imgui_widgets.cpp.s:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/libraries/imgui/imgui_widgets.cpp.s
.PHONY : libraries/imgui/imgui_widgets.cpp.s

source/ImguiHandle/ImguiHandle.o: source/ImguiHandle/ImguiHandle.cpp.o

.PHONY : source/ImguiHandle/ImguiHandle.o

# target to build an object file
source/ImguiHandle/ImguiHandle.cpp.o:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/ImguiHandle/ImguiHandle.cpp.o
.PHONY : source/ImguiHandle/ImguiHandle.cpp.o

source/ImguiHandle/ImguiHandle.i: source/ImguiHandle/ImguiHandle.cpp.i

.PHONY : source/ImguiHandle/ImguiHandle.i

# target to preprocess a source file
source/ImguiHandle/ImguiHandle.cpp.i:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/ImguiHandle/ImguiHandle.cpp.i
.PHONY : source/ImguiHandle/ImguiHandle.cpp.i

source/ImguiHandle/ImguiHandle.s: source/ImguiHandle/ImguiHandle.cpp.s

.PHONY : source/ImguiHandle/ImguiHandle.s

# target to generate assembly for a file
source/ImguiHandle/ImguiHandle.cpp.s:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/ImguiHandle/ImguiHandle.cpp.s
.PHONY : source/ImguiHandle/ImguiHandle.cpp.s

source/IndexBuffers/IndexBuffer.o: source/IndexBuffers/IndexBuffer.cpp.o

.PHONY : source/IndexBuffers/IndexBuffer.o

# target to build an object file
source/IndexBuffers/IndexBuffer.cpp.o:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/IndexBuffers/IndexBuffer.cpp.o
.PHONY : source/IndexBuffers/IndexBuffer.cpp.o

source/IndexBuffers/IndexBuffer.i: source/IndexBuffers/IndexBuffer.cpp.i

.PHONY : source/IndexBuffers/IndexBuffer.i

# target to preprocess a source file
source/IndexBuffers/IndexBuffer.cpp.i:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/IndexBuffers/IndexBuffer.cpp.i
.PHONY : source/IndexBuffers/IndexBuffer.cpp.i

source/IndexBuffers/IndexBuffer.s: source/IndexBuffers/IndexBuffer.cpp.s

.PHONY : source/IndexBuffers/IndexBuffer.s

# target to generate assembly for a file
source/IndexBuffers/IndexBuffer.cpp.s:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/IndexBuffers/IndexBuffer.cpp.s
.PHONY : source/IndexBuffers/IndexBuffer.cpp.s

source/Initialize.o: source/Initialize.cpp.o

.PHONY : source/Initialize.o

# target to build an object file
source/Initialize.cpp.o:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/Initialize.cpp.o
.PHONY : source/Initialize.cpp.o

source/Initialize.i: source/Initialize.cpp.i

.PHONY : source/Initialize.i

# target to preprocess a source file
source/Initialize.cpp.i:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/Initialize.cpp.i
.PHONY : source/Initialize.cpp.i

source/Initialize.s: source/Initialize.cpp.s

.PHONY : source/Initialize.s

# target to generate assembly for a file
source/Initialize.cpp.s:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/Initialize.cpp.s
.PHONY : source/Initialize.cpp.s

source/Renderer/Renderer.o: source/Renderer/Renderer.cpp.o

.PHONY : source/Renderer/Renderer.o

# target to build an object file
source/Renderer/Renderer.cpp.o:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/Renderer/Renderer.cpp.o
.PHONY : source/Renderer/Renderer.cpp.o

source/Renderer/Renderer.i: source/Renderer/Renderer.cpp.i

.PHONY : source/Renderer/Renderer.i

# target to preprocess a source file
source/Renderer/Renderer.cpp.i:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/Renderer/Renderer.cpp.i
.PHONY : source/Renderer/Renderer.cpp.i

source/Renderer/Renderer.s: source/Renderer/Renderer.cpp.s

.PHONY : source/Renderer/Renderer.s

# target to generate assembly for a file
source/Renderer/Renderer.cpp.s:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/Renderer/Renderer.cpp.s
.PHONY : source/Renderer/Renderer.cpp.s

source/Shaders/ShaderInitialize.o: source/Shaders/ShaderInitialize.cpp.o

.PHONY : source/Shaders/ShaderInitialize.o

# target to build an object file
source/Shaders/ShaderInitialize.cpp.o:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/Shaders/ShaderInitialize.cpp.o
.PHONY : source/Shaders/ShaderInitialize.cpp.o

source/Shaders/ShaderInitialize.i: source/Shaders/ShaderInitialize.cpp.i

.PHONY : source/Shaders/ShaderInitialize.i

# target to preprocess a source file
source/Shaders/ShaderInitialize.cpp.i:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/Shaders/ShaderInitialize.cpp.i
.PHONY : source/Shaders/ShaderInitialize.cpp.i

source/Shaders/ShaderInitialize.s: source/Shaders/ShaderInitialize.cpp.s

.PHONY : source/Shaders/ShaderInitialize.s

# target to generate assembly for a file
source/Shaders/ShaderInitialize.cpp.s:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/Shaders/ShaderInitialize.cpp.s
.PHONY : source/Shaders/ShaderInitialize.cpp.s

source/Texture/Texture.o: source/Texture/Texture.cpp.o

.PHONY : source/Texture/Texture.o

# target to build an object file
source/Texture/Texture.cpp.o:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/Texture/Texture.cpp.o
.PHONY : source/Texture/Texture.cpp.o

source/Texture/Texture.i: source/Texture/Texture.cpp.i

.PHONY : source/Texture/Texture.i

# target to preprocess a source file
source/Texture/Texture.cpp.i:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/Texture/Texture.cpp.i
.PHONY : source/Texture/Texture.cpp.i

source/Texture/Texture.s: source/Texture/Texture.cpp.s

.PHONY : source/Texture/Texture.s

# target to generate assembly for a file
source/Texture/Texture.cpp.s:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/Texture/Texture.cpp.s
.PHONY : source/Texture/Texture.cpp.s

source/VertexArrays/VertexArray.o: source/VertexArrays/VertexArray.cpp.o

.PHONY : source/VertexArrays/VertexArray.o

# target to build an object file
source/VertexArrays/VertexArray.cpp.o:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/VertexArrays/VertexArray.cpp.o
.PHONY : source/VertexArrays/VertexArray.cpp.o

source/VertexArrays/VertexArray.i: source/VertexArrays/VertexArray.cpp.i

.PHONY : source/VertexArrays/VertexArray.i

# target to preprocess a source file
source/VertexArrays/VertexArray.cpp.i:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/VertexArrays/VertexArray.cpp.i
.PHONY : source/VertexArrays/VertexArray.cpp.i

source/VertexArrays/VertexArray.s: source/VertexArrays/VertexArray.cpp.s

.PHONY : source/VertexArrays/VertexArray.s

# target to generate assembly for a file
source/VertexArrays/VertexArray.cpp.s:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/VertexArrays/VertexArray.cpp.s
.PHONY : source/VertexArrays/VertexArray.cpp.s

source/VertexBufferLayouts/VertexBufferLayout.o: source/VertexBufferLayouts/VertexBufferLayout.cpp.o

.PHONY : source/VertexBufferLayouts/VertexBufferLayout.o

# target to build an object file
source/VertexBufferLayouts/VertexBufferLayout.cpp.o:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/VertexBufferLayouts/VertexBufferLayout.cpp.o
.PHONY : source/VertexBufferLayouts/VertexBufferLayout.cpp.o

source/VertexBufferLayouts/VertexBufferLayout.i: source/VertexBufferLayouts/VertexBufferLayout.cpp.i

.PHONY : source/VertexBufferLayouts/VertexBufferLayout.i

# target to preprocess a source file
source/VertexBufferLayouts/VertexBufferLayout.cpp.i:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/VertexBufferLayouts/VertexBufferLayout.cpp.i
.PHONY : source/VertexBufferLayouts/VertexBufferLayout.cpp.i

source/VertexBufferLayouts/VertexBufferLayout.s: source/VertexBufferLayouts/VertexBufferLayout.cpp.s

.PHONY : source/VertexBufferLayouts/VertexBufferLayout.s

# target to generate assembly for a file
source/VertexBufferLayouts/VertexBufferLayout.cpp.s:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/VertexBufferLayouts/VertexBufferLayout.cpp.s
.PHONY : source/VertexBufferLayouts/VertexBufferLayout.cpp.s

source/VertexBuffers/VertexBuff.o: source/VertexBuffers/VertexBuff.cpp.o

.PHONY : source/VertexBuffers/VertexBuff.o

# target to build an object file
source/VertexBuffers/VertexBuff.cpp.o:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/VertexBuffers/VertexBuff.cpp.o
.PHONY : source/VertexBuffers/VertexBuff.cpp.o

source/VertexBuffers/VertexBuff.i: source/VertexBuffers/VertexBuff.cpp.i

.PHONY : source/VertexBuffers/VertexBuff.i

# target to preprocess a source file
source/VertexBuffers/VertexBuff.cpp.i:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/VertexBuffers/VertexBuff.cpp.i
.PHONY : source/VertexBuffers/VertexBuff.cpp.i

source/VertexBuffers/VertexBuff.s: source/VertexBuffers/VertexBuff.cpp.s

.PHONY : source/VertexBuffers/VertexBuff.s

# target to generate assembly for a file
source/VertexBuffers/VertexBuff.cpp.s:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/VertexBuffers/VertexBuff.cpp.s
.PHONY : source/VertexBuffers/VertexBuff.cpp.s

source/index.o: source/index.cpp.o

.PHONY : source/index.o

# target to build an object file
source/index.cpp.o:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/index.cpp.o
.PHONY : source/index.cpp.o

source/index.i: source/index.cpp.i

.PHONY : source/index.i

# target to preprocess a source file
source/index.cpp.i:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/index.cpp.i
.PHONY : source/index.cpp.i

source/index.s: source/index.cpp.s

.PHONY : source/index.s

# target to generate assembly for a file
source/index.cpp.s:
	$(MAKE) -f CMakeFiles/OpenGL.dir/build.make CMakeFiles/OpenGL.dir/source/index.cpp.s
.PHONY : source/index.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... STB_IMAGE"
	@echo "... glad"
	@echo "... OpenGL"
	@echo "... glfw"
	@echo "... libraries/StdImage/stb_image.o"
	@echo "... libraries/StdImage/stb_image.i"
	@echo "... libraries/StdImage/stb_image.s"
	@echo "... libraries/glad/src/glad.o"
	@echo "... libraries/glad/src/glad.i"
	@echo "... libraries/glad/src/glad.s"
	@echo "... libraries/imgui/imgui.o"
	@echo "... libraries/imgui/imgui.i"
	@echo "... libraries/imgui/imgui.s"
	@echo "... libraries/imgui/imgui_demo.o"
	@echo "... libraries/imgui/imgui_demo.i"
	@echo "... libraries/imgui/imgui_demo.s"
	@echo "... libraries/imgui/imgui_draw.o"
	@echo "... libraries/imgui/imgui_draw.i"
	@echo "... libraries/imgui/imgui_draw.s"
	@echo "... libraries/imgui/imgui_impl_glfw.o"
	@echo "... libraries/imgui/imgui_impl_glfw.i"
	@echo "... libraries/imgui/imgui_impl_glfw.s"
	@echo "... libraries/imgui/imgui_impl_opengl3.o"
	@echo "... libraries/imgui/imgui_impl_opengl3.i"
	@echo "... libraries/imgui/imgui_impl_opengl3.s"
	@echo "... libraries/imgui/imgui_widgets.o"
	@echo "... libraries/imgui/imgui_widgets.i"
	@echo "... libraries/imgui/imgui_widgets.s"
	@echo "... source/ImguiHandle/ImguiHandle.o"
	@echo "... source/ImguiHandle/ImguiHandle.i"
	@echo "... source/ImguiHandle/ImguiHandle.s"
	@echo "... source/IndexBuffers/IndexBuffer.o"
	@echo "... source/IndexBuffers/IndexBuffer.i"
	@echo "... source/IndexBuffers/IndexBuffer.s"
	@echo "... source/Initialize.o"
	@echo "... source/Initialize.i"
	@echo "... source/Initialize.s"
	@echo "... source/Renderer/Renderer.o"
	@echo "... source/Renderer/Renderer.i"
	@echo "... source/Renderer/Renderer.s"
	@echo "... source/Shaders/ShaderInitialize.o"
	@echo "... source/Shaders/ShaderInitialize.i"
	@echo "... source/Shaders/ShaderInitialize.s"
	@echo "... source/Texture/Texture.o"
	@echo "... source/Texture/Texture.i"
	@echo "... source/Texture/Texture.s"
	@echo "... source/VertexArrays/VertexArray.o"
	@echo "... source/VertexArrays/VertexArray.i"
	@echo "... source/VertexArrays/VertexArray.s"
	@echo "... source/VertexBufferLayouts/VertexBufferLayout.o"
	@echo "... source/VertexBufferLayouts/VertexBufferLayout.i"
	@echo "... source/VertexBufferLayouts/VertexBufferLayout.s"
	@echo "... source/VertexBuffers/VertexBuff.o"
	@echo "... source/VertexBuffers/VertexBuff.i"
	@echo "... source/VertexBuffers/VertexBuff.s"
	@echo "... source/index.o"
	@echo "... source/index.i"
	@echo "... source/index.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

