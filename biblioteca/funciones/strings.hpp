#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <math.h>
#include <stdio.h>
#include <string.h>

#include <iostream>
using std::string;

// 1.2.1.1. Función length
// Descripción: Cuenta la cantidad de caracteres que componen la cadena s.
// Parámetro: string s – Cadena cuya longitud debemos averiguar.
// Retorna: int – Cuántos caracteres contiene la cadena s.
int length(string s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        i++;
    }
    return i;
}

// 1.2.1.1. Función length
// Descripción: Cuenta la cantidad de caracteres que componen la cadena s.
// Parámetro: string s – Cadena cuya longitud debemos averiguar.
// Retorna: int – Cuántos caracteres contiene la cadena s.
int charCount(string s, char c)
{
    int charCounter = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == c)
        {
            charCounter++;
        }
    }
    return charCounter;
}

// 1.2.1.3. Función substring
// Descripción: Retorna la subcadena de s comprendida entre las posiciones d
// (inclu- sive) y h (no inclusive).
string substring(string s, int d, int h)
{
    string ss = "";
    for(int i = d; i < h; i++)
    {
        ss += s[i];
    }
    return ss;
}

// 1.2.1.4. Función substring (sobrecarga)
// Descripción: Retorna la subcadena de s comprendida entre la posición d y el
// final de la cadena.
string substring(string s, int d)  // ok
{
    string ss = "";
    for(int i = d; i < s.length(); i++)
    {
        ss += s[i];
    }
    return ss;
}

// 1.2.1.5. Función indexOf
// Descripción: Retorna la posición que ocupa la primera ocurrencia del carácter
// c dentro de la cadena s. Retorna: int – La posición que ocupa, dentro de s,
// la primera ocurrencia del carácter c, o un valor negativo si s no contiene a
// c.
int indexOf(string s, char c)  // ok
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == c)
        {
            return i;
        }
    }
    return -1;
}

// 1.2.1.6. Función indexOf (sobrecarga)
// Descripción: Retorna la posición que ocupa la primera ocurrencia de un
// carácter c dentro de la cadena s, descartando los primeros offset caracteres
// (desplaza- miento inicial).
int indexOf(string s, char c, int offSet)  // ok
{
    for(int i = offSet; i < s.length(); i++)
    {
        if(s[i] == c)
        {
            return i;
        }
    }
    return -1;
}

// 1.2.1.7. Función indexOf (sobrecarga)
// Descripción: Retorna la posición que ocupa la primera ocurrencia de toSearch
// dentro de la cadena s. Retorna: int – La posición inicial de la primera
// ocurrencia de toSearch dentro de s o un valor negativo si s no contiene a
// toSearch.
int indexOf(string s, string toSearch)  // ok
{
    for(int i = 0, toSearchLength = toSearch.length();
        i <= s.length() - toSearch.length(); i++, toSearchLength++)
    {
        if(substring(s, i, toSearchLength) == toSearch)
        {
            return i;
        }
    }
    return -1;
}

// 1.2.1.8. Función indexOf (sobrecarga)
// Descripción: Retorna la posición que ocupa la primera ocurrencia de toSearch
// dentro de la cadena s, descartando los primeros offeset caracteres (desplaza-
// miento inicial).
// Retorna: int – La posición que ocupa la primera ocurrencia de toSearch
// conside- rando a s a partir de la posición offset.
int indexOf(string s, string toSearch, int offset)
{
    for(int i = offset, toSearchLength = toSearch.length() + offset;
        i <= s.length() - toSearch.length(); i++, toSearchLength++)
    {
        if(substring(s, i, toSearchLength) == toSearch)
        {
            return i;
        }
    }
    return -1;
}

// 1.2.1.9. Función lastIndexOf
// Descripción: Retorna la posición de la última ocurrencia del carácter c
// dentro de s. Parámetros: • string s - Cadena que contiene al carácter c. •
// char c - Carácter cuya última posición, dentro de s, queremos averiguar.
// Retorna: int – La posición que ocupa, dentro de s, la última ocurrencia del
// carácter c, o un valor negativo si s no contiene a c.
int lastIndexOf(string s, char c)
{
    int lastIndex = -1;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == c)
        {
            lastIndex = i;
        }
    }
    return lastIndex;
}

// Descripción: Retorna la posición de la n-ésima ocurrencia de c dentro de s.
// Si n es 0 (cero) retorna -1; si n es mayor que la cantidad de ocurrencias de
// c retorna la longitud de la cadena s. Parámetros: • string s - Cadena que
// contiene al carácter c. • char c - Carácter cuya posición se debe determinar.
// Se asume que s contiene a c, al menos, n veces. • int n - Número de
// ocurrencia de c, contando desde 1. Retorna: int - La posición de la n-ésima
// ocurrencia de c dentro de s. Ejemplo de uso: string s =
// "John|Paul|George|Ringo"; int p = indexOfN(s,'|',1); cout << p << endl; //
// muestra: 4 p = indexOfN(s,'|',2); cout << p << endl; // muestra: 9 p =
// indexOfN(s,'|',3); cout << p << endl; // muestra: 16
int indexOfN(string s, char c, int n)
{
    int charIndexCount = 0;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == c)
        {
            charIndexCount++;
            if(charIndexCount == n)
            {
                return i;
            }
        }
    }
    if(n == 0)
    {
        return -1;
    }
    else
    {
        return s.length();
    }
}

// 1.2.1.11. Función charToInt
// Prototipo: int charToInt(char c);
// Descripción: Retorna el valor numérico que representa el carácter c.
// Parámetro: char c – Carácter que podrá ser numérico o alfabético, siendo ‘0’
// <= c
// <= ‘9’, ‘A’ <= c <= ’Z’, ‘a’ <= c <= ‘z’. Acepta indistintamente mayúsculas y
// minúsculas. Retorna: int - El valor numérico del carácter c. Para letras se
// considera: ‘A’=10.
int charToInt(char c)
{
    int inicio = 0, fin = 0;
    char ascii = 0;
    bool charEncontrado = false;
    if('0' <= c && c <= '9')
    {
        inicio = 0;
        fin = 9;
        ascii = 48;
    }
    else if('A' <= c && c <= 'Z')
    {
        inicio = 10;
        fin = 35;
        ascii = 65;
    }
    else if('a' <= c && c <= 'z')
    {
        inicio = 36;
        fin = 61;
        ascii = 97;
    }
    for(int i = inicio; i <= fin; i++)
    {
        if(c == ascii)
        {
            return i;
        }
        ascii++;
    }

    // string cs =
    // "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; for(int
    // i = 0; i < cs.length(); i++){
    //     if (c == cs[i]){
    //         return i;
    //     }
    // }

    // return 0;
    return -1;

    // OTRA FORMA ES HACER UN STRING CON 0123456789ABCDEF...xyz y recorrerlo y
    // devolver i
}

// 1.2.1.12. Función intToChar
// Descripción: Retorna el carácter que representa al valor de i, que debe estar
// com- prendido entre 0 y 61. Es la función inversa de charToInt. Parámetro:
// int i - Valor numérico. Retorna: char - El carácter que representa al valor
// de i, considerando que 10=’A’.
char intToChar(int charEnInt)
{
    string cs =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for(int pos = 0; pos < cs.length(); pos++)
    {
        if(charEnInt == pos)
        {
            return cs[pos];
        }
    }
    return '?';
}

// 1.2.1.13. Función getDigit
// Prototipo: int getDigit(int n,int i);
// Descripción: Retorna el i-ésimo dígito del valor de n.
// Parámetros:

// • int n – Número entero de 1 o más dígitos desde donde que se quiere ob-
// tener el dígito que se ubica en la i-ésima posición.

// • int i - Posición, contando desde 0 (cero) y de derecha a izquierda, del dí-
// gito de n que queremos obtener.

// Retorna: int - El dígito que se ubica en la i-ésima posición de n.
// Ejemplo de uso:

// int n = 12345;
// int i = 0;
// int r = getDigit(n,i);
// cout << r << endl; // muestra: 5
// i = 1;
// r = getDigit(n,i);
// cout << r << endl; // muestra: 4
int getDigit(int n, int i)
{
    int divisor = 1;
    for(int cont = 0; cont < i; cont++)
    {
        divisor *= 10;
    }
    int eneDigito = (n / divisor) % 10;

    return eneDigito;
}

// 1.2.1.14. Función digitCount
// Prototipo: int digitCount(int n);
// Descripción: Retorna la cantidad de dígitos que contiene el valor de n.
// Parámetro: int n - Valor numérico cuya cantidad de dígitos queremos
// averiguar. Retorna: int - La cantidad de dígitos que tiene el valor de n.
// Ejemplo de uso:
// int n = 12345;
// int i = digitCount(n);
// cout << i << endl; // muestra: 5
int digitCount(int n)
{
    int digitos = 1;
    int divisor = 1;

    while(true)
    {
        if(((n / divisor) < 10) && ((n / divisor) > -10))
        {
            return digitos;
        }
        divisor *= 10;
        digitos++;
    }

    return 0;
}

// 1.2.1.15. Función intToString
// Prototipo: string intToString(int i);
// Descripción: Retorna una cadena de caracteres representando el valor i.
// Parámetro: int i - Valor numérico entero que se va a representar como string.
// Retorna: string - Cadena de caracteres que representando el valor de i.
// Ejemplo de uso:
// int i = 12345;
// string s = intToString(i);
// cout << s << endl; // muestra: 12345
string intToString(int i)
{
    string s = "";
    string signo = "";
    int digito = 0;
    if(i == 0)
    {
        return "0";
    }
    else if(i < 0)
    {
        i *= (-1);
        signo = "-";
    }
    while(i > 0)
    {
        digito = i % 10;
        s = ((char)('0' + digito)) + s;
        i /= 10;
    }
    return signo + s;
}

// 1.2.1.16. Función stringToInt
// Prototipo: int stringToInt(string s,int b);

// Descripción: Retorna el valoro numérico representado en la cadena s, conside-
// rando que dicho valor está expresado en la base numérica b.

// Parámetros:
// • string s - Cadena que representa un valor numérico entero en base b.
// • int b - Base numérica del valor que representado en la cadena s.
// Retorna: int - El número numérico representado en la cadena s.
// Ejemplo de uso:

// string s = "10";
// int i = stringToInt(s,10);
// cout << i << endl; // muestra: 10
// i = stringToInt(s,2);
// cout << i << endl; // muestra: 2
// i = stringToInt(s,16);
// cout << i << endl; // muestra: 16
// s = "12AB";
// i = stringToInt(s,16);
// cout << i << endl; // muestra: 4779
int stringToInt(string s, int b)  // ok
{
    // int basePosicion = 1;
    // int posicion = s.length() - 1;
    // int nroPosicion = 0;
    // int numeroInt = 0;
    // for (int i = 0; i < s.length(); i++){
    //     for(posicion; posicion >= 0; posicion--){
    //         basePosicion *= b;
    //     }
    //     nroPosicion = charToInt(s[i]);
    //     nroPosicion *= basePosicion;
    //     numeroInt += nroPosicion;
    //     nroPosicion = 0;
    //     basePosicion = 0;
    // }

    int signo = s[0] == '-' ? -1 : 1; // ANIADIDO UNA SEMANA DESPUES DE PROGRAMADA LA FUNCION
                                      // SEGURAMENTE ANDA BIEN, NO DEBERIA ROMPER NADA

    int basePosicion = 1;
    int posicion = 0;
    int nroPosicion = 0;
    int numeroInt = 0;
    for(int i = s.length() - 1; i >= 0; i--)
    {
        for(int j = posicion; j > 0; j--)
        {
            basePosicion *= b;
        }
        posicion++;
        nroPosicion = charToInt(s[i]);
        nroPosicion *= basePosicion;
        numeroInt += nroPosicion;
        nroPosicion = 0;
        basePosicion = 1;
    }
    // FUNCA PERFECTOE ESTE CODIGO (EL DE MAS ARRIBA QUE ESTA)
    // COMENTADO NO FUNCIONA
    return signo * numeroInt;
    // SIGNO ANIADIDO UNA SEMANA DESPUES
}

// 1.2.1.17. Función stringToInt (sobrecarga)
// Prototipo: int stringToInt(string s); // SOBRECARGA

// Descripción: Retorna el valor numérico de la cadena s, la cual sólo debe
// contener dí- gitos numéricos en base 10. Esta función es la función inversa
// de intToString.

// Parámetro: string s - Cadena de caracteres que sólo contiene dígitos
// numéricos. Retorna: int - El valor numérico que está representado en la
// cadena s. Ejemplo de uso: string s = "12345"; int i = stringToInt(s); cout <<
// i << endl; // muestra: 12345
int stringToInt(string s)  // ok
{
    return stringToInt(s, 10);
}

// 1.2.1.18. Función charToString
// Prototipo: string charToString(char c);
// Descripción: Retorna una cadena cuyo único carácter es c.
// Parámetro: char c – Carácter que será el contenido de la cadena.
// Retorna: string - Una cadena de longitud 1 cuyo único carácter será c.
// Ejemplo de uso:
// char c = 'A';
// string s = charToString(c);
// cout << s << endl; // muestra: A
// cout << length(s) << endl; // muestra: 1
// c = ' ';
// string s = charToString(c);
// cout << s << endl; // muestra: [VACIO]
// cout << length(s) << endl; // muestra: 1
string charToString(char c)
{
    string cadena = "";
    cadena += c;
    // for(int i = 0; i < 1; i++){
    //     if(c != ' '){
    //         cadena += c;
    //     }else{
    //         cadena = "[VACIO]";
    //     }
    // }
    return cadena;
}

// 1.2.1.19. Función stringToChar
// Prototipo: char stringToChar(string s);
// Descripción: Retorna el único carácter que contiene la cadena s. Esta es la
// función inversa de charToString. Parámetro: string s - Cadena de caracteres
// de longitud 1. Retorna: char - El único carácter que contiene la cadena s.
// Ejemplo de uso:
// string s = "A";
// char c = stringToChar(s);
// cout << c << endl; // muestra: A
// cout << (int)c << endl; // muestra: 65
// s = " ";
// c = stringToChar(s);
// cout << c << endl; // muestra: [VACIO]
// cout << (int)c << endl; // muestra: 32, ASCII de ' '
char stringToChar(string s)
{
    char c = s[0];
    return c;
}

// 1.2.1.20. Función stringToString
// Prototipo: string stringToString(string s);
// Descripción: Retorna la misma cadena que recibe. Se trata de una función
// trivial que usaremos más adelante, dentro de este mismo capítulo. Parámetro:
// string s - Cadena de caracteres. Retorna: string – La misma cadena que recibe
// como parámetro. Ejemplo de uso: string s = stringToString("Hola"); cout << s
// << endl; // muestra: Hola
string stringToString(string s)
{
    string cadena = s;
    return cadena;
}

// 1.2.1.1. Función doubleToString
// Prototipo: string doubleToString(double d,int prec);

// Descripción: Retorna una cadena representando el valor contenido en d con una
// pre- cisión de prec dígitos para la parte decimal.

// Parámetro: double d - Valor que se representará como cadena.
// Parámetro: int prec – Precisión de la parte decimal del número n.
// Retorna: string - Cadena de caracteres representando el valor de d.
// Ejemplo de uso:
// double d = 123.45678;
// string s = doubleToString(d,4);
// cout << s << endl; // muestra: 123.4567
string doubleToString(double d, int prec)
{
    // int multiplicador = 1;
    // for(int i = prec; i > 0; i--){
    //     multiplicador *= 10;
    // }
    // int num = (int)(d * multiplicador);
    // string numeroCadena = intToString(num);

    int multiplicador = 1;
    int parteEntera = (int)d;
    double parteDecimal = (double)(d - parteEntera);
    for(int i = prec; i > 0; i--)
    {
        multiplicador *= 10;
    }
    int decimalInt = (int)(parteDecimal * multiplicador + 0.000000001);
    string decimales = intToString(decimalInt);
    while(decimales.length() < prec)
    {
        decimales = "0" + decimales;
    }
    string s = intToString(parteEntera) + "." + decimales;
    return s;
}

// 1.2.1.2. Función doubleToString (sobrecarga)
// Prototipo: string doubleToString(double d);

// Descripción: Retorna una cadena representando el valor contenido en d con una
// pre- cisión de 3 dígitos para la parte decimal.

// Parámetro: double d - Valor que se representará como cadena.
// Retorna: string - Cadena de caracteres representando el valor de d.
// Ejemplo de uso:
// double d = 123.45678;
// string s = doubleToString(d);
// cout << s << endl; // muestra: 123.456
string doubleToString(double d)
{
    return doubleToString(d, 3);
}

// 1.2.1.3. Función stringToDouble
// Prototipo: double stringToDouble(string s);
// Descripción: Retorna el valor numérico representado en la cadena s.
// Parámetro: string s - Cadena que contiene un valor compatible con double.
// Retorna: double – El valor que está representado en la cadena s.
// Ejemplo de uso:
// string s = "123.4";
// double d = stringToDouble(s);
// cout << d << endl; // muestra: 123.4
double stringToDouble(string s)
{
    int posComa = indexOf(s, '.');
    string stringParteEntera = substring(s, 0, posComa);
    string stringParteDecimal = substring(s, posComa+1, s.length());
    int parteEntera = stringToInt(stringParteEntera);
    int parteDecimal = stringToInt(stringParteDecimal);
    int divisor = 1;
    for(int i = 0; i < stringParteDecimal.length(); i++){
        divisor *= 10;
    }
    double decimales = (double)parteDecimal / divisor;
    double numerin = (double)parteEntera + decimales;
    return numerin;
}

// 1.2.1.4. Función isEmpty
// Prototipo: bool isEmpty(string s);
// Descripción: Retorna true o false según s sea o no la cadena vacía.
// Parámetro: string s - Una cadena de caracteres.
// Retorna: bool – Retorna true si s es la cadena vacía o false si no lo es.
// Ejemplo de uso:
// string s = "";
// cout << isEmpty(s) << endl; // true
// s = "Hola";
// cout << isEmpty(s) << endl; // false
// s = " ";
// cout << isEmpty(s) << endl; // false
bool isEmpty(string s)
{
    return s == "";
}

// 1.2.1.5. Función startsWith
// Prototipo: bool startsWith(string s,string x);
// Descripción: Determina si x es prefijo de s.
// Parámetros:
// • string s - Cadena que podría comenzar con x.
// • char x – Cadena que podría ser prefijo de s.
// Retorna: bool - true si x es prefijo de s.
// Ejemplo de uso:
// string s1 = "cursoDeAlgoritmos";
// string s2 = "curso";
// if( startsWith(s1,s2) )
// {
// cout << s2 << " es prefijo de: " << s1 << endl;
// }
bool startsWith(string s, string x)
{
    // ESTA FORMA FUNCIONA, PERO DA ERRORES SI S ES DE MENOR LONGITUD QUE X
    // string prefijo = substring(s, 0, x.length());
    // return (prefijo == x);

    for(int i = 0; i < x.length(); i++){
        if(s[i] != x[i]){
            return false;
        }
    }
    return true;
}

// 1.2.1.6. Función endsWith
// Prototipo: bool endsWith(string s,string x);
// Descripción: Determina si x es sufijo de s.
// Parámetros:
// • string s - Cadena que podría finalizar con x.
// • char x – Cadena que podría ser sufijo de s.
// Retorna: bool - true si x es sufijo de s.
// Ejemplo de uso:
// string s1 = "cursoDeAlgoritmos";
// string s2 = "Algoritmos";
// if( endsWith(s1,s2) )
// {
// cout << s2 << " es sufijo de: " << s1 << endl;
// }
bool endsWith(string s, string x)
{
    if(s.length() < x.length()){
        return false;
    }
    string cadenaFinal = substring(s, s.length() - x.length());
    if(!(cadenaFinal == x)){
        return false;
    }
    return true;
}

// 1.2.1.7. Función contains
// Prototipo: bool contains(string s,char c);
// Descripción: Determinar si la cadena s contiene al carácter c.
// Parámetros:
// • string s - Cadena que podría contener al carácter c.
// • char c - Carácter cuyo valor podría estar contenido en s.
// Retorna: bool - true si s contiene a c; false si no lo contiene.
// Ejemplo de uso:
// string s = "abcd";
// char c = 'b';
// if( contains(s,c) )
// {
// cout << s << " contiene a: " << c << endl;
// }
// c = 'X';
// if( !contains(s,c) )
// {
// cout << s << " NO contiene a: " << c << endl;
// }
bool contains(string s, char c)
{
    for(int i = 0; i < s.length(); i++){
        if(s[i] == c){
            return true;
        }
    }
    return false;
}

// 1.2.1.8. Función replace
// Prototipo: string replace(string s,char oldChar,char newChar);
// Descripción: Reemplaza en s todas las ocurrencias de oldChar por newChar.
// Parámetros:
// • string s - Cadena sobre la cual se reemplazarán los caracteres.
// • char oldChar - Carácter que va a ser reemplazado por newChar.
// • char newChar - Valor que reemplazará todas las ocurrencias de oldChar.
// Retorna: string - La cadena s con caracteres oldChar donde antes tenía oldChar.
// Ejemplo de uso:
// string s = "Esto es una prueba";
// string r = replace(s,'e','X');
// cout << r << endl; // SALIDA: Esto Xs una pruXba
string replace(string s, char oldChar, char newChar)
{
    for(int i = 0; i < s.length(); i++){
        if(s[i] == oldChar){
            s[i] = newChar;
        }
    }
    return s;
}

// 1.2.1.9. Función insertAt
// Prototipo: string insertAt(string s,int pos,char c);
// Descripción: Insertar el carácter c en la posición pos de la cadena s.
// Parámetros:
// • string s - Cadena de caracteres donde se insertará un carácter.
// • int pos - Posición de s se va a insertar al carácter c.
// • char c - Carácter que se insertará en s, en la posición pos.
// Retorna: string - Una cadena cuya longitud será length(s)+1, idéntica a s pero
// con el valor de c insertado en la posición pos.
// Ejemplo de uso:
// string s = "Esto es una prueba";
// int pos = 6;
// char c = 'X';
// string r = insertAt(s,pos,c);
// cout << r << endl; // SALIDA: Esto eXs una prueba
string insertAt(string s, int pos, char c)
{
    string cadenaAnterior = substring(s, 0, pos);
    string cadenaPosterior = substring(s, pos);
    string cadenaRet = cadenaAnterior + c + cadenaPosterior;
    return cadenaRet;
}

// 1.2.1.10. Función removeAt
// Prototipo: string removeAt(string s,int pos);
// Descripción: Remover de s el carácter ubicado en la posición pos.
// Parámetros:
// • string s - Cadena de caracteres sobre la cual se removerá un carácter.
// • int pos - Posición del carácter que se removerá.
// Retorna: string - Una cadena igual a s pero sin s[pos].
// Ejemplo de uso:
// string s = "Esto es una prueba";
// int pos = 7;
// string r = removeAt(s,pos);
// cout << r << endl; // SALIDA: Esto esuna prueba
string removeAt(string s, int pos)
{
    string cadenaAnterior = substring(s, 0, pos);
    string cadenaPosterior = substring(s, pos+1);
    string cadenaRet = cadenaAnterior + cadenaPosterior;
    return cadenaRet;
}

// 1.2.1.11. Función ltrim
// Prototipo: string ltrim(string s);
// Descripción: Recorta los espacios en blanco que se encuentren a la izquierda de s.
// Parámetro: string s - Cadena que podría tener espacios a la izquierda.
// Retorna: string - Una cadena idéntica a s pero sin espacios a la izquierda.
// Ejemplo de uso:
// string s = " Esto es una prueba"; // espacios a izq
// string r = ltrim(s);
// cout << "[" << r << "]" << endl; // [Esto es una prueba]
// s = "Esto es una prueba"; // sin espacios
// r = ltrim(s);
// cout << "[" << r << "]" << endl; // [Esto es una prueba]
// s = " Esto es una prueba "; // espacios a izq y der
// r = ltrim(s);
// cout << "[" << r << "]" << endl; // [Esto es una prueba ]
string ltrim(string s)
{
    while(s[0] == ' '){
        s = removeAt(s, 0);
    }
    return s;
}

// 1.2.1.12. Función rtrim
// Prototipo: string rtrim(string s);
// Descripción: Recortar los espacios en blanco a la derecha de s.
// Parámetro: string s - Cadena que podría tener espacios a la derecha.
// Retorna: string - Una cadena idéntica a s sin espacios en blanco a la derecha.
// Ejemplo de uso:
// string s = "Esto es una prueba "; // espacios a der
// string r = rtrim(s);
// cout << "[" << r << "]" << endl; // [Esto es una prueba]
// s = "Esto es una prueba"; // sin espacios
// r = rtrim(s);
// cout << "[" << r << "]" << endl; // [Esto es una prueba]
// s = " Esto es una prueba "; // espacios a izq y der
// r = rtrim(s);
// cout << "[" << r << "]" << endl; // [ Esto es una prueba]
string rtrim(string s)
{
    while(s[s.length() - 1] == ' '){
        s = removeAt(s, s.length() - 1);
    }
    return s;
}

// 1.2.1.13. Función trim
// Prototipo: string trim(string s);
// Descripción: Recortar los espacios en blanco ubicados a izquierda y derecha de s.
// Parámetro: string s - Cadena que podría contener espacios en los extremos.
// Retorna: string - Una cadena idéntica a s sin espacios en los extremos.
// Ejemplo de uso:
// // con espacios a izquierda y derecha
// string s = " Esto es una prueba ";
// string r = trim(s);
// cout << "[" << r << "]" << endl; // [Esto es una prueba]
// // con espacios dentro de la cadena
// s = "Esto es una prueba";
// r = rtrim(s);
// cout << "[" << r << "]" << endl; // [Esto es una prueba]
string trim(string s)
{
    // FUNCIONA CUALQUIERA DE LAS DOS MANERAS VISTAS ABAJO
    return rtrim(ltrim(s));
    // return ltrim(rtrim(s));
}

// 1.2.1.14. Función replicate
// Prototipo: string replicate(char c,int n);
// Descripción: Generar una cadena de caracteres compuesta por n caracteres c.
// Parámetros:
// • char c - Carácter que se replicará n veces para generar la cadena.
// • int n - Cantidad de caracteres que tendrá la cadena generada.
// Retorna: string - Una cadena compuesta por n caracteres c.
// Ejemplo de uso:
// int n = 5;
// char c = 'X'
// string r = replicate(c,n);
// cout << "[" << r << "]" << endl; // muestra: [XXXXX]
// c = ' ';
// r = replicate(c,n);
// cout << "[" << r << "]" << endl; // muestra: [ ]
string replicate(char c, int n)
{
    string stringRet = "";
    for(int i = 0; i < n; i++){
        stringRet += c;
        // stringRet = stringRet + c;
    }
    return stringRet;
}

// 1.2.1.15. Función spaces
// Prototipo: string spaces(int n);
// Descripción: Genera una cadena de caracteres compuesta por n caracteres ' '.
// Parámetro: int n – Longitud de la cadena que se generará.
// Retorna: string - Una cadena compuesta por n caracteres ' '.
// Ejemplo de uso:
// int n = 5;
// string r = spaces(n);
// // muestra: [ ] (cinco espacios)
// cout << "[" << r << "]" << endl;
string spaces(int n)
{
    return replicate(' ', n);
}

// 1.2.1.16. Función lpad
// Prototipo: string lpad(string s,int n,char c);
// Descripción: Retorna una cadena idéntica a s, con longitud n completando, si fuese
// necesario, con caracteres c a la izquierda hasta llegar a la longitud requerida.
// Parámetros:
// • int n - Longitud final que tendrá la cadena.
// • char c - Carácter con que se completará a s si fuera necesario.
// Retorna: string - Una cadena de longitud n compuesta por n-length(s) carac-
// teres c seguidos de la cadena s.
// Ejemplo de uso:
// string s = "Hola";
// int n = 10;
// char c = 'X';
// string r = lpad(s,n,c);
// cout << "[" << r << "]" << endl; // muestra: [XXXXXXHola]
string lpad(string s, int n, char c)
{
    // LAS DOS FORMAS FUNCIONAN PERFECTOOOOOO
    
    // for(int i = s.length(); i < n; i++){
    //     s = insertAt(s, 0, c);
    // }

    while(s.length() < n){
        s = insertAt(s, 0, c);
    }
    return s;
}

// 1.2.1.17. Función rpad
// Prototipo: string rpad(string s,int n,char c);
// Descripción: Idem lpad pero, de ser necesario, agrega caracteres c a la derecha.
// Parámetros:
// • int n - Longitud final que tendrá la cadena retornada.
// • char c - Carácter con que se debe completará la cadena.

// 48 | Apéndice 2 ● Especificaciones y API

// CURSO DE ALGORITMOS Y PROGRAMACIÓN A FONDO – PABLO A. SZNAJDLEDER THE JAVA LISTENER

// Retorna: string - Una cadena de longitud n compuesta por el contenido de s se-
// guida de n-length(s) caracteres c.

// Ejemplo de uso:
// string s = "Hola";
// int n = 10;
// char c = 'X';
// string r = rpad(s,n,c);
// cout << "[" << r << "]" << endl; // muestra: [HolaXXXXXX]
string rpad(string s, int n, char c)
{
    // FUNCIONA PERFECTO, PERO NO SE PORQUE NO SE ROMPE (YO PIENSO QUE DEBERIA ROMPERSE)
    while(s.length() < n){
        s = insertAt(s, s.length(), c);
    }
    return s;
}

// 1.2.1.18. Función cpad
// Prototipo: string cpad(string s,int n,char c);
// Descripción: Idem rpad pero distribuye los caracteres c a izquierda y derecha.
// Parámetros:
// • int n - Longitud final que tendrá la cadena.
// • char c - Carácter con que se completará si fuerea necesario.
// Retorna: string - Una cadena de longitud n compuesta por s y caracteres c
// distribuidos a la izquierda y a la derecha de modo tal que su longitud final sea n.
// Ejemplo de uso:
// string s = "Hola";
// int n = 10;
// char c = 'X';
// string r = cpad(s,n,c);
// cout << "[" << r << "]" << endl; // muestra: [XXXHolaXXX]
string cpad(string s, int n, char c)
{
    n = n - s.length();
    int izq = n / 2, der = n / 2;
    if(n % 2 != 0){
        izq += 1;
    }

    s = lpad(s, izq + s.length(), c);
    s = rpad(s, der + s.length(), c);

    return s;
}

// 1.2.1.19. Función isDigit
// Prototipo: bool isDigit(char c);
// Descripción: Determinar si el valor de c corresponde o no a un dígito numérico.
// Parámetro: char c - Carácter a determinar si representa a un dígito numérico.
// Retorna: bool - true si c es '0', '1', '2', ..., '9', false en cualquier otro caso.
// Ejemplo de uso:
// char c = '9';
// if( isDigit(c) )
// {
// cout << c << " es digito" << endl; // SALIDA
// }
// c = 'A';
// if( !isDigit(c) )
// {
// cout << c << " NO es digito" << endl; // SALIDA
// }
bool isDigit(char c)
{
    // if('0' <= c && c <= '9'){
    //     return true;
    // }
    // return false;
    return '0' <= c && c <= '9';
}

// 1.2.1.20. Función isLetter
// Prototipo: bool isLetter(char c);
// Descripción: Determina si el valor de c corresponde o no a una letra.
// Parámetro: char c - Carácter a determinar si representa a una letra.
// Retorna: bool - true si c es 'A', 'B', 'C', ..., 'Z' o 'a', 'b', 'c', ..., 'z'. Si no retorna false.
// Ejemplo de uso:
// char c = 'X';
// if( isLetter(c) )
// {
// cout << c << " es letra" << endl; // SALIDA
// }
// c = '9';
// if( !isLetter(c) )
// {
// cout << c << " NO es letra" << endl; // SALIDA
// }
bool isLetter(char c)
{
    if(10 <= charToInt(c) && charToInt(c) <= 61){
        return true;
    }
    return false;

    // OTRA FORMAAAAA
    // return (10 <= charToInt(c) && charToInt(c) <= 61)
}

// 1.2.1.21. Función isUpperCase
// Prototipo: bool isUpperCase(char c);
// Descripción: Determinar si el valor de c corresponde a una letra mayúscula.
// Parámetro: char c - Carácter para determinar si es una letra mayúscula.
// Retorna: bool - true si c es 'A', 'B', 'C', ..., 'Z', false en cualquier otro caso.
// Ejemplo de uso:
// char c = 'X';
// if( isUpperCase(c) )
// {
// cout << c << " es letra mayuscula" << endl; // SALIDA
// }
// c = 'x';
// if( !isUpperCase(c) )
// {
// cout << c << " NO es mayuscula" << endl; // SALIDA
// }
bool isUpperCase(char c)
{
    return (10 <= charToInt(c) && charToInt(c) <= 35);
}

// 1.2.1.22. Función isLowerCase
// Prototipo: bool isLowerCase(char c);
// Descripción: Determina si el valor de c corresponde a una letra minúscula.
// Parámetro: char c - Carácter a debe determinar si contiene una letra minúscula.
// Retorna: bool - true si c es 'a', 'b', 'c', ..., 'z', false en cualquier otro caso.
// Ejemplo de uso:
// char c = 'a';
// if( isLowerCase(c) )
// {
// cout << c << " es letra minuscula" << endl; // SALIDA
// }
// c = 'A';
// if( !isLowerCase(c) )
// {
// cout << c << " NO es minuscula" << endl; // SALIDA
// }
bool isLowerCase(char c)
{
    return (36 <= charToInt(c) && charToInt(c) <= 61);
}

// 1.2.1.23. Función toUpperCase
// Prototipo: char toUpperCase(char c);
// Descripción: Convertir el valor de c a mayúscula.
// Parámetro: char c - El carácter cuyo valor se debe convertir a mayúscula.
// Retorna: char – Si c es una letra minúscula retorna su mayúscula, en cualquier otro
// caso retorna el mismo valor de c.
// Ejemplo de uso:
// char c = 'a';
// char r = toUpperCase(c);
// cout << r << endl; // Salida: A (convierte a mayuscula)
// c = 'B';
// r = toUpperCase(c);
// cout << r << endl; // Salida: B (ya era mayuscula)
// c = '9';
// r = toUpperCase(c);
// cout << r << endl; // Salida: 9 (no es una letra)
char toUpperCase(char c)
{
    if(isLowerCase(c)){
        c = intToChar(charToInt(c) - 26);
    }
    return c;
}

// 1.2.1.24. Función toLowerCase
// Prototipo: char toLowerCase(char c);
// Descripción: Convierte el valor de c a minúscula.
// Parámetro: char c - El carácter cuyo valor se debe convertir a minúscula.
// Retorna: char – Si c es un una letra mayúscula retorna su minúscula, en cualquier
// otro caso retorna el mismo carácter c.
// Ejemplo de uso:
// char c = 'A';
// char r = toLowerCase(c);
// cout << r << endl; // Salida: a (convierte a minuscula)
// c = 'b';
// r = toLowerCase(c);
// cout << r << endl; // Salida: b (ya era minuscula)
// c = '9';
// r = toLowerCase(c);
// cout << r << endl; // Salida: 9 (no es una letra)
char toLowerCase(char c)
{
    if(isUpperCase(c)){
        c = intToChar(charToInt(c) + 26);
    }
    return c;
}

// 1.2.1.25. Función toUpperCase (sobrecarga)
// Prototipo: string toUpperCase(string s);
// Descripción: Retorna una cadena idéntica a s pero completamente en mayúsculas.
// Parámetro: string s – Cadena cuyo valor se debe convertir a mayúscula.
// Retorna: string – Una cadena igual a s pero totalmente en mayúsculas.
// Ejemplo de uso:
// string s = "hola";
// string r = toUpperCase(s);
// cout << r << endl; // Salida: HOLA
string toUpperCase(string s)
{
    string sRet = "";
    for(int i = 0; i < s.length(); i++){
        sRet += toUpperCase(s[i]);
    }
    return sRet;
}

// 1.2.1.26. Función toLowerCase (sobrecarga)
// Prototipo: string toLowerCase(string s);
// Descripción: Retorna una cadena idéntica a s pero completamente en minúsculas.
// Parámetro: string s – Cadena cuyo valor se debe convertir a minúsculas.
// Retorna: string – Una cadena igual a s pero totalmente en munúsculas.
// Ejemplo de uso:
// string s = "HOLA";
// string r = toLowerCase(s);
// cout << r << endl; // Salida: hola
string toLowerCase(string s)
{
    string sRet = "";
    for(int i = 0; i < s.length(); i++){
        sRet += toLowerCase(s[i]);
    }
    return sRet;
}

// 1.2.1.27. Función cmpString
// Prototipo: int cmpString(string a,string b);
// Descripción: Compara alfabéticamente dos cadenas.
// Parámetros:
// • string a – Cadena a comparar.
// • string b – Cadena a comparar.
// Retorna: int – Un valor negativo si a es alfabéticamente menor que b. Un valor
// positivo si a es alfabéticamente mayor que b, o 0 si ambas cadenas son iguales.
// Ejemplo de uso:
// string s1 = "Carlos";
// string s2 = "Pablo";
// if( cmpString(s1,s2)<0 )
// {
// cout << s1 << " es menor que: " << s2 << endl;
// }
int cmpString(string a, string b)
{
    if(a>b){
        return 1;
    }else if(a==b){
        return 0;
    }
    return -1;
}

// 1.2.1.28. Función cmpDouble
// Prototipo: int cmpDouble(double a,double b);
// Descripción: Compara dos valores.
// Parámetros:
// • double a – Valor a comparar.
// • double b – Valor a comparar.
// Retorna: int – Un valor negativo si a es menor que b. Un valor positivo si a es mayor
// que b, o 0 si ambos valores son iguales.
// Ejemplo de uso:
// double x = 25.7;
// double y = 36.9;
// if( cmpDouble(x,y)<0 )
// {
// cout << x << " es menor que: " << y << endl;
// }
int cmpDouble(double a, double b)
{
    if(a>b){
        return 1;
    }else if(a==b){
        return 0;
    }
    return -1;
}

char* stringToCString(string s)
{
    char* ret = new char[length(s) + 1];

    int i = 0;
    while(s[i] != '\0')
    {
        ret[i] = (char)s[i];
        i++;
    }

    ret[i] = '\0';
    return ret;
}

string cStringToString(char c[])
{
    return string(c);
}

#endif
