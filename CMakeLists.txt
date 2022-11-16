cmake_minimum_required(VERSION 3.15)
project(ACS_Lab2_Tykhonovskyi_K23_1 VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)

file("GLOB_RECURSE" "SOURCE_FILES" "Sourse/*.cpp")
add_executable(main main.cpp ${SOURCE_FILES})
target_include_directories(main PUBLIC "./Headers")

if(UNIX)
	target_link_libraries(main ncurses)
endif(UNIX)