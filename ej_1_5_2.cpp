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

int primerNroConMDigitosD(int nroInicio, int m, int d);

void imprimirNNumeros(int nroInicio, int n, int m, int d);

int main()
{
    // 1.5.2. Primeros n números que tienen m dígitos d
    // Dificultad: moderada, Requerido: Indispensable.
    // Se ingresan por teclado 3 valores enteros: n, m y d. Se pide mostrar por consola los
    // primeros n números naturales que tienen, al menos, m dígitos d. Por ejemplo, si
    // n=5, m=3 y d=4, la salida del programa debería ser: 444, 1444, 2444, 3444, 4044.

    // string primerosNNaturales = "n";
    // string minimaCantidadApariciones = "m";
    // string digitoQueBuscamos = "d";

    int n = 0, m = 0, d = 0;
    while(true){
        cout << "Ingrese una N cantidad de nros con M cantidad de digitos D: ";
        cin >> n >> m >> d;
    
        imprimirNNumeros(1, n, m, d);
        cout << "\n";
    }
    return 0;    
}

// int numerosConMDigitosD();

// La funcion a continuacion, rehacerla mas adelante, ya que, con esta se buscaba optimizar mas el programa, en vez de ir buscando
// de numero en numero, con paso 1. Usar los multiplos de D. 
// Ej: ingresamos los primeros 5 numeros con una cantidad 1 de 5s. La salida es 5 15 25. 
// Todos son multiplos de 5. 
// HMMM aunque sin embargo, si por ejemplo, estamos en 500, la proxima salida valida seria 501, no 505. PARA PENSAR

// REPAMPANOS, tendre que dejar de trabajar con esta funcion, la queria pensar de una manera muy compleja
// int primerNroConMDigitosD(int nroInicio, int m, int d){
//     int n = nroInicio;
//     int digitosDEnN = 0; 
//     while(digitosDEnN < m){
//         if(digitCount(n) >= m){
//             for(int i = 0; i < digitCount(n); i++){
//                 if(getDigit(n, i) == d){
//                     digitosDEnN++;
//                 }
//             }
//         }
//     }
// }

int primerNroConMDigitosD(int nroInicio, int m, int d){
    int n = nroInicio - 1;
    int digitosDEnN = 0; 
    while(digitosDEnN < m){
        n++;
        digitosDEnN = 0; 
        if(digitCount(n) >= m){
            for(int i = 0; i < digitCount(n); i++){
                if(getDigit(n, i) == d){
                    digitosDEnN++;
                }
            }
        }
    }
    return n;
}

void imprimirNNumeros(int nroInicio, int n, int m, int d){
    for(int i = 1; i <= n; i++){
        int numerinNumerazo = primerNroConMDigitosD(nroInicio, m, d);
        cout << i << ". " << numerinNumerazo << endl;
        nroInicio = numerinNumerazo + 1;
    }
}