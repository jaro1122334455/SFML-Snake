#include "snake_logic/Block.h"

Block::Block(float x, float y, float width, float height)
{
    blockX = x;
    blockY = y;

    position.x = blockX;
    position.y = blockY;

    shape.setPosition(position);
    shape.setSize(sf::Vector2f{width, height});
    //shape.setOrigin(width/2.f, height/2.f);
    // shape.setFillColor(sf::Color::Green);
    shape.setFillColor(game_setup::color_3);
    shape.setOutlineThickness(0);
    shape.setOutlineColor(sf::Color::White);
}

void Block::draw(sf::RenderTarget& target, sf::RenderStates state) const                         //target to przesłane okno do wyświetlania (tak jak window.draw())
{
    target.draw(this->shape, state);
}

sf::RectangleShape& Block::getShape()
{
    return this->shape;
}