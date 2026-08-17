#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

// 1.7.1.1. Función add
// Descripción: Agrega el elemento e al final de arr incrementando su longitud len.
// Retorna: int – La posición del array donde quedó ubicado el elemento e que acabamos de agregar.
template <typename T>
int add(T arr[], int& len, T e)
{
    arr[len] = e;
    len++;
    return len - 1;
}

// 1.7.1.2. Función insert
// Descripción: Inserta el elemento e en la posición p del array arr. Desplaza los elementos ubicados a partir de p+1 e incrementa la longitud len.
template <typename T>
void insert(T arr[], int& len, T e, int p)
{
    for (int i = len; i > p; i--){
        arr[i] = arr[i - 1];
    }

    arr[p] = e;
    len++;
}

// 1.7.1.3. Función remove
// Descripción: Remueve el elemento ubicado en la posición p del array arr. Desplaza ubicados a partir de p y decrementa la longitud len.
// Retorna: T – Elemento que fue removido del array.
template <typename T>
T remove(T arr[], int& len, int p)
{
    T ret = arr[p];
    for (int i = p; i < len - 1; i++){
        arr[i] = arr[i + 1];
    }
    len--;
    return ret;
}

// 1.7.1.4. Función find
// Descripción: Retorna la posición de la primera ocurrencia de k dentro de arr o un valor negativo si arr no contiene a k.
// Retorna: int – Posición de la primera ocurrencia de k dentro de arr o un valor negativo si arr no contiene a k.
template <typename T, typename K>
int find(T arr[], int len, K k, int cmpTK(T,K))
{
    for (int i = 0; i < len; i++){
        if (cmpTK(arr[i], k) == 0){
            return i;
        }
    }
    return -1;
}

// 1.7.1.5. Función orderedInsert
// Descripción: Inserta e dentro de arr según el criterio de precedencia que establece cmpTT, y retorna la posición donde dicho elemento quedó insertado. El array arr debe estar ordenado o vacío.
// Retorna: int – Posición donde quedó insertado e dentro de arr.
template <typename T>
int orderedInsert(T arr[], int& len, T e, int cmpTT(T,T))
{
    for(int i = 0; i < len; i++){
        if(cmpTT(arr[i], e) > 0){
            insert(arr, len, e, i);
            return i;
        }
    }
    // insert(arr, len, e, len);
    add(arr, len, e);
    return len-1;
}

// 1.7.1.6. Función sort
// Descripción: Ordena arr según el criterio de precedencia que establece cmpTT.
template <typename T>
void sort(T arr[], int len, int cmpTT(T,T))
{
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len - 1; j++){
            T t1 = arr[j];
            T t2 = arr[j+1];
            if(cmpTT(t1, t2) > 0){
                arr[j] = t2;
                arr[j+1] = t1;
            }
        }
    }
}

#endif
