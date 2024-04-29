#ifndef BLOQUE_H_INCLUDED
#define BLOQUE_H_INCLUDED
#pragma once
#include <raylib.h>

///ESTOS PEQUEÑOS BLOQUES REPRESENTAN DE LO QUE ESTÁ HECHO EL OBSTACULO...SERÁ UNA MATRIZ DE BLOQUES...///

class Bloque{
    public:
        Bloque(Vector2 posicion);
        void draw();
    private:
        Vector2 posicion;

};


#endif // BLOQUE_H_INCLUDED
