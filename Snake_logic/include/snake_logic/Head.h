#pragma once
#include <SFML/Graphics.hpp>
#include "game_setup.h"
#include "Block.h"

using namespace game_setup;

class Head : public Block
{   
    private:

    // int positionX;
    // int positionY;

    std::vector<Head> elements;
    // sf::Vector2f direction;
    

    float moveX {blockSize};
    float moveY {0};

    // sf::Clock clk;

    sf::Clock clk;

    float deltaTime = 0.0f;
    float totalTime = 0.0f;
    float moveSpeed = 500.0f;
    // float deltaTime = 0.0f;
    // float totalTime = 0.0f;
    // const float moveSpeed = 500.0f;
    

    sf::Vector2f moveVector{moveX, moveY};
    // virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;
    
    public:

    Head(){};
    Head(float x, float y, float width, float height);

    void setBlockPosition(float x, float y);

    void checkPosition();
    // Head() = delete;
    ~Head() = default;
    //virtual ~Head() = default;

    void update();

    sf::Vector2f getDirection();
};