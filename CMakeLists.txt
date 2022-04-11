#Build script of ModPlug Player API
#Copyright (C) 2022 Volkan Orhan

#This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.

#This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

#You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

cmake_minimum_required(VERSION 3.5)

project(ModPlugPlayerAPI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

file(GLOB MODPLUGPLAYERAPI_SRC
    "src/*.hpp"
    "src/*.cpp"
    "src/*.ui"
)

file(GLOB MODPLUGPLAYERAPI_TEST
    "test/*.hpp"
    "test/*.cpp"
    "test/*.ui"
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ModPlugPlayerAPI
        MANUAL_FINALIZATION
        ${MODPLUGPLAYERAPI_SRC}
        ${MODPLUGPLAYERAPI_TEST}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ModPlugPlayerAPI APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ModPlugPlayerAPI SHARED
            ${MODPLUGPLAYERAPI_SRC}
            ${MODPLUGPLAYERAPI_TEST}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ModPlugPlayerAPI
            ${MODPLUGPLAYERAPI_SRC}
            ${MODPLUGPLAYERAPI_TEST}
        )
    endif()
endif()

include_directories(src)
include_directories(test)

target_link_libraries(ModPlugPlayerAPI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_compile_definitions(ModPlugPlayerAPI PRIVATE UNTITLED32_LIBRARY)

set_target_properties(ModPlugPlayerAPI PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ModPlugPlayerAPI)
endif()

