#include <iostream>

using std::string;
using std::cout;


#include "../../funciones/strings.hpp"

// 1.5.7. TAD Matriz
// Dificultad: intermedia, Requerido: recomendable.
// Desarrollar y probar el TAD Matriz según la siguiente estructura y especificaciones.
// Nombre del TAD: Matriz.
// Descripción: Representa una matriz numérica de n filas y m columnas.
// Restricción: Cada celda de la matriz puede contener un número de un único dígito.
// struct Matriz
// {
//  string s;
//  int filas;
//  int columnas;
// }

// Prototipo: Matriz matriz(int n,int m);
// Descripción: Retorna una instancia Matriz.
// Parámetros:
// • int n - Cantidad de filas de la matriz.
// • int m - Cantidad de columnas de la matriz.

// Retorna: Matriz - Una instancia de Matriz preparada para contener una matriz
// de n filas y m columnas.
// ---
// Prototipo: Matriz matriz(String x,int n,int m);
// Descripción: Retorna una instancia Matriz inicializada con el contenido de x.
// Parámetros:
// • String x - Contenido de la matriz que se está instanciando.
// • int n - Cantidad de filas.
// • int m - Cantidad de columnas.
// Retorna: Matriz - Una instancia de Matriz de n filas y m columnas, inicializada
// con el contenido de la cadena x.
// Ejemplo: Si x="123456789012", n=3 y m=4, la matriz representada por este
// conjunto de parámetros que estos parámetros están representando es la siguiente:
// 1 2 3 4
// 5 6 7 8
// 9 0 1 2
// ---
// Prototipo: int matrizGet(Matriz m,int f,int c);
// Descripción: Retorna el valor (número de un dígito) que la matriz m contiene en la
// celda determinada por la fila f y la columna c.
// Parámetros:
// • Matriz m - Matriz.
// • int f - Fila.
// • int c - Columna.
// Retorna: int - El valor (número de un dígito) que la matriz m contiene en la celda
// determinada por la fila f y la columna c.
// ---
// Prototipo: void matrizSet(Matriz& m,int f,int c,int v);

// Descripción: Asigna el valor v (número de un dígito) en la celda determinada por la
// fila f y la columna c de la matriz m.
// Parámetros:
// • Matriz m - Matriz.
// • int f - Fila.
// • int c - Columna.
// • int v - Valor numérico (de un solo dígito) que se asignará.
// Retorna: void.
// ---
// Prototipo: Matriz matrizSumar(Matriz a,Matriz b);
// Descripción: Retorna la matriz que resulta de sumar a+b.
// Parámetros:
// • Matriz a - Matriz a sumar.
// • Matriz b - Matriz a sumar.
// Retorna: Matriz - La matriz resultante de la suma de las matrices a y b.
// ---
// Prototipo: Matriz matrizRestar(Matriz a,Matriz b);
// Descripción: Retorna la matriz que resulta de restar a-b.
// Parámetros:
// • Matriz a - Minuendo.
// • Matriz b - Sustraendo.
// Retorna: Matriz - La matriz que resulta de restar a-b.
// NOTA: Esta implementación del TAD Matriz tiene la restricción de que cada
// elemento de la matriz debe ser un valor numérico de un solo dígito, sin signo. Por
// esto, aceptaremos que las operaciones de suma y resta no arrojarán resultados que
// excedan estas limitaciones.
// Por ejemplo: si sumamos las dos matrices que vemos a continuación, la
// matriz resultante cumple con las restricciones del TAD.

// 1 4 2    6 5 3
// 7 2 5    1 2 4
// 1 3 8    2 6 1
// Figura 2.2. Ejemplo de matrices que podrían aplicar para la operación matrizSumar

struct Matriz
{
    string s;
    int filas;
    int columnas;
};

Matriz matriz(int n, int m){
    Matriz mtz;
    mtz.filas = n;
    mtz.columnas = m;
    return mtz;
}

Matriz matriz(string x,int n,int m){
    Matriz mtz;
    mtz.s = x;
    mtz.filas = n;
    mtz.columnas = m;
    return mtz;
}

// Funcion propia de su servidor, Daniel
void imprimirMatriz(Matriz mtz){
    int pos = 0;
    for(int i = 0; i < mtz.filas; i++){
        for(int j = 0; j < mtz.columnas; j++){
            cout << mtz.s[pos] << " ";
            pos++;
        }
        cout << "\n";
    }
}

int posicion(Matriz m, int f, int c){
    int posicion = (f - 1) * m.columnas + (c - 1);
    return posicion;
}

int matrizGet(Matriz m, int f, int c){    
    // Para buscar el valor que se encuentra en la fila f y columna c
    // a la fila le restamos 1, ya que, para buscar el valor, vamos a hacerlo desde el inicio
    // de la fila en la que se encuentra. Como los strings cuentan sus posiciones desde 0, y nosotros
    // calculamos (f - 1) * m.columnas, eos quiere decir que siempre vamos a estar en la 1er posicion
    // de la fila que estamos buscando. Entonces, si buscamos en la columna 1, ya estamos parado en esa
    // fila y columna, entonces a la columna le restamos 1, y terminamos sumando 0 columnas
    // osea no nos movemos porque ya estamos parados sobre el valor que queremos.
    int valor = (f - 1) * m.columnas + (c - 1);
    return (charToInt(m.s[valor]));
}

void matrizSet(Matriz& m,int f,int c,int v){
    int pos = posicion(m, f, c);
    m.s[pos] = intToChar(v);
}

bool unDigitoPositivo(int n){
    return (n >= 0 && n <= 9);
}

Matriz matrizSumar(Matriz a,Matriz b){
    int suma = 0;
    string valoresMSuma = "";
    Matriz matrizSuma;
    if(a.filas != b.filas || a.columnas != b.columnas){
        matrizSuma = matriz("0", 1, 1);
    }else{
        matrizSuma = matriz(a.filas, a.columnas);
        for(int i = 0; i < length(a.s); i++){
            suma = charToInt(a.s[i]) + charToInt(b.s[i]);
            if (unDigitoPositivo(suma)){
                // matrizSuma.s[i] = intToChar(suma);
                valoresMSuma = valoresMSuma + intToChar(suma);
            }else{
                valoresMSuma = valoresMSuma + 'X';
            }
        }
    }
    matrizSuma.s = valoresMSuma;
    return matrizSuma;
}

// Exactamente la misma funcion que la anterior, solo que cambia el signo en la linea 183
Matriz matrizRestar(Matriz a, Matriz b){
    int diferencia = 0;
    string valoresMResta = "";
    Matriz matrizResta;
    if(a.filas != b.filas || a.columnas != b.columnas){
        matrizResta = matriz("0", 1, 1);
    }else{
        matrizResta = matriz(a.filas, a.columnas);
        for(int i = 0; i < length(a.s); i++){
            diferencia = charToInt(a.s[i]) - charToInt(b.s[i]);
            if (unDigitoPositivo(diferencia)){
                // matrizSuma.s[i] = intToChar(suma);
                valoresMResta = valoresMResta + intToChar(diferencia);
            }else{
                valoresMResta = valoresMResta + 'X';
            }
        }
    }
    matrizResta.s = valoresMResta;
    return matrizResta;
}

// Esta funcion la hice yo, en caso de que no quisieramos estar programando la misma funcion
// solo que cambiandole el signo
Matriz matrizOperacion(char operacion, Matriz a, Matriz b){
    int resultadoOperacion = 0;
    string valoresMResultado = "";
    Matriz mResultado;
    if(a.filas != b.filas || a.columnas != b.columnas){
        mResultado = matriz("0", 1, 1);
    }else{
        mResultado = matriz(a.filas, a.columnas);
        for(int i = 0; i < length(a.s); i++){
            int aInt = charToInt(a.s[i]);
            int bInt = charToInt(b.s[i]);
            // resultadoOperacion = charToInt(a.s[i]) - charToInt(b.s[i]);
            resultadoOperacion = operacion == '+' ? aInt + bInt:
                                 operacion == '-' ? aInt - bInt:
                                 operacion == '*' ? aInt * bInt:
                                 0;
            if (unDigitoPositivo(resultadoOperacion)){
                // matrizSuma.s[i] = intToChar(suma);
                valoresMResultado = valoresMResultado + intToChar(resultadoOperacion);
            }else{
                valoresMResultado = valoresMResultado + 'X';
            }
        }
    }
    mResultado.s = valoresMResultado;
    return mResultado;
}

// Aca la funcion sumar sale simplemente de usar la anterior funcion pasandole el signo
Matriz miMatrizSumar(Matriz a,Matriz b){
    return matrizOperacion('+', a, b);
}

// Lo mismo para la funcion de resta
Matriz miMatrizRestar(Matriz a,Matriz b){
    return matrizOperacion('-', a, b);
}