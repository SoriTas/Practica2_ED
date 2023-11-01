#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main (int argc, char *argv[]){

    char *origen, *destino; // nombres de los ficheros
    int e1, e2, s1, s2;

    // Comprobar validez de la llamada
    if (argc != 7) {
        cerr << "Error: Numero incorrecto de parametros.\n";
    }

    // Obtener argumentos
    origen  = argv[1];
    destino = argv[2];
    e1 = atoi(argv[3]);
    e2 = atoi(argv[4]);
    s1 = atoi(argv[5]);
    s2 = atoi(argv[6]);

    Image imagen;

    if (!imagen.Load(origen)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    imagen.AdjustContrast(e1, e2, s1, s2);

    imagen.Save(destino);
}