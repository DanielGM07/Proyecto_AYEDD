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

int cmpInt(int a, int b);
int cmpIntDes(int a, int b);

// TAD Collections pruebas
int main()
{
    // Coll<string> c1 = coll<string>('|');
    // c1.s = "a|b|c";
    // cout << collSize<string>(c1) << endl;
    // collRemoveAll<string>(c1);
    // cout << collSize<string>(c1) << endl;
    
    // collRemoveAt<string>(c1, 1);
    // cout << c1.s << endl;
    // int primerAdd = collAdd<string>(c1, "d", stringToString);
    // cout << primerAdd << " " << c1.s << endl;
    // int segundoAdd = collAdd<string>(c1, "d", stringToString);
    // cout << segundoAdd << " " << c1.s << endl;

    // Coll<int> c = coll<int>('|');
    // c.s = "1|2|3|4|5";
    // cout << c.s << endl;
    // collSetAt<int>(c, 10, 2, intToString);
    // cout << c.s << endl;
    // int n = collGetAt<int>(c, 2, stringToInt);
    // cout << n << endl;
    
    // int collFind(Coll<T> c, 
    //              K k, 
    //              int cmpTK(T, K), 
    //              T tFromString(string))

    // Coll<int> c = coll<int>('|');
    // c.s = "1|4|10|5|2|3";
    // int pos = collFind<int>(c, 52, cmpInt, stringToInt);
    // cout << pos << endl;

    // Coll<int> c = coll<int>('|');
    // c.s = "1|4|10|5|2|3|123|5|1|2|90|-1|-25|-24|-23|23";
    // cout << c.s << endl;
    // collSort<int>(c, cmpInt, stringToInt, intToString);
    // cout << c.s << endl;

    // Coll<string> c = coll<string>('|');
    // c.s = "";
    // string hasNext = collHasNext<string>(c) ? "Si tiene siguiente" : "No tiene siguiente";
    // cout << hasNext << endl;
    // c.s = "1|2";
    // hasNext = collHasNext<string>(c) ? "Si tiene siguiente" : "No tiene siguiente";
    // cout << hasNext << endl;

    Coll<string> c = coll<string>();
    c.s = "a|b|c|d|e";
    

    return 0;    
}

int cmpInt(int a, int b){
    return a-b;
}

int cmpIntDes(int a, int b){
    return b-a;
}