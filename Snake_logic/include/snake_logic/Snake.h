#pragma once
#include <SFML/Graphics.hpp>
#include "game_setup.h"
// #include "../Food_dir/include/Food/Food.h"
#include "Head.h"
#include "Food.h"
// #include "Head_dir/Head.h"
// #include "Head.h"
// #include "Food.h"
#include <vector>
#include <list>

using namespace game_setup;

class Snake : public Head
{
    private:

    int total = 1;


    Head tail[1];

    Head h1;
    Head h2;


    std::vector<Head> tail_;
    // std::list<Head> tail_;

    


    std::vector<Head*> elements;
    std::list<Head> snakeElements;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates state) const;
    

    public:

    Snake(float x, float y, float width, float height);
    Snake() = delete;
    ~Snake() = default;

    void update();
    void setBlockPosition(float x, float y);
    std::vector<Head>& getTail();
    void checkPosition();
    void grow();
    bool isColidingWithFood(Food&);
    bool isColidingWithItself();
    bool isFoodColidingWithSnake(sf::Vector2f);


};