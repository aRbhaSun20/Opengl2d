# Project definition
cmake_minimum_required(VERSION 3.1)
project(OpenGL)

# Source files
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libraries")

# Vetex Buffer
set(VERTEX_DIR "${SRC_DIR}/VertexBuffers")
set(VERTEX_BUFFER "${VERTEX_DIR}/VertexBuffer.h" 
    "${VERTEX_DIR}/VertexBuffer.cpp") 

#Index Buffer
set(INDEX_DIR "${SRC_DIR}/IndexBuffers")
set(INDEX_BUFFER  "${INDEX_DIR}/IndexBuffer.h" 
    "${INDEX_DIR}/IndexBuffer.cpp")

# Vertex Array and Vertex Buffer Layout
#set(VERTEX_ARRAY_LAYOUT "${SRC_DIR}/VertexBufferLayout.h"
#     "${SRC_DIR}/VertexArray.h" "${SRC_DIR}/VertexArray.cpp" )

# Shader Contents
set(SHADER_DIR "${SRC_DIR}/Shaders")
set(SHADER_FILES "${SHADER_DIR}/ShaderInitialize.h" 
    "${SHADER_DIR}/ShaderInitialize.cpp")

# Application files 
set(SECONDARY "${SRC_DIR}/index.h" "${SRC_DIR}/Initialize.cpp" "${VERTEX_ARRAY_LAYOUT}"
    "${VERTEX_BUFFER}" "${INDEX_BUFFER}" "${SHADER_FILES}" )
set(SOURCES "${SRC_DIR}/index.cpp" "${SECONDARY}" )

# Executable definition and properties
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "${SRC_DIR}")
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

# GLFW
set(GLFW_DIR "${LIB_DIR}/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory("${GLFW_DIR}")
target_link_libraries(${PROJECT_NAME} "glfw" "${GLFW_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLFW_DIR}/include")
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

# glad
set(GLAD_DIR "${LIB_DIR}/glad")
add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glad" "${CMAKE_DL_LIBS}")
