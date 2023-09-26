#include "snake_logic/Food.h"


Food::Food(float x, float y)
{
    getShape().setFillColor(game_setup::color_4);
    getShape().setPosition(x , y);
    getShape().setSize(sf::Vector2f{blockSize, blockSize});
    getShape().setOutlineThickness(-1);
    getShape().setOutlineColor(game_setup::color_5);
}

Food::Food(float x, float y, float width, float height) : Block(x, y, width, height)
{
    getShape().setFillColor(sf::Color::Black);

};