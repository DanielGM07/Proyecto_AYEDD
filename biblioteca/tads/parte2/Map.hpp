
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>

#include "Array.hpp"
#include <cassert>

using std::string;

// 1.8.2.1. Estructura del TAD
template <typename K, typename T>
struct Map
{   
    Array<K> key;
    Array<T> value;

};

// 1.8.2.2. Función map
// Prototipo: Map<K,V> map();
// Retorna: Map<K,V> – El map.
template <typename K, typename V>
Map<K, V> map()
{
    Map<K, V> map;
    map.key = array<K>();
    map.value = array<V>();

    return map;
}


template <typename K>
int cmpKK(K a, K b)
{
    if(a > b){
        return 1;
    }else if(a < b){
        return -1;
    }else{
        return 0;
    }

    // REVISAR MAS ADELANTE SI SE VUELVE A USAR EL CMPKK QUE NO FALLE
    // POR ESTE RETURN

}

// 1.8.2.3. Función mapGet
// Descripción: Retorna la dirección de memoria del valor asociado a la clave k o NULL si
// m no contiene ningún valor asociado a dicha clave.
// Retorna: V* - Dirección de memoria del elemento vinculado con la clave k o NULL si
// m no contiene ningún valor asociado a k.
template <typename K, typename V>
V* mapGet(Map<K, V> m, K k)
{
    int pos = arrayFind(m.key, k, cmpKK);
    if (pos >= 0){
        V* dir = arrayGet<V>(m.value, pos);
        return dir;
    }
    return NULL;
}

// 1.8.2.4. Función mapPut
// Descripción: Agrega al map m el elemento v asociado a la clave k. Si existía una entrada
// vinculada a k se debe reemplazar el valor anterior por v.
// Retorna: V* - Dirección de memoria del elemento vinculado con la clave k.
template <typename K, typename V>
V* mapPut(Map<K, V>& m, K k, V v)
{
    V* dir = mapGet<K,V>(m, k);
    if (dir != NULL){
        *dir = v;
        return dir;
    }
    arrayAdd(m.key, k);

    // ESTE CODIGO ES MAS EFICIENTE QUE LAS DOS LINEAS COMENTADAS DE ABAJO, YA QUE ESAS VUELVEN A RECORRER EL ARRAY DE KEYS
    int pos = arrayAdd(m.value, v);
    return arrayGet(m.value, pos);

    // arrayAdd(m.value, v);
    // return mapGet(m, k);
}

// 1.8.2.5. Función mapContains
// Descripción: Verifica si m contiene a k.
// Retorna: bool - true o false según m contenga, o no, una entrada vinculada a k.
template <typename K, typename V>
bool mapContains(Map<K, V> m, K k)
{
    return mapGet(m, k);
}

// 1.8.2.6. Función mapRemove
// Descripción: Elimina de m la entrada identificada con la clave k.
// Parámetros:
// • Map<K,V>& m – El map.
// • K k –Clave que identifica la entrada a remover.
// Retorna: V – Valor que contenía la entrada asociada a la clave k.
template <typename K, typename V>
V mapRemove(Map<K, V>& m, K k)
{    
    int pos = arrayFind(m.key, k, cmpKK);
    assert(pos >= 0 && "El valor con dicha clave no existe");
    arrayRemove(m.key, pos);
    return arrayRemove(m.value, pos);
}

// 1.8.2.7. Función mapRemoveAll
// Descripción: Elimina todas las entradas del map m.
// Parámetro: Map<K,V>& m – El map.
// Retorna: void.
template <typename K, typename V>
void mapRemoveAll(Map<K, V>& m)
{
    arrayRemoveAll(m.key);
    arrayRemoveAll(m.value);
}

// 1.8.2.8. Función mapSize
// Prototipo: int mapSize(Map<K,V> m);
// Descripción: Retorna la cantidad actual de entradas que tiene m.
// Parámetro: Map<K,V>& m – El map.
// Retorna: int – Cantidad de entradas que tiene el map m.
template <typename K, typename V>
int mapSize(Map<K, V> m)
{
    return arraySize(m.key);
}

// 1.8.2.9. Función mapHasNext
// Prototipo: bool mapHasNext(Map<K,V> m);
// Descripción: Indica si quedan más elementos para continuar iterando el map.
// Parámetro: Map<K,V> m – El map.
// Retorna: bool – true o false según queden elementos para continuar iterando.
template <typename K, typename V>
bool mapHasNext(Map<K, V> m)
{
    return (m.key.curr < mapSize(m)) && (m.value.curr < mapSize(m));
}

// 1.8.2.10. Función mapNextKey
// Prototipo: K mapNextKey(Map<K,V>& m);
// Descripción: Permite iterar sobre las claves del map. Esta función es mutuamente
// excluyente respecto de mapNextValue.
// Parámetro: Map<K,V>& m – El map.
// Retorna: K – La siguiente clave dentro de una iteración.
template <typename K, typename V>
K mapNextKey(Map<K, V>& m)
{
    K* nextK = arrayNext(m.key);
    return *nextK;
}

// 1.8.2.11. Función mapNextValue
// Descripción: Permite iterar sobre los valores que contiene el map. Esta función es mu-
// tuamente excluyente despecto de mapNextKey.
// Parámetro: Map<K,V>& m – El map.
// Retorna: V* – Dirección de memoria del siguiente valor dentro de una iteración.
template <typename K, typename V>
V* mapNextValue(Map<K, V>& m)
{
    V* nextV = arrayNext(m.value);
    return nextV;
}

// 1.8.2.12. Función mapReset
// Descripción: Prepara el map para comenzar una nueva iteración.
// Retorna: void.
template <typename K, typename V>
void mapReset(Map<K, V>& m)
{
    m.key.curr = 0;
    m.value.curr = 0;
}

// 1.8.2.13. Función mapDiscover
// Prototipo: V* mapDiscover(Map<K,V>& m,K k,V v);
// Descripción: Descubre (busca, y si no encuentre agrega) una entrada {k,v} en el map m.
// Parámetros:
// • Map<K,V>& m – El map.
// • K k – Key.
// • V v – Value que será agregado en caso de no existir una entrada para k.
// Retorna: V* - La dirección de memoria del value asociado a k, agregado o encontrado.
template <typename K, typename V>
V* mapDiscover(Map<K, V>& m, K k, V v)
{
    // if(mapContains(m, k)){
    //     return mapGet(m, k);
    // }
    // return mapPut(m, k, v);

    int* dir = mapGet(m, k);
    if(dir != NULL){
        return dir;
    }
    return mapPut(m, k, v);
}

// 1.8.2.14. Función mapSortByKeys
// Descripción: Ordena el map aplicando sobre sus claves el criterio que establece cmpKK.
template <typename K, typename V>
void mapSortByKeys(Map<K, V>& m, int cmpKK(K, K))
{
    // BUBBLE SORT / ORDENAMIENTO BURBUJA BV
    int mSize = mapSize(m);
    for(int i = 0; i < mSize; i++){
        for(int j = 0; j < mSize-1; j++){
            K k1 = m.key.arr[j];
            K k2 = m.key.arr[j + 1];
            V v1 = m.value.arr[j];
            V v2 = m.value.arr[j + 1];

            if(cmpKK(k1, k2) > 0){
                m.key.arr[j] = k2;
                m.key.arr[j + 1] = k1;
                m.value.arr[j] = v2;
                m.value.arr[j + 1] = v1;
            }
        }
    }
}

// 1.8.2.15. Función mapSortByValues
// Descripción: Ordena el map aplicando sobre sus values el criterio que establece cmpVV.
template <typename K, typename V>
void mapSortByValues(Map<K, V>& m, int cmpVV(V, V))
{
    // BUBBLE SORT / ORDENAMIENTO BURBUJA BV
    int mSize = mapSize(m);
    for(int i = 0; i < mSize; i++){
        for(int j = 0; j < mSize-1; j++){
            K k1 = m.key.arr[j];
            K k2 = m.key.arr[j + 1];
            V v1 = m.value.arr[j];
            V v2 = m.value.arr[j + 1];

            if(cmpVV(v1, v2) > 0){
                m.key.arr[j] = k2;
                m.key.arr[j + 1] = k1;
                m.value.arr[j] = v2;
                m.value.arr[j + 1] = v1;
            }
        }
    }
}

#endif
