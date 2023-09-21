#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Snake_logic/include/snake_logic/game_setup.h"
#include <vector>
#include <list>
#include "snake_logic/Block.h"
#include "snake_logic/Head.h"
#include "snake_logic/Snake.h"
#include "snake_logic/Food.h"

using namespace game_setup;

// const int W = 1600;
// const int H = 600;
// const int blockSize = 10;
// const int frame = 10;




int main()
{
    sf::RenderWindow window(sf::VideoMode(W, H), "SFML works!");
    // window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(frameRate);
    /*sf::RectangleShape shape({50, 50});
    shape.setOrigin(25, 25);
    shape.setOutlineThickness(5);
    shape.setOutlineColor(sf::Color::White);
    shape.setPosition(H/2, W/2);
    shape.setFillColor(sf::Color::Green);*/

    std::vector<Block> blocks;

    for(int i = 0; i < (H/blockSize); i++)                         //rysowanie planszy
    {
        for(int j = 0; j < (W/blockSize); j++)
        {
            blocks.emplace_back((j) * (blockSize), (i) * (blockSize), blockSize, blockSize);                                            //Funkcja przyjmuje funkcje konstruktora
        }
    }

    sf::Font f1;
    f1.loadFromFile("../fonts/Arimo_Bold.ttf");



    int scoreInt = 0;
    sf::Text score;
    score.setString("SCORE: " + std::to_string(scoreInt));
    score.setFillColor(sf::Color::White);
    score.setFont(f1);
    score.setCharacterSize(40);
    score.setOrigin(score.getGlobalBounds().width / 2, score.getGlobalBounds().height / 2);
    score.setPosition({W/2, (H/2) * 0.25 });



    //std::list<Head> Snake;

    // int total = 1;
    // Head tail[32];

    // std::list<Head> snakeElementss;


    // Head head_1(W/2, H/2, blockSize, blockSize);
    // Head head_2(W/2 - blockSize, H/2, blockSize, blockSize);

    // snakeElementss.push_front(head_1);
    // snakeElementss.push_front(head_2);
    // Head head2(W/2, H/2, blockSize, blockSize);


    //Snake.push_back(head);
    //Snake.push_back(head2);

    Snake snake(W/2, H/2, blockSize, blockSize);

    Head H_1(W/2, H/2, blockSize, blockSize);

    int w = W;
    int h = H;



    int possibleValues = (W - 0) / blockSize;

    // Food f1(50, 50, blockSize, blockSize);

    Food f2(50, 50);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int randomX = (std::rand() % possibleValues) * blockSize;
    // int randomX = (std::rand() % ((501 - 0) / blockSize)) * blockSize + 0;
    int randomY = (std::rand() % possibleValues) * blockSize;
    // int randomY = (std::rand() % possibleValues) * blockSize;



    Food* F = new Food(randomX, randomY);




    int value = 150;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        for(auto& block : blocks)
        {
            window.draw(block);
        }

        /*for(auto& element : Snake)
        {
            window.draw(element);
            element.update();

        }*/




        snake.update();

        H_1.update();
        

        // std::cout << snake.isColidingWithItself() << std::endl;

        if(snake.isColidingWithItself())
        {
            // sf::RenderWindow window_2(sf::VideoMode(W / 2, H / 2), "SFML test!");
            sf::Text text;
            sf::Font font;

            sf::RectangleShape shape;

            // shape.setPosition(W/2, H/2);
            shape.setSize(sf::Vector2f{W/2, H/2});

            sf::Time t1 = sf::seconds(10);

            
            



            

            // while (window_2.isOpen()) 
            // {
                
            //     sf::Event event2;
            //     while (window_2.pollEvent(event2)) 
            //     {
            //         if (event2.type == sf::Event::Closed) 
            //         {
            //             window_2.close();
            //         }
            //     }

            // }

            // text.setFont(font);
            // text.setString("Przegrana");
            // text.setCharacterSize(50);
            // text.setFillColor(sf::Color::White);

            
            window.draw(text);
            window.draw(shape);
            window.display();

            // sf::sleep(t1);

            // window_2.draw(text);
            // window_2.clear();
            // window_2.display();
        }

        // std::cout << snake.isColidingWithFood(*F) << std::endl;


        if(snake.isColidingWithFood(*F))
        {   
            scoreInt++;
            score.setString("SCORE: " + std::to_string(scoreInt));

            randomX = (std::rand() % possibleValues) * blockSize;
            randomY = (std::rand() % possibleValues) * blockSize;

            // randomX = 475;
            // randomY = 475;

            sf::Vector2f foodNewPosition = {float(randomX), float(randomY)};

            // std::cout << foodNewPosition.x << " " << foodNewPosition.y << std::endl;

            if(snake.isFoodColidingWithSnake(foodNewPosition))
            {
                
                // std::cout << "Blad" << std::endl;

                do
                {
                    std::srand(static_cast<unsigned int>(std::time(nullptr)));
                    randomX = (std::rand() % possibleValues) * blockSize;
                    randomY = (std::rand() % possibleValues) * blockSize;

                    sf::Vector2f foodNewPosition = {float(randomX), float(randomY)};
                    
                    (*F) = Food(randomX, randomY);

                    std::cout << "Nowa pozycja" << std::endl;
                    std::cout << "N:" << randomX << " " << randomY << std::endl;
                    // randomX = 25;
                    // randomY = 25;


                }
                while(!snake.isFoodColidingWithSnake(foodNewPosition));


            }
            else
            {
                (*F) = Food(randomX, randomY);
                // std::cout << "OK" << std::endl;
            }


            // (*F) = Food(randomX, randomY);


            snake.grow();
        }

        

        window.draw(snake);
        window.draw(score);
        snake.checkPosition();
        // H_1.checkPosition();
        // window.draw(H_1);

        // f1.update();

        // window.draw(f1);
        // window.draw(f2);
        window.draw(*F);

        // for(auto& element : snakeElementss)
        // {
        //     window.draw(element.shape);
        //     element.update();
        // }

        
        // window.draw(head_1);
        // head_1.update();
        // window.draw(head2);
        // head2.update();


        window.display();
        // window_2.display();
    }

    
}