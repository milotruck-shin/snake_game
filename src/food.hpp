#ifndef FOOD_HPP
#define FOOD_HPP
#include <raylib.h>
#include <deque>

class Food{
public:
    Vector2 position; // 6th column and 7th row with count starting from index 0. Top right corner coordinate system.
    Texture2D texture;

    void Draw();
    Food(std::deque<Vector2> snakeBody);
    ~Food();
    Vector2 GenerateRandomCell();
    Vector2 GenerateRandomPos(std::deque<Vector2> snakeBody);
};

#endif