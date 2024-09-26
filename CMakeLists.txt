cmake_minimum_required(VERSION 3.10)
project(NearestPoints LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_TESTS "Build test executable" ON)

set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(LIBRARY_SOURCES
    ${SOURCE_DIR}/GeometryObjects.cpp
    ${SOURCE_DIR}/3DMathOperations.cpp
    ${SOURCE_DIR}/NearestPointsAlgorithm.cpp
)

add_library(${BINARY}-lib ${LIBRARY_SOURCES})
set_target_properties(${BINARY}-lib PROPERTIES PREFIX "")
target_include_directories(${BINARY}-lib PUBLIC ${INCLUDE_DIR} ${CMAKE_BINARY_DIR}/include)

add_executable(${BINARY} ${SOURCE_DIR}/main.cpp)
target_link_libraries(${BINARY} PRIVATE ${BINARY}-lib)

if (BUILD_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory(test)
endif (BUILD_TESTS)