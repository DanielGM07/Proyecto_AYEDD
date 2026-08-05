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
    Fecha f1 = fecha(2019, 11, 10, 15, 30, 10, 501);
    Fecha f2 = fecha(2019, 11, 10, 15, 30, 10, 502);
    
    int cmp = fechaCmp(f1, f2);

    if(cmp > 0){
        cout << "Fecha 1 es mayor" << endl;
    }else if(cmp == 0){
        cout << "Son iguales" << endl;
    }else{
        cout << "Fecha 1 es menor" << endl;
    }

    return 0;    
}