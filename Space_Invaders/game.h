#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#pragma once
#include "SpaceShip.h"
#include "obstaculo.h"
#include "alien.h"

class Game{
    public:
        Game();///CONSTRUCTOR///
        ~Game();///DESTRUCTOR///

        void dibujar();///DIBUJA TODOS LOS OBJETOS DEL JUEGO///
        void update();///ACTUALIZA LAS POSICIONES DE TODOS LOS OBJETOS DEL JUEGO///
        void handleInput();///MANEJA LS ENTRADAS DEL JUGADOR///

    private:
        void borrarLaserInactivo();///MÉTODO QUE BORRA LOS LASERS INACTIVOS EN EL VECTOR DE LASERS///
        std::vector<Obstaculo> crearObstaculos(); ///VECTOR QUE CREA OBSTACULOS Y RETORNA UN VECTOR DE OBSTACULOS///
        std::vector<Alien> crearAliens(); ///VECTOR QUE CREA ALIENS Y RETORNA UN VECTOR DE ALIENS///
        ///----------///
        Spaceship spaceship;
        std::vector<Alien> aliens;
        std::vector<Obstaculo> obstaculos;

};

#endif // GAME_H_INCLUDED
