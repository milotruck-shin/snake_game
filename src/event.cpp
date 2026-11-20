#include "event.hpp"
#include "raylib.h"
#include <raymath.h>
#include <iostream>
#include "utils.hpp"

int Game::score=0;
bool running = true;
double lastUpdateTime = 0;

void Game::Draw(){
    food.Draw();
    snake.Draw();
}

void Game::Update(){
    if(running){
        snake.Update();
        CheckCollisionWithFood();
        CheckCollisionWithEdges();
        CheckCollisionWithTail();
    }

}

bool Game::eventTriggered(double interval){
    double currentTime = GetTime();  //get elapsed time in seconds since InitWindow()
    if(currentTime-lastUpdateTime>=interval){
        lastUpdateTime = currentTime;
        return true;
    } else {
        return false;
    }
}

void Game::UserCtrl(Snake& snake){
    if(IsKeyPressed(KEY_UP)&&snake.direction.y!=1){
        snake.direction = {0,-1};
        running = true;
    }
    else if(IsKeyPressed(KEY_DOWN)&&snake.direction.y!=-1){
        snake.direction = {0,1};
        running = true;

    }
    else if(IsKeyPressed(KEY_LEFT)&&snake.direction.x!=1){
        snake.direction = {-1,0};
        running = true;

    }
    else if(IsKeyPressed(KEY_RIGHT)&&snake.direction.x!=-1){
        snake.direction = {1,0};
        running = true;

    }
}

void Game::CheckCollisionWithFood(){
    if(Vector2Equals(snake.body[0],food.position)){
        food.position = food.GenerateRandomPos(snake.body);
        snake.addSegment = true;
        score++;
    }
}

void Game::CheckCollisionWithEdges(){
    if(snake.body[0].x==cellCount||snake.body[0].x==-1){
        GameOver();
    }
    if(snake.body[0].y==cellCount||snake.body[0].y==-1){
        GameOver();
    }
}

void Game::CheckCollisionWithTail(){
    std::deque<Vector2> headlessBody = snake.body;
    headlessBody.pop_front();
    if(Utils::ElementInDeque(snake.body[0], headlessBody)){
        GameOver();
    }
}

bool Game::ElementInDeque(Vector2 element, std::deque<Vector2> deque){
    for(unsigned int i=0;i<deque.size();i++){
        if(Vector2Equals(deque[i],element)){
            return true;
        }
    }
    return false;
}

void Game::GameOver(){
    snake.Reset();
    food.position=food.GenerateRandomPos(snake.body);
    running = false;
    score=0;

}