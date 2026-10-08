#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>

#include "../../funciones/lists.hpp"
#include "../../tads/parte2/List.hpp"

using std::string;

template <typename T>
struct Stack
{
    List<T> lst;
};

template <typename T>
Stack<T> stack()
{
    Stack<T> st;
    st.lst = list<T>();
    return st;
}

// 1.9.5.3. Función stackPush 
// Descripción: Apila el elemento e. 
// Retorna: T* – Dirección de memoria del elemento que se apiló.
template <typename T>
T* stackPush(Stack<T>& st, T e)
{
    return listAddFisrt(st.lst, e);
}

// 1.9.5.4. Función stackPop 
// Descripción: Desapila un elemento. 
// Retorna: T – Elemento que se desapiló.
template <typename T>
T stackPop(Stack<T>& st)
{
    return removeFirst(st.lst);
}

// 1.9.5.5. Función stackIsEmpty 
// Descripción: Retorna true o false según la pila tenga elementos o no. 
// Retorna: bool –true o false según la pila tenga elementos o no. 
template <typename T>
bool stackIsEmpty(Stack<T> st)
{
    return listIsEmpty(st.lst);
}

// 1.9.5.6. Función stackSize 
// Descripción: Retorna la cantidad de elementos que tiene la pila. 
// Retorna: int – Cuántos elementos tiene la pila.
template <typename T>
int stackSize(Stack<T> st)
{
    return listSize(st.lst);
}

#endif
