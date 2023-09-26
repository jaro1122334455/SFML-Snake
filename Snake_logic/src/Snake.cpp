#include "snake_logic/Snake.h"
#include <iostream>
#include <algorithm>



Snake::Snake(float x, float y, float width, float height) : Head(x, y, width, height)
{
    Head partOne (x, y, width, height);
    Head partTwo (W/2 - blockSize, H/2, blockSize, blockSize);

    
    Head partThree(W/2 - (2 * blockSize), H/2, blockSize, blockSize);

    tail_.push_back(partOne);
    tail_.push_back(partTwo);
    tail_.push_back(partThree);

};

void Snake::draw(sf::RenderTarget& target, sf::RenderStates state) const                         //target to przesłane okno do wyświetlania (tak jak window.draw())
{
    // pętla do wywoływania funkcji rysowania dla każdego elementu w tablicy
    for(auto& element : this->tail_)
    {
        target.draw(element, state);
    }
}

void Snake::update()
{

    // tail[4] = tail[3];

    // tail[3] = tail[2];

    // tail[2] = tail[1];

    // tail[1] = tail[0];


    
    // tail[0].update();

    // int i = total - 1;

    // while(i != 0)
    // {
    //     tail[i] = tail[i - 1];
    //     i --;
    // }

    // tail[0].update();



    int i = tail_.size() - 1;

    while(i != 0)
    {
        tail_.at(i) = tail_.at(i - 1);
        i --;
    }

    tail_.at(0).update();


}

void Snake::grow()
{
    Head h;
    tail_.push_back(h);
}

bool Snake::isColidingWithFood(Food& f)
{

    if(tail_.at(0).getShape().getPosition() == f.getShape().getPosition())
    {
        return true;
    }

    return false;

}


bool Snake::isColidingWithItself()
{

    for(auto it = tail_.begin() + 1; it != tail_.end(); it++)
    {
        if((*it).getShape().getPosition() == tail_.at(0).getShape().getPosition())
        {
            return true;

        }
    }

    return false;
}

bool Snake::isFoodColidingWithSnake(sf::Vector2f foodPosition)
{

    for(auto& element : tail_)
    {
        if(foodPosition == element.getShape().getPosition())
        {
            return true;
        }
    }

    return false;
}

void Snake::checkPosition()
{
    for(auto& element : tail_)
    {
        element.checkPosition();
    }
}

std::vector<Head>& Snake::getTail()
{
    return this->tail_;
}
