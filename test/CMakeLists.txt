# Download GoogleTest Testing Framework
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  )

# For Windows: Prevent overriding the parent project's compiler/linker settings
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

enable_testing()

add_executable(
  CDS_Arr_test
  CDS_Arr_test.cpp
)

target_link_libraries(
  CDS_Arr_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(CDS_Arr_test)

