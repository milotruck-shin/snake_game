#ifndef SNAKE_HPP
#define SNAKE_HPP
#include "raylib.h"
#include "constant.hpp"

#include <deque>
class Snake{
public:
    Snake();
    void Draw();
    void Update();
    void Reset();
    static bool addSegment;
    Vector2 direction;
    std::deque<Vector2> body;
private:

};

#endif