include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG release-1.12.0
)

FetchContent_MakeAvailable(googletest)


set(BINARY ${CMAKE_PROJECT_NAME}_tst)

set(TEST_SOURCES
    3DMathTests.cpp
    GeometryObjectsTests.cpp
    NearestPointsAlgorithmTests.cpp
)

add_executable(${BINARY} test_runner.cpp ${TEST_SOURCES})

target_link_libraries(${BINARY} PRIVATE 
    GTest::gtest_main
    ${CMAKE_PROJECT_NAME}-lib 
)

target_include_directories(${BINARY} PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_test(all_tests ${BINARY})