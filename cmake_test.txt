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


if (DOXYGEN_FOUND)
   set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/prj.cw/Doxy/Doxyfile)
   set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

   configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
   message("Doxygen build started")

   add_custom_target(doc_doxygen ALL
       COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
       WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
       COMMENT "Generating API documentation with Doxygen"
       VERBATIM )
else (DOXYGEN_FOUND)
 message("Doxygen needs to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

add_subdirectory(prj.codeforces)
add_subdirectory(prj.cw)
