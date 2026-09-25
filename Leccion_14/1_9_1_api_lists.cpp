#include <iostream>
#include <string>

#include "../biblioteca/funciones/lists.hpp"
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

template <typename T>
void show(Node<T>* p){
    while(p != NULL){
        cout << p->info << endl;
        p = p->sig;
    }
}

int main(){
    Node<int>* p = NULL;
    addFirst<int>(p, 1);
    addFirst<int>(p, 2);
    addFirst<int>(p, 3);
    addFirst<int>(p, 4);

    show(p);

    int removed = remove(p, 4, cmpInt);
    
    cout << "\n" << removed << "\n" << endl;

    show(p);

    return 0;
}