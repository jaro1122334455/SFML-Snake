#include "snake_logic/Snake.h"
// #include "Head.h"
#include <iostream>
#include <algorithm>



Snake::Snake(float x, float y, float width, float height) : Head(x, y, width, height)
{
    // Head partOne (W/2, H/2, blockSize, blockSize);
    Head partOne (x, y, width, height);
    Head partTwo (W/2 - blockSize, H/2, blockSize, blockSize);

    
    Head partThree(W/2 - (2 * blockSize), H/2, blockSize, blockSize);
    // Head partFour(W/2 - (3 * blockSize), H/2, blockSize, blockSize);

    // Head partFive(W/2 - (4 * blockSize), H/2, blockSize, blockSize);
    // Head partSix(W/2 - (5 * blockSize), H/2, blockSize, blockSize);



    // Head partFive(W/2 - (4 * blockSize), H/2, blockSize, blockSize);


    // // this->elements.push_back(partOne);
    // // this->elements.push_back(partTwo);

    // this->snakeElements.push_front(partThree);
    // this->snakeElements.push_front(partFour);

    // this->elements.push_back(partThree);
    
    // tail_[0] = partOne;
    // tail_.push_back(partFour);
    // tail_.push_back(partThree);
    // tail_.push_back(partTwo);
    // tail_.push_back(partOne);

    tail_.push_back(partOne);
    tail_.push_back(partTwo);
    tail_.push_back(partThree);
    // tail_.push_back(partFour);
    // tail_.push_back(partFive);
    // tail_.push_back(partSix);

    // tail_.at(0) = partOne;

    // tail_.emplace_back(x, y, width, height);

    // tail[0]= partOne;
    // tail[1] = partTwo;
    // tail[2] = partThree;
    // tail[3] = partFour;
    // tail[4] = partFive;

    
    

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
    // std::cout << "Snake update" << std::endl;

    // for(auto& element : snakeElements)
    // {
    //     element.update();
    // }

    // tail[0].update();
    
    
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

    // std::cout << "Position 0: " << tail_.at(0).getShape().getPosition().x << " " << tail_.at(0).getShape().getPosition().y  << std::endl;
    // std::cout << "Position 1: " << tail_.at(1).getShape().getPosition().x << " " << tail_.at(1).getShape().getPosition().y  << std::endl;
    // std::cout << "Position 2: " << tail_.at(2).getShape().getPosition().x << " " << tail_.at(2).getShape().getPosition().y  << std::endl;
    // std::cout << "Position 3: " << tail_.at(3).getShape().getPosition().x << " " << tail_.at(3).getShape().getPosition().y  << std::endl;
    // std::cout << "Position 1: " << tail_.at(2).getBlockPosition().x << " " << tail_.at(2).getBlockPosition().y << std::endl;

    // std::cout << "size: " << tail_.size() << std::endl;

    // tail_.front().update();

    // tail[1].update();

    // tail_.at(0).update();


    // int i = tail_.size() - 1;






    // int i = tail_.size() - 1;

    // std::cout << "tail: " << tail_.size() << std::endl;

    // int i = tail_.size() - 1;

    // std::cout << tail_.size() << std::endl;


    

    
    



    // while(i != 0)
    // {
    //     std::list<Head>::iterator it = tail_.end();
    //     // std::advance(it, i);
    //     std::list<Head>::iterator it_2 = tail_.end();
    //     std::advance(it_2, i - 1);

    //     it = it_2;
    //     i--;
    // }

    // // tail_[0].update();

    // tail_.front().update();
        

    

    // for(int i = total - 1; i <= 0; i--)
    // {
    //     // auto prev = tail[i + 1];
    //     // auto temp = tail[i];

    //     while(i == 0)
    //     {
    //         tail[i] = tail[i - 1];
    //     }
        
    


    //     // tail[i] = prev;

    //     // prev = temp;
        
    //     // tail[i] = prev;
    //     // prev.update();

    //     if(i == 0)
    //     {
    //         tail[i].update();
    //     }
        
    // }


    // tail[0].update();
    // for(int i = 0; i < total - 1; i++)
    // {
    //     // auto he = tail[i];

    //     // tail[i] = tail[i + 1];

    //     // he.update();
    //     tail[i].update();
        
    // }

    // for(auto& element : tail)
    // {
    //     element.update();
    //     // element.
    // }
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
        // delete f;
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
            // std::cout << "Position H: " << tail_.at(0).getShape().getPosition().x << " " << tail_.at(0).getShape().getPosition().y  << std::endl;
            // std::cout << "Position 0: " << (*it).getShape().getPosition().x << " " << (*it).getShape().getPosition().y  << std::endl;

            return true;

        }
    }

    return false;
}

bool Snake::isFoodColidingWithSnake(sf::Vector2f foodPosition)
{
    // auto foodPosition = F.getShape().getPosition();

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

// void Snake::update()
// {
//     // for(int i = 0; i < total - 1; i++)
//     // {
//     //     tail[i] = tail[i - 1];
//     // } 

//     this->shape.move(this->moveVector);


//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && moveVector.x > -blockSize)
//     {
//         moveVector.y = 0;
//         moveVector.x = blockSize;

//         // return sf::Vector2f(moveVector.x, moveVector.y);

//     }

//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && moveVector.x < blockSize)
//     {
//         moveVector.y = 0;
//         moveVector.x = -blockSize;

//         // return sf::Vector2f(moveVector.x, moveVector.y);

//     }

//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && moveVector.y < blockSize)
//     {
//         moveVector.y = -blockSize;
//         moveVector.x = 0;

//         // return sf::Vector2f(moveVector.x, moveVector.y);

//     }

//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && moveVector.y > -blockSize)
//     {   
//         moveVector.y = blockSize;
//         moveVector.x = 0;

//         // return sf::Vector2f(moveVector.x, moveVector.y);

//     }

//     // return sf::Vector2f(0, 0);
// }

// void Snake::update_3()
// {

//     elements.front().update();
//     //std::cout << elements.front().shape.getPosition().x << " " << elements.front().shape.getPosition().y << std::endl;

//     sf::Vector2f headPosition = elements.at(0).shape.getPosition();
    

//     //elements.front().update();

//     //sf::Vector2f temp1 = elements.front().getDirection();

//     //std::vector<Head>::iterator it;

//     for(std::vector<Head>::iterator iter = (elements.begin() + 1); iter != elements.end(); iter++)
//     {                        
//                                                                     //jeśli głowa porusza się w:
//         if(elements.at(0).getDirection() == sf::Vector2f(50, 0))    //prawo
//         {
//             (*iter).shape.move(sf::Vector2f(50, 0));

//             /*if(elements.at(1).shape.getPosition().x == headPosition.x && elements.at(1).shape.getPosition().y == headPosition.y)
//             {
//                 std::cout << "test" << std::endl;
//             }*/
//             break;

//         }

//         if(elements.at(0).getDirection() == sf::Vector2f(-50, 0))    //lewo
//         {
//             (*iter).shape.move(sf::Vector2f(-50, 0));
//         }

//         if(elements.at(0).getDirection() == sf::Vector2f(0, 50))     //dół
//         {   

//             /*while((*iter).shape.getPosition() == elements.at(0).shape.getPosition())
//             {
//                 (*iter).shape.move(sf::Vector2f(50, 0));
//                 std::cout << "test" << std::endl;
//             }*/
//             (*iter).shape.move(sf::Vector2f(50, 0));
//             break;

//             //(*iter).shape.move(sf::Vector2f(0, 50));
//         }

//         if(elements.at(0).getDirection() == sf::Vector2f(0, -50))     //góra
//         {
//             (*iter).shape.move(sf::Vector2f(0, -50));
//         }


//     }



// }