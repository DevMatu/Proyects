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
