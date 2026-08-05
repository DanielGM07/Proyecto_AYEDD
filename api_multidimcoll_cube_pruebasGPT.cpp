#include <iostream>

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

void imprimirValor3(int x)
{
    if(x >= 0 && x < 10)
    {
        cout << "00";
    }
    else if(x >= 0 && x < 100)
    {
        cout << "0";
    }

    cout << x;
}

void imprimirCubeInt(Cube<int> cu)
{
    cout << endl;
    cout << "Cube de " << cu.f << " filas x ";
    cout << cu.c << " columnas x ";
    cout << cu.p << " profundidades" << endl;

    for(int p = 0; p < cu.p; p++)
    {
        cout << endl;
        cout << "p = " << p << endl;

        for(int f = 0; f < cu.f; f++)
        {
            cout << "f=" << f << " [ ";

            for(int c = 0; c < cu.c; c++)
            {
                int valor = cubeGetAt<int>(cu, f, c, p, stringToInt);
                imprimirValor3(valor);

                if(c < cu.c - 1)
                {
                    cout << ", ";
                }
            }

            cout << " ]" << endl;
        }
    }
}

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
    // CUBE 2x2x2
    // ---------------------------------------------------------
    titulo("Cube A - 2x2x2");

    Cube<int> a = cube<int>(2, 2, 2, 0, intToString);

    rellenarCubeConCoordenadas(a);
    imprimirCubeInt(a);

    cout << endl;
    cout << "Valor esperado en [f=1, c=1, p=1]: 111" << endl;
    cout << "Valor obtenido en [f=1, c=1, p=1]: ";
    cout << cubeGetAt<int>(a, 1, 1, 1, stringToInt) << endl;


    // ---------------------------------------------------------
    // CUBE 3x3x3
    // ---------------------------------------------------------
    titulo("Cube B - 3x3x3");

    Cube<int> b = cube<int>(3, 3, 3, 0, intToString);

    rellenarCubeConCoordenadas(b);
    imprimirCubeInt(b);

    cout << endl;
    cout << "Valor esperado en [f=2, c=1, p=2]: 212" << endl;
    cout << "Valor obtenido en [f=2, c=1, p=2]: ";
    cout << cubeGetAt<int>(b, 2, 1, 2, stringToInt) << endl;


    // ---------------------------------------------------------
    // CUBE 1x3x2 - una sola fila
    // ---------------------------------------------------------
    titulo("Cube C - 1x3x2");

    Cube<int> c = cube<int>(1, 3, 2, 0, intToString);

    rellenarCubeConCoordenadas(c);
    imprimirCubeInt(c);


    // ---------------------------------------------------------
    // CUBE 3x1x2 - una sola columna
    // ---------------------------------------------------------
    titulo("Cube D - 3x1x2");

    Cube<int> d = cube<int>(3, 1, 2, 0, intToString);

    rellenarCubeConCoordenadas(d);
    imprimirCubeInt(d);


    // ---------------------------------------------------------
    // CUBE 1x1x1
    // ---------------------------------------------------------
    titulo("Cube E - 1x1x1");

    Cube<int> e = cube<int>(1, 1, 1, 777, intToString);

    imprimirCubeInt(e);

    cout << endl;
    cout << "Valor esperado en [f=0, c=0, p=0]: 777" << endl;
    cout << "Valor obtenido en [f=0, c=0, p=0]: ";
    cout << cubeGetAt<int>(e, 0, 0, 0, stringToInt) << endl;


    // ---------------------------------------------------------
    // PRUEBAS QUE PUEDEN ROMPER
    // NO DESCOMENTAR TODAS DE UNA
    // ---------------------------------------------------------

    /*
    titulo("Prueba que puede romper - fila fuera de rango");

    // Cube A tiene filas 0 y 1.
    // Pedir fila 2 NO corresponde.
    cout << cubeGetAt<int>(a, 2, 0, 0, stringToInt) << endl;
    */

    /*
    titulo("Prueba que puede romper - columna fuera de rango");

    // Cube A tiene columnas 0 y 1.
    // Pedir columna 2 NO corresponde.
    cout << cubeGetAt<int>(a, 0, 2, 0, stringToInt) << endl;
    */

    /*
    titulo("Prueba que puede romper - profundidad fuera de rango");

    // Cube A tiene profundidades 0 y 1.
    // Pedir profundidad 2 NO corresponde.
    cout << cubeGetAt<int>(a, 0, 0, 2, stringToInt) << endl;
    */

    /*
    titulo("Prueba que puede romper - posicion negativa");

    // No usamos posiciones negativas.
    cout << cubeGetAt<int>(a, -1, 0, 0, stringToInt) << endl;
    */

    /*
    titulo("Prueba delicada - valores negativos");

    // Esto depende de si tu stringToInt soporta el signo '-'.
    Cube<int> neg = cube<int>(2, 2, 2, -1, intToString);
    imprimirCubeInt(neg);
    */

    /*
    titulo("Prueba delicada - cube con 0 profundidades");

    // Crear puede no romper porque no agrega elementos.
    // Pero NO deberias hacer get/set sobre este cube.
    Cube<int> vacio = cube<int>(2, 2, 0, 0, intToString);
    imprimirCubeInt(vacio);
    */

    return 0;
}