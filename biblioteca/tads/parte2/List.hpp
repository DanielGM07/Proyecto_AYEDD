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
    assert(lst.p != NULL && "La lista no puede estar vacia");
    if(lst.curr == lst.p){
        lst.curr = lst.curr->sig;
        // lst.curr = lst.p->sig;
    }

    T removed = removeFirst(lst.p);
    lst.size--;

    if(lst.size == 0){
        lst.curr = NULL;
    }
    return removed;
}

// 1.9.4.7. Función listFind 
// Descripción: Retorna la dirección del primer elemento concordante con k según cmpTK. 
// Retorna: T* – Dirección del elemento encontrado o NULL si no hubo concordancia.
template <typename T, typename K>
T* listFind(List<T> lst, K k, int cmpTK(T, K))
{
    Node<T>* found = find(lst.p, k, cmpTK);
    if( found == NULL) return NULL;
    T* inf = &found->info;
    return inf;
}

// 1.9.4.8. Función listIsEmpty 
// Descripción: Indica si la lista está vacía o tiene elementos. 
// Retorna: bool – true si la lista está vacía, false si tiene elementos.
template <typename T>
bool listIsEmpty(List<T> lst)
{
    return isEmpty(lst.p);
}

// 1.9.4.9. Función listSize 
// Descripción: Indica cuántos elementos tiene la lista. 
// Retorna: int – Cantidad de elementos que tiene la lista. 
template <typename T>
int listSize(List<T> lst)
{
    return lst.size;
}

// 1.9.4.10. Función listFree 
// Descripción: Libera la memoria que ocupa la lista. 
template <typename T>
void listFree(List<T>& lst)
{
    lst.size = 0;
    lst.curr = NULL;
    free(lst.p);
}

// 1.9.4.11. Función listDiscover 
// Descripción: Descubre el elemento t en la lista lst. 
// Retorna: T* - Dirección del elemento encontrado, o recientemente agregado al final 
// de la lista lst.
template <typename T>
T* listDiscover(List<T>& lst, T t, int cmpTT(T, T))
{
    Node<T>* discovered = find(lst.p, t, cmpTT);
    if( discovered != NULL){
        return &discovered->info;
    }else{
        Node<T>* added = add(lst.p, t);
        lst.size++;
        return &added->info;
    }
}

// 1.9.4.12. Función listOrderedInsert 
// Descripción: Inserta un elemento según el orden que establece cmpTT. La lista debe 
// estar ordenada (según cmpTT) o vacía. 
// Retorna: T* – Dirección del elemento insertado
template <typename T>
T* listOrderedInsert(List<T>& lst, T t, int cmpTT(T, T))
{
    Node<T>* inserted = orderedInsert(lst.p, t, cmpTT);
    lst.size++;
    if(lst.size == 1)
    {
        lst.curr = lst.p;
    }
    return &inserted->info;
}

// 1.9.4.13. Función listSort 
// Descripción: Ordena la lista según el criterio que establece cmpTT. 
template <typename T>
void listSort(List<T>& lst, int cmpTT(T, T))
{
    sort(lst.p, cmpTT);
}

// 1.9.4.14. Función listReset 
// Descripción: Prepara la lista para iterarla. 
template <typename T>
void listReset(List<T>& lst)
{
    lst.curr = lst.p;
}

// 1.9.4.15. Función listHasNext 
// Descripción: Indica si quedan más elementos para seguir iterando la lista. 
// Retorna: bool – true si es posible seguir iterando la lista.
template <typename T>
bool listHasNext(List<T> lst)
{
    return lst.curr != NULL;
}

// 1.9.4.16. Función listNext 
// Descripción: Retorna la dirección del siguiente elemento de la lista en la iteración. 
// Retorna: T* – Dirección del siguiente elemento en la iteración.
template <typename T>
T* listNext(List<T>& lst)
{
    T* nextT = NULL;
    if(lst.curr != NULL){
        nextT = &lst.curr->info;
        lst.curr = lst.curr->sig;
    }
    return nextT;
}

// 1.9.4.17. Función listNext (sobrecarga) 
// Descripción: Retorna la dirección del siguiente elemento de la lista en la iteración.
// Parámetros:  
// • List<T>& lst - Lista. 
// • bool& eol – Indicador de que se llegó al final de la lista (End Of List). 
// Retorna: T* – Dirección del siguiente elemento en la iteración.
template <typename T>
T* listNext(List<T>& lst, bool& endOfList)
{
    T* nextT = listNext(lst);
    endOfList = lst.curr == NULL;
    return nextT;
}

#endif
