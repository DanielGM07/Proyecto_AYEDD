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

string tsEntreCorchos(string s);

int main()
{
    // 1.6.3. Posiciones del máximo y mínimo
    // Indicar en qué posiciones se encuentra el máximo y el mínimo valor. Por ejemplo, si se
    // ingresa: 3, 6, 1, 8, -1, 2, 8, 4, -1, 5, la salida debería ser: Máximo: 8, en posiciones:
    // {3, 6}, Mínimo: -1, en posiciones: {4, 8}.
    
    // FUNCIONA EPETACULAAA, NOSE COMO PERO FUNCIONA
    // na mentira, codigo muy repetitivo que se puede reciclar, aunque asi ya esta bastante bien optimizado

    string conj;
    int maximo = 0, minimo = 0;
    string possMax = "";
    string possMin = "";
    cout << "Ingrese numeros enteros (finalice el ingreso con 0): ";
    conj = ingresoConjunto();
    
    // TODO lo que esta dentro de este for se puede OPTIMIZAR BASTANTE MUCHO
    for(int i = 0; i < tokenCount(conj, '|'); i++){
        int tokAct = stringToInt(getTokenAt(conj, '|', i));
        string posAct = intToString(i);
        if(i == 0){
            maximo = tokAct;
            minimo = tokAct;
            addToken(possMax, '|', posAct);
            addToken(possMin, '|', posAct);
        }else if(tokAct >= maximo){
            if(tokAct == maximo){
                addToken(possMax, '|', posAct);
            }else{
                possMax = "";
                addToken(possMax, '|', posAct);
                maximo = tokAct;
            }
        }else if(tokAct <= minimo){
            if(tokAct == minimo){
                addToken(possMin, '|', posAct);
            }else{
                possMin = "";
                addToken(possMin, '|', posAct);
                minimo = tokAct;
            }
        }
    }

    cout << "MAXIMO: "<< maximo << endl;
    cout << "POSICIONES MAXIMO: "<< tsEntreCorchos(possMax) << endl;
    cout << "\nMINIMO: "<< minimo << endl;
    cout << "POSICIONES MINIMO: "<< tsEntreCorchos(possMin) << endl;

    return 0;    
}

// Corte regex. Mentira, no tiene nada que ver con regex
// Si estas leyendo esto, echale una ojeadita a regex. 
// Si no venis bien con programacion, ni mires regex.
// Es solo un dato de color, mejor no busques regex, es horrible
// regexregexregexregexregexregexregexregexregexregexregexregexregexregex
string tsEntreCorchos(string s){
    string sRet = "";
    int cantTokens = tokenCount(s, '|');
    for(int i = 0; i < cantTokens; i++){
        string t = getTokenAt(s, '|', i);
        sRet = i == 0 && i == cantTokens - 1 ? "{" + s + "}" : 
               i == 0 ? "{" + t + ", ":
               i == cantTokens - 1 ? sRet + t + "}":
               sRet + t + ", ";
    }
    return sRet;
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