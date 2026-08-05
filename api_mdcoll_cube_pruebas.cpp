#include <iostream>

// INCLUDES DE GPT, NO SIRVEN JEJEJE
// #include "strings.hpp"
// #include "Coll.hpp"
// #include "MultidimColl.hpp" 

#include "biblioteca/funciones/millis.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/intro/Fraccion.hpp"
#include "biblioteca/tads/parte1/Fecha.hpp"
#include "biblioteca/tads/parte1/Timer.hpp"
#include "biblioteca/tads/parte1/Coll.hpp"

#include "biblioteca/tads/parte1/MultidimColl.hpp"

#include "biblioteca/tads/parte2/Array.hpp"
#include "biblioteca/tads/parte2/List.hpp"
#include "biblioteca/tads/parte2/Map.hpp"
#include "biblioteca/tads/parte2/Queue.hpp"
#include "biblioteca/tads/parte2/Stack.hpp"
#include "principal.hpp"

// Funcion por cha ge pe te jejeje, me gusto y me la quedo
void rellenarCubeConCoordenadas(Cube<int>& cu)
{
    for(int p = 0; p < cu.p; p++)
    {
        for(int f = 0; f < cu.f; f++)
        {
            for(int c = 0; c < cu.c; c++)
            {
                // Valor con forma FCP:
                // fila, columna, profundidad
                //
                // Ejemplo:
                // 120 = fila 1, columna 2, profundidad 0
                // 211 = fila 2, columna 1, profundidad 1

                int valor = f * 100 + c * 10 + p;

                cubeSetAt<int>(cu, valor, f, c, p, intToString);
            }
        }
    }
}

int main(){

    Cube<int> a = cube<int>(10, 5, 6, 0, intToString);

    printCube<int>(a, stringToInt, intToString);
    cout << "\n\n";

    rellenarCubeConCoordenadas(a);
    printCube<int>(a, stringToInt, intToString);
    
    cout << "\n\n";
    cout << "\n\n";
    cout << "\n\n";

    Cube<string> str = cube<string>(3, 2, 3, "0", stringToString);

    cubeSetAt<string>(str, "Daniel", 0, 0, 0, stringToString);
    cubeSetAt<string>(str, "pepe", 1, 0, 0, stringToString);
    cubeSetAt<string>(str, "danielon", 2, 0, 0, stringToString);

    cubeSetAt<string>(str, "asdasd", 0, 1, 0, stringToString);
    cubeSetAt<string>(str, "alberto", 1, 1, 0, stringToString);
    cubeSetAt<string>(str, "nose", 2, 1, 0, stringToString);


    cubeSetAt<string>(str, "sin ideas", 0, 0, 1, stringToString);
    cubeSetAt<string>(str, "me estoy", 1, 0, 1, stringToString);
    cubeSetAt<string>(str, "quedando", 2, 0, 1, stringToString);

    cubeSetAt<string>(str, "eee mesi", 0, 1, 1, stringToString);
    cubeSetAt<string>(str, "crack mesi", 1, 1, 1, stringToString);
    cubeSetAt<string>(str, "el messias", 2, 1, 1, stringToString);


    cubeSetAt<string>(str, "ya casi", 0, 0, 2, stringToString);
    cubeSetAt<string>(str, "terminamos", 1, 0, 2, stringToString);
    cubeSetAt<string>(str, "daleeee", 2, 0, 2, stringToString);

    cubeSetAt<string>(str, "falta poco", 0, 1, 2, stringToString);
    cubeSetAt<string>(str, "muuuuuy", 1, 1, 2, stringToString);
    cubeSetAt<string>(str, "pocooo", 2, 1, 2, stringToString);

    printCube<string>(str, stringToString, stringToString);
    return 0;
}