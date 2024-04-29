#include "game.h"
#include "alien.h"
#include <iostream>

///CONSTRUCTOR///
Game::Game()
{
    obstaculos = crearObstaculos();
    aliens = crearAliens();
}

///DESTRUCTOR///
Game::~Game()
{
    Alien::unloadImages();
}

///GAME UPDATE///
void Game::update()
{
    for(auto& laser : spaceship.lasers){
        laser.update();
    }

    borrarLaserInactivo();
}

///DIBUJAR///
void Game::dibujar()
{
    spaceship.draw();

    for(auto& laser : spaceship.lasers){ ///AUTO& SE UTILIZA PARA DEDUCIR AUTOMÁTICAMENTE EL TIPO DE DATO DE CADA ELEMENTO///
        laser.draw();
    }

    for(auto& obstaculo: obstaculos){
        obstaculo.draw();
    }

    for(auto& alien: aliens){
        alien.draw();
    }
}

///MANEJO DE ENTRADAS///
void Game::handleInput()
{
    if(IsKeyDown(KEY_LEFT)){
        spaceship.moveLeft();

    } else if(IsKeyDown(KEY_RIGHT)){
        spaceship.moveRigth();

    } else if(IsKeyDown(KEY_SPACE)){
        spaceship.dispararLaser();
    }

}

///BORRAR LASERS INACTIVOS///
void Game::borrarLaserInactivo()
{
    for(auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();){
        if(!it -> active){
            it = spaceship.lasers.erase(it);
        }else {
            ++it;
        }
    }
}

///CREAR OBSTACULOS///
std::vector<Obstaculo> Game::crearObstaculos()
{
    ///PARA CREAR LOS CUATRO OBSTACULOS CON UNA SEPARACION, PRIMERO TENEMOS QUE SABER QUE TAMAÑO OCUPA CADO UNO///
    ///TOMAMOS CUANTOS ELEMENTOS TIENE LA PRIMERA FILA DE GRID, LO QUE NOS DA EL TOTAL DE COLUMNAS///
    ///EN ESTE CASO 23 Y LUEGO * 3 (3 ES EL ANCHO DE LOS BLOQUES QUE COMPONEN UN OBSTACULO)///
    int obstaculoAncho = Obstaculo::grid[0].size() * 3;

    ///AHORA HAY QUE CALCULAR LA SEPARACION ENTRE OBSTACULOS///
    ///TOMAMOS EL LARGO TOTAL DE LA PANTALLA Y EL LARGO DE LOS CUATRO OBSTACULOS JUNTOS///
    float separacion = (GetScreenWidth() - (4*obstaculoAncho))/5;

    ///CREAMOS LOS OBSTACULOS///
    for(int i=0; i<4; i++){
        float offsetX = (i + 1) * separacion + i * obstaculoAncho;
        /**PRIMER OBSTACULO: (0 + 1) * 474 + 0 * 69 = 543
        SEGUNDO OBSTACULO: (1 + 1) * 474 + 1 * 69 = 1017
        ...
        ...**/
        obstaculos.push_back(Obstaculo({offsetX, float(GetScreenHeight()- 100)}));
    }
    return obstaculos;
}

///CREAR ALIENS///
std::vector<Alien> Game::crearAliens()
{
    std::vector<Alien> aliens; ///5 FILAS 11 COLUMNAS///
    ///EL VALOR DE LAS filas,columnas y celdas(55) ESTA HARDCODEADO, SE PUEDEN HACER EN VARIABLES///
    for(int fila=0; fila<5; fila++){
        for(int column=0; column<11; column++){

            ///DEPENDIENDO EN LA FILA EN LA QUE ESTEMOS ASIGNAMOS UN TIPO DE ALIEN///
            int alienType;
            if(fila == 0){
                alienType = 3;
            } else if(fila == 1 || fila == 2){
                alienType = 2;
            } else{
                alienType = 1;
            }

            /**PRIMER ALIEN : 75 PIXELS EN X y 100 EN Y
            SEGUNDO ALIEN : 75+1*55 = 130 PIXELS EN X Y 100 EN Y
            SUMA X HASTA QUE EL CICLO INTERNO COMPLETE UNA VUELTA...*/
            float x = 75 + column * 55;
            float y = 100 + fila * 55;
            aliens.push_back(Alien(alienType, {x,y}));
        }
    }
    return aliens;
}

