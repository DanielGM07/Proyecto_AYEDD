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

    int vRem = mapRemove<string, int>(m1, "dos");

    int* dirK = &m1.value.arr[0];

    cout << dirK << endl;

    cout << mapGet<string, int>(m1, "uno") << endl;
    
    cout << vRem << endl;

    cout << (mapContains<string, int>(m1, "uno") ? "verdadero" : "falso") << endl;
    cout << (mapContains<string, int>(m1, "DO") ? "verdadero" : "falso") << endl;
    return 0;
}