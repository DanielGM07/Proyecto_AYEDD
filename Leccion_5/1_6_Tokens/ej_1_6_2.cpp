#include <iostream>
#include <string>

#include "../../biblioteca/funciones/millis.hpp"
#include "../../biblioteca/funciones/files.hpp"
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/tads/intro/Fraccion.hpp"
#include "../../biblioteca/tads/parte1/Fecha.hpp"
#include "../../biblioteca/tads/parte1/Timer.hpp"
#include "../../biblioteca/tads/parte1/Coll.hpp"
#include "../../biblioteca/tads/parte2/Array.hpp"
#include "../../biblioteca/tads/parte2/List.hpp"
#include "../../biblioteca/tads/parte2/Map.hpp"
#include "../../biblioteca/tads/parte2/Queue.hpp"
#include "../../biblioteca/tads/parte2/Stack.hpp"
#include "../../principal.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::to_string;

// 1.6. Lección 5
// Los siguientes ejercicios deben resolverse usando las funciones de las bibliotecas
// de tokens y cadenas de caracteres.
// En todos los casos, salvo que se indique lo contrario, se debe considerar que
// el usuario ingresará por teclado un conjunto de valores numéricos enteros, finalizando
// el ingreso de datos con un valor 0 (cero), que no formará parte del conjunto.

string ingresoConjunto();

int main()
{
    // 1.6.2. Elementos repetidos
    // Mostrar todo el conjunto descartando los valores repetidos, si los hubiera.
    
    string conjunto;
    string conjSinRepes = "";
    string ingreso = "";
    cout << "Ingrese numeros enteros (finalice el ingreso con 0): ";
    conjunto = ingresoConjunto();
    
    for(int i = 0; i < tokenCount(conjunto, '|'); i++){
        string tokenActual = getTokenAt(conjunto, '|', i);
        if ((findToken(conjSinRepes, '|', tokenActual)) == -1) addToken(conjSinRepes, '|', tokenActual);
    }

    cout << "CONJUNTO: "<< conjunto << endl;
    cout << "CONJUNTO SIN REPETIDAS: "<< conjSinRepes << endl;

    return 0;    
}

string ingresoConjunto(){
    string ingreso;
    string conjRet;
    while(ingreso != "0"){
        addToken(conjRet, '|', ingreso);
        cin >> ingreso;
    }
    return conjRet;
}