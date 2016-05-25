# Build TestList
add_executable(TestList
  List.hpp
  TestList.cpp
  vec2.cpp
  circle.cpp)
target_link_libraries(TestList
  m)