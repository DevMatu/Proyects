#include "game.h"
#include <iostream>
#include <fstream>

///CONSTRUCTOR///
Game::Game()
{
    music = LoadMusicStream("Sonidos/music.ogg");
    PlayMusicStream(music);

    explosionSound = LoadSound("Sonidos/explosion.ogg");
    initGame();
}

///DESTRUCTOR///
Game::~Game()
{
    Alien::unloadImages();
    UnloadMusicStream(music);
    UnloadSound(explosionSound);
}

///GAME UPDATE///
void Game::update()
{
    if(run){
        double tiempoActual = GetTime();
        if(tiempoActual - timeLastSpawn > mysteryShipSpawnInterval) {
            mysteryship.spawn();
            timeLastSpawn = GetTime();
            mysteryShipSpawnInterval = GetRandomValue(10,20);
        }

        for(auto& laser : spaceship.lasers){
            laser.update();
        }

        moverAliens();

        alienShootLaser();

        for(auto& laser : alienLasers)
        {
            laser.update();
        }

        borrarLaserInactivo();

        mysteryship.update();

        checkForCollisions(); ///LLAMAMOS AL METODO QUE CORROBORA LAS COLISIONES///
    }
    else{
        if(IsKeyDown(KEY_ENTER)){
            reset();
            initGame();
        }
    }
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

    for(auto& laser : alienLasers)
    {
        laser.draw();
    }

    mysteryship.draw();
}

///MANEJO DE ENTRADAS///
void Game::handleInput()
{
    if(run){

        if(IsKeyDown(KEY_LEFT)){
            spaceship.moveLeft();

        } else if(IsKeyDown(KEY_RIGHT)){
            spaceship.moveRigth();

        } else if(IsKeyDown(KEY_SPACE)){
            spaceship.dispararLaser();
        }

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

    for(auto it = alienLasers.begin(); it != alienLasers.end();){
        if(!it -> active){
            it = alienLasers.erase(it);
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
        obstaculos.push_back(Obstaculo({offsetX, float(GetScreenHeight()- 200)}));
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

///MOVIEMIENTO DE LOS ALIENS///
void Game::moverAliens()
{
    for(auto& alien : aliens){
        if(alien.position.x + alien.alienImages[alien.type - 1].width > GetScreenWidth() - 25)
        {
            alienDirection = -1;
            moverAliensAbajo(4); ///CADA VEZ QUE TOQUEN LA PANTALLA SE MOVERÁN 4 PIXELES HACIA ABAJO///
        }
        if(alien.position.x < 25)
        {
            alienDirection = 1;
            moverAliensAbajo(4);
        }
        alien.update(alienDirection);
    }
}
void Game::moverAliensAbajo(int distance)
{
    for(auto& alien : aliens)
    {
        alien.position.y += distance;
    }
}

///DISPARO LASER DE LOS ALIENS///
void Game::alienShootLaser()
{
    double tiempoActual = GetTime();
    ///SI EL TIEMPO ACTUAL MENOS EL TIEMPO EN EL QUE SE DISPARO EL ULTIMO LASER ES MAYOR QUE EL INTERVALO DE DISPARO Y EL VECTOR DE ALIENS NO ESTA VACIO///
    if(tiempoActual - alienLastFire >= 0.35 && !aliens.empty()){

        int randomIndex = GetRandomValue(0, aliens.size()-1);

        Alien& alien = aliens[randomIndex]; ///DECLARAMOS UNA REFERENCIA A UN OBJETO DE LA CLASE ALIEN.///

        alienLasers.push_back(Laser({alien.position.x + alien.alienImages[alien.type-1].width/2,
                alien.position.y + alien.alienImages[alien.type -1].height}, 6));///LE ASIGNAMOS, AL VECTOR, EL CONSTRUCTOR DE LASER///
        ///EL CONSTRUCTOR VA A RECIBIR EL CENTRO DE LA IMAGEN DE UN ALIEN EN X e Y, TAMBIEN LA VELOCIDAD DEL LASER///
        alienLastFire = GetTime();

    }
}

///METODO PARA VERIFIACAR SI HAY COLISIONES///
void Game::checkForCollisions()
{
    ///SPACESHIP LASERS///
    //RECORREMOS CADA LASER DE LA NAVE Y CHEQUEAMOS SI EL LASER COLISIONÓ//
    for(auto& laser : spaceship.lasers){
        auto it = aliens.begin(); //CREAMOS UN ITERADOR Y HACEMOS QUE APUNTE AL COMIENZO DEL VECTOR DE ALIENS//
        while(it != aliens.end()){ //MIENTRAS EL ITERADOR NO LLEGUE AL FINAL DEL VECTOR, ITERAR//
            /**CHEAQUEAMOS SI HAY UNA SUPERPOSISION O UNA COLISION ENTRE EL RECTANGULO DEL LASER DE LA NAVE
            CON EL RECTANGULO DE ALGUN ALIEN DEL VECTOR. it ACCEDE CON PUNTERO THIS AL METODO QUE DEVUELVE EL RECTANGULO DEL
            ALIEN*/
            if(CheckCollisionRecs(it -> getRect(), laser.getRect()))
            {
                PlaySound(explosionSound);
                if(it -> type == 1){
                    score += 100;
                }else if(it -> type == 2){
                    score += 200;
                }else if(it -> type == 3){
                    score += 300;
                }
                checkForHigscore();

                it = aliens.erase(it);
                laser.active = false;
            }
            else{
                it++;
            }
        }

        for(auto& obstaculo : obstaculos){
            auto it = obstaculo.bloques.begin();

            while(it != obstaculo.bloques.end()){
                if(CheckCollisionRecs(it -> getRect(), laser.getRect())){
                    it = obstaculo.bloques.erase(it);
                    laser.active = false;
                }
                else{
                    it++;
                }
            }
        }

        if(CheckCollisionRecs(mysteryship.getRect(), laser.getRect())){
            mysteryship.alive = false;
            laser.active = false;
            score += 500;
            checkForHigscore();
            PlaySound(explosionSound);
        }

    }

    ///ALIEN LASERS///
    //NECESITAMOS CICLAR A TRAVES DE TODOS LOS LASERS DE LOS ALIENS//
    for(auto& laser : alienLasers){
        //CHEQUEAMOS SI ALGUN LASER DE LOS ALIENS COLISIONA CON LA NAVE/CAÑON//
        if(CheckCollisionRecs(laser.getRect(), spaceship.getRect())){
            laser.active = false;
            vidas--;
            if(vidas == 0){
                gameOver();
            }
        }

        for(auto& obstaculo : obstaculos){
            auto it = obstaculo.bloques.begin();

            while(it != obstaculo.bloques.end()){
                if(CheckCollisionRecs(it -> getRect(), laser.getRect())){
                    it = obstaculo.bloques.erase(it);
                    laser.active = false;
                }
                else{
                    it++;
                }
            }
        }
    }

    ///ALIEN COLISION WHITH OBSTACLE///
    for(auto& alien : aliens){

        for(auto& obstaculo : obstaculos){
            auto it = obstaculo.bloques.begin();

            while(it != obstaculo.bloques.end()){
                if(CheckCollisionRecs(it -> getRect(), alien.getRect())){
                    it = obstaculo.bloques.erase(it);

                }
                else{
                    it++;
                }
            }
        }

        if(CheckCollisionRecs(alien.getRect(), spaceship.getRect())){
            gameOver();
        }
    }
}

///GAME OVER///
void Game::gameOver()
{
    run = false;
}

///INICIALIZAR EL JUEGO///
void Game::initGame()
{
    obstaculos = crearObstaculos();

    aliens = crearAliens();
    alienDirection = 1;
    alienLastFire = 0.0;

    timeLastSpawn = 0.0;
    vidas = 3;
    score = 0;
    higScore = loadHigscoreFromFile();
    run = true;

    mysteryShipSpawnInterval = GetRandomValue(10,20);
}

void Game::reset()
{
    spaceship.reset();
    aliens.clear();
    alienLasers.clear();
    obstaculos.clear();
}

///METODO PARA MANEJAR EL HIGSCORE///
void Game::checkForHigscore()
{
    if(score > higScore){
        higScore = score;
        saveHigscoreToFile(higScore);
    }
}

///MANEJO DE ARCHIVOS///
int Game::saveHigscoreToFile(int higScore)
{
    FILE *pFile = fopen("highscore.dat", "wb");
    if (pFile != nullptr) {
        fwrite(&higScore, sizeof(higScore), 1, pFile);
        fclose(pFile);
        return 0; ///EXITO///
    } else {
        return -1; ///ERROR AL ABRIR EL ARCHIVO///
    }
}

int Game::loadHigscoreFromFile()
{
    int higScore = 0;
    FILE* file = fopen("highscore.dat", "rb");
    if (file != nullptr) {
        fread(&higScore, sizeof(higScore), 1, file);
        fclose(file);
    }
    return higScore;
}


























