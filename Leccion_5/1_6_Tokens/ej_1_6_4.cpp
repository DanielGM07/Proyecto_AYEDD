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
    // 1.6.4. Suma
    // Mostrar todos los pares, tal la suma de sus componentes sea 30. Por ejemplo, si el
    // conjunto ingresado fuera: 3, 25, 8, 2, 5, 19, 22, 9, 14, 11, 4, la salida debería ser:
    // 25+5 = 30
    // 8+22 = 30
    // 19+11 = 30
    
    // Funca perfecto

    string conj;
    cout << "Ingrese un conjunto: " << endl;
    conj = ingresoConjunto();
    int ts = tokenCount(conj, '|');
    string sumaPar;

    for(int i = 0; i < ts; i++){
        string tIStr = getTokenAt(conj, '|', i);
        int tI = stringToInt(getTokenAt(conj, '|', i));
        for(int j = 1; j < ts; j++){
            string tJStr = getTokenAt(conj, '|', i+j);
            int tJ = stringToInt(getTokenAt(conj, '|', i+j));
                sumaPar = tI + tJ == 30 ? tIStr + " + " + tJStr + " = 30" : "";
                if(sumaPar != "") cout << sumaPar << endl;
        }
    }
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