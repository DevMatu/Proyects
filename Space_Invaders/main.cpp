#include <raylib.h>
#include <string>
#include "game.h"

std::string formatosCerosIzquierda(int number, int width)
{
    std::string numberText = std::to_string(number);
    int leadingZeros = width - numberText.length();
    return numberText = std::string(leadingZeros, '0') + numberText;
}

int main()
{
    Color grey = {29,29,27,255}; ///CREAMOS EL COLOR GRIS Color nombre = {red, green, blue, alpha}///
    Color yellow = {243, 216, 63, 255};
    ///CREAMOS UNA VENTANA CON LARGO Y ANCHO///
    int offset = 10;
    const int windowWidth = 750;
    const int windowHeight = 700;

    ///INICIALIZAMOS LA VENTANA///
    InitWindow(windowWidth + offset, windowHeight + 2*offset, "Space Invaders");
    InitAudioDevice();

    Font font = LoadFontEx("Font/monogram.ttf", 64,0,0);
    Texture2D spaceshipImage = LoadTexture("Graphics/spaceship.png");

    SetTargetFPS(60);

    Game game; ///CREAMOS UN OBJETO "Game"///

    ///MIENTRAS LA VENTANA NO SE CIERRE, EJECUTAR EL CICLO///
    while(WindowShouldClose() == false) {
        UpdateMusicStream(game.music);
        game.handleInput();
        game.update();

        BeginDrawing();///COMIENZO DEL DIBUJADO///
        ClearBackground(grey);
        DrawRectangleRoundedLines({10, 10, 740, 700}, 0.18f, 20, 2, yellow); ///RENDERIZA UN RECTANGULO REDONDEADO EN PANTALLA///
        DrawLineEx({25, 640}, {735, 640}, 3, yellow);

        if(game.run){
            DrawTextEx(font, "LEVEL 01", {530,660}, 34, 2, yellow);
        }
        else{
            DrawTextEx(font, "GAME OVER", {530,660}, 34, 2, yellow);
        }

        float x = 50.0;
        for(int i=0; i<game.vidas; i++){
            DrawTextureV(spaceshipImage, {x, 660}, WHITE);
            x+=50;
        }

        DrawTextEx(font, "SCORE", {50, 15}, 34, 2, yellow);
        std::string scoreText = formatosCerosIzquierda(game.score, 5);
        DrawTextEx(font, scoreText.c_str(), {50, 40}, 34, 2, yellow);

        DrawTextEx(font, "HIG-SCORE", {530,15}, 34, 2, yellow);
        std::string HigScoreText = formatosCerosIzquierda(game.higScore, 5);
        DrawTextEx(font, HigScoreText.c_str(), {570,40}, 34, 2, yellow);

        game.dibujar();
        EndDrawing();///FIN DEL DIBUJADO///

    }

    CloseWindow();
    CloseAudioDevice();
    return 0;
}
