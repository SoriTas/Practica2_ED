/**
 * @file imageop.cpp
 * @brief Fichero con definiciones para el resto de métodos de la clase Image
 */

#include <iostream>
#include <cmath>
#include "../include/image.h"

#include <cassert>

using namespace std;

Image Image::Crop(int nrow, int ncol, int height, int width) const{
    Image aux(height, width);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            aux.set_pixel(i,j, get_pixel(nrow+i,ncol+j));
        }
    }

    return aux;
}

Image Image::Zoom2X() const{
  int rows = get_rows();
  int cols = get_cols();
  byte interpol1[rows * 2 - 1][cols * 2 - 1];
  Image aux(rows * 2 - 1,cols * 2 - 1);
  for (int i = 0;i < rows;i++){
    if (i % 2 == 0){
      for (int j = 0;j < cols * 2 - 1;j++){
         if (j % 2 != 0) {
          interpol1[i][j] = (interpol1[i][j - 1] + interpol1[i][j + 1]) / 2;
         }
         else{
             interpol1[i][j] = get_pixel(i,j/2);
         }
      }
    }
  }
  for (int i = 0;i < rows * 2 - 1;i++){
    if (i % 2 != 0){  
      for (int j = 0;j < cols * 2 - 1;j++){
          interpol1[i][j] = (interpol1[i - 1][j] + interpol1[i + 1][j]) / 2;
      }
    }
  }
  for (int i = 0;i < rows * 2 - 1;i++){
      for (int j = 0;j < cols * 2 - 1;j++){
        aux.set_pixel(i,j,round(interpol1[i][j]));
      }
    }

  return aux;
}

Image Image::Subsample(int factor) const{
  if (factor < 0){
    throw out_of_range("Factor out of range");
  }
  Image aux;
  int rows = get_rows();
  int cols = get_cols();
  int media;
  byte Icon[rows / factor][cols / factor];
  for(int i = 0 ; i < rows/factor ; i++){
    for(int j = 0; j < factor; j++){
      for(int m = i * factor; m < factor ;m++){
        for(int l = j * factor;l < factor;l++){
          media += get_pixel(m,l);
        }
       aux.set_pixel(i,j,(media / factor));
      }
    }
  }
  return aux;
}
