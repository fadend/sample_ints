cmake_minimum_required(VERSION 4.2)

project(sample_ints)

enable_testing()

add_executable(sample_ints src/sample_ints_main.cc)

target_include_directories(sample_ints
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(tests)