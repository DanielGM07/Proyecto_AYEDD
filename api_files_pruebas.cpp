#include <iostream>
#include <string>
#include <stdio.h>

#include "biblioteca/funciones/millis.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/intro/Fraccion.hpp"
#include "biblioteca/tads/parte1/Fecha.hpp"
#include "biblioteca/tads/parte1/Timer.hpp"
#include "biblioteca/tads/parte1/Coll.hpp"
#include "biblioteca/tads/parte2/Array.hpp"
#include "biblioteca/tads/parte2/List.hpp"
#include "biblioteca/tads/parte2/Map.hpp"
#include "biblioteca/tads/parte2/Queue.hpp"
#include "biblioteca/tads/parte2/Stack.hpp"
#include "principal.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::to_string;

// C:\vscode\mingw\bin
// Los archivos se crean en esa direccion 
int main()
{
    // FILE* f = fopen("C:/vscode/Workspace/AlgoritmosAFondo_EMPTY_v2.7.36/prueba.dat", "w+b");
    // writeString(f, "Hola mundi");
    // writeString(f, " eee messi");
    // writeString(f, "ycristiano");
    // fclose(f);
    
    // FILE* f = fopen("C:/vscode/Workspace/AlgoritmosAFondo_EMPTY_v2.7.36/prueba.txt", "w+b");
    // writeString(f, "pruba");
    // writeString(f, " pruba pruba");
    // writeString(f, "ycriprubastiano");

    // fclose(f);

    FILE* f = fopen("C:/vscode/Workspace/AlgoritmosAFondo_EMPTY_v2.7.36/prueba.txt", "r+b");
    seek<char>(f, 0);
    string ln;
    bool hayMas = readLine(f, ln);
    while(hayMas){
        cout << ln << endl;
        hayMas = readLine(f, ln);
    }

    fclose(f);

    return 0;
}