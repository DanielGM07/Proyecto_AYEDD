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


int main()
{
    /*
    1.5.5. Reconocer si una cadena tiene un formato determinado
    Dificultad: intermedia, Requerido: recomendable.
    El usuario ingresa una cadena con su apellido, nombre, curso y legajo. Se pide validar
    que respete exactamente el siguiente formato: Apellido(s), Nombre(s) (Curso, Legajo).
    Los apellidos pueden ser simples o compuestos y los nombres pueden incluir segundo
    nombre; ambos pueden abreviarse, pero toda abreviatura debe finalizar en punto.
    
    La coma tras el apellido y el espacio posterior son obligatorios. 
    
    El curso siempre comienza con K mayúscula seguido de 4 dígitos. 
    
    El legajo siempre consiste en 4 dígitos. 
    
    Curso y legajo se encierran entre paréntesis, separados por coma y espacio. 
    
    Las mayúsculas y minúsculas deben conservarse tal como se escriben.
    
    Algunos ejemplos válidos son:
        • Sznajdleder, Pablo (K1001, 5432)
        • Sznaj. Pablo Augusto (K1001, 5432) ESTE EJEMPLO QUE EL PROFE PUSO COMO VALIDO DEBERIA ESTAR MAL
        • Sznaj., Pablo Augusto (K1001, 5432) ESTE EJEMPLO SERIA EL CORRECTO (VALIDO)
        • Sznajdleder R., Pablo (K1001, 5432)
        • Sznajdleder R., Pablo August. (K1001, 5432)
        • Sznajdleder Rotman, Pablo (K1001, 5432)
    */
    
    return 0;    
}

bool formatoCorrecto(string s){
    
}
