#include "../biblioteca/funciones/millis.hpp"
#include "../biblioteca/funciones/files.hpp"
#include "../biblioteca/funciones/strings.hpp"
#include "../biblioteca/funciones/tokens.hpp"

#include "../biblioteca/tads/parte1/Fecha.hpp"
#include "../biblioteca/tads/parte1/Timer.hpp"
#include "../biblioteca/tads/parte1/Coll.hpp"

#include "../biblioteca/tads/parte2/Array.hpp"
#include "../biblioteca/tads/parte2/List.hpp"
#include "../biblioteca/tads/parte2/Map.hpp"
#include "../biblioteca/tads/parte2/Queue.hpp"
#include "../biblioteca/tads/parte2/Stack.hpp"

int main(){
    // En la clase de hoy vemos el trabajo practico xdddddd
    
    // 01111011
    unsigned char i = 123; // Guarda un valor de char sin signo, que tiene un tamaño de 255 bits en total
    
    // 00100111
    unsigned char j = 39;
    
    // Operadores a nivel bit

    // i = 01111011
    // j = 00100111
    // k = 00100011
    unsigned char k = i&j;

    // i = 01111011
    // j = 00100111
    // k = 01111111
    unsigned char o = i|j;


    // 01111011
    unsigned char i = 123;

    // i = 00001111
    unsigned char k = i >> 3;

    // i = 11101100
    unsigned char k = i << 2;

    // MASCARA DEL USUARIO
    // 01000110
    
    // 00100000
    // 01000000

    // Operadores a nivel bit
    
}