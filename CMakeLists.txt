cmake_minimum_required(VERSION 3.10)

option(BUILD_SAMPLES ON)

set(PROJECT_NAME stack_and_queue)
project(${PROJECT_NAME})

find_package(OpenMP REQUIRED)
if(OpenMP_CXX_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

include(CTest)
enable_testing()  # defines BUILD_TESTING

set(MP2_TESTS   "test_${PROJECT_NAME}")
set(MP2_CUSTOM_PROJECT "${PROJECT_NAME}")
set(MP2_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# add_subdirectory(include)

if(BUILD_SAMPLES)
	add_subdirectory(samples)
endif()

if(BUILD_TESTING)
    add_subdirectory(gtest)
	add_subdirectory(test)
endif()


# REPORT
message( STATUS "")
message( STATUS "General configuration for ${PROJECT_NAME}")
message( STATUS "======================================")
message( STATUS "")
message( STATUS "   Configuration: ${CMAKE_BUILD_TYPE}")
message( STATUS "")
