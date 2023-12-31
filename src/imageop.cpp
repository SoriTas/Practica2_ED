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
  Image aux(rows * 2 - 1,cols * 2 - 1);
  for(int i = 0; i < rows * 2 - 1,cols * 2 - 1;i++){
      for(int j = 0;j < cols * 2 - 1;j++){
        if(i % 2 == 0 && j % 2 == 0){
          aux.set_pixel(i,j,get_pixel(i/2,j/2) );
        }
        else if(i % 2 == 0 && j != 0){
          aux.set_pixel(i,j,(get_pixel(i/2,(j-1)/2) + get_pixel(i/2,(j + 1)/2)/2));
        }
        else if(i % 2 != 0, j == 0){
          aux.set_pixel(i,j,(get_pixel(((i-1)/2),j) + get_pixel((i+1)/2,j)/2));
        }
        else{
          aux.set_pixel(i,j,(get_pixel((i-1)/2,j)+get_pixel((i+1)/2,j)+get_pixel(((i-1)/2),j) + get_pixel((i+1)/2,j)/2)/4);
        }
      }
    }
  return aux;
}
  /*for (int i = 0;i < rows;i++){
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
*/
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
    for(int j = 0; j < cols/factor; j++){
      for(int m = i * factor; m < factor * i + factor ;m++){
        for(int l = j * factor;l < factor * j + factor;l++){
          media += get_pixel(m,l);
        }
       aux.set_pixel(i,j,(media / (factor * factor)));
      }
    }
  }
  return aux;
}

void Image::AdjustContrast(byte in1, byte in2, byte out1, byte out2) {
    if (in1 > in2 || out1 > out2 || in1 < 0 || in1 > 255 || in2 < 0 || in2 > 255 || out1 < 0 || out1 > 255 || out2 < 0 || out2 > 255) {
        throw out_of_range("Factor out of range");
       }

    byte min = out1;
    byte max = out2;
    byte a = in1;
    byte b = in2;
    int valor=0;
    byte z;
    double aux;

    aux = ((int)max-(int)min)*1.0/((int)b-(int)a);

    for (int i=0; i < this.size(); i++){

        z = get_pixel(i);

        if( z >= a && z<=b){

            valor = (unsigned int)min + round(cociente*((unsigned int)z-(unsigned int)a));

            set_pixel(i,(byte)valor);

        }

        else{

            set_pixel (i,z);

        }


    }
}
