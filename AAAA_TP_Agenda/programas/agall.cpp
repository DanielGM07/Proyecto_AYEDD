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

// agall (agenda-all)
// Este programa muestra los datos de todos los contactos registrados en la agenda.
//
// C:\>agall.exe AGENDA.dat
//
// ----[AGENDA.dat]----
// Nro. de serie: 54321
// Full filename: C:/algoritmos/DEMO.dat
// Fecha de ultimo acceso: 2026/9/2
// Cantidad de campos configurados: 4
// Campo [codigo: 1, descripcion: Nombre]
// Campo [codigo: 2, descripcion: Celular]
// Campo [codigo: 3, descripcion: Email]
// Campo [codigo: 4, descripcion: Instagram]
// Cantidad de Registros (contactos): 3
// -----------------------
// Nombre: Bill Gates
// Celular: 1145322411
// Email: bill@microsoft.com
// Instagram: @billgms
// -----------------------
// Nombre: Jeff Bezos
// Celular: 1155342331
// Email: jeff@amazon.com
// -----------------------
// Nombre: Larry Ellison
// Email: larry@oracle.com
// ----[FIN CONTENIDO DEL ARCHIVO]----

int main(int argc, char** argv){
    // FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AAAA_TP_Agenda/agendas/AGENDA-TEST.dat", "r+b");

    // unsigned int serialNumber = readSerialNumber(f);

    // cout << "Numero de serie " << serialNumber << endl;

    // fclose(f);
    // if(argv[1] == NULL){
    //     argv[1] = (char*)"DEFAULT";
    // }

    if(argc < 2){
        cout << "Uso: agall.exe <nombre archivo>" << endl;
        return 0;
    }

    cout << "--------[" << argv[1] << "]--------" << endl;
    
    // FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AAAA_TP_Agenda/agendas/AGENDA-TEST.dat", "r+b");

    FILE* f = fopen(argv[1], "r+b");

    if(f == NULL){
        cout << "La ruta es incorrecta o el archivo no existe." << endl;
        return 0;
    }

    unsigned int sn = readSerialNumber(f);
    string snStr = serialNumberToString(sn);

    string fn = readFileName(f);
    string fnStr = fileNameToString(fn);
    
    Fecha date = readDate(f);
    string dateStr = lastAccessDateToString(date);

    unsigned int fc = readFieldCount(f);
    string fcStr = fieldCountToString(fc);

    Map<unsigned char, string> rtMap = readRegTypes(f, fc);
    string rtMapStr = rtMapToString(rtMap);

    unsigned int cc = readContactCount(f);
    string ccStr = contactCountToString(cc);
    
    Array<RegData> contactsArr = readContacts(f, cc);
    string cArrStr = arrContactsToString(contactsArr, rtMap);


    cout << snStr << endl;
    cout << fnStr << endl;
    cout << dateStr << endl;
    cout << fcStr << endl;
    cout << rtMapStr;
    cout << ccStr << endl;
    cout << cArrStr;

    cout << "----[FIN CONTENIDO DEL ARCHIVO]----" << endl;

    fclose(f);

    return 0;
}