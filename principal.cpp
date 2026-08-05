
#include <iostream>
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

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;

int main()
{
    // cout << "Hola Mundo !" << endl;
    // return 0;

    /*
    Fraccion a = fraccion(2,9);
    cout << fraccionToString(a) << endl; // debo ver 2/9
    Fraccion b = fraccion(4,6);

    Fraccion c = fraccionSumar(a,b);
    cout << fraccionToString(c) << endl; // debo ver 48/54
    Fraccion d = fraccionSimplificar(c);
    cout << fraccionToString(d) << endl; // debo ver 8/9
    cout << "\n";
    cout << "\n";

    Fraccion multEsc = fraccionMultiplicar(a, 3);
    Fraccion multFra = fraccionMultiplicar(a, b);
    cout << fraccionToString(multEsc) << endl;
    cout << fraccionToString(multFra) << endl;

    cout << "\n";
    cout << fraccionToString(fraccionSimplificar(multEsc)) << endl;
    cout << fraccionToString(fraccionSimplificar(multFra)) << endl;
    cout << "\n";
    */

    // ts es una fecha expresada en milisegundos
    long long ts = attributesToMillis(2026, 5, 27, 14, 35, 20, 123);

    // f es una fecha expresada como estructura que tiene atributos
    Fecha f = fecha(ts);

    cout << "Timestamp en milisegundos: " << ts << endl;
    cout << "Fecha completa: " << millisToString(ts) << endl;

    cout << "Anio: " << f.anio << endl;
    cout << "Mes: " << f.mes << endl;
    cout << "Dia: " << f.dia << endl;
    cout << "Hora: " << f.hora << endl;
    cout << "Minuto: " << f.minuto << endl;
    cout << "Segundo: " << f.segundo << endl;
    cout << "Milisegundo: " << f.milisegundo << endl;

    return 0;
}
