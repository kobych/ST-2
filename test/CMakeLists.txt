add_executable(${PROJECT_NAME}.test
  AllTests.cpp
  tests.cpp)

target_link_libraries(${PROJECT_NAME}.test
  ${PROJECT_NAME} gtest gtest_main pthread)

target_compile_definitions(${PROJECT_NAME}.test 
  PRIVATE TEST_DIR="${CMAKE_CURRENT_LIST_DIR}")

target_include_directories(${PROJECT_NAME}.test
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)

install(TARGETS ${PROJECT_NAME}.test
        DESTINATION "${tool_dest}")
