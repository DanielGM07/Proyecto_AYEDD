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

int main()
{
    Map<string, int> m1 = map<string,int>();
    // arrayAdd<string>(m1.key, "uno");
    mapPut<string, int>(m1, "uno", 1);
    mapPut<string, int>(m1, "dos", 2);
    mapPut<string, int>(m1, "tres", 3);
    mapPut<string, int>(m1, "cuatro", 4);

    int* dir = &m1.value.arr[0];
    cout << dir << endl;

    cout << mapNextValue<string, int>(m1) << endl;

    cout << mapDiscover<string, int>(m1, "uno", 3) << endl;

    cout << mapDiscover<string, int>(m1, "cuatro", 5) << endl;

    cout << mapDiscover<string, int>(m1, "sinco", 5) << endl;

    return 0;
}