add_library(snake_logic 
src/Block.cpp 
src/Food.cpp 
src/Head.cpp 
src/Snake.cpp)

# Dodanie folderu include
include_directories(/opt/homebrew/include)
target_include_directories(snake_logic PUBLIC include)