cmake_minimum_required(VERSION 3.6)
#project_name
project(simur)

find_package(SFML 2.4.2 REQUIRED system window graphics)
find_package(GLUT REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(libigl CONFIG REQUIRED)
find_package(imgui REQUIRED)

add_executable(app "code/simur.cpp")

target_link_libraries(app sfml-window sfml-graphics)
target_link_libraries(app GLUT::GLUT)
target_link_libraries(app glfw)
target_link_libraries(app glad::glad)
target_link_libraries(app GLEW::GLEW)
target_link_libraries(app igl::igl_core igl::igl_glfw igl::igl_imgui igl::igl_opengl)
target_link_libraries(app imgui::imgui)

