cmake_minimum_required(VERSION 3.20)
project(client_memebox)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost 1.40.0 REQUIRED system)
find_package(Boost COMPONENTS log log_setup REQUIRED)
link_directories(${Boost_LIBRARY_DIR})

include_directories(include)

add_executable(client_memebox include/client_memebox.h src/client_memebox.cpp src/request.cpp)

target_link_libraries(client_memebox boost_thread pthread ${BOOST_LIBRARIES})
