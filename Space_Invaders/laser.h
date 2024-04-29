#ifndef LASER_H_INCLUDED
#define LASER_H_INCLUDED
#pragma once
#include <raylib.h>


class Laser{
    public:
        ///CONSTRUCTOR///
        Laser(Vector2 position, int speed);///AGREGAMOS POSICION Y VELOCIDAD AL LASER///
        void update();
        void draw();
        bool active;
    private:
        Vector2 position;
        int speed;

};

#endif // LASER_H_INCLUDED
