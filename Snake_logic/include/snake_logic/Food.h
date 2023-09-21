#pragma once
#include <SFML/Graphics.hpp>
#include "Block.h"
// #include "Snake.h"
#include "game_setup.h"

using namespace game_setup;

class Food : public Block
{
    private:

    // virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;

    public:
    Food(){};
    Food(float x, float y);
    Food(float x, float y, float width, float height);
    // bool isColidingWithSnake(Snake);
    void update();
    ~Food() = default;



};