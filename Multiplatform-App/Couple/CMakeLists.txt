cmake_minimum_required(VERSION 3.1.0)

project(Couple)

set(PROJECT_NAME "Couple") 

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

if(MACOS)
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
    set(Qt5Core_VERSION "5.15.2")
    set(Qt5_DIR "~/Qt/${Qt5Core_VERSION}")
    set(CMAKE_MODULE_PATH "${Qt5_DIR}")
    set(CMAKE_PREFIX_PATH "${Qt5_DIR}/gcc_64/lib/cmake/Qt5")

    message(STATUS "    CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
    message(STATUS "    QML_IMPORT_PATH: ${QML_IMPORT_PATH}")
endif()

if(WIN)
    set(CMAKE_PREFIX_PATH "D:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5")
    set(Qt5_DIR "D:/Qt/5.15.2/mingw81_64/bin")
    set(Qt5Core_VERSION "5.15")
    set(Qt5Qml_DIR "D:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5Qml")
    set(Qt5Core_DIR "D:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5Core")
    set(Qt5Quick_DIR "D:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5Quick")
    set(Qt5Widgets_DIR "D:/Qt/5.15.2/mingw81_64/lib/cmake/Qt5Widgets") 
endif()

if(MACOS)
set(Qt_DIR "/Users/gadominguez/Qt")
set(Qt_Version "6.5.0")
set(CMAKE_PREFIX_PATH "${Qt_DIR}/${Qt_Version}/macos/lib/cmake/Qt6")
endif()

message(STATUS "    CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

if(ANDROID)
    set(ANDROID_ABIS "armeabi-v7a")
    #set(ANDROID_ABIS "arm64-v8a")
    set(ANDROID_ARM_NEON "ON")
    set(Qt5Core_VERSION "5.15")
    set(CMAKE_MODULE_PATH "~/Qt/5.15.2")
    set(CMAKE_PREFIX_PATH "~/Qt/5.15.2/android/lib/cmake/Qt5")
    set(Qt5_DIR "~/Qt/5.15.2/android/lib/cmake/Qt5")
    set(Qt5Qml_DIR "~/Qt/5.15.2/android/lib/cmake/Qt5Qml")
    set(Qt5Core_DIR "~/Qt/5.15.2/android/lib/cmake/Qt5Core")
    set(Qt5Quick_DIR "~/Qt/5.15.2/android/lib/cmake/Qt5Quick")
    set(Qt5Widgets_DIR "~/Qt/5.15.2/android/lib/cmake/Qt5Widgets")
endif()

find_package(Qt6 REQUIRED COMPONENTS Qml Quick Widgets Sql)

 message(STATUS "--------------------------------")

if(LINUX)
include_directories(${Qt5_DIR}/gcc_64/include/)
include_directories(${Qt5_DIR}/gcc_64/include/QtWidgets)
include_directories(./)
endif()

if(MACOS)
include_directories(${Qt_DIR}/${Qt_Version})
set(MYSQL_CONNECTOR_CPP_DIR "/usr/local/mysql-cxx-arm")
set(MYSQL_CONNECTOR_CPP_INCLUDE_DIR "${MYSQL_CONNECTOR_CPP_DIR}/include")
set(MYSQL_CONNECTOR_CPP_LIB_DIR "${MYSQL_CONNECTOR_CPP_DIR}/lib64")
include_directories(${MYSQL_CONNECTOR_CPP_INCLUDE_DIR})
link_directories(${MYSQL_CONNECTOR_CPP_LIB_DIR})
endif()

qt6_add_resources(RESOURCES ./qml.qrc)

if(ANDROID)
    add_library(${PROJECT_NAME} SHARED
            main.cpp
            ${RESOURCES})
else()
add_executable(${PROJECT_NAME}
        main.cpp
        ${RESOURCES})
endif()

if(LINUX)
    target_link_libraries(${PROJECT_NAME} Qt::Quick Qt::Qml Qt::Widgets)
endif()

if(ANDROID)
    target_link_libraries(${PROJECT_NAME} Qt::Quick Qt::Qml Qt::Widgets)
endif()


if(WIN)
target_link_libraries(${PROJECT_NAME} Qt::Quick Qt::Qml Qt::Widgets)
endif()


if(MACOS)
target_link_libraries(${PROJECT_NAME} Qt::Quick Qt::Qml Qt::Widgets Qt::Sql mysqlcppconn mysqlcppconn8)
set_target_properties(${PROJECT_NAME}  PROPERTIES
MACOSX_BUNDLE FALSE)
endif()