cmake_minimum_required(VERSION 3.5.0)

project(Snake)

# Wymuś C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(Snake_logic)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window Audio Network)

if(SFML_FOUND)
    message(STATUS "SFML found")
    # include_directories(/opt/homebrew/include)
    add_executable(${PROJECT_NAME} main.cpp)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::Audio
        SFML::Network
    )
else()
    message(FATAL_ERROR "SFML not found")
endif()

set(SOURCES main.cpp)


# add_executable(Snake 
# ${SOURCES})



target_link_libraries(Snake PUBLIC snake_logic)
# target_link_libraries(Snake PRIVATE sfml-graphics)


# target_include_directories(Snake PRIVATE /home/jarek/SFML-2.6.0/include)

# target_link_libraries(Snake PRIVATE
#     /home/jarek/SFML-2.6.0/lib/libsfml-graphics.so
#     /home/jarek/SFML-2.6.0/lib/libsfml-window.so
#     /home/jarek/SFML-2.6.0/lib/libsfml-system.so
# )



# target_include_directories(Snake PRIVATE SFML-2.6.0/include)


# target_link_libraries(Snake PRIVATE
#     SFML-2.6.0/lib/libsfml-graphics.so
#     SFML-2.6.0/lib/libsfml-window.so
#     SFML-2.6.0/lib/libsfml-system.so
# )



