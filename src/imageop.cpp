/**
 * @file imageop.cpp
 * @brief Fichero con definiciones para el resto de métodos de la clase Image
 */

#include <iostream>
#include <cmath>
#include "../include/image.h"

#include <cassert>

Image::Image Crop(int nrow, int ncol, int height, int width) const{
    Image aux(height, width);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            aux.set_pixel(i,j, this.get_pixel(nrow+i,ncol+j));
        }
    }

    return aux;
}

