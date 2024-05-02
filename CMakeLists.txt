cmake_minimum_required(VERSION 3.10)

project(L2DGE VERSION 0.4.0)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(external_libs/glfw)
add_subdirectory(examples)

set(SOURCES
    external_libs/stb/stb_image.cpp
    src/Shader.cpp
    src/Window.cpp
    src/Clock.cpp
    src/Input.cpp
    src/Renderable.cpp
    src/Render.cpp
    src/RenderState.cpp
    src/VertexBuffer.cpp
    src/VertexArray.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC include
    PRIVATE external_libs/glfw
    PRIVATE external_libs/stb
    PRIVATE external_libs/glm
)

target_link_libraries(${PROJECT_NAME}
    GLEW::GLEW
    OpenGL::GL
    glfw
    )
