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


int main()
{
    Fecha f1 = fecha(2026, 4, 20, 17, 30);
    Fecha f2 = fecha(2021, 2, 10, 7, 40);
    Fecha f3 = fecha(2022, 10, 45, 11, 10);
    Fecha f4 = fecha(2018, 7, 9, 20, 25);    

    Fecha fSumaSegundos = fechaAddSegundos(f1, 75);
    cout << fechaToString(f1) << endl;
    cout << fechaToString(fSumaSegundos) << endl;

    cout << "\n";

    Fecha fSumaMinutos = fechaAddMinutos(f2, 65);
    cout << fechaToString(f2) << endl;
    cout << fechaToString(fSumaMinutos) << endl;

    cout << "\n";

    Fecha fSumaHoras = fechaAddHoras(f3, 20);
    cout << fechaToString(f3) << endl;
    cout << fechaToString(fSumaHoras) << endl;

    cout << "\n";

    Fecha fSumaDias = fechaAddDias(f4, 10);
    cout << fechaToString(f4) << endl;
    cout << fechaToString(fSumaDias) << endl;

    return 0;    
}