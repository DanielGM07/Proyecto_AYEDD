#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include <iostream>

#include "../../funciones/lists.hpp"
#include "../../tads/parte2/List.hpp"

using std::string;

template <typename T>
struct Queue
{
    List<T> lst;
};

template <typename T>
Queue<T> queue()
{
    Queue<T> q;
    q.lst = list<T>();
    return q;
}

// 1.9.6.3. Función queueEnqueue 
// Descripción: Encola el elemento e. 
// Retorna: T* – Dirección de memoria del elemento que se encoló.
template <typename T>
T* queueEnqueue(Queue<T>& q, T e)
{
    return listAdd(q.lst, e);
}

// 1.9.6.4. Función queueDequeue 
// Descripción: Desencola un elemento. 
// Retorna: T – Elemento que se desencoló.
template <typename T>
T queueDequeue(Queue<T>& q)
{
    return listRemoveFirst(q.lst);
}

// 1.9.6.5. Función queueIsEmpty 
// Descripción: Retorna true o false según la cola tenga elementos o no. 
// Retorna: bool –true o false según la cola tenga elementos o no. 
template <typename T>
bool queueIsEmpty(Queue<T> q)
{
    return listIsEmpty(q.lst);
}

// 1.9.6.6. Función queueSize 
// Descripción: Retorna la cantidad de elementos que tiene la cola. 
// Retorna: int – Cuántos elementos tiene la cola. 
template <typename T>
int queueSize(Queue<T> q)
{
    return listSize(q.lst);
}

#endif
