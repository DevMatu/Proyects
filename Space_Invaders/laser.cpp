#include "laser.h"
#include <iostream>

///CONSTRUCTOR///
Laser::Laser(Vector2 position, int speed)
{
    this -> position = position;
    this -> speed = speed;
    active = true;
}

///DIBUJAR EL LASER///
void Laser::draw()
{
    if(active){
        DrawRectangle(position.x, position.y, 4, 15, {0,255,0,255});
    }
}

///MOVIMIENTO DEL LASER///
void Laser::update()
{
    position.y += speed;
    if(active){
        if(position.y > GetScreenHeight() || position.y < 0){
            active = false;
        }
    }
}
