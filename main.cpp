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



int main()
{
    sf::RenderWindow window(sf::VideoMode(W, H), "SFML SNAKE");
    window.setFramerateLimit(frameRate);


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


    Snake snake(W/2, H/2, blockSize, blockSize);

    Head H_1(W/2, H/2, blockSize, blockSize);

    int w = W;
    int h = H;



    int possibleValues = (W - 0) / blockSize;


    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int randomX = (std::rand() % possibleValues) * blockSize;
    int randomY = (std::rand() % possibleValues) * blockSize;


    Food* F = new Food(randomX, randomY);

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


        snake.update();

        H_1.update();
        
        // Tymczasowa funkcja do sprawdzania kolizji węża z samym sobą
        // wyświetla biały kwadrat na chwilę
        if(snake.isColidingWithItself())     
        {
            sf::Text text;
            sf::Font font;

            sf::RectangleShape shape;

            shape.setSize(sf::Vector2f{W/2, H/2});

            sf::Time t1 = sf::seconds(10);

            window.draw(text);
            window.draw(shape);
            window.display();

        }


        // Funkcja do sprawdzania kolizji z jedzeniem
        if(snake.isColidingWithFood(*F))                                                         // Jeśli wąż koliduje z jedzeniem dodaj punkt wygeneruj nowe wsp 
        {                                                                                        // jedzenia i zwiększ długość węża (linijka 150)
            scoreInt++; 
            score.setString("SCORE: " + std::to_string(scoreInt));

            randomX = (std::rand() % possibleValues) * blockSize;
            randomY = (std::rand() % possibleValues) * blockSize;


            sf::Vector2f foodNewPosition = {float(randomX), float(randomY)};


            if(snake.isFoodColidingWithSnake(foodNewPosition))                                   // Jeśli nowe współrzędne jedzenia wygenerują się na ciele węża
            {                                                                                    // to generuj nowe do momentu aż tak nie będzie

                do
                {
                    std::srand(static_cast<unsigned int>(std::time(nullptr)));
                    randomX = (std::rand() % possibleValues) * blockSize;
                    randomY = (std::rand() % possibleValues) * blockSize;

                    sf::Vector2f foodNewPosition = {float(randomX), float(randomY)};
                    
                    (*F) = Food(randomX, randomY);

                    std::cout << "Nowa pozycja" << std::endl;
                    std::cout << "N:" << randomX << " " << randomY << std::endl;

                }
                while(!snake.isFoodColidingWithSnake(foodNewPosition));


            }
            else                                                                               // Jeśli współrzędne jedzenia nie kolidują z wężem zmień wartości w 
            {                                                                                  // dotychczasowej pozycji
                (*F) = Food(randomX, randomY);
            }

            snake.grow();
        }
    

        window.draw(snake);
        window.draw(score);
        snake.checkPosition();

        window.draw(*F);

        window.display();

    }

    
}