#include <iostream>
#include <string>

#include "../../biblioteca/funciones/millis.hpp"
#include "../../biblioteca/funciones/files.hpp"
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/tads/intro/Fraccion.hpp"
#include "../../biblioteca/tads/parte1/Fecha.hpp"
#include "../../biblioteca/tads/parte1/Timer.hpp"
#include "../../biblioteca/tads/parte1/Coll.hpp"
#include "../../biblioteca/tads/parte2/Array.hpp"
#include "../../biblioteca/tads/parte2/List.hpp"
#include "../../biblioteca/tads/parte2/Map.hpp"
#include "../../biblioteca/tads/parte2/Queue.hpp"
#include "../../biblioteca/tads/parte2/Stack.hpp"
#include "../../principal.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::to_string;

int sumaCaracteres(string abc, string cadena);

int sumaDigitos(int numerin);

int main()
{
    // 1.5.1. Valor numérico asociado a una cadena
    // Dificultad: moderada, Requerido: Indispensable.
    // Se ingresa por teclado una cadena de caracteres, sin espacios en blanco y totalmente
    // en mayúscula. Considerando que cada uno de sus caracteres tiene un valor numé-
    // rico según la siguiente lista: A=1, B=2, C=3, D=4, ...M=13, N=14, Ñ=15, O=16, ...
    // así hasta llegar a Z=27, se debe obtener la suma de los valores asignados a cada
    // uno de los caracteres de la cadena ingresada. Si la suma obtenida tiene más de un
    // dígito, habrá que sumar sus dígitos. Así sucesivamente hasta obtener un valor
    // numérico de un único dígito.
    // Por ejemplo: Σ OCTAVIANO = 104. Como este valor tiene más de un dígito
    // sumamos sus dígitos: 1 + 0 + 4 = 5. Dado que 5 es un número de un único dígito,
    // llegamos al resultado final. De otro modo, hubiéramos tenido que sumar sus dígitos
    // una y otra vez hasta obtener un valor de un solo dígito.
    // NOTA: La cadena ingresada no tendrá caracteres especiales como Ñ o tildes.

    // string abc1 = "ABCDEFGHIJKLMN";
    // string abc2 = "OPQRSTUVWXYZ";
    string abc = "ABCDEFGHIJKLMN-OPQRSTUVWXYZ";

    string cadenaIngresada = "";
    while(true){
        cout << "Ingrese una cadena en mayusculas y sin espacio" << endl;
        cin >> cadenaIngresada;
    
        int valorInicialCadena = sumaCaracteres(abc, cadenaIngresada);
        int valorFinalCadena = sumaDigitos(valorInicialCadena);
    
        cout << "VALOR INCIAL CADENA: " << valorInicialCadena << endl;
        cout << "\n";
        cout << "VALOR FINAL CADENA: " << valorFinalCadena << endl;
        cout << "\n";
    }

    return 0;    
}

int sumaCaracteres(string abc, string cadena){
    int valorActual = 0;
    int sumTotal = 0;
    for(int i = 0; i < length(cadena); i++){
        cadena[i] = toUpperCase(cadena[i]);
        valorActual = (indexOf(abc, cadena[i]) + 1);
        sumTotal += valorActual;
    }
    return sumTotal;
}

int sumaDigitos(int numerin){
    int sumaDigitos = numerin;
    int digitos = digitCount(numerin);
    bool digitosMayor1 = (digitCount(numerin) > 1);
    while(digitosMayor1){
        sumaDigitos = 0;
        for (int i = 0; i < digitos; i++){
            sumaDigitos += getDigit(numerin, i);
        }
        digitos = digitCount(numerin);
        digitosMayor1 = (digitCount(sumaDigitos) > 1);
        if(digitosMayor1){
            numerin = sumaDigitos;
            sumaDigitos = 0;
        }
    }
    return sumaDigitos;
}

// Esta funcion me la penso la IA, yo hice la anterior que es mucho mas choclo (aunque funciona perfecto)
// sin embargo, logre entender como funciona esta funcion, que es lo importante.
int otraSumaDigitos(int numerin){
    while(digitCount(numerin) > 1){
        int suma = 0;
        int digitos = digitCount(numerin);

        for(int i = 0; i < digitos; i++){
            suma += getDigit(numerin, i);
        }

        numerin = suma;
    }

    return numerin;
}