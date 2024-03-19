cmake_minimum_required(VERSION 3.25)


project(CopilotIntro)


set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})
# Include Conan script
include(cmake/conan.cmake)

# Detect if we are in a conan environment
if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    # Setup Conan
    conan_cmake_run(CONANFILE conanfile.txt
                    BASIC_SETUP CMAKE_TARGETS
                    BUILD missing)
endif()


find_package(nlohmann_json REQUIRED)

add_library(MyLib STATIC src/settings.cpp src/settings.h)
target_link_libraries(MyLib PRIVATE nlohmann_json::nlohmann_json)

add_executable(test src/main.cpp)
target_link_libraries(test PRIVATE MyLib)