/*
================================================================================
RESUMEN RAPIDO DE FUNCIONES - STRINGS / CONVERSIONES / UTILIDADES
================================================================================
Este archivo es una chuleta para saber que hace cada funcion y en que casos usarla.
No reemplaza al .hpp real: sirve como guia comentada para consultar rapido.

IMPORTANTE:
- Muchas funciones asumen que los parametros son validos.
- Si pasas posiciones fuera de rango, cadenas vacias o formatos incorrectos,
  algunas pueden fallar o devolver resultados inesperados.
- Las posiciones de los strings empiezan en 0.

================================================================================
1) FUNCIONES DE LONGITUD Y CONTEO
================================================================================

length(string s)
- Cuenta cuantos caracteres tiene la cadena s.
- Devuelve un int con la cantidad de caracteres.
- Uso tipico: saber el largo de una palabra o recorrer un string.
- Ejemplo: length("Hola") -> 4

charCount(string s, char c)
- Cuenta cuantas veces aparece el caracter c dentro de s.
- Devuelve la cantidad de ocurrencias.
- Uso tipico: contar separadores, letras repetidas, espacios, etc.
- Ejemplo: charCount("banana", 'a') -> 3

================================================================================
2) SUBCADENAS
================================================================================

substring(string s, int d, int h)
- Devuelve una parte de s desde la posicion d hasta h, sin incluir h.
- Es decir: [d, h).
- Uso tipico: cortar una palabra entre dos posiciones.
- Ejemplo: substring("Algoritmo", 0, 4) -> "Algo"

substring(string s, int d)
- Devuelve una parte de s desde la posicion d hasta el final.
- Uso tipico: quedarte con el resto de una cadena.
- Ejemplo: substring("Algoritmo", 4) -> "ritmo"

================================================================================
3) BUSQUEDAS DE POSICIONES
================================================================================

indexOf(string s, char c)
- Busca la primera aparicion del caracter c dentro de s.
- Devuelve la posicion donde aparece por primera vez.
- Si no lo encuentra, devuelve -1.
- Ejemplo: indexOf("Hola", 'l') -> 2

indexOf(string s, char c, int offset)
- Busca la primera aparicion de c, pero empezando desde offset.
- Sirve para ignorar una parte inicial de la cadena.
- Si no lo encuentra, devuelve -1.
- Ejemplo: indexOf("banana", 'a', 2) -> 3

indexOf(string s, string toSearch)
- Busca la primera aparicion de una subcadena dentro de s.
- Devuelve la posicion inicial donde aparece.
- Si no la encuentra, devuelve -1.
- Ejemplo: indexOf("curso de C++", "de") -> 6

indexOf(string s, string toSearch, int offset)
- Igual que la anterior, pero empieza a buscar desde offset.
- Sirve para buscar una palabra/frase despues de cierta posicion.
- Si no la encuentra, devuelve -1.

lastIndexOf(string s, char c)
- Busca la ultima aparicion del caracter c dentro de s.
- Devuelve la posicion de la ultima ocurrencia.
- Si no lo encuentra, devuelve -1.
- Ejemplo: lastIndexOf("banana", 'a') -> 5

indexOfN(string s, char c, int n)
- Devuelve la posicion de la n-esima aparicion del caracter c.
- n se cuenta desde 1.
- Si n es 0, devuelve -1.
- Si no existe la n-esima aparicion, devuelve s.length().
- Uso tipico: encontrar el segundo, tercer, cuarto separador, etc.
- Ejemplo: indexOfN("John|Paul|George|Ringo", '|', 2) -> 9

================================================================================
4) CONVERSIONES ENTRE CARACTERES, NUMEROS Y STRINGS
================================================================================

charToInt(char c)
- Convierte un caracter a su valor numerico segun esta tabla:
  '0'..'9'  -> 0..9
  'A'..'Z'  -> 10..35
  'a'..'z'  -> 36..61
- Si el caracter no pertenece a esos rangos, devuelve 0.
- Uso tipico: trabajar con bases numericas o codificar caracteres.
- Ejemplo: charToInt('A') -> 10

intToChar(int i)
- Es la inversa de charToInt.
- Convierte un numero entre 0 y 61 a su caracter correspondiente.
- 0..9 -> '0'..'9'
- 10..35 -> 'A'..'Z'
- 36..61 -> 'a'..'z'
- Si el numero no corresponde, devuelve '?'.
- Ejemplo: intToChar(10) -> 'A'

getDigit(int n, int i)
- Devuelve el digito ubicado en la posicion i de n.
- La posicion se cuenta desde la derecha y empieza en 0.
- Uso tipico: separar digitos de un numero.
- Ejemplo: getDigit(12345, 0) -> 5
- Ejemplo: getDigit(12345, 2) -> 3

digitCount(int n)
- Devuelve cuantos digitos tiene un numero entero.
- Sirve para saber cuantas posiciones numericas hay que recorrer.
- Ejemplo: digitCount(12345) -> 5

intToString(int i)
- Convierte un numero entero a string.
- Soporta numeros negativos.
- Uso tipico: mostrar o concatenar numeros como texto.
- Ejemplo: intToString(123) -> "123"

stringToInt(string s, int b)
- Convierte un string que representa un numero en base b a int decimal.
- Usa charToInt para interpretar cada caracter.
- Uso tipico: pasar de binario, hexadecimal u otra base a decimal.
- Ejemplo: stringToInt("10", 2) -> 2
- Ejemplo: stringToInt("12AB", 16) -> 4779

stringToInt(string s)
- Sobrecarga de stringToInt.
- Convierte un string numerico en base 10 a int.
- Ejemplo: stringToInt("12345") -> 12345

charToString(char c)
- Convierte un caracter en un string de longitud 1.
- Uso tipico: concatenar caracteres como cadenas.
- Ejemplo: charToString('A') -> "A"

stringToChar(string s)
- Devuelve el primer caracter de un string.
- Se usa pensando en strings de longitud 1.
- Ejemplo: stringToChar("A") -> 'A'

stringToString(string s)
- Devuelve exactamente el mismo string recibido.
- Es una funcion trivial, util para mantener una misma estructura de conversiones.
- Ejemplo: stringToString("Hola") -> "Hola"

doubleToString(double d, int prec)
- Convierte un double a string usando prec digitos decimales.
- No redondea de forma completa: principalmente corta/arma la parte decimal.
- Uso tipico: mostrar un numero decimal con cierta cantidad de decimales.
- Ejemplo: doubleToString(123.45678, 4) -> "123.4567"

doubleToString(double d)
- Sobrecarga de doubleToString.
- Convierte un double a string usando 3 decimales por defecto.
- Ejemplo: doubleToString(123.45678) -> "123.456"

stringToDouble(string s)
- Convierte un string con punto decimal a double.
- Asume que el string tiene un punto '.'.
- Uso tipico: transformar texto numerico decimal en numero real.
- Ejemplo: stringToDouble("123.4") -> 123.4

================================================================================
5) VALIDACIONES Y CONSULTAS SOBRE STRINGS
================================================================================

isEmpty(string s)
- Devuelve true si s es una cadena vacia "".
- Devuelve false si tiene cualquier caracter, incluso espacios.
- Ejemplo: isEmpty("") -> true
- Ejemplo: isEmpty(" ") -> false

startsWith(string s, string x)
- Devuelve true si s empieza con x.
- Uso tipico: validar prefijos.
- Ejemplo: startsWith("cursoDeAlgoritmos", "curso") -> true
- Ojo: conviene que s tenga longitud mayor o igual que x.

endsWith(string s, string x)
- Devuelve true si s termina con x.
- Uso tipico: validar sufijos o extensiones.
- Ejemplo: endsWith("archivo.txt", ".txt") -> true

contains(string s, char c)
- Devuelve true si s contiene el caracter c.
- Devuelve false si no aparece.
- Uso tipico: validar si una cadena tiene espacios, puntos, guiones, etc.
- Ejemplo: contains("abcd", 'b') -> true

================================================================================
6) MODIFICACION DE STRINGS
================================================================================

replace(string s, char oldChar, char newChar)
- Reemplaza todas las apariciones de oldChar por newChar.
- Devuelve una nueva cadena modificada.
- Ejemplo: replace("banana", 'a', 'X') -> "bXnXnX"

insertAt(string s, int pos, char c)
- Inserta el caracter c en la posicion pos.
- La cadena final tiene un caracter mas.
- Uso tipico: agregar un caracter en el medio de una cadena.
- Ejemplo: insertAt("Hla", 1, 'o') -> "Hola"

removeAt(string s, int pos)
- Elimina el caracter ubicado en la posicion pos.
- La cadena final tiene un caracter menos.
- Uso tipico: borrar un caracter especifico.
- Ejemplo: removeAt("Hooola", 2) -> "Hola"

================================================================================
7) RECORTE DE ESPACIOS
================================================================================

ltrim(string s)
- Elimina los espacios que estan al principio de la cadena.
- No elimina espacios del medio ni de la derecha.
- Ejemplo: ltrim("   Hola") -> "Hola"
- Ojo: con cadena vacia podria fallar porque accede a s[0].

rtrim(string s)
- Elimina los espacios que estan al final de la cadena.
- No elimina espacios del medio ni de la izquierda.
- Ejemplo: rtrim("Hola   ") -> "Hola"
- Ojo: con cadena vacia podria fallar porque accede a la ultima posicion.

trim(string s)
- Elimina espacios tanto al principio como al final.
- No elimina espacios internos.
- Ejemplo: trim("   Hola mundo   ") -> "Hola mundo"

================================================================================
8) REPETICION, ESPACIOS Y RELLENO
================================================================================

replicate(char c, int n)
- Genera un string formado por el caracter c repetido n veces.
- Uso tipico: crear separadores, lineas o rellenos.
- Ejemplo: replicate('X', 5) -> "XXXXX"

spaces(int n)
- Genera un string formado por n espacios.
- Es un caso particular de replicate.
- Ejemplo: spaces(5) -> "     "

lpad(string s, int n, char c)
- Agrega caracteres c a la izquierda hasta que s tenga longitud n.
- Si s ya mide n o mas, queda igual.
- Uso tipico: alinear texto o completar con ceros a la izquierda.
- Ejemplo: lpad("7", 3, '0') -> "007"

rpad(string s, int n, char c)
- Agrega caracteres c a la derecha hasta que s tenga longitud n.
- Si s ya mide n o mas, queda igual.
- Uso tipico: alinear texto en columnas.
- Ejemplo: rpad("Hola", 8, '.') -> "Hola...."

cpad(string s, int n, char c)
- Centra s dentro de una cadena de longitud n, rellenando con c a izquierda y derecha.
- Si sobran caracteres impares, agrega uno mas a la izquierda.
- Uso tipico: centrar titulos o textos.
- Ejemplo: cpad("Hola", 10, 'X') -> "XXXHolaXXX"

================================================================================
9) VALIDACIONES DE CARACTERES
================================================================================

isDigit(char c)
- Devuelve true si c es un digito entre '0' y '9'.
- Ejemplo: isDigit('9') -> true
- Ejemplo: isDigit('A') -> false

isLetter(char c)
- Devuelve true si c es una letra mayuscula o minuscula del alfabeto ingles.
- No contempla la letra enie ni caracteres con tilde.
- Ejemplo: isLetter('A') -> true
- Ejemplo: isLetter('9') -> false

isUpperCase(char c)
- Devuelve true si c es una letra mayuscula entre 'A' y 'Z'.
- Ejemplo: isUpperCase('A') -> true
- Ejemplo: isUpperCase('a') -> false

isLowerCase(char c)
- Devuelve true si c es una letra minuscula entre 'a' y 'z'.
- Ejemplo: isLowerCase('a') -> true
- Ejemplo: isLowerCase('A') -> false

================================================================================
10) CONVERSION ENTRE MAYUSCULAS Y MINUSCULAS
================================================================================

toUpperCase(char c)
- Si c es una letra minuscula, la convierte a mayuscula.
- Si no es minuscula, devuelve c sin cambios.
- Ejemplo: toUpperCase('a') -> 'A'
- Ejemplo: toUpperCase('9') -> '9'

toLowerCase(char c)
- Si c es una letra mayuscula, la convierte a minuscula.
- Si no es mayuscula, devuelve c sin cambios.
- Ejemplo: toLowerCase('A') -> 'a'
- Ejemplo: toLowerCase('9') -> '9'

toUpperCase(string s)
- Convierte todo el string a mayusculas.
- Los caracteres que no son letras quedan iguales.
- Ejemplo: toUpperCase("Hola 123") -> "HOLA 123"

toLowerCase(string s)
- Convierte todo el string a minusculas.
- Los caracteres que no son letras quedan iguales.
- Ejemplo: toLowerCase("Hola 123") -> "hola 123"

================================================================================
11) COMPARACIONES
================================================================================

cmpString(string a, string b)
- Compara dos cadenas alfabeticamente/lexicograficamente.
- Devuelve:
  -1 si a es menor que b
   0 si son iguales
   1 si a es mayor que b
- Uso tipico: ordenar palabras o comparar nombres.
- Ejemplo: cmpString("Carlos", "Pablo") -> -1

cmpDouble(double a, double b)
- Compara dos numeros double.
- Devuelve:
  -1 si a es menor que b
   0 si son iguales
   1 si a es mayor que b
- Uso tipico: ordenar o decidir entre dos valores decimales.
- Ejemplo: cmpDouble(25.7, 36.9) -> -1

================================================================================
12) CONVERSIONES ENTRE string Y C-STRING
================================================================================

stringToCString(string s)
- Convierte un string de C++ a un char* terminado en '\0'.
- Reserva memoria dinamica con new.
- Uso tipico: cuando una funcion antigua de C pide char*.
- Ojo: al usar new, despues deberia liberarse la memoria con delete[].

cStringToString(char c[])
- Convierte un arreglo de chars estilo C a string de C++.
- Uso tipico: pasar de char[] a string.
- Ejemplo: cStringToString("Hola") -> "Hola"

================================================================================
ORDEN MENTAL PARA SABER CUAL USAR
================================================================================

- Para medir: length, charCount, digitCount.
- Para cortar texto: substring.
- Para buscar posiciones: indexOf, lastIndexOf, indexOfN.
- Para preguntar si contiene o empieza/termina con algo: contains, startsWith, endsWith.
- Para convertir datos: charToInt, intToChar, intToString, stringToInt,
  doubleToString, stringToDouble, charToString, stringToChar.
- Para limpiar espacios: ltrim, rtrim, trim.
- Para modificar texto: replace, insertAt, removeAt.
- Para rellenar/alinear: replicate, spaces, lpad, rpad, cpad.
- Para validar caracteres: isDigit, isLetter, isUpperCase, isLowerCase.
- Para cambiar mayusculas/minusculas: toUpperCase, toLowerCase.
- Para comparar: cmpString, cmpDouble.
- Para compatibilidad con C: stringToCString, cStringToString.
================================================================================
*/
