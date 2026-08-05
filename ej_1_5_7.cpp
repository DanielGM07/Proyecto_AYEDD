#include <iostream>
#include <string>

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
#include "biblioteca/tads/tads_propios/BigInt.hpp"
#include "biblioteca/tads/tads_propios/Matriz.hpp"
#include "principal.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::to_string;

int main()
{
    // 1.5.7 TAD Matriz
    // FINISHED

    // cout << "Ingrese una cadena: " << endl;
    // string sMtz = "";
    // cin >> sMtz;
    // cout << "Great! Ahora ingrese filas y columnas: " << endl;
    // int f = 0, c = 0;
    // cin >> f >> c;
    // Matriz mtz = matriz(sMtz, f, c);
    // int filav = 2, colv = 1;

    // cout << "LA MATRIXXX: \n" << endl;
    // imprimirMatriz(mtz);
    // cout << "\n" << endl;
    // cout << "FILA: " << filav << " y COLUMNA: " << colv 
    //      << "\nVALOR: " << matrizGet(mtz, filav, colv) << endl;
    // cout << "\n" << endl;

    // matrizSet(mtz, 3, 3, 7);
    // imprimirMatriz(mtz);
    // cout << "\n\n\n" << endl;

    Matriz m1;
    Matriz m2;
    cout << "Ingrese 2 matrices de misma cantidad de filas y columnas: " << endl;
    cout << "Matriz 1 valores: ";
    cin >> m1.s;
    cout << "Matriz filas y columnas: ";
    cin >> m1.filas >> m1.columnas;
    cout << "Matriz 2 valores: ";
    cin >> m2.s;
    cout << "Matriz filas y columnas: ";
    cin >> m2.filas >> m2.columnas;
    imprimirMatriz(m1);
    cout << "\n-\n" << endl;
    imprimirMatriz(m2);
    cout << "\n_________________\n" << endl;
    Matriz mSuma = miMatrizRestar(m1, m2);
    imprimirMatriz(mSuma);
    return 0;
}