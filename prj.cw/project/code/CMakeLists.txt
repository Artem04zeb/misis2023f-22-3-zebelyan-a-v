add_library(morphs morph.cpp include/morph.hpp)

set_property(TARGET morphs PROPERTY CXX_STANDARD 14)
target_include_directories(morphs PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(morphs          glfw
                                      GLUT::GLUT  
                                      glad::glad  
                                      GLEW::GLEW
                                      igl::igl_core 
                                      igl::igl_glfw
                                      igl::igl_imgui
                                      igl::igl_opengl
                                      imgui::imgui
                                      sfml-window sfml-graphics
                                    
  ) 
