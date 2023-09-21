#pragma once
#include <SFML/Graphics.hpp>

class Block : public sf::Drawable
{   
    private:
    
    sf::RectangleShape shape;
    float blockX;
    float blockY;

    sf::Vector2f position{blockX, blockY};

    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;
    
    public:

    Block(){};
    Block(float x, float y, float width, float height);

    // void update();

    sf::RectangleShape& getShape();

    float getBlockX()
    {
        return blockX;
    }

    float getBlockY()
    {
        return blockY;
    }

    void setBlockX(float x)
    {
        this->blockX = x;
    }

    void setBlockY(float y)
    {
        this->blockY = y;
    }

    void setBlockPosition(float x, float y)
    {
        position.x = x;
        position.y = y;
    }

    sf::Vector2f getBlockPosition()
    {
        return position;
    }


    // Block() = delete;
    ~Block() = default;

};