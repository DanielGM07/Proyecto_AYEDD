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
    /*
    ENERO       MES 1   : 31 DIAS
    FEBRERO     MES 2   : 28 O 29 DIAS DEPENDE EL ANIO
    MARZO       MES 3   : 31 DIAS
    ABRIL       MES 4   : 30 DIAS
    MAYO        MES 5   : 31 DIAS
    JUNIO       MES 6   : 30 DIAS
    JULIO       MES 7   : 31 DIAS
    AGOSTO      MES 8   : 31 DIAS
    SEPTIEMBRE  MES 9   : 30 DIAS
    OCTUBRE     MES 10  : 31 DIAS
    NOVIEMBRE   MES 11  : 30 DIAS
    DICIEMBRE   MES 12  : 31 DIAS   
    */
    // Fecha f1 = fecha(2024, 11, 10, 15, 30, 10, 501);
    cout << "DIAS: " << fechaDiasEnMes(2, 2023) << endl;
    return 0;    
}