#pragma once
#include <deque>
#include "raylib.h"
#include "raymath.h"

namespace Utils{
    inline bool ElementInDeque(Vector2 element, std::deque<Vector2> deque){
    for(const auto& item:deque){
        if(Vector2Equals(item,element)){
            return true;
        }
    }
    return false;
}

}
