#ifndef EVENT_HPP
#define EVENT_HPP
#include "snake.hpp"
#include "food.hpp"


class Game{
public:
    Snake snake;
    Food food{snake.body};
    static int score;
    bool eventTriggered(double interval);
    void UserCtrl(Snake& snake);
    void Draw();
    void Update();
    void CheckCollisionWithFood();
    void CheckCollisionWithEdges();
    void CheckCollisionWithTail();
    bool ElementInDeque(Vector2 element, std::deque<Vector2> deque);
    void GameOver();
    void Reset();
private:

};
#endif