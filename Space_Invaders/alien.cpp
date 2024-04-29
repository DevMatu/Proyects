#include "alien.h"

///DEFINIR E INICIALIZAR EL ATRIBUTO DE LAS TEXTURAS///
Texture2D Alien::alienImages[3] = {};

///CONSTRUCTOR///
Alien::Alien(int type, Vector2 position)
{
    this -> type = type;
    this -> position = position;

    if(alienImages[type - 1].id == 0){ ///CORROBORAMOS QUE LA TEXTURA QUE QUEREMOS UTILIZAR ESTE CARGADA///
        ///.id EST� ACCEDIENDO AL VALOR DEL MIEMBRO ID DEL ELEMENTO EN LA POSICI�N type - 1 DEL VECTOR alienImages///

        switch(type){
            case 1:
                alienImages[0] = LoadTexture("Graphics/alien_1.png");
                break;
            case 2:
                alienImages[1] = LoadTexture("Graphics/alien_2.png");
                break;
            case 3:
                alienImages[3] = LoadTexture("Graphics/alien_3.png");
                break;
            default:
                alienImages[0] = LoadTexture("Graphics/alien_1.png");
                break;
        }
    }
}

///DIBUJAR ALIEN EN PANTALLA///
void Alien::draw()
{
    DrawTextureV(alienImages[type - 1], position, WHITE);///FUNCION PARA DIBUJAR UNA TEXTURA EN PANTALLA///
}

///GETTER DEL TIPO///
int Alien::getType()
{
    return type;
}

///LIBERAR LAS TEXTURAS DE LOS ALIENS///
void Alien::unloadImages(){
    for(int i=0; i<4; i++){
        UnloadTexture(alienImages[i]);
    }
}
