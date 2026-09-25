#ifndef _TLIST_T_
#define _TLIST_T_

#include <stdio.h>

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;

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
    T t;

    Node<T>* auxAnt = p;
    if(cmpTK(p->info, k) == 0)
    {
        t = p->info;
        p = p->sig;
        delete auxAnt;
        return t;
    }
    else
    {
        Node<T>* aux = auxAnt->sig;
        while(aux != NULL)
        {
            if(cmpTK((aux->info), k) == 0)
            {
                auxAnt->sig = aux->sig;
                t = aux->info;
                delete aux;
                return t;
            }
            auxAnt = auxAnt->sig;
            aux = aux->sig;
        }
    }

    // Node<T>* auxAnt = p;

    // if(cmpTK( (auxAnt->info), k) == 0){
    //     if(aux != NULL) auxAnt->sig = aux->sig;
    //     p = aux;

    //     t = auxAnt->info;
    //     delete auxAnt;
    //     return t;
    // }
    // return t;
}

template <typename T>
T removeFirst(Node<T>*& p)
{
    T t;
    return t;
}

template <typename T, typename K>
Node<T>* find(Node<T>* p, K k, int cmpTK(T, K))
{
    return NULL;
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p, T e, int cmpTT(T, T))
{
    return NULL;
}

template <typename T>
Node<T>* searchAndInsert(Node<T>*& p, T e, bool& enc, int cmpTT(T, T))
{
    return NULL;
}

template <typename T>
void sort(Node<T>*& p, int cmpTT(T, T))
{
}

template <typename T>
bool isEmpty(Node<T>* p)
{
    return true;
}

template <typename T>
void free(Node<T>*& p)
{
}

template <typename T>
Node<T>* push(Node<T>*& p, T e)
{
    return NULL;
}

template <typename T>
T pop(Node<T>*& p)
{
    T t;
    return t;
}

template <typename T>
Node<T>* enqueue(Node<T>*& p, Node<T>*& q, T e)
{
    return NULL;
}

template <typename T>
Node<T>* enqueue(Node<T>*& q, T e)
{
    return NULL;
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
    T t;
    return t;
}

template <typename T>
T dequeue(Node<T>*& q)
{
    T t;
    return t;
}

#endif
