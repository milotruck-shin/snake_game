#include <iostream>
#include <raylib.h>
#include "constant.hpp"
#include "food.hpp"
#include "snake.hpp"
#include "event.hpp"


int main(){

    std::cout<<"Starting the game..."<<std::endl;
    InitWindow(2*offset + cellSize * cellCount, 2*offset + cellSize * cellCount,"Retro Snake");
    SetTargetFPS(60); //sets 60fps
    Game game;

    while(WindowShouldClose()==false)
    {
        BeginDrawing();
        if(game.eventTriggered(0.2)){
            game.Update();
        }

        game.UserCtrl(game.snake);
        game.Draw();

        ClearBackground(green);
        DrawRectangleLinesEx(Rectangle{(float)offset-5,(float)offset-5,(float)cellSize*cellCount+10,(float)cellSize*cellCount+10},5,darkGreen);
        DrawText("Retro Snake",offset-5,20,40,darkGreen);
        DrawText(TextFormat("%i",game.score),offset+cellSize*cellCount-10,20,40,darkGreen);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}