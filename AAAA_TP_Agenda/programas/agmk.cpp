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

#include <stdlib.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::to_string;

// agmk (agenda-make)
// Este programa permite crear una agenda definiendo los campos que el usuario desee establecer.

// En el siguiente ejemplo se muestra cómo utilizar el comando para generar el archivo AGENDA.dat, preparado para registrar por cada contacto los campos Nombre, Celular, Email e Instagram.

/*
    C:\> agmk.exe AGENDA.dat Nombre Celular Email Instagram
*/

// Como se observa, el programa recibe en la línea de comandos el nombre del archivo a crear y, a continuación, la lista de campos que la agenda deberá soportar.

int main(int argc, char** argv){
    // RUTA HARDCODEADA, PUEDE SER O MUY UTIL O CONTRAPRODUCENTE SI USAMOS EL PROGRAMA EN OTRA COMPU. DESCARTADO
    // string path = "C:/vscode/Workspace/Proyecto_AYEDD/AAAA_TP_Agenda/agendas/" + stringToString(argv[1]);
    // // path += argv[1];
    // FILE* f = fopen(path.c_str(), "w+b");

    // COMENTARIO DE CHAT GPT EXPLICANDO COMO FUNCIONA SRAND
    // Inicializa la semilla del generador pseudoaleatorio usando el instante actual.
    // rand() no genera números realmente aleatorios: genera una secuencia calculada a partir de una semilla.
    // Si no se cambia esa semilla, cada ejecución del programa puede producir la misma secuencia de valores.
    // Al usar currTimeMillis(), la semilla cambia según el momento en que se ejecuta el programa, haciendo que
    // la secuencia generada por rand() sea distinta entre ejecuciones. Esto NO garantiza que un número nunca se repita;
    // solamente evita comenzar siempre desde la misma secuencia pseudoaleatoria.
    // FIN COMENTARIO DE CHA GIPITI
    srand((unsigned int)currTimeMillis());

    // if(argv[1] == NULL){
    if(argc < 2){
        cout << "Uso: agmk.exe <archivo a crear> [campo 1] [campo 2] ... [campo n]" << endl;
        return 0;
    }
    
    if(!endsWith(argv[1], ".dat")){
        cout << "El archivo debe ser .dat" << endl;
        return 0;
    }

    FILE* f = fopen(argv[1], "w+b");

    if(f == NULL){
        cout << "No se pudo crear el archivo." << endl;
        return 0;
    }

    if(fieldCount(argc) > 255){
        cout << "La agenda no puede tener mas de 255 campos." << endl;
        return 0;
    }

    unsigned int sn = chooseSerialNumber();
    writeSerialNumber(f, sn);

    string fn = argv[1];
    writeFileName(f, fn);

    Fecha currDate = getCurrentDate();
    writeDate(f, currDate);

    unsigned int fCount = fieldCount(argc);
    writeFieldCount(f, fCount);

    Map<unsigned char, string> mapRt = map<unsigned char, string>();
    for(int i = 1; i <= fCount; i++){
        mapRegType(mapRt, i, argv[i+1]);
    }
    writeRegTypes(f, mapRt);

    writeContactCount(f, 0);

    fclose(f);

    return 0;
}