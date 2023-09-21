cmake_minimum_required(VERSION 3.0.0)

project(Snake VERSION 1.0.0)


add_subdirectory(Snake_logic)



add_executable(Snake 
main.cpp)



target_link_libraries(Snake PUBLIC snake_logic)






target_include_directories(Snake PRIVATE /home/jarek/SFML-2.6.0/include)

target_link_libraries(Snake PRIVATE
    /home/jarek/SFML-2.6.0/lib/libsfml-graphics.so
    /home/jarek/SFML-2.6.0/lib/libsfml-window.so
    /home/jarek/SFML-2.6.0/lib/libsfml-system.so
)



