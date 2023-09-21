add_library(snake_logic 
src/Block.cpp 
src/Food.cpp 
src/Head.cpp 
src/Snake.cpp)

# Dodanie folderu include
target_include_directories(snake_logic PUBLIC include)