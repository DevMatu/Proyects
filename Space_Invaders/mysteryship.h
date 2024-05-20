#ifndef MYSTERYSHIP_H_INCLUDED
#define MYSTERYSHIP_H_INCLUDED
#pragma once
#include <raylib.h>

class MysteryShip
{
    public:
        MysteryShip();
        ~MysteryShip();
        void draw();
        void update();
        void spawn();
        bool alive;
        Rectangle getRect();
    private:
        Texture2D imagen;
        Vector2 posicion;
        int speed;
};

#endif // MYSTERYSHIP_H_INCLUDED
