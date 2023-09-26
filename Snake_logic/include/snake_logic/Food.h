#pragma once
#include <SFML/Graphics.hpp>
#include "Block.h"
// #include "Snake.h"
#include "game_setup.h"

using namespace game_setup;

class Food : public Block
{
    private:

    public:
    Food(){};
    Food(float x, float y);
    Food(float x, float y, float width, float height);
    void update();
    ~Food() = default;



};