#ifndef BLOQUE_H_INCLUDED
#define BLOQUE_H_INCLUDED
#pragma once
#include <raylib.h>

///ESTOS PEQUE�OS BLOQUES REPRESENTAN DE LO QUE EST� HECHO EL OBSTACULO...SER� UNA MATRIZ DE BLOQUES...///

class Bloque{
    public:
        Bloque(Vector2 posicion);
        void draw();
    private:
        Vector2 posicion;

};


#endif // BLOQUE_H_INCLUDED
