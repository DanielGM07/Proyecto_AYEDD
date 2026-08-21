#include <iostream>
#include <string>

#include "../biblioteca/funciones/millis.hpp"
#include "../biblioteca/funciones/files.hpp"
#include "../biblioteca/funciones/strings.hpp"
#include "../biblioteca/funciones/tokens.hpp"
#include "../biblioteca/tads/intro/Fraccion.hpp"
#include "../biblioteca/tads/parte1/Fecha.hpp"
#include "../biblioteca/tads/parte1/Timer.hpp"
#include "../biblioteca/tads/parte1/Coll.hpp"
#include "../biblioteca/tads/parte2/Array.hpp"
#include "../biblioteca/tads/parte2/List.hpp"
#include "../biblioteca/tads/parte2/Map.hpp"
#include "../biblioteca/tads/parte2/Queue.hpp"
#include "../biblioteca/tads/parte2/Stack.hpp"
#include "../principal.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::to_string;

// Porque el array pasa por referencia
// leccion 3 de gestion de memoria
int main (){
    int i;
    cout << " direccion de memoria es " << i << endl;
    // i = NULL;
    // cout << " direccion de memoria es " << &i << endl;
    i = 123;
    cout << " direccion de memoria es " << &i << endl;
    int* p = &i;
    cout << *p << " y su direccion de memoria es " << &i << endl;


    return 0;
}