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