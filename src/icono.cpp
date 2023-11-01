#include <iostream>
#include <image.h>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]){
    if (argc != 3){
        throw out_of_range("Invalid arguments!");
    }
    char * fich_orig = argv[1];
    char * fich_rdo = argv[2];
    int factor = atoi(argv[3]);
    
    Image icon;
  
    if(!image.Load(fich_orig)){
      cerr << "Error: No pudo leerse imagen";
    }

    icon = image.Subsample(factor);

    icon.Save(fich_rdo);
}