#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <stdio.h>
#include <iostream>
#include "strings.hpp"
using std::string;

// 1.3.1.1. Función tokenCount
// Descripción: Cuenta la cantidad tokens que el separador sep genera en s.
int tokenCount(string s, char sep)
{
    return isEmpty(s) ? 0 : charCount(s, sep) + 1;
}

void addToken(string& s, char sep, string t)
{
    // De todas formas voy a dejar mi forma, asi toda mal optimizada jejeje
    s = tokenCount(s, sep) > 0 ? 
        s + sep + t : // retorno por true
        t;            // retorno por falso
    
    // Forma del profe. Tiene sentido, solo que yo trate de pensarlo usando la funcion anterior, tokenCount
    // s = isEmpty(s)?t:s+sep+t;
}

// 1.3.1.3. Función getTokenAt
// Descripción: Retorna el i-ésimo token de la cadena tokenizada s.
string getTokenAt(string s, char sep, int i)
{
    return substring(s, indexOfN(s, sep, i) + 1, indexOfN(s, sep, i+1));
}

// 1.3.1.4. Función removeTokenAt
// Descripción: Remueve de s el token ubicado en la posición i.
void removeTokenAt(string& s, char sep, int i)
{
    int iIni = i == 0 ? indexOfN(s, sep, i) + 1: indexOfN(s, sep, i);
    int largoToken = length(getTokenAt(s, sep, i));

    for (int j = 0; j <= largoToken; j++){
        s = removeAt(s, iIni);
    }
}

// 1.3.1.5. Función setTokenAt
// Descripción: Reemplaza por t el token de s ubicado en la posición i.
void setTokenAt(string& s, char sep, string t, int i)
{
    // asd|set|asd
    // asd|aset|asd
    // asd|asset|asd
    // asd|asdset|asd
    // asd|asdset|asd
    // asd|asd|set|asd
    //        |set     REMOVEMOS EXACTAMENTE ESOS CARACTERES DE LA CADENA CON EL METODO REMOVETOKENAT
    // asd|asd|asd
    int iIni = indexOfN(s, sep, i) + 1;
    for(int j = 0; j < length(t); j++){
        s = insertAt(s, iIni + j, t[j]);
        if(j == length(t) - 1) s = insertAt(s, iIni + length(t), sep);
    }
    removeTokenAt(s, sep, i+1);
}

// 1.3.1.6. Función findToken
// Prototipo: int findToken(string s, char sep,string t);
// Descripción: Determinar la posición que el token t ocupa dentro de la cadena s.

// indexOf(string s, string toSearch)

int findToken(string s, char sep, string t)
{
    // s0|s1|s2|s3|s4 TOTAL 5
    //
    //
    // int posIniT = indexOf(s, t);
    // if(posIniT >= 0){

    // }else{
    //     return posIniT;
    // }

    for (int i = 0; i < tokenCount(s, sep); i++){
        if (t == getTokenAt(s, sep, i)) return i;
    }
    return -1;
}

#endif
