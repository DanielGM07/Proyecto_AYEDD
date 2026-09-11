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

int cmpInt(int a, int b){
    return a-b;
}

int cmpIntReverse(int a, int b){
    return b-a;
}

int main(){
    Array<int> arr = array<int>();
    arrayAdd(arr, 1);
    arrayAdd(arr, 2);
    arrayAdd(arr, 3);
    arrayAdd(arr, 4);
    arrayAdd(arr, 5);

    arrayAdd(arr, 6);
    arrayAdd(arr, 7);

    arrayAdd(arr, 8);

    Array<int> arrOrd = array<int>();

    arrayAdd(arrOrd, 1);
    arrayAdd(arrOrd, 10);
    arrayAdd(arrOrd, 15);

    for (int i = 0; i < arr.len; i++){
        cout << arr.arr[i] << endl;
    }

    cout << "\n";

    arraySet(arr, 2, 666);

    for (int i = 0; i < arr.len; i++){
        cout << arr.arr[i] << endl;
    }
    cout << arrayGet(arr, 1) << endl;

    cout << "\n";

    arrayInsert(arr, 10, 4);

    for (int i = 0; i < arr.len; i++){
        cout << arr.arr[i] << endl;
    }

    cout << "\n";

    arrayRemove(arr, 2);

    for (int i = 0; i < arr.len; i++){
        cout << arr.arr[i] << endl;
    }

    arrayRemoveAll(arr);

    cout << "\n" << "Array vacio ==> \n";
        
    for (int i = 0; i < arr.len; i++){
        cout << arr.arr[i] << endl;
    }

    cout << "\n" << "Sip, vacio como el banco central \n";

    // Tengo que terminar de testear esto ya que anda medio mal
    cout << arrayOrderedInsert(arrOrd, 5, cmpInt);

    cout << "\n\n";

    for (int i = 0; i < arrOrd.len; i++){
        cout << arrOrd.arr[i] << endl;
    }

    cout << "\n";

    // FUNCIONAAA EL ARRAY DISCOVER
    cout << "MEMORY DIRECTION from function: " << arrayDiscover(arrOrd, 10, cmpInt);

    int* dir = &arrOrd.arr[2];

    cout << "\n";
    cout << "\n";
    cout << "MEMORY DIRECTION from hardcode: " << dir << endl;
    cout << "\n";
    cout << "\n";
    cout << "MEMORY DIRECTION, added, from function: " << arrayDiscover(arrOrd, 67, cmpInt);
    cout << "\n";
    cout << "\n";
    int* dir2 = &arrOrd.arr[4];
    cout << "MEMORY DIRECTION, added, from hardcode: " << dir2 << endl;

    cout << "\n";

    for (int i = 0; i < arrOrd.len; i++){
        cout << arrOrd.arr[i] << endl;
    }
    cout << "\n";
    cout << "\n";

    // EPETACULAAA, YA CASI DOMINO PUNTEROS Y DIRECCIONES DE MEMORIA

    Array<int> a3 = array<int>();
    arrayAdd(a3, 67);
    arrayAdd(a3, 7);
    arrayAdd(a3, 13);
    arrayAdd(a3, 33);
    arrayAdd(a3, 1);
    cout << "NOT SORTED ARRAY!!: " << endl;
    for (int i = 0; i < a3.len; i++){
        cout << a3.arr[i] << endl;
    }
    
    cout << "\n";
    cout << "\n";
    arraySort(a3, cmpInt);
    cout << "YES SORTED ARRAY!!: " << endl;
    for (int i = 0; i < a3.len; i++){
        cout << a3.arr[i] << endl;
    }
        
    cout << "\n";
    cout << "\n";
    arraySort(a3, cmpIntReverse);
    cout << "YES SORTED ARRAY!!: " << endl;
    for (int i = 0; i < a3.len; i++){
        cout << a3.arr[i] << endl;
    }

    cout << "\n";

    Array<string> fa = array<string>();
    arrayAdd<string>(fa, "Daniel");
    arrayAdd<string>(fa, "Messi");
    arrayAdd<string>(fa, "Cristiano");
    arrayAdd<string>(fa, "La champions");
    arrayAdd<string>(fa, "La copa del mundo");

    while( arrayHasNext<string>(fa) ){
        string* str = arrayNext<string>(fa);
        cout << *str << endl; 
    }
    cout << "\n";

    Array<int> fa1 = array<int>();
    arrayAdd<int>(fa1, 10);
    arrayAdd<int>(fa1, 20);
    arrayAdd<int>(fa1, 30);
    arrayAdd<int>(fa1, 40);
    arrayAdd<int>(fa1, 50);

    while( arrayHasNext<int>(fa1) ){
        int* str = arrayNext<int>(fa1);
        cout << *str << endl; 
    }
    
    cout << "\nHMMMMMMM";
    while( arrayHasNext<int>(fa1) ){
        int* str = arrayNext<int>(fa1);
        cout << *str << endl; 
    }
    cout << "HMMMMMMM\n\n";
    arrayReset<int>(fa1);
    
    while( arrayHasNext<int>(fa1) ){
        int* str = arrayNext<int>(fa1);
        cout << *str << endl; 
    }

    // ALLLLLLRIGHT, ALL FUNCTIONS WERE TESTED, EVERYTHING'S OKAY

    return 0;

}