#include "SpaceShip.h"

///CONSTRUCTOR 1///
Spaceship::Spaceship()
{
    image = LoadTexture("Graphics/spaceship.png");///CARGAMOS LA TEXTURA DE LA NAVE///
    ///UNA VEZ CARGADA LA TEXTURA DIBUJAMOS LA NAVE EN ALGUNA POSICION EN LA VENTANA///
    posicion.x = (GetScreenWidth() - image.width)/2;
    posicion.y = GetScreenHeight() - image.height;
    lastFireTime = 0.0;
}

///DESTRUCTOR///
Spaceship::~Spaceship()
{
    ///CADA VEZ QUE CARGAMOS UNA TEXTURA, ÉSTA SE TIENE QUE LIBERAR CUANDO CERRAMOS EL JUEGO///
    UnloadTexture(image);
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
    if(posicion.x < 0){
        posicion.x = 0;
    }
}
void Spaceship::moveRigth()
{
    posicion.x += 7;
    if(posicion.x > GetRenderWidth()-image.width){
        posicion.x = GetRenderWidth()-image.width;
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
    }
}




