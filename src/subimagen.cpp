/**
 * @file subimagen.cpp
 * @brief Programa de la actividad 1: Genera una subimagen a partir de la imagen de un fichero y almacena la subimagen en otro fichero.
 */

 #include <iostream>
 #include <cmath>
 #include "../include/image.h"

 void guardarSubimagen( const char* fich_orig, const char* fich_rdo, int fila, int col, int filas_sub, int cols_sub ){
    Image imagen, resultado;

    imagen.Load(fich_orig);

    resultado = imagen.Crop(fila, col, filas_sub, cols_sub);

    resultado.Save(fich_rdo);

 }