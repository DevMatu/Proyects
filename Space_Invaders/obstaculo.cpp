#include "obstaculo.h"

///INICIALIZAMOS LA "MATRIZ"///
std::vector<std::vector<int>> Obstaculo::grid = {
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1}
    };

///grid[0].size; grid[0] REPRESENTA LA PRIMERA FILA Y .size() TOMA LA CANTIDAD DE COLUMNAS DE ESTA FILA ///

///CONSTRUCTOR 1///
Obstaculo::Obstaculo(Vector2 posicion)
{
    this -> posicion = posicion;

    ///ESTE BUCLE ITERA SOBRE CADA FILA DE LA MATRIZ GRID. grid.size()///
    for(int fila=0;fila<grid.size();fila++){
        ///TOMAMOS CUANTOS ELEMENTOS TIENE LA PRIMERA FILA DE GRID, LO QUE NOS DA EL TOTAL DE COLUMNAS///
        ///grid[0].size() DEVUELVE EL NÚMERO DE COLUMNAS EN LA PRIMERA FILA DE LA MATRIZ///
        for(int columna=0;columna<grid[0].size(); columna++){
            if(grid[fila][columna] == 1){

                ///CADA CELDA DE LA MATRIZ GRID REPRESENTA UN BLOQUE DE 3X3 PIXELES, POR LO QUE MULTIPLICAMOS LA///
                ///COLUMNA POR 3 PARA OBTENER LA POSICIóN///
                float pos_x = posicion.x + columna * 3;
                float pos_y = posicion.y + fila * 3;
                Bloque bloque = Bloque({pos_x,pos_y});
                bloques.push_back(bloque);
            }
        }
    }
}

///DIBUJAR TODOS LOS BLOQUES INICIALIZADOS(CON SUS POSICIONES CALCULADAS)EN EL VECTOR DE BLOQUES///
void Obstaculo::draw(){
    for(auto& bloque : bloques){
        bloque.draw();
    }
}
