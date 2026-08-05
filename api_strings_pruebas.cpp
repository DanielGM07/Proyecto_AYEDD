#include <iostream>
#include <string>

#include "biblioteca/funciones/millis.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/intro/Fraccion.hpp"
#include "biblioteca/tads/parte1/Fecha.hpp"
#include "biblioteca/tads/parte1/Timer.hpp"
#include "biblioteca/tads/parte1/Coll.hpp"
#include "biblioteca/tads/parte2/Array.hpp"
#include "biblioteca/tads/parte2/List.hpp"
#include "biblioteca/tads/parte2/Map.hpp"
#include "biblioteca/tads/parte2/Queue.hpp"
#include "biblioteca/tads/parte2/Stack.hpp"
#include "principal.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::to_string;

// int indexOf(string s, string toSearch) 
int main()
{
    // string s = "Esto es una prueba una";
    // string buscar = "una";
    // cout << indexOf(s, buscar, 9) << endl;
    
    // string s = "ana habia una naranaja anaranjada";
    // char c = 't';
    // cout << s.length() - 1 << endl;
    // cout << lastIndexOf(s, c) << endl;

    // string s = "naranja anaranjada";
    // char c = 'a';
    // cout << indexOfN(s, c, 2) << endl;

    // char c = 'z';
    // cout << charToInt(c) << endl;

    // int pos = 62;
    // cout << intToChar(pos) << endl;

    // int numerin = 69420;
    // cout << getDigit(numerin, 3) << endl;

    // int numerin = -123;
    // cout << digitCount(numerin) << endl;
    
    // int numerin = -2346978;
    // cout << intToString(numerin) << endl;

    // string numerin = "AB";
    // cout << stringToInt(numerin, 16) << endl;

    // string numerin = "12345";
    // cout << numerin + numerin << endl;
    // cout << stringToInt(numerin) << endl;
    // cout << stringToInt(numerin) + 5 << endl;

    // char c = ' ';
    // cout << charToString(c) << endl;
    // cout << charToString(c).length() << endl;

    // string s = "u";
    // cout << stringToChar(s) << endl;
    // cout << (int)stringToChar(s) << endl;

    // double d = 123.69420;
    // cout << doubleToString(d, 0) << endl;

    // double d = 123.00942;
    // cout << doubleToString(d, 7) << endl;

    // string dobel = "6.69421";
    // cout << stringToDouble(dobel) << endl;
    
    // string s1 = "";
    // string s2 = " ";
    // string s3 = "a";
    // string esVacio1 = isEmpty(s1) ? "verdadero" : "falso";
    // string esVacio2 = isEmpty(s2) ? "verdadero" : "falso";
    // string esVacio3 = isEmpty(s3) ? "verdadero" : "falso";
    // cout << esVacio1 << endl;
    // cout << esVacio2 << endl;
    // cout << esVacio3 << endl;

    // string s1 = "cu";
    // string s2 = "curso";
    // string empiezaCon = startsWith(s1, s2) ? "verdadero" : "falso";
    // cout << empiezaCon << endl;

    // string s2 = "so";
    // string s1 = "curso";
    // string terminaCon = endsWith(s1, s2) ? "verdadero" : "falso";
    // cout << terminaCon << endl;

    // string s = "cadenita";
    // char c = 'r';
    // string loContiene = contains(s, c) ? "verdadero" : "falso";
    // cout << loContiene << endl;

    // string s = "naranjada";
    // char oldC = 'a';
    // char newC = '?';
    // string newS = replace(s, oldC, newC);
    // cout << newS << endl;

    // string s = "naranjada";
    // char carac = 'X';
    // int pos = 4;
    // string newS = insertAt(s, pos, carac);
    // cout << newS << endl;

    // string s = "cadena";
    // int pos = 0;
    // string newS = removeAt(s, pos);
    // cout << newS << endl;

    // string s = "  cadena  ";
    // string newS = ltrim(s);
    // cout << "[" << newS << "]" << endl;

    // string s = "   cadena     ";
    // string newS = rtrim(s);
    // cout << "[" << newS << "]" << endl;

    // string s = "      cadena     ";
    // string newS = trim(s);
    // cout << "[" << newS << "]" << endl;

    // char s = 'D';
    // int n = 3;
    // string newS = replicate(s, n);
    // cout << "[" << newS << "]" << endl;

    // int n = 3;
    // string newS = spaces(n);
    // cout << "[" << newS << "]" << endl;

    // string s = "Hola";
    // char c = 'x';
    // int n = 10;
    // string newS = lpad(s, n, c);
    // cout << "[" << newS << "]" << endl;

    // string s = "Hola";
    // char c = 'x';
    // int n = 10;
    // string newS = rpad(s, n, c);
    // cout << "[" << newS << "]" << endl;

    // string s = "Hola";
    // char c = 'x';
    // int n = 9;
    // string newS = cpad(s, n, c);
    // cout << "[" << newS << "]" << endl;

    // char c = '5';
    // string digito = isDigit(c) ? "verdadero" : "falso";
    // cout << digito << endl;

    // char c = 'Z';
    // string letra = isLetter(c) ? "verdadero" : "falso";
    // cout << letra << endl;

    // char c = 'a';
    // string mayus = isUpperCase(c) ? "verdadero" : "falso";
    // cout << mayus << endl;

    // char c = 'z';
    // string minus = isLowerCase(c) ? "verdadero" : "falso";
    // cout << minus << endl;

    // char c = 'z';
    // char upper = toUpperCase(c);
    // cout << upper << endl;

    // char c = 'V';
    // char lower = toLowerCase(c);
    // cout << lower << endl;

    // string s = "hOlaaaaaAa45-";
    // string upper = toUpperCase(s);
    // cout << upper << endl;

    // string s = "hoLAAAAAaaAAAa45-";
    // string lower = toLowerCase(s);
    // cout << lower << endl;

    // string s1 = "Pablaa";
    // string s2 = "Pabla";
    // int n = cmpString(s1, s2);
    // string s1Es = n > 0 ? "s1 es mayor" : n == 0 ? "son iguales" : "s1 es menor";
    // cout << s1Es << endl;

    // double s1 = 3.2;
    // double s2 = 3.145;
    // int n = cmpDouble(s1, s2);
    // string s1Es = n > 0 ? "s1 es mayor" : n == 0 ? "son iguales" : "s1 es menor";
    // cout << s1Es << endl;

    int n = 9;
    cout << intToString(n) << endl;

    return 0;    
}