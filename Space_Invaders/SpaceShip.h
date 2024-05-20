#ifndef SPACESHIP_H_INCLUDED
#define SPACESHIP_H_INCLUDED

#pragma once
#include <raylib.h>
#include <vector>
#include "laser.h"

class Spaceship{
    public:
        Spaceship();///CONSTRUCTOR///
        ~Spaceship();///DESTRUCTOR///

        void draw(); ///PARA DIBUJAR LA IMAGEN DE LA NAVE EN LA PANTALLA///
        void moveLeft();///MOVER LA NAVE A LA IZQUIERDA///
        void moveRigth();///MOVER LA NAVE A LA DERECHA///
        void dispararLaser();///DISPARAR LASER///
        Rectangle getRect();
        void reset();

        std::vector<Laser> lasers; ///VECTOR DONDE SE ALMACENARAN TODOS LOS LASERS///

    private:
        Texture2D image;///Texture2D ES UNA ESTRUCTURA QUE REPRESENTA UNA IMAGEN 2D///
        Vector2 posicion;///Vector2 ES UNA ESTRUCTURA REPRESENTAR COORDENADAS EN 2D///
        double lastFireTime=0.0; ///VA A GUARDAR EL TIEMPO EN EL QUE EL ULTIMO LASER FUE DISPARADO///
        Sound laserSound;

};


#endif // SPACESHIP_H_INCLUDED
