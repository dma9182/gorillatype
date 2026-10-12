cmake_minimum_required(VERSION 3.20)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER gcc-14)
set(CMAKE_CXX_COMPILER g++-14)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(gorillatype LANGUAGES CXX)

add_executable(gorillatype
        src/main.cpp
)

include(FetchContent)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG main # or a specific version like v7.0.3
)
FetchContent_MakeAvailable(ftxui)

target_link_libraries(gorillatype PRIVATE
ftxui::component
ftxui::dom
ftxui::screen
)
