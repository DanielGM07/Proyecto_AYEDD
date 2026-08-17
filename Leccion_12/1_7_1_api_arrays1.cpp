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

int sumaCaracteres(string abc, string cadena);

int sumaDigitos(int numerin);

int cmpInt(int a, int b){
    return a-b;
}

int cmpInt1(int a, int b){
    return b-a;
}

int main()
{
    int len = 6;

    int arrAsc[10] = {1, 2, 3, 5, 6, 7};
    int arrDesc[10] = {7, 6, 5, 3, 2, 1};

    for (int i = 0; i < len; i++){
        cout << arrDesc[i] << endl;
    }

    int posOrd = orderedInsert<int>(arrDesc, len, 0, cmpInt1);
    cout << "\n" << posOrd << " pos insercion" << "\n\n";

    for (int i = 0; i < len; i++){
        cout << arrDesc[i] << endl;
    }

    return 0;
}
