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
        if(position.y > GetScreenHeight() - 100 || position.y < 25){
            active = false;
        }
    }
}

///DEVOLVEMOS UN RECTANGULO CON EL TAMAÑI Y LA POSICION DEL LASER///
Rectangle Laser::getRect()
{
    Rectangle rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.width = 4;
    rect.height = 15;
    return rect;
}
