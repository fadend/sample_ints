# Copied from code provided by Gemini.

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(googletest)

add_executable(unit_tests int_sampler_test.cc)

target_include_directories(sample_ints
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(unit_tests PRIVATE GTest::gtest
    GTest::gmock GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(unit_tests)