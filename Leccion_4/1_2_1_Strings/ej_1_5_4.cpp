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

int cantidadPersonas(string s);
string persona(string s);
void imprimirPersonas(string s);

// Anda perfecto este programa, se lo mande a chatgpt para que me lo corrija, y solo cambie una linea
// Podria aniadir un par de cosas mas como para optimizarlo un poquitito pero decidi no aniadirlo,
// ni si quiera en los comentarios

// El programa no evalua cadenas inestables (por ejemplo, una cadena que no tenga comas, o una cadena que 
// termine en | ). Estrictamente las cadenas tienen un formato en el cual ingresarse

// Ejemplo de ingreso valido
// Nombre,2-oct-1970,Nacionalidad|Nombre,9-dic-1985,Nacionalidad|Nombre,14-ene-1992,Nacionalidad

int main()
{
    // 1.5.4. Interpretar datos contenidos en una cadena
    // Dificultad: intermedia, Requerido: recomendable.
    // Se ingresa por teclado una cadena que contiene el nombre, la fecha de nacimiento y
    // la nacionalidad de varias personas. Por ejemplo:
    // "Pedro,2-oct-1970,Argentino|Juan,9-dic-1985,Chileno|Pablo,14-ene-1992,Argentino"
    // Como vemos, la cadena contiene los datos de Pedro, Juan y Pablo separados
    // mediante el carácter ‘|’ (carácter pipe). A su vez, los datos de cada uno de ellos se
    // separan entre sí mediante el carácter ‘,’ (carácter coma). Por su parte, los atributos
    // de las fechas de nacimiento están separados entre sí por el carácter ‘-‘ (guion).
    // Se pide desarrollar un programa que muestre por pantalla los datos de
    // cada persona. Por ejemplo, según el ejemplo anterior, el programa debería mostrar:
    // Cantidad de personas: 3
    // ---
    // Nombre: Pedro
    // Fecha de nacimiento: Dia 2, Mes oct, Anio 1970
    // Nacionalidad: Argentino
    // ---
    // Nombre: Juan
    // ...
    cout << "Ingrese una cadena con nombre, fecha de nacimiento y nacionalidad: " << endl;
    string cadena = "";
    cin >> cadena;
    imprimirPersonas(cadena);

    return 0;    
}

int cantidadPersonas(string s){
    return charCount(s, '|') + 1;
}

// "Pedro,2-oct-1970,Argentino|Juan,9-dic-1985,Chileno|Pablo,14-ene-1992,Argentino"
    // Nombre: Pedro
    // Fecha de nacimiento: Dia 2, Mes oct, Anio 1970
    // Nacionalidad: Argentino
string persona(string s){
    string ficha = "";
    string nombre = "", nacionalidad = "";
    string dia = "-", mes = "-", anio = "-";

    nombre = substring(s, 0, indexOfN(s, ',', 1));
    dia = substring(s, indexOfN(s, ',', 1) + 1, indexOfN(s, '-', 1));
    mes = substring(s, indexOfN(s, '-', 1) + 1, indexOfN(s, '-', 2));
    anio = substring(s, indexOfN(s, '-', 2) + 1, indexOfN(s, ',', 2));
    nacionalidad = substring(s, indexOfN(s, ',', 2) + 1);
    
    ficha = "Nombre: " + nombre + "\n" +
            "Fecha de Nacimiento: Dia: " + dia + ", Mes: " + mes + ", Anio: " + anio + "\n" +
            "Nacionalidad: " + nacionalidad;
    
    return ficha;
}

void imprimirPersonas(string s){
    int cFinSs = '|';
    int posInicial = 0;
    cout << "Cantidad de personas: " << cantidadPersonas(s) << endl << endl;
    for(int i = 1; i <= cantidadPersonas(s); i++){
        int posCFinal = indexOfN(s, cFinSs, i);

        if(i == cantidadPersonas(s)){
            // Segun chat gpt, este codigo de abajo es inestanble e impredecible
            // cFinSs = '\0';
            // posCFinal = indexOfN(s, cFinSs, 1);
            
            // Si estamos parados en la ultima persona de la cadena, entonces, la posicion final 
            // va a ser la ultima posicion de la cadena, es decir, el largo de la cadena
            posCFinal = length(s);
        }

        string ss = substring(s, posInicial, posCFinal);
        posInicial = posCFinal + 1;

        cout << "===============" << endl;
        cout << persona(ss) << endl;
        cout << "===============\n" << endl;
    }
}