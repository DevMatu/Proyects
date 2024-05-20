#include "SpaceShip.h"

///CONSTRUCTOR///
Spaceship::Spaceship()
{
    image = LoadTexture("Graphics/spaceship.png");///CARGAMOS LA TEXTURA DE LA NAVE///
    ///UNA VEZ CARGADA LA TEXTURA DIBUJAMOS LA NAVE EN ALGUNA POSICION EN LA VENTANA///
    posicion.x = (GetScreenWidth() - image.width)/2;
    posicion.y = GetScreenHeight() - image.height - 100;
    lastFireTime = 0.0;
    laserSound = LoadSound("Sonidos/laser.ogg");
}

///DESTRUCTOR///
Spaceship::~Spaceship()
{
    ///CADA VEZ QUE CARGAMOS UNA TEXTURA, ÉSTA SE TIENE QUE LIBERAR CUANDO CERRAMOS EL JUEGO///
    UnloadTexture(image);
    UnloadSound(laserSound);
}

///DIBUJAR LA NAVE///
void Spaceship::draw()
{
    DrawTextureV(image,posicion,WHITE);///FUNCION PARA DIBUJAR UNA TEXTURA EN PANTALLA///
}

///MOVIMIENTOS DE LA NAVE///
void Spaceship::moveLeft()
{
    posicion.x -= 7;
    if(posicion.x < 25){
        posicion.x = 25;
    }
}
void Spaceship::moveRigth()
{
    posicion.x += 7;
    if(posicion.x > GetRenderWidth()-image.width - 25){
        posicion.x = GetRenderWidth()-image.width - 25;
    }
}

///DISPARAR LASER///
void Spaceship::dispararLaser()
{
    if(GetTime() - lastFireTime >= 0.35){ ///DISPARAR UN LASER CADA 35 MILISEGUNDOS///
        lasers.push_back(Laser({posicion.x + image.width/2-2,posicion.y}, -6)); ///CREAR UN LASER Y GUARDARLO EN EL VECTOR DE LASERS///
        ///POSICION.X + IMAGE.WIDTH/2 = REPRESENTA EL MEDIO DE LA PANTALLA///
        ///-2 EL LASER TIENE UN ANCHO DE 4 PIXELES POR LO QUE HAY QUE MOVERLO 2 PIXELES HACIA LA IZQ PARA QUE QUEDE CENTRADO///
        lastFireTime = GetTime();
        PlaySound(laserSound);
    }
}

///DEVOLVER UN RECTANGULO CON EL TAMAÑO Y LA POSICION DE LA NAVE///
Rectangle Spaceship::getRect()
{
    return {posicion.x, posicion.y, float(image.width), float(image.height)};
}

///RESETEAR LA NAVE/CAÑON///
void Spaceship::reset()
{
    posicion.x = (GetScreenWidth() - image.width)/2;
    posicion.y = GetScreenHeight() - image.height - 100;
    lasers.clear();
}



