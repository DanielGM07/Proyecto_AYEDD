#include "../../biblioteca/funciones/millis.hpp"
#include "../../biblioteca/funciones/files.hpp"
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"

#include "../../biblioteca/tads/parte1/Fecha.hpp"
#include "../../biblioteca/tads/parte1/Timer.hpp"
#include "../../biblioteca/tads/parte1/Coll.hpp"

#include "../../biblioteca/tads/parte2/Array.hpp"
#include "../../biblioteca/tads/parte2/List.hpp"
#include "../../biblioteca/tads/parte2/Map.hpp"
#include "../../biblioteca/tads/parte2/Queue.hpp"
#include "../../biblioteca/tads/parte2/Stack.hpp"

#include "hcf_principal.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::to_string;

// Por cada búsqueda, emitir un listado (ordenado decrecientemente 
// por el porcentaje de concordancia) de todas las casas disponibles 
// cuya concordancia está por encima del valor tolerancia del registro 
// de la búsqueda. Por cada casa, se debe invocar a la función 
// mostrarCasa, que mostrará en la página Web las fotos, detalles y 
// demás datos que resultarán de interés para el usuario.

int main(){
    Array<Caract> caracts = leerCaracteristicas();
    Array<Casa> casas = subirCasas();

    bool continuar = true;
    while (continuar){
        Busqueda busq = leerBusqueda(caracts);

        Array<Casa> casasDisponibles = casasDisponiblesPorConcordancia(casas, busq);

        ordenarPorConcordancia(casasDisponibles, busq);

        mostrarListaCasas(casasDisponibles, caracts, busq);

        continuar = continuarOperando();
    }

    cout << "Programa terminado." << endl;
    return 0;
}