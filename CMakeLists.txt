cmake_minimum_required(VERSION 2.8)
# Project Name
PROJECT(HW_OPENGL)

#########################################################
# FIND GLUT
#########################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)
#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})

link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)




#########################################################
# Include Files
#########################################################
add_executable(robot-city-rampage main.cpp Landscape.cpp Landscape.h Robot.cpp Robot.h Building.cpp Building.h BuildingFactory.cpp BuildingFactory.h Explosion.cpp Explosion.h)

target_include_directories(robot-city-rampage PRIVATE ${GlmIncludeDir})

########################################################
# Linking & stuff
#########################################################

  # create the program "test"
  target_link_libraries(robot-city-rampage ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
