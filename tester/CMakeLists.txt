cmake_minimum_required(VERSION 3.23)
project(Tester)

add_executable(Tester src/main.cpp)
target_link_libraries(Tester ${CONAN_LIBS})
