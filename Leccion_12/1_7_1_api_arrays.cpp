#include <iostream>
#include <string>

#include "../biblioteca/funciones/millis.hpp"
#include "../biblioteca/funciones/files.hpp"
#include "../biblioteca/funciones/strings.hpp"
#include "../biblioteca/funciones/tokens.hpp"
#include "../biblioteca/tads/intro/Fraccion.hpp"
#include "../biblioteca/tads/parte1/Fecha.hpp"
#include "../biblioteca/tads/parte1/Timer.hpp"
#include "../biblioteca/tads/parte1/Coll.hpp"
#include "../biblioteca/tads/parte2/Array.hpp"
#include "../biblioteca/tads/parte2/List.hpp"
#include "../biblioteca/tads/parte2/Map.hpp"
#include "../biblioteca/tads/parte2/Queue.hpp"
#include "../biblioteca/tads/parte2/Stack.hpp"
#include "../principal.hpp"

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
    int len = 0;
    // Tener siempre MUCHO CUIDADO con el tamaño del array, ya que, 
    // este no se puede modificar. Ademas, si mas adelante tenemos pensado
    // insertar o añadir mas valores, hay que tener en cuenta que 
    // este puede desbordarse y empezar a dar resultados inesperados
    // Ejemplo: en un inicio pusimos que sea un array de 10 espacios (arr[10])
    // y llenamos todos esos espacios con valores, si despues hacemos un insert,
    // va a saltar todo a la mierda. Me acaba de pasar xd jajajaja
    int arr[11];

    for (int i = 0; i <= 9; i++){
        int pos = add(arr, len, (i+1)*2);
        cout << "Pos actual: " << pos << "\n";
    }

    cout << "\n";

    for (int i = 0; i < len; i++){
        cout << i << ". " << arr[i] << "\n";
    }

    cout << "\n";

    cout << len << endl;

    insert(arr, len, 5, 2);

    cout << len << endl;

    for (int i = 0; i < len; i++){
        cout << i << ". " << arr[i] << "\n";
    }

    while (len > 0){
        int removed = remove(arr, len, 0);
        cout << "Removed " << removed << "\n";
    }

    return 0;
}
