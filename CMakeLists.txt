cmake_minimum_required(VERSION 3.16.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(MovingSqr)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

set("root" ${CMAKE_SOURCE_DIR}/OpenGL-MovingSqr)

file(GLOB sources "${root}/source/*.cpp")

add_executable(movingsqr ${sources})

target_link_libraries(movingsqr ${OPENGL_LIBRARIES} glfw GLEW::GLEW)

add_custom_command(
        TARGET movingsqr POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${root}/resource
        ${CMAKE_CURRENT_BINARY_DIR}/resource
)
