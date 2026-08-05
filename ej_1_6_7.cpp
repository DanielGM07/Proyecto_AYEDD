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
#include "principal.hpp"

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

string rotarValoresKVeces(string s, int k);

string ingresoConjunto();

int main()
{
    // 1.6.7. Rotar un conjunto de valores
    // Además del conjunto de valores numéricos enteros, el usuario ingresará un valor k que
    // llamaremos valore de rotación. Se pide mostrar todos los elementos del conjunto
    // rotándolos k posiciones. Por ejemplo, si el conjunto fuera: 1, 2, 3, 4, 5 y k=3, la
    // salida deberá ser: 3, 4, 5, 1, 2.
    // Es decir, en el ejemplo anterior el último valor es 5 y el primero es 1. Entonces,
    // sacamos el último valor y lo colocamos en el primer lugar, desplazando todos los demás
    // valores hacia la derecha. Así k veces.

    string conj;
    cout << "Ingrese un conjunto: " << endl;
    conj = ingresoConjunto();
    cout << "Ingrese la cantidad de veces que lo quiere rotar: " << endl;
    int kVeces = 0;
    cin >> kVeces;
    string conjRotado = rotarValoresKVeces(conj, kVeces);
    cout << "CONJUNTO: " << conj << endl;
    cout << "CONJUNTO ROTADO: " << conjRotado << endl;

    return 0;    
}

string rotarValoresKVeces(string s, int k){
    string sRotado;
    int ts = tokenCount(s, '|');
    int modK = k % ts;
    if(modK == 0) return s;
    for(int i = 0; i < ts; i++){
        // 0 1 2 3 4 pos
        // 1 2 3 4 5
        // 
        int posTokAct = i == 0 ? ts - modK : 
                     posTokAct + 1 == ts ? 
                     0 : 
                     posTokAct + 1;
        string tokAct = getTokenAt(s, '|', posTokAct);
        addToken(sRotado, '|', tokAct);
    }
    return sRotado;
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