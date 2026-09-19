#include "../../biblioteca/funciones/millis.hpp"
#include "../../biblioteca/funciones/files.hpp"
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/funciones/arrays.hpp"
#include "../../biblioteca/funciones/lists.hpp"
#include "../../biblioteca/tads/intro/Fraccion.hpp"
#include "../../biblioteca/tads/parte1/Fecha.hpp"
#include "../../biblioteca/tads/parte1/Timer.hpp"
#include "../../biblioteca/tads/parte1/Coll.hpp"
#include "../../biblioteca/tads/parte2/Array.hpp"
#include "../../biblioteca/tads/parte2/List.hpp"
#include "../../biblioteca/tads/parte2/Map.hpp"
#include "../../biblioteca/tads/parte2/Queue.hpp"
#include "../../biblioteca/tads/parte2/Stack.hpp"
#include "../../biblioteca/tads/parte1/BitWriter.hpp"
#include "../../biblioteca/tads/parte1/BitReader.hpp"

#include "../biblioteca_agenda/agenda.hpp"
#include "../biblioteca_agenda/agendaFile.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::to_string;

int main(int argc, char** argv){
    
    // agask (agenda-ask)
    // Este programa permite buscar contactos que coincidan con un valor determinado dentro de alguno de sus campos.

    // En el siguiente ejemplo se realiza una búsqueda de los contactos que contienen la cadena "Pablo" en el campo Nombre.

    /*
    C:\> agask.exe AGENDA.dat nombre Pablo 
    Nombre: Juan Pablo
    Celular: 1133234464
    email: juanpa@gmail.com
    ig: @Juanpa34 

    Nombre: Pablo Sz
    Celular: 1144192312
    email: pablosz@gmail.com
    ig: @pabloszn 

    Se encontraron 2 contactos
    */

    if( argc < 2 ){
        cout << "Uso: agadd.exe \nIngrese los datos del contacto \n<campo 1> \n<campo 2> \n... \n<campo n>" << endl;
        return 0;
    }

    FILE* f = fopen(argv[1], "r+b");
    
    if(f == NULL){
        cout << "La ruta es incorrecta o el archivo no existe." << endl;
        return 0;
    }

    // cout << ""



    fclose(f);
}