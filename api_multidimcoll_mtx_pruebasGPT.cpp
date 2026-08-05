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

using namespace std;

// TODO ESTE .CPP ES UNA PRUEBA DEL TAD MATRIX Y SUS FUNCIONES
// PROGRAMADAS POR MI EN EL MULTIDIMCOLL.HPP
// TODO ESTE .CPP FUE HECHO POR GPT EN BASE A LO QUE PROGRAME

void imprimirMtxInt(Mtx<int> m)
{
    for(int f = 0; f < m.f; f++)
    {
        cout << "[ ";
        for(int c = 0; c < m.c; c++)
        {
            cout << mtxGetAt<int>(m, f, c, stringToInt);

            if(c < m.c - 1)
            {
                cout << ", ";
            }
        }
        cout << " ]" << endl;
    }
};

void titulo(string s)
{
    cout << endl;
    cout << "==============================" << endl;
    cout << s << endl;
    cout << "==============================" << endl;
}

int main()
{
    // ---------------------------------------------------------
    // MATRIZ 2x3
    // ---------------------------------------------------------
    titulo("Matriz A - 2x3");

    Mtx<int> a = mtx<int>(2, 3, 0, intToString);

    mtxSetAt<int>(a, 10, 0, 0, intToString);
    mtxSetAt<int>(a, 11, 0, 1, intToString);
    mtxSetAt<int>(a, 12, 0, 2, intToString);

    mtxSetAt<int>(a, 20, 1, 0, intToString);
    mtxSetAt<int>(a, 21, 1, 1, intToString);
    mtxSetAt<int>(a, 22, 1, 2, intToString);

    imprimirMtxInt(a);
    cout << "\n";
    printMtx<int>(a, stringToInt, intToString);

    cout << endl;
    cout << "Valor esperado en [1,2]: 22" << endl;
    cout << "Valor obtenido en [1,2]: ";
    cout << mtxGetAt<int>(a, 1, 2, stringToInt) << endl;


    // ---------------------------------------------------------
    // MATRIZ 3x3 tipo identidad
    // ---------------------------------------------------------
    titulo("Matriz B - 3x3 identidad");

    Mtx<int> b = mtx<int>(3, 3, 0, intToString);

    mtxSetAt<int>(b, 1, 0, 0, intToString);
    mtxSetAt<int>(b, 1, 1, 1, intToString);
    mtxSetAt<int>(b, 1, 2, 2, intToString);

    imprimirMtxInt(b);


    // ---------------------------------------------------------
    // MATRIZ 1x5, una sola fila
    // ---------------------------------------------------------
    titulo("Matriz C - 1x5");

    Mtx<int> c = mtx<int>(1, 5, 9, intToString);

    mtxSetAt<int>(c, 1, 0, 0, intToString);
    mtxSetAt<int>(c, 2, 0, 1, intToString);
    mtxSetAt<int>(c, 3, 0, 2, intToString);
    mtxSetAt<int>(c, 4, 0, 3, intToString);
    mtxSetAt<int>(c, 5, 0, 4, intToString);

    imprimirMtxInt(c);


    // ---------------------------------------------------------
    // MATRIZ 4x1, una sola columna
    // ---------------------------------------------------------
    titulo("Matriz D - 4x1");

    Mtx<int> d = mtx<int>(4, 1, 0, intToString);

    mtxSetAt<int>(d, 100, 0, 0, intToString);
    mtxSetAt<int>(d, 200, 1, 0, intToString);
    mtxSetAt<int>(d, 300, 2, 0, intToString);
    mtxSetAt<int>(d, 400, 3, 0, intToString);

    imprimirMtxInt(d);


    // ---------------------------------------------------------
    // MATRIZ 1x1
    // ---------------------------------------------------------
    titulo("Matriz E - 1x1");

    Mtx<int> e = mtx<int>(1, 1, 777, intToString);

    imprimirMtxInt(e);

    cout << endl;
    cout << "Valor esperado en [0,0]: 777" << endl;
    cout << "Valor obtenido en [0,0]: ";
    cout << mtxGetAt<int>(e, 0, 0, stringToInt) << endl;


    // ---------------------------------------------------------
    // PRUEBAS QUE PUEDEN ROMPER
    // NO LAS EJECUTES TODAS DE UNA
    // ---------------------------------------------------------

    /*
    titulo("Prueba que puede romper - fila fuera de rango");

    // Matriz A tiene filas 0 y 1.
    // Pedir fila 2 NO corresponde.
    cout << mtxGetAt<int>(a, 2, 0, stringToInt) << endl;
    */

    /*
    titulo("Prueba que puede romper - columna fuera de rango");

    // Matriz A tiene columnas 0, 1 y 2.
    // Pedir columna 3 NO corresponde.
    cout << mtxGetAt<int>(a, 0, 3, stringToInt) << endl;
    */

    /*
    titulo("Prueba que puede romper - posicion negativa");

    // No usamos posiciones negativas.
    cout << mtxGetAt<int>(a, -1, 0, stringToInt) << endl;
    */

    /*
    titulo("Prueba delicada - numeros negativos");

    // Esto depende de si tu stringToInt sabe convertir strings con '-'.
    // Si tu stringToInt solo acepta digitos, esto puede fallar.
    Mtx<int> neg = mtx<int>(2, 2, -1, intToString);
    imprimirMtxInt(neg);
    */

    /*
    titulo("Prueba delicada - matriz con 0 filas");

    // Crear puede no romper porque no agrega elementos.
    // Pero NO deberias hacer get/set sobre esta matriz.
    Mtx<int> vacia = mtx<int>(0, 3, 0, intToString);
    imprimirMtxInt(vacia);
    */

    return 0;
}