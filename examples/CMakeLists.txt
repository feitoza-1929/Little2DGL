project(example_result)

add_executable(${PROJECT_NAME} sandbox.cpp)
target_link_libraries(${PROJECT_NAME} L2DGL)
