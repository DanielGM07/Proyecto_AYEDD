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

int cmpInt2(int a, int b){
    return b-a;
}

template <typename T>
void show(Node<T>* p){
    while(p != NULL){
        cout << p->info << endl;
        p = p->sig;
    }
}

void jumpLine(){
    cout << "\n";
}

int main(){
    Node<int>* p = NULL;

    // add<int>(p, 1);
    // add<int>(p, 2);
    // add<int>(p, 3);
    // add<int>(p, 4);
    // add<int>(p, 5);
    // add<int>(p, 6);
    // add<int>(p, 7);

    add<int>(p, 3);
    add<int>(p, 1);
    add<int>(p, 4);
    add<int>(p, 2);

    show(p);

    jumpLine();

    sort(p, cmpInt2);
    
    show(p);

    free(p);

    if(p == NULL) cout << "P = NULL";

    jumpLine();
    return 0;
}