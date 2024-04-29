#include <raylib.h>
#include "game.h"

int main()
{
    Color grey = {29,29,27,255}; ///CREAMOS EL COLOR GRIS Color nombre = {red, green, blue, alpha}///
    ///CREAMOS UNA VENTANA CON LARGO Y ANCHO///
    const int windowWidth = 750;
    const int windowHeight = 700;

    ///INICIALIZAMOS LA VENTANA///
    InitWindow(windowWidth, windowHeight, "Space Invaders");
    SetTargetFPS(60);

    Game game; ///CREAMOS UN OBJETO "Game"///

    ///MIENTRAS LA VENTANA NO SE CIERRE, EJECUTAR EL CICLO///
    while(WindowShouldClose() == false) {

        game.handleInput();
        game.update();

        BeginDrawing();///COMIENZO DEL DIBUJADO///
        ClearBackground(grey);
        game.dibujar();
        EndDrawing();///FIN DEL DIBUJADO///

    }

    CloseWindow();
    return 0;
}
