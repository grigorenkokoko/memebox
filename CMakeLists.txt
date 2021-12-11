cmake_minimum_required(VERSION 3.20)

project(memebox_data_base)

set(CMAKE_CXX_STANDARD 17)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")

set(PQXX /usr/local/include/pqxx)

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

add_executable(memebox_data_base main.cpp)

target_link_libraries(memebox_data_base  ${PQXX_LIB} ${PQ_LIB})
