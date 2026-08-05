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

int main(){

    Mtx<int> a = mtx<int>(5, 6, 0, intToString);

    printMtx<int>(a, stringToInt, intToString);
    cout << "\n";

    mtxSetAt<int>(a, 1000,  0, 0, intToString);
    mtxSetAt<int>(a, 11,    0, 1, intToString);
    mtxSetAt<int>(a, 2,     0, 2, intToString);
    mtxSetAt<int>(a, 104,   0, 3, intToString);
    mtxSetAt<int>(a, 11,    0, 4, intToString);
    mtxSetAt<int>(a, 126,   0, 5, intToString);

    mtxSetAt<int>(a, 1000,  1, 0, intToString);
    mtxSetAt<int>(a, 11,    1, 1, intToString);
    mtxSetAt<int>(a, 2,     1, 2, intToString);
    mtxSetAt<int>(a, 104,   1, 3, intToString);
    mtxSetAt<int>(a, 11,    1, 4, intToString);
    mtxSetAt<int>(a, 126,   1, 5, intToString);

    mtxSetAt<int>(a, 1000,  2, 0, intToString);
    mtxSetAt<int>(a, 11,    2, 1, intToString);
    mtxSetAt<int>(a, 2,     2, 2, intToString);
    mtxSetAt<int>(a, 104,   2, 3, intToString);
    mtxSetAt<int>(a, 11,    2, 4, intToString);
    mtxSetAt<int>(a, 126,   2, 5, intToString);

    mtxSetAt<int>(a, 1000,  3, 0, intToString);
    mtxSetAt<int>(a, 11,    3, 1, intToString);
    mtxSetAt<int>(a, 2,     3, 2, intToString);
    mtxSetAt<int>(a, 104,   3, 3, intToString);
    mtxSetAt<int>(a, 11,    3, 4, intToString);
    mtxSetAt<int>(a, 126,   3, 5, intToString);

    mtxSetAt<int>(a, 1000,  4, 0, intToString);
    mtxSetAt<int>(a, 110123,    4, 1, intToString);
    mtxSetAt<int>(a, 2,     4, 2, intToString);
    mtxSetAt<int>(a, 104,   4, 3, intToString);
    mtxSetAt<int>(a, 11,    4, 4, intToString);
    mtxSetAt<int>(a, 126,   4, 5, intToString);

    printMtx<int>(a, stringToInt, intToString);
    return 0;
}