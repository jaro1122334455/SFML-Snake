cmake_minimum_required(VERSION 3.0.0)

project(Snake)


add_subdirectory(Snake_logic)




set(SOURCES main.cpp)


add_executable(Snake 
${SOURCES})



target_link_libraries(Snake PUBLIC snake_logic)

    
    

    







target_include_directories(Snake PRIVATE /home/jarek/SFML-2.6.0/include)

target_link_libraries(Snake PRIVATE
    /home/jarek/SFML-2.6.0/lib/libsfml-graphics.so
    /home/jarek/SFML-2.6.0/lib/libsfml-window.so
    /home/jarek/SFML-2.6.0/lib/libsfml-system.so
)



