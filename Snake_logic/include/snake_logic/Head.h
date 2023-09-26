#pragma once
#include <SFML/Graphics.hpp>
#include "game_setup.h"
#include "Block.h"

using namespace game_setup;

class Head : public Block
{   
    private:

    std::vector<Head> elements;

    float moveX {blockSize};
    float moveY {0};

    sf::Vector2f moveVector{moveX, moveY};

    
    public:

    Head(){};
    Head(float x, float y, float width, float height);

    void setBlockPosition(float x, float y);

    void checkPosition();

    ~Head() = default;


    void update();

    sf::Vector2f getDirection();
};