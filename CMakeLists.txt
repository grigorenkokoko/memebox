set(CMAKE_AUTOMOC ON)

cmake_minimum_required(VERSION 3.21)
project(client_cmake)

set(CMAKE_CXX_STANDARD 20)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

find_package(Boost 1.40.0 REQUIRED system)
find_package(Boost COMPONENTS log log_setup REQUIRED)
link_directories(${Boost_LIBRARY_DIR})

find_package(nlohmann_json 3.2.0 REQUIRED)

set(SOURCES src/client_memebox.cpp src/mainwindow.cpp src/registrationwin.cpp src/request.cpp src/scaledpixmap.cpp src/secondwindow.cpp src/base64.cpp)
set(HEADER_FILES include/client_memebox.h include/mainwindow.h include/registrationwin.h src/scaledpixmap.cpp include/secondwindow.h
        include/ui_mainwindow.h include/ui_registrationwin.h include/ui_secondwindow.h include/mainwindow.ui include/registrationwin.ui include/secondwindow.ui
        include/base64.h
        ${Boost_INCLUDE_DIR})

#include_directories(include ${Boost_INCLUDE_DIR})
#aux_source_directory(src SRC)

add_executable(client_cmake src/main.cpp ${SOURCES} ${HEADER_FILES})
target_link_libraries(client_cmake
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        boost_thread
        pthread
        ${BOOST_LIBRARIES}
        nlohmann_json::nlohmann_json
        )

target_include_directories(client_cmake PUBLIC include)
