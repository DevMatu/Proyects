#ifndef OBSTACULO_H_INCLUDED
#define OBSTACULO_H_INCLUDED
#pragma once
#include <vector>
#include "bloque.h"

class Obstaculo{
    public:
        Obstaculo(Vector2 posicion);

        void draw();
        Vector2 posicion;
        std::vector<Bloque> bloques;
        ///HACEMOS UN VECTOR DE VECTORES DE TIPO ENTERO PARA HACER UNA "MATRIZ DINÁMICA"///
        ///LO DECLARAMOS DE MANERA STATIC PARA PODER ACCEDER A EL SIN TENER QUE CREAR UN OBJETO///
        ///IGUALMENTE AUN HAY QUE INICIALIZARLO..///
        static std::vector<std::vector<int>> grid;
    private:

};


#endif // OBSTACULO_H_INCLUDED
