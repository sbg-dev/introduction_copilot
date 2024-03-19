cmake_minimum_required(VERSION 3.10)

# set the project name
project(MyProject)

execute_process(COMMAND conan install ${CMAKE_SOURCE_DIR} --install-folder ${CMAKE_BINARY_DIR} -pr=intro_copilot)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) # Include Conan-generated file
conan_basic_setup(TARGETS) 

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_library(MyLibrary src/settings.cpp src/settings.h)
target_link_libraries(MyLibrary CONAN_PKG::nlohmann_json)
target_include_directories(MyLibrary PRIVATE ${CONAN_INCLUDE_DIRS})
add_executable(MyProject src/main.cpp)
target_link_libraries(MyProject MyLibrary)