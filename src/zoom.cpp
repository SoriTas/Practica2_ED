#include <iostream>
#include <image.h>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){
  if (argc != 5){
    throw out_of_range("Invalid arguments!");
  }
  
  char * fich_orig = argv[1];
  char * fich_rdo = argv[2];
  int fila = atoi(argv[3]);
  int columna = atoi(argv[4]);
  int lado = atoi(argv[5]);
  Image zoom;
  
  if(!image.Load(fich_orig)){
    cerr << "Error: No pudo leerse imagen";
  }

  zoom = image.Zoom2x();
  zoom.crop(fila,columna,lado,lado);

  subimage.Save(fich_rdo);
}
