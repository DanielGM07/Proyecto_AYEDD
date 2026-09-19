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

    if(argc < 2){
        cout << "Uso: agadd.exe \nIngrese los datos del contacto \n<campo 1> \n<campo 2> \n... \n<campo n>" << endl;
        return 0;
    }
    
    FILE* f = fopen(argv[1], "r+b");

    if(f == NULL){
        cout << "La ruta es incorrecta o el archivo no existe." << endl;
        return 0;
    }
    
    cout << "Ingrese los datos del contacto" << endl;

    moveToFieldCount(f);

    unsigned int fc = readFieldCount(f);

    Map<unsigned char, string> mapRt = readRegTypes(f, fc);

    int posCc = filePos<unsigned char>(f);

    unsigned int cc = readContactCount(f);

    int fullFields = 0;

    Map<unsigned char, string> mapRdIdVal = map<unsigned char, string>();

    mapReset(mapRt);
    while( mapHasNext(mapRt) ){

        unsigned char key = mapNextKey(mapRt);
        string fieldDesc = *mapGet(mapRt, key);

        cout << fieldDesc << ": ";
        string fieldValue = "";
        // cin >> fieldValue;
        
        getline(cin, fieldValue);

        fieldValue = trim(fieldValue);
        if( fieldValue != "" ){
            mapPut<unsigned char, string>(mapRdIdVal, key, fieldValue);
            fullFields++;
        }
        cout << endl;
    }
    RegData rd = regData();
    rd.compFs = fullFields;
    rd.mapIdVal = mapRdIdVal;

    fseek(f, 0, SEEK_END);

    writeRegData(f, rd);

    seek<unsigned char>(f, posCc);
    
    writeContactCount(f, (cc + 1));
    
    cout << "El contacto fue registrado exitosamente. " << endl;
    
    fclose(f);

    return 0;
}