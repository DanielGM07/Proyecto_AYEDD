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


int main()
{
    Fecha f = fecha(2020, 12, 30, 14, 30);

    cout << "Anio: " << f.anio << endl;
    cout << "Mes: " << f.mes << endl;
    cout << "Dia: " << f.dia << endl;
    cout << "Hora: " << f.hora << endl;
    cout << "Minuto: " << f.minuto << endl;
    cout << "Segundo: " << f.segundo << endl;
    cout << "Milisegundo: " << f.milisegundo << endl;
    
    return 0;    
}