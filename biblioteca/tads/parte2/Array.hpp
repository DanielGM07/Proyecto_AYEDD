#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../../funciones/arrays.hpp"

using std::string;

template<typename T>
struct Array
{
    // T arr[];
    T* arr = new T[5];
    int len;
    int curr;
};

// 1.8.1.2. Función array
// Descripción: Inicializa un array cuya capacidad inicial será establecida por defecto. La longitud del array será 0, y se incrementará a medida que se agreguen o inserten nuevos elementos.
// Retorna: Array<T> – El array.
template<typename T>
Array<T> array()
{
    Array<T> ar;
    // ar.arr[5];   NO CONVIENE PQ LA MEMORIA YA LA RESERVAMOS EN EL STRUCT
    ar.len = 0;
    ar.curr = 0;
    return ar;
}

// 1.8.1.3. Función arrayAdd
// Descripción: Agrega t al final de a incrementando, de ser necesario, su capacidad. Retorna la posición del arr donde quedó ubicado el elemento t.
// Retorna: int – Posición de a donde se agregó el elemento t.
template<typename T>
int arrayAdd(Array<T>& a,T t)
{
    // supongo que habra que gestionar punteros hmmm...
    // int len = a.len; MMMMMMMMMMMMMMMMMMMMMM
    if (a.len > 4){
        T* b = new T[a.len + 1];
        for (int i = 0; i < (a.len + 1); i++){
            b[i] = a.arr[i];
        }
        delete a.arr;
        a.arr = b;
    }

    a.arr[a.len] = t;
    a.len++;
    return a.len - 1;
}

// 1.8.1.4. Función arrayGet
// Descripción: Retorna la dirección del elemento de a ubicado en la posición p.
// Retorna: T* – Dirección del elemento ubicado en la posición p del array a.
template<typename T>
T* arrayGet(Array<T> a,int p)
{
    T* dir = &a.arr[p];
    return dir;
}

// 1.8.1.5. Función arraySet
// Descripción: Asigna el elemento t en la posición p del array a.
template<typename T>
void arraySet(Array<T>& a, int p, T t)
{
    a.arr[p] = t;
}

// 1.8.1.6. Función arrayInsert
// Descripción: Inserta t en la posición p del array a.
// LA DIFERENCIA CON ARRAY SET ES QUE ACA VAMOS A MOVER TODO UN PASO A LA DERECHA
template<typename T>
void arrayInsert(Array<T>& a, T t, int p)
{
    if (a.len > 4){
        T* b = new T[a.len + 1];
        for (int i = 0; i < (a.len + 1); i++){
            b[i] = a.arr[i];
        }
        delete a.arr;
        a.arr = b;
    }

    for (int i = a.len; i > p; i--){
        a.arr[i] = a.arr[i - 1];
    }

    a.arr[p] = t;
    a.len++;
}

// 1.8.1.7. Función arraySize
// Descripción: Retorna la longitud actual del array.
// Retorna: int – Longitud del array a.
template<typename T>
int arraySize(Array<T> a)
{
    return a.len;
}

// 1.8.1.8. Función arrayRemove
// Descripción: Remove el elemento de a ubicado en la posición p.
// Retorna: T – Elemento que ocupaba la posición p dentro de a.
template<typename T>
T arrayRemove(Array<T>& a, int p)
{
    T t = a.arr[p];
    for (int i = p; i < a.len; i++){
        a.arr[i] = a.arr[i+1];
    }
    a.len--;
    return t;
}

// 1.8.1.9. Función arrayRemoveAll
// Descripción: Remueve todos los elemento de a dejándolo vacío, con longitud 0.
template<typename T>
void arrayRemoveAll(Array<T>& a)
{
    // ESTO QUE HICE YO ACA ABAJO SERIA LO CORRECTO PARA DEJAR COMO TAL EL ARRAY A
    // DIRECCIONANDO A UN ARRAY VACIO, PERO LE PREGUNTE AL PROFE PABLO Y ME DIJO
    // LA BBSITA BEBE LIN, NO MENTIRA. ME DIJO QUE CON PONER EL LEN DEL ARRAY EN 0
    // YA CUMPLIA.
    // T* b = new T[a.len + 1];
    // delete a.arr;
    // a.arr = b;
    a.len = 0;
}

// 1.8.1.10. Función arrayFind
// Descripción: Retorna la posición que k ocupa dentro de a, según la función de compa-
// ración cmpTK, o un valor negativo si a no contiene a k.
// Retorna: int – Posición de la primera ocurrencia de k dentro de a o un valor negativo
// si a no contiene a k.
template<typename T,typename K>
int arrayFind(Array<T> a,K k,int cmpTK(T,K))
{
    // ES VALIDO PERO MEJOR RETORNAMOS DIRECTAMENTE
    // int pos = find(a.arr, a.len, k, cmpTK);
    return find(a.arr, a.len, k, cmpTK);
}

// 1.8.1.11. Función arrayOrderedInsert
// Descripción: Inserta t en a según el criterio de precedencia que establece cmpTT.
// Retorna: int – Posición donde quedó insertado t dentro de a.
template<typename T>
int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T))
{
    return orderedInsert(a.arr, a.len, t, cmpTT);
}

// 1.8.1.12. Función arrayDiscover
// Prototipo: T* arrayDiscover(Array<T>& a,T t,int cmpTT(T,T));
// Descripción: Descubre (busca, y si no encuentra lo agrega) al elemento t en el array a.
// Retorna: T* - La dirección del elemento encontrado, o recientemente agregado.
template<typename T>
T* arrayDiscover(Array<T>& a, T t,int cmpTT(T,T))
{
    // CHEQUEAR ESTE CODIGO
    // int pos = arrayFind(a, t, cmpTT);
    // int* dir = &pos;
    // if (pos >= 0){
    //     return dir;
    // }
    // int newPos = arrayAdd(a, t);
    // int* newDir = &newPos;
    // return newDir;
    // TA INCHEQUEABLE EL CODIGO DE ARRIBA
    
    // THIS IS BULLSHIT, LETS DO SOME IMPROVEMENTS
    // int pos = arrayFind(a, t, cmpTT);
    // T* dir = &a.arr[pos];
    // if (pos >= 0 ){
    //     return dir;
    // }
    // int lastPos = arrayAdd(a, t);
    // T* newDir = &a.arr[lastPos];
    // return newDir;

    int pos = arrayFind(a, t, cmpTT);

    if (pos >= 0){
        return &a.arr[pos];
    }

    int newPos = arrayAdd(a, t);
    return &a.arr[newPos];
}

// 1.8.1.13. Función arraySort
// Descripción: Ordena el array a según establece cmpTT.
template<typename T>
void arraySort(Array<T>& a, int cmpTT(T,T))
{
    sort(a.arr, a.len, cmpTT);
}

template<typename T>
void arrayReset(Array<T>& a)
{
    a.curr = 0;
}

template<typename T>
bool arrayHasNext(Array<T>& a)
{
    return a.curr < arraySize(a);
}

template<typename T>
T* arrayNext(Array<T>& a)
{
    T* t = arrayGet<T>(a, a.curr);
    a.curr++;
    return t;
}

#endif
