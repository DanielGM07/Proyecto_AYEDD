#ifndef _TLIST_T_
#define _TLIST_T_

#include <stdio.h>

#include <iostream>

#include <cassert>

using std::cin;
using std::cout;
using std::endl;
// using std::getline;
using std::string;
// using std::to_string;

template <typename T>
struct Node
{
    T info;
    Node<T>* sig;
};

template <typename T>
Node<T>* add(Node<T>*& p, T e)
{
    Node<T>* nuevo = new Node<T>();
    nuevo->info = e;
    nuevo->sig = NULL;

    if(p == NULL)
    {
        p = nuevo;
    }
    else
    {
        Node<T>* aux = p;
        while(aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }

    return nuevo;
}

template <typename T>
Node<T>* addFirst(Node<T>*& p, T e)
{
    Node<T>* newFirst = new Node<T>();
    newFirst->info = e;
    newFirst->sig = p;

    p = newFirst;

    return newFirst;
}

// 1.9.1.4. Función remove
// Descripción: Remueve la primera ocurrencia del elemento concordante con
// cmpTK. Retorna: T – Valor del elemento que fue removido.
template <typename T, typename K>
T remove(Node<T>*& p, K k, int cmpTK(T, K))
{
    assert(p != NULL && "P no puede ser nulo");

    Node<T>* auxAnt = p;
    if(cmpTK(p->info, k) == 0)
    {
        T t = p->info;
        p = p->sig;
        delete auxAnt;
        return t;
    }

    Node<T>* aux = auxAnt->sig;

    while(aux != NULL)
    {
        if(cmpTK((aux->info), k) == 0)
        {
            auxAnt->sig = aux->sig;
            
            T t = aux->info;
            delete aux;
            return t;
        }
        auxAnt = auxAnt->sig;
        aux = aux->sig;
    }

    assert(false && "El elemento a remover no existe en la lista");
}

// 1.9.1.5. Función removeFirst 
// Descripción: Remueve el primer elemento de la lista direccionada por p. 
// Retorna: T – Valor del elemento que acabamos de remover.
template <typename T>
T removeFirst(Node<T>*& p)
{
    T t = p->info;

    Node<T>* aux = p->sig;
    
    delete p;

    p = aux;

    return t;
}

// 1.9.1.6. Función find
// Descripción: Retorna la dirección del nodo que contiene la primera ocurrencia  de k, 
// según cmpTK, o NULL si ningún elemento concuerda con dicha clave de búsqueda.
// Retorna: Node<T>* – Dirección del nodo que contiene la primera ocurrencia del ele-
// mento que buscamos o NULL si la lista no contiene dicho elemento.
template <typename T, typename K>
Node<T>* find(Node<T>* p, K k, int cmpTK(T, K))
{
    Node<T>* aux = p;
    while(aux != NULL){
        T t = aux->info;
        if(cmpTK(t, k) == 0){
            return aux;
        }
        aux = aux->sig;
    }
    return NULL;
}

// 1.9.1.7. Función orderedInsert
// Descripción: Inserta el elemento e en la lista direccionada por p según el criterio que 
// establece la función cmpTT. La lista debe estar vacía u ordenada según cmpTT. 
// Retorna: Node<T>* – Dirección del nodo que acabamos de insertar.
template <typename T>
Node<T>* orderedInsert(Node<T>*& p, T e, int cmpTT(T, T))
{
    if(p == NULL){
        p = new Node<T>();
        p->info = e;
        p->sig = NULL;
        return p;
    }

    Node<T>* auxAnt = p;
    if(cmpTT(auxAnt->info, e) > 0){
        return addFirst(p, e);
    }

    Node<T>* aux = auxAnt->sig;

    Node<T>* newInsert = new Node<T>();
    newInsert->info = e;

    while (aux != NULL){
        if(cmpTT(aux->info, e) > 0 ){
            // Node<T>* newInsert = new Node<T>();
            // newInsert->info = e;
            newInsert->sig = aux;
            auxAnt->sig = newInsert;
            return newInsert;
        }
        auxAnt = aux;
        aux = aux->sig;
    }

    newInsert->sig = NULL;
    auxAnt->sig = newInsert;

    return newInsert;
}

// 1.9.1.8. Función searchAndInsert
// Descripción: Busca en la lista direccionada por p la primera ocurrencia de e, y retorna 
// la dirección del nodo que lo contiene. Si e no existe en la lista entonces lo insertar en 
// orden,  según  el  criterio  establecido  por  cmpTT,  y  retorna  la  dirección  del  nodo 
// insertado. Asigna true o false a enc según e fue encontrado o insertado.
// Retorna: Node<T>* – Dirección del nodo que acabamos de encontrar o insertar.
template <typename T>
Node<T>* searchAndInsert(Node<T>*& p, T e, bool& enc, int cmpTT(T, T))
{
    Node<T>* foundNode = find(p, e, cmpTT);

    if(foundNode != NULL){
        enc = true;
        return foundNode;
    }else{
        enc = false;
        return orderedInsert(p, e, cmpTT);
    }
}

// 1.9.1.9. Función sort
// Descripción:  Ordena  la  lista  direccionada  por  p  según  el  criterio  que  establece  la 
// función de comparación cmpTT. 
template <typename T>
void sort(Node<T>*& p, int cmpTT(T, T))
{
    assert(p != NULL && "P no puede ser NULL");
    if(p->sig == NULL){
        return;
    }

    // Node<T>* auxAnt = p;
    // Node<T>* aux = auxAnt->sig;
    bool sorted = false;
    while ( !sorted ){
        Node<T>* auxAntAnt = p;
        Node<T>* auxAnt = auxAntAnt->sig;

        Node<T>* aux = auxAnt->sig;

        sorted = true;
        
        if(cmpTT(auxAntAnt->info, auxAnt->info) > 0){
            sorted = false;

            auxAntAnt->sig = aux;
            auxAnt->sig = auxAntAnt;

            auxAntAnt = auxAnt;
            auxAnt = auxAntAnt->sig;

            p = auxAntAnt;
        }

        while(aux != NULL){

            if(cmpTT(auxAnt->info, aux->info) > 0){
                sorted = false;

                auxAnt->sig = aux->sig;
                aux->sig = auxAnt;
                auxAntAnt->sig = aux;
                
                auxAntAnt = auxAntAnt->sig;
                auxAnt = aux->sig;
                aux = auxAnt->sig;

            }else{
                auxAntAnt = auxAnt;
                auxAnt = auxAntAnt->sig;
                aux = auxAnt->sig;
            }

        }
    }
}

// 1.9.1.10. Función isEmpty
// Descripción: Indica si la lista direccionada por p tiene o no elemento.
// Retorna: bool – true o false según la lista tenga o no elementos. 
template <typename T>
bool isEmpty(Node<T>* p)
{
    return p == NULL;
}

// 1.9.1.11. Función free
// Descripción: Libera la memoria que utiliza lista direccionada por p. Asigna NULL a p.
template <typename T>
void free(Node<T>*& p)
{
    Node<T>* aux = p;
    while(aux != NULL){
        p = p->sig;
        delete aux;
        aux = p;
    }
}

// 1.9.2.1. Función push
// Descripción: Inserta un nodo conteniendo a e al inicio de la lista direccionada por p
// Retorna: Node<T>* – Dirección del nodo que contiene al elemento que se agregó.
template <typename T>
Node<T>* push(Node<T>*& p, T e)
{
    return addFirst(p, e);
}

// 1.9.2.2. Función pop
// Descripción: Remueve el primer nodo de la lista direccionada por p.
// Retorna: T – Elemento que contenía el nodo que fue removido.
template <typename T>
T pop(Node<T>*& p)
{
    return removeFirst(p);
}

// 1.9.3.1. Función enqueue
// Descripción: Agrega el elemento e al final la lista direccionada por q
// Retorna: Node<T>* – Dirección del nodo que contiene al elemento que se agregó.
template <typename T>
Node<T>* enqueue(Node<T>*& p, Node<T>*& q, T e)
{
    Node<T>* newElm = new Node<T>();

    newElm->info = e;
    newElm->sig = NULL;

    if(q == NULL){
        p = newElm;
        q = newElm;
    }else{
        q->sig = newElm;
        q = newElm;
    }

    return newElm;
}

// 1.9.3.2. Función enqueue (sobrecarga)
// Descripción: Agrega el elemento e al final la lista circular direccionada por q.
// Retorna: Node<T>* – Dirección del nodo que contiene al elemento que se agregó.
template <typename T>
Node<T>* enqueue(Node<T>*& q, T e)
{
    Node<T>* newElm = new Node<T>();
    newElm->info = e;

    if(q == NULL){
        newElm->sig = newElm;
    }else{
        newElm->sig = q->sig;
        q->sig = newElm;
    }

    q = newElm;

    return newElm;
}

// 1.9.3.3. Función dequeue
// Descripción: Remueve el primer nodo de la lista direccionada por p
// Retorna: T – Elemento que contenía el nodo que fue removido.
template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
    T removed = pop(p);

    if(p = NULL){
        q = NULL;
    }

    return removed;
}

// 1.9.3.4. Función dequeue (sobrecarga) 
// Descripción: Remueve el primer nodo de la lista circular direccionada por q.
// Retorna: T – Elemento que contenía el nodo que fue removido. 
template <typename T>
T dequeue(Node<T>*& q)
{
    Node<T>* first = q->sig;
    T firstInfo = first->info;

    if(q == q->sig){
        delete first; // delete q; (son lo mismo)
        q = NULL;
    }else{
        q->sig = first->sig;
        delete first;
    }
    
    return firstInfo;
}

#endif
