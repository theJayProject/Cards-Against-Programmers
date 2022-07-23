cmake_minimum_required(VERSION 3.20.2)
include(FetchContent)
project(Cards_Against_Programmers)

set(CMAKE_CXX_STANDARD 20)
set(SFML_VERSION "2.5.1")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

FetchContent_Declare(
        sfml
        GIT_REPOSITORY  https://github.com/SFML/SFML.git
        GIT_TAG         ${SFML_VERSION}
)

FetchContent_MakeAvailable(sfml)

add_executable(Cards_Against_Programmers main.cpp Game.h Game.cpp Player.h Player.cpp)
target_link_libraries(Cards_Against_Programmers PRIVATE sfml-graphics sfml-audio sfml-network sfml-window sfml-system)
target_compile_options(Cards_Against_Programmers PRIVATE -Wall)

