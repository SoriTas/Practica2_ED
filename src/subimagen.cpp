/**
 * @file subimagen.cpp
 * @brief Programa de la actividad 1: Genera una subimagen a partir de la imagen de un fichero y almacena la subimagen en otro fichero.
 */

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main (int argc, char *argv[]){
 
  char *origen, *destino; // nombres de los ficheros
  Image image, subimage;
  int fila, col, filas_sub, cols_sub;

  // Comprobar validez de la llamada
  if (argc != 7){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: subimagen <FichImagenOriginal> <FichImagenDestino> <Fila inic> <Col inic> <NumFilas> <NumCols>\n";
    exit (1);
  }

  // Obtener argumentos
  origen  = argv[1];
  destino = argv[2];
  fila = atoi(argv[3]);
  col = atoi(argv[4]);
  filas_sub = atoi(argv[5]);
  cols_sub = atoi(argv[6]);

  // Mostramos argumentos
  cout << endl;
  cout << "Fichero origen: " << origen << endl;
  cout << "Fichero resultado: " << destino << endl;
  cout << "Coordenada fila inicial" << fila << endl;
  cout << "Coordenada columna inicial" << col << endl;
  cout << "Número filas subimagen" << filas_sub << endl;
  cout << "Número columnas subimagen" << cols_sub << endl;

  // Leer la imagen del fichero de entrada
  if (!image.Load(origen)){
    cerr << "Error: No pudo leerse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }

  // Mostrar los parametros de la Imagen
  cout << endl;
  cout << "Dimensiones de " << origen << ":" << endl;
  cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;

  subimage = image.Crop(fila, col, filas_sub, cols_sub);

  subimage.Save(destino);

}