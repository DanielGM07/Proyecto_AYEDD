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

    for (int i = 0; i < arrOrd.len; i++){
        cout << arrOrd.arr[i] << endl;
    }
    return 0;

}