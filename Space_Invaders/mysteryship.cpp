#include <iostream>
#include "mysteryship.h"

///CONSTRUCTOR///
MysteryShip::MysteryShip()
{
    imagen = LoadTexture("Graphics/mystery.png"); ///CARGAMOS LA TEXTURA DE LA NAVE MISTERIOSA///
    posicion.x = 100;
    posicion.y = 100;
    alive = false;

}
///DESTRUCTOR///
MysteryShip::~MysteryShip()
{
    UnloadTexture(imagen);
}

///SPAWN DE LA NAVE///
void MysteryShip::spawn()
{
    posicion.y = 65;
    int side = GetRandomValue(0,1);

    if(side == 0){
        posicion.x = 25;
        speed = 3;
    }else{
        posicion.x = GetScreenWidth() - imagen.width - 25;
        speed = -3;
    }
    alive = true;
}

///ACTUALIZAR LA NAVE///
void MysteryShip::update()
{
    if(alive){
        posicion.x += speed;
        if(posicion.x > GetScreenWidth() - imagen.width - 25  || posicion.x < 25){
            alive = false;
        }
    }
}

///DIBUJAR LA NAVE MISTERIOSA///
void MysteryShip::draw()
{
    if(alive){
        DrawTextureV(imagen,posicion,WHITE);
    }
}

///DEVOLVER UN RECTANGULO CON EL TAMAÑO Y LA POSICION DE LA NAVE MISTERIOSA///
Rectangle MysteryShip::getRect()
{
    ///SOLO PODREMOS COLISIONAR CON LA NAVE SI ESTA ES VISIBLE///
    if(alive){
        return{posicion.x, posicion.y, float(imagen.width), float(imagen.height)};
    } else{
        return {posicion.x, posicion.y, 0, 0};
    }
}
