#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>

#include "../../funciones/lists.hpp"

using std::string;

template <typename T>
struct List
{
    T info;
    int size;
    Node<T>* p;
    Node<T>* curr;
};

template <typename T>
List<T> list()
{
    List<T> list;

    list.size = 0;
    list.p = NULL;
    list.curr = NULL;

    return list;
}

// 1.9.4.3. Función listAdd 
// Descripción: Agrega un elemento al final de la lista. 
// Retorna: T* – Dirección de memoria del elemento que se agregó.
template <typename T>
T* listAdd(List<T>& lst, T e)
{
    Node<T>* aux = add(lst.p, e);

    if(lst.p->sig == NULL){
        lst.curr = lst.p;
    }
    
    lst.size++;

    return &aux->info;
}

// 1.9.4.4. Función listAddFirst
// Descripción: Agrega el elemento e al inicio de la lista.
// Retorna: T* – Dirección de memoria del elemento que se agregó.
template <typename T>
T* listAddFirst(List<T>& lst, T e)
{
    Node<T>* aux = addFirst(lst.p, e);

    if(lst.p->sig == NULL){
        lst.curr = lst.p;
    }

    lst.size++;

    return &aux->info;
}

// 1.9.4.5. Función listRemove
// Descripción: Remueve el elemento que concuerde con k según la función cmpTK. 
// Retorna: T – Elemento que fue removido. 
template <typename T, typename K>
T listRemove(List<T>& lst, K k, int cmpTK(T, K))
{
    assert(lst.p != NULL && "La lista no puede estar vacia");
    if(lst.curr == find(lst.p, k, cmpTK)){
        lst.curr = lst.curr->sig;
    }
    T removed = remove(lst.p, k, cmpTK);
    lst.size--;
    if (lst.size == 0){
        lst.curr = NULL;
    }
    return removed;
}

// 1.9.4.6. Función listRemoveFirst 
// Descripción: Desenlaza y libera el primer nodo de la lista enlazada, retornando el valor 
// del elemento que contenía. 
// Retorna: T – Elemento que contenía el (ex) primer nodo de la lista.
template <typename T>
T listRemoveFirst(List<T>& lst)
{
    T removed = removeFirst(lst.p);
    return {};
}

template <typename T, typename K>
T* listFind(List<T> lst, K k, int cmpTK(T, K))
{
    return NULL;
}

template <typename T>
bool listIsEmpty(List<T> lst)
{
    return true;
}

template <typename T>
int listSize(List<T> lst)
{
    return 0;
}

template <typename T>
void listFree(List<T>& lst)
{
}

template <typename T>
T* listDiscover(List<T>& lst, T t, int cmpTT)
{
    return NULL;
}

template <typename T>
T* listOrderedInsert(List<T>& lst, T t, int cmpTT(T, T))
{
    return NULL;
}

template <typename T>
void listSort(List<T>& lst, int cmpTT(T, T))
{
}

template <typename T>
void listReset(List<T>& lst)
{
}

template <typename T>
bool listHasNext(List<T> lst)
{
    return true;
}

template <typename T>
T* listNext(List<T>& lst)
{
    return NULL;
}

template <typename T>
T* listNext(List<T>& lst, bool& endOfList)
{
    return NULL;
}

#endif
