#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>

#include "../../funciones/strings.hpp"

using std::string;

// 1.4.2.1. Estructura del TAD
template <typename T>
struct Coll
{
    string s;
    char sep;
    
    int curr = 0;
};

// 1.4.2.2. Función coll
template <typename T>
Coll<T> coll(char sep)
{
    Coll<T> c;
    c.s = "";
    c.sep = sep;
    c.curr = 0;
    return c;
}

// 1.4.2.3. Función coll (sobrecarga)
template <typename T>
Coll<T> coll()
{
    Coll<T> c;
    c.s = "";
    c.sep = '|';
    return c;
}

// 1.4.2.4. Función collSize
template <typename T>
int collSize(Coll<T> c)
{
    int cSize = tokenCount(c.s, c.sep);
    return cSize;
}

// 1.4.2.5. Función collRemoveAll
template <typename T>
void collRemoveAll(Coll<T>& c)
{
    while(collSize<T>(c) > 0){
        removeTokenAt(c.s, c.sep, 0);
    }
}

// void removeTokenAt(string& s, char sep, int i)

// 1.4.2.6. Función collRemoveAt
template <typename T>
void collRemoveAt(Coll<T>& c, int p)
{  
    removeTokenAt(c.s, c.sep, p);
}

// 1.4.2.7. Función collAdd
template <typename T>
int collAdd(Coll<T>& c, 
            T t, 
            string tToString(T))
{
    string newT = tToString(t);
    addToken(c.s, c.sep, newT);
    return collSize<T>(c)-1;
}

// 1.4.2.8. Función collSetAt
template <typename T>
void collSetAt(Coll<T>& c, 
               T t, 
               int p, 
               string tToString(T))
{
    // void setTokenAt(string& s, char sep, string t, int i)
    string itemToSet = tToString(t);
    setTokenAt(c.s, c.sep, itemToSet, p);
}

// string getTokenAt(string s, char sep, int i)

// 1.4.2.9. Función collGetAt
template <typename T>
T collGetAt(Coll<T> c, 
            int p, 
            T tFromString(string))
{
    string itemToGet = getTokenAt(c.s, c.sep, p);
    T itemToT = tFromString(itemToGet);
    return itemToT;
}

// 1.4.2.10. Función collFind
// Descripción: Determina si la colección c contiene al elemento k.
// Esto lo hace comparando cada elmento del coll con k, usando cmpTK

template <typename T, typename K>
int collFind(Coll<T> c, 
             K k, 
             int cmpTK(T, K), 
             T tFromString(string))
{
    // Primero obtenemos el largo de la coleccion
    int n = collSize<T>(c);

    // Iteramos hasta el ultimo elemento
    for(int i = 0; i < n; i++){

        // Convertimos el elemento de la posicion actual (i: iterador), de string a T 
        // (tipo de dato de la coleccion)
        T t = collGetAt<T>(c, i, tFromString);

        // Comparamos t con k (pueden ser de tipos de datos distintos o no)
        // En caso de ser tipos de datos distintos, aun asi podria hacerle la comparacion
        // dependiendo de que metodo se pase como cmpTK.
        // Ej. se pasa cmpStringInt(string s, int n) que convierte el string a int
        // para hacer la comparacion
        if(cmpTK(t, k) == 0){
            return i;
        }
    }

    // Si ningun elemento de la coleccion es igual a k, se devuelve -1
    return -1;
}

// T collGetAt(Coll<T> c, 
//             int p, 
//             T tFromString(string))

// 1.4.2.11. Función collSort
// Descripción: Ordena los elementos de la colección c según el criterio de precedencia
// que establece cmpTT.
template <typename T>
void collSort(Coll<T>& c, 
              int cmpTT(T, T), 
              T tFromString(string),
              string tToString(T))
{
    int size = collSize<T>(c);

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-1; j++){
            T t1 = collGetAt<T>(c, j, tFromString);
            T t2 = collGetAt<T>(c, j+1, tFromString);

            if(cmpTT(t1, t2) > 0){
                collSetAt<T>(c, t1, j+1, tToString);
                collSetAt<T>(c, t2, j, tToString);
            }
        }
    }
}

// 1.4.2.12. Función collHasNext
template <typename T>
bool collHasNext(Coll<T> c)
{
    return c.curr < collSize<T>(c);
}

// 1.4.2.13. Función collNext
template <typename T>
T collNext(Coll<T>& c, 
           T tFromString(string))
{
    T t = collGetAt<T>(c, c.curr, tFromString);
    c.curr++;
    return t;
}

// 1.4.2.14. Función collNext (sobrecarga)
// Descripción: Retorna el próximo elemento de la colección c, indicando si se llegó al
// final de la colección. De este modo, permite prescindir de usar collHasNext.
template <typename T>
T collNext(Coll<T>& c, 
           bool& endOfColl, 
           T tFromString(string))
{
    T t = collNext(c, tFromString);
    endOfColl = (c.curr == collSize<T>(c));
    return t;
}

// 1.4.2.15. Función collReset
// Descripción: Reinicia la colección c para que la podamos volver a iterar.
template <typename T>
void collReset(Coll<T>& c)
{
    c.curr = 0;
}

template<typename T>
string collToString(Coll<T> c)
{
	return c.sep+c.s;
}

template<typename T>
Coll<T> collFromString(string s)
{
	Coll<T> c;
	c.sep=s[0];
	c.s=substring(s,1);
	return c;
}

#endif
