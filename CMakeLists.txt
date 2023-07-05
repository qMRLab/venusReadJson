project(VenusReadJson)

cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5Widgets REQUIRED) # find and setup Qt5 for this project
find_package(Qt5Script REQUIRED)
find_package(Qt5Xml REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Concurrent REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5PrintSupport REQUIRED)
find_package(Qt5WebSockets REQUIRED)

find_package(RthLibs REQUIRED)

if(NOT Log4cxx_FOUND)
  find_package(Log4cxx REQUIRED)
endif()

# https://cmake.org/cmake/help/latest/module/FindMatlab.html

# CMake 3.13.4 

# the variable "qtproject_SRCS" contains all .cpp files of this project
set(VenusReadJson_SRCS
	VenusReadJson.cpp
	VenusReadJsonPlugin.cpp
)

set(VenusReadJson_MOC_HDRS
	VenusReadJson.h
	VenusReadJsonPlugin.h
)



include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Script_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${RTHLIBS_INCLUDE_DIR})
include_directories(${LOG4CXX_INCLUDE_DIR})

message(RTHLIBS_INCLUDE_DIR="${RTHLIBS_INCLUDE_DIR}")

add_definitions(${Qt5Core_DEFINITIONS})
add_definitions(${Qt5Script_DEFINITIONS})

QT5_WRAP_CPP(VenusReadJson_MOC_SRCS ${VenusReadJson_MOC_HDRS})

# Don't forget to include output directory, otherwise
# the UI file won't be wrapped!

ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_SHARED)
#ADD_DEFINITIONS(-DQT_NO_DEBUG)
#ADD_DEFINITIONS(-std=c++11 -Wall -Wextra)
ADD_DEFINITIONS(-Wall -Wextra -Werror)



#SET(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

ADD_LIBRARY(VenusReadJsonPlugin MODULE ${VenusReadJson_SRCS} ${VenusReadJson_MOC_SRCS} ${INCS})

target_link_libraries(VenusReadJsonPlugin Qt5::Core Qt5::Widgets Qt5::Script ${RTHLIBS_LIBRARIES}  ${LOG4CXX_LIBRARIES})

INSTALL(TARGETS VenusReadJsonPlugin LIBRARY DESTINATION ~/HeartVista/script)
