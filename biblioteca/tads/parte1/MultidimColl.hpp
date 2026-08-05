#ifndef _TMTX_T_
#define _TMTX_T_

#include <iostream>

#include "Coll.hpp"

using std::string;

// Uso std porque quiero imprimir algunas cosas
using std::cout;

// 1.4.4.1. Estructura del TAD
template <typename T>
struct Mtx
{
    Coll<T> colls;
    int f;
    int c;
};

// 1.4.4.2. Función mtx
// Prototipo: Mtx<T> mtx(int rows
//                      ,int cols
//                      ,T defaultValue
//                      ,string tToString(T));
// Descripción: Crea y retorna una matriz de rows filas por cols columnas, asignando
// defaultValue a cada una de las rows*cols celdas.
template <typename T>
Mtx<T> mtx(int f, 
           int c, 
           T valorDefault, 
           string tToString(T))
{
    // A ESTO LE ESTARIA FALTANDO UN METODO DE CONVERSION DE COLLTOSTRING
    // Coll< Coll<T> > filas = coll<Coll<T>>();
    // int posFila = 0;
    // while(posFila < f){
    //     Coll<T> columnas;
    //     int posCol = 0;
    //     while(posCol < c){
    //         posCol = collAdd(columnas, valorDefault, tToString);
    //     }
    //     posFila = collAdd(filas, columnas, tToString);
    // }
    // Mtx<T> mtx;
    // mtx.colls = filas;
    // return mtx;

    Mtx<T> mtx;
    mtx.colls = coll<T>();
    mtx.f = f;
    mtx.c = c;

    for(int i = 0; i < f*c; i++){
        collAdd<T>(mtx.colls, valorDefault, tToString);
    }

    return mtx;
}

template <typename T>
int coordenadasToInt(Mtx<T> m, int f, int c)
{
    return 0;
}

// 1.4.4.4. Función mtxGetAt
// Prototipo: T mtxGetAt(Mtx<T> m
//                       ,int row
//                       ,int col
//                       ,T tFromString(string));
// Descripción: Retorna el valor que contiene la matriz en la celda [row,col].
template <typename T>
T mtxGetAt(Mtx<T> m, int f, int c, T tFromString(string))
{
    T t = collGetAt<T>(m.colls, (f*m.c) + c, tFromString);
    return t;
}

// 1.4.4.3. Función mtxSetAt
// Prototipo: void mtxSetAt(Mtx<T> m
//                          ,T value
//                          ,int row
//                          ,int col
//                          ,string tToString(T));
// Descripción: Asigna value en la celda de la intersección [row,col] de la matriz.     
template <typename T>
void mtxSetAt(Mtx<T>& m,            // EN QUE MATRIXXX
              T t,                  // VALOR QUE SE ASIGNARA
              int f,                // EN QUE FILA SE ASIGNARA
              int c,                // COLUMNAS
              string tToString(T))  // SI E
{
    collSetAt<T>(m.colls, 
                 t, 
                 (f*m.c) + c, // recordar que las filas (f) y columnas (c)
                              // empiezan desde 0 (cero)
                 tToString);
}

template<typename T>
void printMtx(Mtx<T> m, 
              T tFromString(string),
              string tToString(T)){
    string s;
    for(int row = 0; row < m.f; row++){
        for(int col = 0; col < m.c; col++){
            T t = mtxGetAt<T>(m, row, col, tFromString);
            string tStr = tToString(t);
            s = col == 0 && col == m.c - 1 ? "[" + s + "]" : 
                col == 0 ? "[" + tStr + "\t":
                col == m.c - 1 ? s + tStr + "]":
                s + tStr + "\t";
        }
        cout << s << "\n";
    }
}

template <typename T>
struct Cube
{
    Coll<T> colls;
    int f;
    int c;
    int p;
};

template <typename T>
Cube<T> cube(int f, 
             int c, 
             int p, 
             T valorDefault, 
             string tToString(T))
{
    // ESTO IBA BIEN ENCAMINADO, PERO, NECESITARIAMOS DE MUCHAS OTRAS FUNCIONES Y TENER 
    // MUCHAS COSAS EN CUENTA, ASI QUE VAMOS A AGARRARLO MAS POR UN CAMINO LINEAL, AL IGUAL
    // QUE EL TAD MATRIX
    // Coll<Mtx<T>> collMtxs;
    // Mtx<T> mtx;
    // for(int i = 0; i < p; i++){
    //     mtx<T>(f, c, valorDefault, tToString);
    //     collAdd<Mtx<T>>(collMtxs, mtx, tToString);
    // }
    // return {};

    Cube<T> cube;
    cube.colls = coll<T>();
    cube.f = f;
    cube.c = c;
    cube.p = p;

    // 1RA FORMA QUE SE ME OCURRIO
    // for(int i = 0; i < p; i++){
    //     for (int j = 0; j < f; j++){
    //         for (int k = 0; k < c; k++){
    //             collAdd<T>(cube.colls, valorDefault, tToString);
    //         }
    //     }
    // }

    // 2DA FORMA
    for(int i = 0; i < p; i++){
        for (int j = 0; j < f*c; j++){
            collAdd<T>(cube.colls, valorDefault, tToString);
        }
    }

    // 3RA FORMA
    // for (int i = 0; i < p*f*c; i++){
    //     CollAdd<T>(cube.colls, valorDefault, tToString);
    // }

    // Porque funcionan las tres formas?
    // Al tratarse de colleciones lineales (es decir estamos 
    // usando el TAD Coll directamente que guarda todo en un solo string)
    // Entonces simplemente vamos asignando valores hasta que lleguemos al
    // largo de nuestra cadena, que va a ser la cantidad de columnas, por 
    // filas por profundidad

    return cube;
}

template <typename T>
int coordenadasToInt(Cube<T> cu, int f, int c, int p)
{
    return 0;
}


template <typename T>
T cubeGetAt(Cube<T> cube, int f, int c, int p, T tFromString(string))
{
    T t = collGetAt<T>(cube.colls, 
                      (p * cube.f * cube.c) + (f * cube.c) + c,
                      tFromString);
    return t;
}

// 1.4.6.3. Función cubeSetAt
// Prototipo: void cubeSetAt(Cube<T> c
//                           ,T value
//                           ,int row
//                           ,int col
//                           ,int deep
//                           ,string tToString(T));
// Descripción: Asigna value en la celda de la intersección [row,col,deep] del cubo c.
template <typename T>
void cubeSetAt(Cube<T>& cube, T t, int f, int c, int p, string tToString(T))
{
    collSetAt<T>(cube.colls, 
                 t, 
                 (p*cube.f*cube.c) + (f*cube.c) + c, // recordar que las filas (f) y columnas (c)
                                                     // empiezan desde 0 (cero) y tambien la
                                                     // profundidad (p)
                 tToString);
}

template <typename T>
void printCube(Cube<T> cube, 
               T tFromString(string),
               string tToString(T)){
    string s;
    for(int deep = cube.p-1; deep >= 0; deep--){
        // OPTIMIZAR EL FOR DE TABS CON UNA FUNCION
        for(int tabsD = deep; tabsD < cube.p-1; tabsD++){
            cout << "\t";
        }
        cout << "Deep: " << deep << "\n";
        for(int row = 0; row < cube.f; row++){
            for(int col = 0; col < cube.c; col++){
                T t = cubeGetAt<T>(cube, row, col, deep, tFromString);
                string tStr = tToString(t);
                s = col == 0 && col == cube.c - 1 ? "[" + s + "]" : 
                    col == 0 ? "[" + tStr + "\t":
                    col == cube.c - 1 ? s + tStr + "]":
                    s + tStr + "\t";
            }
            for(int tabs = deep; tabs < cube.p-1; tabs++){
                cout << "\t";
            }
            cout << s << "\n";
        }

        cout << "\n";
        // for(int tabs = deep; tabs < cube.p-1; tabs++){
        //     cout << "\t";
        // }

        // [1   2   3]
        // [1   2   3]
        // [1   2   3]
        //      [1   2   3]
        //      [1   2   3]
        //      [1   2   3]
        //          [1   2   3]
        //          [1   2   3]
        //          [1   2   3]
        //              ...
    }
        
}

//  [0, 1, 2]
//  [0, 1, 2]
//  [0, 1, 2]
//      [0, 1, 2]
//      [0, 1, 2]
//      [0, 1, 2]
//          [0, 1, 2]
//          [0, 1, 2]
//          [0, 1, 2]

//  [0, 1, 2]
//  [0, 1, 2]
//  [0, 1, 2] [0, 1, 2]     
//            [0, 1, 2] 
//            [0, 1, 2] [0, 1, 2]
//                      [0, 1, 2]
//                      [0, 1, 2] 

//  [0, 1, 2]
//  [0, 1, 2]
//  [0, 1, 2]
//           [0, 1, 2]
//           [0, 1, 2]
//           [0, 1, 2]
//                    [0, 1, 2]
//                    [0, 1, 2]
//                    [0, 1, 2]

// PURO CHICHE JAJAJA 1
//  [0, 1, 2]
//  [0, [0, 1, 2]
//  [0, [0, [0, 1, 2]
//      [0, [0, [0, 1, 2]
//          [0, [0, 1, 2]
//              [0, 1, 2]

// PURO CHICHE JAJAJA 2
//  [0, 1, 2]
//  [0,[0, 1, 2]
//  [0,[0,[0, 1, 2]
//     [0,[0,[0, 1, 2]
//        [0,[0, 1, 2]
//           [0, 1, 2]

#endif
