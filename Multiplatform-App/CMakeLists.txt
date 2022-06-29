cmake_minimum_required(VERSION 3.1.0)

project(Multiplatform)

 message(STATUS "------- COMPILER CONFIGURATION -------")

if(LINUX)
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

    message(STATUS "    CMAKE_C_COMPILER: ${CMAKE_C_COMPILER}")
    message(STATUS "    CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
endif()

if(WIN)
    set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/cc.exe")
    set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/c++.exe")

    message(STATUS "    CMAKE_C_COMPILER: ${CMAKE_C_COMPILER}")
    message(STATUS "    CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "    CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

message(STATUS "------- QT CONFIGURATION -------")

if(LINUX)
    set(QtCore_DIRECTORY "~/Qt")
    set(QtCore_RELEASE "6") 
    set(QtCore_VERSION "6.2.4")
    set(QtCore_COMPILER_NAME "gcc_64")
endif()

if(WIN)
    set(QtCore_DIRECTORY "C:/Qt")
    set(QtCore_RELEASE "6")
    set(QtCore_VERSION "6.2.4")
    set(QtCore_COMPILER_NAME "mingw_64")
endif()

if(ANDROID)
    set(QtCore_RELEASE "6")
    set(QtCore_VERSION "6.2.4")
    set(QtCore_COMPILER_NAME "android")
    set(ANDROID_ABIS "armeabi-v7a")
    #set(ANDROID_ABIS "arm64-v8a")
    set(ANDROID_ARM_NEON "ON")
endif()

######################################################################### 

######## BETWEEN THIS LINES (1/2) NO MODIFICATIONS SHOULD BE NECESSARY ##

#########################################################################

set(Qt_DIR_GLOBAL "${QtCore_DIRECTORY}/${QtCore_VERSION}")
set(Qt_DIR_COMPILER "${Qt_DIR_GLOBAL}/${QtCore_COMPILER_NAME}")

set(CMAKE_MODULE_PATH "${Qt_DIR_GLOBAL}")
set(CMAKE_PREFIX_PATH "${Qt_DIR_COMPILER}")  

######################################################################### 

######## BETWEEN THIS LINES (2/2) NO MODIFICATIONS SHOULD BE NECESSARY ##

#########################################################################

message(STATUS "    QtCore_DIRECTORY  = ${QtCore_DIRECTORY}")
message(STATUS "    QtCore_RELEASE = ${QtCore_RELEASE}")
message(STATUS "    QtCore_VERSION = ${QtCore_VERSION}") 
message(STATUS "    QtCore_COMPILER_NAME = ${QtCore_COMPILER_NAME}" )
message(STATUS "    Qt_DIR_GLOBAL = ${Qt_DIR_GLOBAL}" )
message(STATUS "    Qt_DIR_COMPILER = ${Qt_DIR_COMPILER}" )

message(STATUS "")
message(STATUS "")
message(STATUS "------- WARNING !! -------")
message(STATUS "------- IF NOT BUILD SUCCESFULLY MODIFY THIS VARIABLES IN CMAKELISTS -------")
message(STATUS "")
message(STATUS "    QtCore_DIRECTORY = ${QtCore_DIRECTORY}")
message(STATUS "    QtCore_RELEASE = ${QtCore_RELEASE}")
message(STATUS "    QtCore_VERSION = ${QtCore_VERSION}") 
message(STATUS "    QtCore_COMPILER_NAME = ${QtCore_COMPILER_NAME}" )
message(STATUS "    Qt_DIR_GLOBAL = ${Qt_DIR_GLOBAL}" )
message(STATUS "    Qt_DIR_COMPILER = ${Qt_DIR_COMPILER}" )
if(ANDROID)
message(STATUS "    ANDROID_ABIS = ${ANDROID_ABIS}" )
message(STATUS "    ANDROID_ARM_NEON = ${ANDROID_ARM_NEON}" )
endif()
message(STATUS "")
message(STATUS "------- END WARNING !! -------")

message(STATUS "")
message(STATUS "")

message(STATUS "--------------------------------")

find_package(Qt${QtCore_RELEASE} REQUIRED COMPONENTS Qml Quick Widgets)

if(LINUX)
include_directories(${Qt5_DIR}/gcc_64/include/)
include_directories(${Qt5_DIR}/gcc_64/include/QtWidgets)
include_directories(./)
endif()

qt6_add_resources(RESOURCES ./qml.qrc)

if(ANDROID)
    add_library(Hello SHARED
            main.cpp
            ${RESOURCES})
else()
add_executable(Hello
        main.cpp
        ${RESOURCES})
endif()

if(LINUX)
    target_link_libraries(Hello Qt${QtCore_RELEASE}::Quick Qt${QtCore_RELEASE}::Qml Qt${QtCore_RELEASE}::Widgets)
endif()

if(ANDROID)
    target_link_libraries(Hello Qt${QtCore_RELEASE}::Quick Qt${QtCore_RELEASE}::Qml Qt${QtCore_RELEASE}::Widgets)
endif()

if(WIN)
target_link_libraries(Hello Qt${QtCore_RELEASE}::Quick Qt${QtCore_RELEASE}::Qml Qt${QtCore_RELEASE}::Widgets)
endif()