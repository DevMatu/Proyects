#ifndef ALIEN_H_INCLUDED
#define ALIEN_H_INCLUDED
#pragma once
#include <raylib.h>

class Alien
{
    public:
        ///METODOS///
        Alien(int type, Vector2 position); ///CONSTRUCTOR///
        void draw(); ///DIBUJAR LOS ALIENS EN PANTALLA///
        void update(int direccion); ///MOVIMIENTO DE LOS ALIENS///
        int getType();
        static void unloadImages(); ///METODO PARA LIBERAR TEXTURAS///
        Rectangle getRect();

        ///ATRIBUTOS///
        /**LA PRIMERA VEZ QUE SE CREE UN ALIEN VA A CARGAR ESTE ATRIBUTO Y SE CARGARAN LAS 3 IMAGENES
        ESTO SIRVE PARA NO TENER QUE CARGAR LAS IMAGENES DE ALIEN POR SEPARADO, LO QUE VA A OPTIMIZAR EL PROGRAMA*/
        static Texture2D alienImages[3];

        int type; ///TIPO DE ALIEN (HAY TRES TIPOS)///
        Vector2 position; ///POSICION DEL ALIEN///

    private:

};


#endif // ALIEN_H_INCLUDED
