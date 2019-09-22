cmake_minimum_required(VERSION 3.5)

project(comparator_generator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCES sort_by.cpp)
set(HEADERS airline_ticket.h test_runner.h)

add_executable(comparator_generator ${SOURCES} ${HEADERS})
