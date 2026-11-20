#include "food.hpp"
#include "constant.hpp"
#include <raymath.h>
#include "utils.hpp"

Food::Food(std::deque<Vector2> snakeBody){
    Image image = LoadImage("C:/Users/Ji Shin/Desktop/coding/snake game/src/Graphics/food.png");
    texture=LoadTextureFromImage(image);
    UnloadImage(image);
    position = GenerateRandomPos(snakeBody);
}

Food::~Food(){
    UnloadTexture(texture);
}

void Food::Draw(){
    DrawTexture(texture, offset+position.x * cellSize, offset+position.y * cellSize, WHITE);
}

Vector2 Food::GenerateRandomCell(){
    float x = GetRandomValue(0,cellCount-1);
    float y = GetRandomValue(0,cellCount-1);
    return Vector2(x,y);    
}

Vector2 Food::GenerateRandomPos(std::deque<Vector2> snakeBody){
    Vector2 position=GenerateRandomCell();
    
    while(Utils::ElementInDeque(position,snakeBody)){
        position=GenerateRandomCell();
    }
    return position;
}