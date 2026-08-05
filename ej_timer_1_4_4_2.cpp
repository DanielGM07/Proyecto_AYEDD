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

// 1.4.4.2. Cuánto demora calcular un número de Fibonacci
// Usando la siguiente implementación recursiva del número de Fibonacci, calcular cuánto
// tiempo podría requerir resolver fibonacci(100).
// Sugerencia: medir cuánto demora para n=40, n=41, ..., n=50, e inferir.

double fibonacci(int n);

int main()
{
    Timer t = timer();
    int x;
    cout << "Ingrese un numero para conocer cuanto demora la funcion FIBONACCI: " << endl;
    cin >> x;
    timerStart(t);
    double n = fibonacci(x);
    timerStop(t);
    double segundos = (double)timerElapsedTime(t)/1000;
    cout << "La funcion demoro " << segundos << " segundos" << endl;
    cout << "FIBONACCI N: " << n << endl;

    return 0;    
}

double fibonacci(int n)
{
    if(n<2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}