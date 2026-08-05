#ifndef _TFILES_T_
#define _TFILES_T_

#include <stdio.h>

#include <iostream>
#include "strings.hpp"
using std::string;

// 1.5.1.1. Función write
// Prototipo: void write(FILE* f,T t);
// Descripción: Escribe el valor t en la posición actual del archivo f.
template <typename T>
void write(FILE* f, T t)
{
    fwrite(&t, sizeof(T), 1, f);
}

// 1.5.1.2. Función read
// Prototipo: T read(FILE* f);
// Descripción: Lee del archivo f un registro tipo T y retorna el valor leído.
// Parámetro: FILE* f – Archivo desde el cual vamos a leer un registro.
template <typename T>
T read(FILE* f)
{
    T t;
    fread(&t, sizeof(T), 1, f);
    return t;
}

// 1.5.1.3. Función seek
// Prototipo: void seek(FILE* f,int n);
// Descripción: Mueve el indicador de posición del archivo f al inicio del registro n.
template <typename T>
void seek(FILE* f, int n)
{
    fseek(f, n*sizeof(T), SEEK_SET);
}

// 1.5.1.4. Función fileSize
// Descripción: Retorna la cantidad de registros tipo T que contiene el archivo.
template <typename T>
int fileSize(FILE* f)
{
    int actual = ftell(f);
    fseek(f, 0, SEEK_END);
    int ultimo = ftell(f);
    fseek(f, actual, SEEK_SET);
    int tamanio = (ultimo/sizeof(T));
    return tamanio;
}

// 1.5.1.5. Función filePos
// Descripción: Retorna el número de registro que está siendo apuntado por el indicador
// de posición del archivo f.
template <typename T>
int filePos(FILE* f)
{
    // int posByte = ftell(f);
    // int posAct = posByte/sizeof(T);
    // return posAct;

    // O DIRECTAMENTE
    return (ftell(f)/sizeof(T));
}

// --- manejor de archivos de texto ---
// Sugerencia: implementar usando fread y fwrite

// 1.5.1.6. Función readLine
// Prototipo: bool readLine(FILE* f,string& ln);
// Descripción: Lee una línea de texto desde el archivo f y la asigna a ln. Retorna true
// si quedan más líneas por leer.
bool readLine(FILE* f,string& ln)
{
    ln = "";
    char c = read<char>(f);
    while(!feof(f) && c != '\n'){
        ln += c;
        c = read<char>(f);
    }

    // La condicion ln != "" se agrega, ya que, podemos estar en el final del archivo
    // pero la linea donde termina el archivo puede tener una palabra a leer, entonces
    // todavia podemos leer esa linea
    // y cuando pasemos a la siguiente iteracion ahi si
    // estariamos en el final del archivo y en un linea vacia, entonces ya no hay nada que leer
    return !feof(f) || ln != "";
}

// 1.5.1.7. Función readWord
// Prototipo: bool readWord(FILE* f,string& w,string alsoAllowed);
// Descripción: Lee una palabra desde el archivo f y la asigna a w, considerando que
// palabra es un conjunto de caracteres comprendidos en [A-Z], [a-z], [0-9] más
// aquellos caracteres comprendidos en alsoAllowed.
bool readWord(FILE* f,
              string& w,
              string alsoAllowed)
{
    w = "";
    char c = read<char>(f);

    // Salteamos todos los caracteres que nosotros no permitimos
    while( !feof(f) && !(charToInt(c) != -1 || contains(alsoAllowed, c)) ){
        c = read<char>(f);
    }

    // Ahora si leemos la palabra
    while(!feof(f) && (charToInt(c) != -1 || contains(alsoAllowed, c))){
        w += c;
        c = read<char>(f);
    }

    return w != "";
}


bool readWord(FILE* f,string& w)
{
    return readWord(f, w, "");
}

// 1.5.1.9. Función writeString
// Prototipo: void writeString(FILE* f,string s);
// Descripción: Escribe la cadena s en el archivo f.
void writeString(FILE* f,string s)
{
    for(int i = 0; i<length(s); i++){
        write<char>(f, s[i]);
    }
}

// 1.5.1.10. Función writeWord
// Prototipo: void writeWord(FILE* f,string w);
// Descripción: Escribe la palabra w en el archivo f.
// la diferencia con la funcion anterior es que vamos a aniadir un espacio al final
void writeWord(FILE* f,string w)
{
    writeString(f, w + " ");
}

// 1.5.1.11. Función writeLine
// Prototipo: void writeLine(FILE* f,string ln);
// Descripción: Escribe la línea ln en el archivo f.
// hace un salto de linea despues de escribir ln
void writeLine(FILE* f,string ln)
{
    writeString(f, ln + '\n');
}

#endif
