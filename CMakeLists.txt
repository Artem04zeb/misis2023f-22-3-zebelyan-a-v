cmake_minimum_required(VERSION 3.6)

project("Morph")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(SFML 2.4.2 REQUIRED system window graphics)
find_package(GLUT REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(libigl CONFIG REQUIRED)
find_package(imgui REQUIRED)
find_package(doxygen)


# Generate Docs
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(prj.codeforces)
add_subdirectory(prj.cw)
