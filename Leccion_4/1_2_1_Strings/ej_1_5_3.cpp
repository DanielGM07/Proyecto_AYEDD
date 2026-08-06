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

bool esAnagrama(string a,string b);

int main()
{
    // 1.5.3. Anagrama
    // Dificultad: moderada, Requerido: Indispensable.
    //
    // Desarrollar y probar adecuadamente una función llamada esAnagrama,
    // que reciba dos cadenas de caracteres y determine si ambas son anagramas
    // entre sí.
    //
    // La función debe responder con true si las dos cadenas contienen exactamente
    // los mismos caracteres, con la misma cantidad de apariciones de cada uno,
    // aunque estén ubicados en distinto orden.
    //
    // En caso contrario, debe responder false.
    //
    // Prototipo:
    // bool esAnagrama(string a, string b);

    // Dos cadenas son anagramas si:
    // - Tienen la misma cantidad de caracteres.
    // - Contienen exactamente los mismos caracteres.
    // - Cada carácter aparece la misma cantidad de veces en ambas.
    // - El orden de los caracteres puede ser diferente.
    // - No sobra ni falta ningún carácter.
    // - Se comparan caracteres, no significados.
    // - Mayúsculas, minúsculas, espacios y símbolos cuentan,
    //   salvo que la consigna indique lo contrario.

    // while(true){
    string a = "", b = "";
    cout << "Ingrese dos cadenas para saber si son anagramas: ";
    cin >> a;
    cin >> b;
    string anagramus = esAnagrama(a, b) ? "CHI ES ANAGRAMA :)" : "NIO ES ANAGRAMA :(";
    cout << anagramus << endl;
    // }

    return 0;    
}

bool esAnagrama(string a,string b){
    if(length(a) != length(b)){
        return false;
    }else{
        int largoInicial = length(a);
        for(int i = 0; i < largoInicial; i++){
            char c = a[0];
            if(contains(b, c)){
                a = removeAt(a, 0);
                b = removeAt(b, indexOf(b, c));
            }else{
                return false;
            }
        }
    }
    return true;
}