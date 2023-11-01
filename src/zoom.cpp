#include <iostream>
#include <image.h>
#include <cstring>
#include <cstdlib>

using namespace std;

int main (int argc, char *argv[]){

    cout << "jol2";

    if (argc != 6){
        cerr << "Error: Numero incorrecto de parametros.\n";
  }

    char *origen, *destino;
    int fila, columna, lado;

  origen = argv[1];
  destino = argv[2];
  fila = atoi(argv[3]);
  columna = atoi(argv[4]);
  lado = atoi(argv[5]);
  Image zoom, image;

  if(!image.Load(origen)){
    cerr << "Error: No pudo leerse imagen";
  }

  zoom.Crop(fila,columna,lado,lado);
  zoom = image.Zoom2X();

  zoom.Save(destino);
}
