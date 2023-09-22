// #include "../include/Head.h"
#include "snake_logic/Head.h"
// #include "game_setup.h"
#include <iostream>

// using namespace game_setup;

/*Head::Head(float x, float y, float width, float height)
{
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f{width, height});
    //shape.setOrigin(width/2.f, height/2.f);
    shape.setFillColor(sf::Color::Blue);
    shape.setOutlineThickness(-5);
    shape.setOutlineColor(sf::Color::White);
}*/

Head::Head(float x, float y, float width, float height) : Block(x, y, width, height)
{
    getShape().setFillColor(game_setup::color_1);

    getShape().setOutlineThickness(-1);
    getShape().setOutlineColor(game_setup::color_2);
    // position.x = x;
    // position.y = y;

    // getShape().setPosition(position);

    // this->elements.push_back(this);

};

// void Head::draw(sf::RenderTarget& target, sf::RenderStates state) const                         //target to przesłane okno do wyświetlania (tak jak window.draw())
// {
//     std::cout << "Draw head" << std::endl;


//     target.draw(this->shape, state);

    
//     // for(auto& element : this->elements)
//     // {
//     //     target.draw(element, state);
//     // }
// }


void Head::update()                     //zrobić tu zwracanie vektora zamiast void i wtedy wysyłać ten vector jako argument w klasie snake update
{
    // std::cout << "Head update" << std::endl;



    // deltaTime = clk.restart().asMilliseconds();
    // totalTime += deltaTime;

    // deltaTime = clk.restart().asMilliseconds();

    getShape().move(this->moveVector);

    // std::cout << "deltaTime: " << deltaTime << std::endl;
    // std::cout << "moveSpeed: " << moveSpeed << std::endl;

    // if(totalTime >= 1.0f / moveSpeed)
    // {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && moveVector.x > (-blockSize))
        {
            moveVector.y = 0;
            moveVector.x = blockSize;


        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && moveVector.x < (blockSize))
        {
            moveVector.y = 0;
            moveVector.x = -blockSize;

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && moveVector.y < (blockSize))
        {
            moveVector.y = -blockSize;
            moveVector.x = 0;

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && moveVector.y > (-blockSize))
        {   
            moveVector.y = blockSize;
            moveVector.x = 0;


        }


}

void Head::checkPosition()
{
    float x = 0;
    float y = 0;

    // std::cout << getShape().getPosition().x << " " << getShape().getPosition().y << std::endl;

    if(getShape().getPosition().x > W)                         //prawa krawędź
    {
        // x = getShape().getPosition().x;
        y = getShape().getPosition().y;


        this->getShape().setPosition({0, y});
    }

    if(getShape().getPosition().x < 0)                        //lewa krawędź
    {
        x = W;
        y = getShape().getPosition().y;


        this->getShape().setPosition({x, y});
    }

    if(getShape().getPosition().y > H)                        //dolna krawędź
    {
        x = getShape().getPosition().x;
        y = 0;


        this->getShape().setPosition({x, y});
    }

    if(getShape().getPosition().y < 0)                        //dolna krawędź
    {
        x = getShape().getPosition().x;
        y = H;


        this->getShape().setPosition({x, y});
    }
}


sf::Vector2f Head::getDirection()
{
    
    return sf::Vector2f(this->moveVector.x, this->moveVector.y);


}

