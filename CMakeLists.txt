cmake_minimum_required(VERSION 3.10)

project(L2DGL VERSION 0.1.3)

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
    src/Canvas.cpp
    src/QuadShape.cpp
    src/Vector2.cpp)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PUBLIC include
    PUBLIC external_libs/glfw
)

target_link_libraries(${PROJECT_NAME}
    GLEW::GLEW
    OpenGL::GL
    glfw
)