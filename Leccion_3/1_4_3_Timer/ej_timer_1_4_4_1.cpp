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


// Probar cuánto tiempo demora un doble while
// Utilizar el TAD Timer para medir cuánto demora la computadora en resolver la función
// f, para los siguientes valores de n: 100, 1000, 10000, 100000.

void f(int n);

int main()
{
    Timer t = timer();
    int x;
    cout << "Ingrese un numero para conocer cuanto demora la funcion: " << endl;
    cin >> x;
    timerStart(t);
    f(x);
    timerStop(t);
    double segundos = (double)timerElapsedTime(t)/1000;
    cout << "La funcion demoro " << segundos << " segundos" << endl;
    
    return 0;    
}

void f(int n)
{
    int i=0;
    while(i<n)
    {
        int j=0;
        while(j<n)
        {
            j = j+1;
        }
        i = i+1;
    }
}