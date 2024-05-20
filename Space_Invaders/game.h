#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#pragma once
#include "SpaceShip.h"
#include "obstaculo.h"
#include "alien.h"
#include "mysteryship.h"


class Game{
    public:
        Game();///CONSTRUCTOR///
        ~Game();///DESTRUCTOR///

        void dibujar();///DIBUJA TODOS LOS OBJETOS DEL JUEGO///
        void update();///ACTUALIZA LAS POSICIONES DE TODOS LOS OBJETOS DEL JUEGO///
        void handleInput();///MANEJA LS ENTRADAS DEL JUGADOR///
        int vidas;
        bool run;
        int score;
        int higScore;
        Music music;

    private:
        ///METODOS///
        void borrarLaserInactivo();///MÉTODO QUE BORRA LOS LASERS INACTIVOS EN EL VECTOR DE LASERS///
        std::vector<Obstaculo> crearObstaculos(); ///VECTOR QUE CREA OBSTACULOS Y RETORNA UN VECTOR DE OBSTACULOS///
        std::vector<Alien> crearAliens(); ///VECTOR QUE CREA ALIENS Y RETORNA UN VECTOR DE ALIENS///
        void moverAliens();
        void moverAliensAbajo(int distance);
        void alienShootLaser();
        void checkForCollisions();
        void gameOver();
        void reset();
        void initGame();
        void checkForHigscore();
        int saveHigscoreToFile(int higScore);
        int loadHigscoreFromFile();

        ///ATRIBUTOS///
        Spaceship spaceship;

        std::vector<Alien> aliens;
        std::vector<Obstaculo> obstaculos;
        int alienDirection;
        std::vector<Laser> alienLasers;
        float alienLastFire;

        MysteryShip mysteryship;
        float mysteryShipSpawnInterval; ///GUARDAMOS EL INTERVALO EN EL QUE LA NAVE APARECERÁ///
        ///EL INTERVALO NO PUEDE SER CONSTANTE, ESTE TIENE QUE VARIAR///
        float timeLastSpawn; ///GUARDAMOS EL TIEMPO EN EL QUE LA NAVE SPAWNEO///
        Sound explosionSound;

};

#endif // GAME_H_INCLUDED
