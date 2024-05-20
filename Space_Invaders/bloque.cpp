#include "bloque.h"

///CONSTRUCTOR///
Bloque::Bloque(Vector2 posicion)
{
    this -> posicion = posicion;
}

///DIBUJAR EL BLOQUE///
void Bloque::draw()
{
    DrawRectangle(posicion.x, posicion.y, 3, 3, {243,216,63,255});
}

///DEVOLVEMOS UN RECTANGULO CON LA POSICION Y EL TAMAÑO DE LOS BLOQUES QUE COMPONEN LOS OBSTACULOS///
Rectangle Bloque::getRect()
{
    Rectangle rect;
    rect.x = posicion.x;
    rect.y = posicion.y;
    rect.width = 3;
    rect.height = 3;
    return rect;
}
