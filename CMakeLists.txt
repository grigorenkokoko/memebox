cmake_minimum_required(VERSION 3.20)
project(server_memebox)

find_package(Boost 1.40.0 REQUIRED system)
find_package(Boost COMPONENTS log log_setup REQUIRED)
link_directories(${Boost_LIBRARY_DIR})

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")

set(PQXX /usr/local/include/pqxx)

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

include_directories(include)

add_executable(server_memebox src/server_memebox.cpp src/connection.cpp src/response.cpp src/base64.cpp)

target_link_libraries(server_memebox boost_thread pthread ${BOOST_LIBRARIES} ${PQXX_LIB} ${PQ_LIB})