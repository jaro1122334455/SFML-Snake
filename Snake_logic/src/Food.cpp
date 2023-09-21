#include "snake_logic/Food.h"
// #include "Snake.h"


Food::Food(float x, float y)
{
    getShape().setFillColor(sf::Color::Red);
    // setBlockX(x);
    // setBlockY(y);
    getShape().setPosition(x , y);
    getShape().setSize(sf::Vector2f{blockSize, blockSize});
    getShape().setOutlineThickness(-1);
    getShape().setOutlineColor(sf::Color::White);
}

// bool Food::isColidingWithSnake(Snake S)
// {
//     auto foodPosition = this->getShape().getPosition();

//     for(auto& element : S.getTail())
//     {
//         if(foodPosition == element.getShape().getPosition())
//         {
//             return true;
//         }
//     }

//     return false;
// }



Food::Food(float x, float y, float width, float height) : Block(x, y, width, height)
{
    getShape().setFillColor(sf::Color::Black);
    // position.x = x;
    // position.y = y;

    // getShape().setPosition(position);
    
    
    // this->elements.push_back(this);

};