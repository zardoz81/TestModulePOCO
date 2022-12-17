cmake_minimum_required(VERSION 3.23)
project(ExampleModule)

add_library(ExampleModule SHARED src/EMModule.cpp ../sdk/BaseModule.cpp)
target_link_libraries(ExampleModule ${CONAN_LIBS})
