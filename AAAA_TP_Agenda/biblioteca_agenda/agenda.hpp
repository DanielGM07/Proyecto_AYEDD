
#ifndef _AGENDA_
#define _AGENDA_

#include <iostream>

#include "agendaFile.hpp"

#include <stdlib.h>

#include "../../biblioteca/tads/parte1/BitWriter.hpp"
#include "../../biblioteca/tads/parte1/BitReader.hpp"
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/tads/parte1/Fecha.hpp"
#include "../../biblioteca/tads/parte2/Map.hpp"

// AGENDA ALL
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

const unsigned int MAX_SERIAL_NUMBER = 65535;

string serialNumberToString(unsigned int serialNumber){
    string snString = "Nro. de serie: " + intToString(serialNumber);
    return snString;
}

string fileNameToString(string fileName){
    string fnString = "Full filename: " + fileName;

    return fnString;
}

string lastAccessDateToString(Fecha date){
    // string laString = "Fecha de ultimo acceso: " + 
    //                     intToString(fechaGetDia(date)) + "/" + 
    //                     intToString(fechaGetMes(date)) + "/" + 
    //                     intToString(fechaGetAnio(date)); 

    string laString = "Fecha de ultimo acceso: " + 
                        intToString(fechaGetAnio(date)) + "/" + 
                        intToString(fechaGetMes(date)) + "/" + 
                        intToString(fechaGetDia(date)); 
    return laString;
}

string fieldCountToString(unsigned int fieldCount){
    string fcString = "Cantidad de campos configurados: " + intToString(fieldCount);
    return fcString;
}

// Campo [codigo: 1, descripcion: Nombre]
// Campo [codigo: 2, descripcion: Celular]
// Campo [codigo: 3, descripcion: Email]
// Campo [codigo: 4, descripcion: Instagram]

string rtMapToString(Map<unsigned char, string> rtMap){
    string rtMapString = "";
    string idString = "";
    string descString = "";
    mapReset(rtMap);
    // for(int i = 0; i < mapSize(rtMap); i++){
    while (mapHasNext(rtMap)){
        unsigned char id = mapNextKey(rtMap);
        // idString = intToString((int)mapNextKey(rtMap));
        idString = intToString((int)id);
        // descString = *mapNextValue(rtMap);
        descString = *mapGet(rtMap, id);
        rtMapString += "Campo [codigo: " + idString + ", descripcion: " + descString + "]\n";
    }
    return rtMapString;
}

string contactCountToString(unsigned int contactCount){
    string ccString = "Cantidad de Registros (contactos): " + intToString(contactCount);
    return ccString;
}

string arrContactsToString(Array<RegData> rdArray, Map<unsigned char, string> rtMap){
    arrayReset(rdArray);
    // mapReset(rtMap);
    string contactData = "";

    while( arrayHasNext(rdArray) ){
        RegData rd = *arrayNext(rdArray);
        mapReset(rd.mapIdVal);
        contactData += "------------------------------\n";
        // for (int i = 0; i < rd.compFs; i++){
        while ( mapHasNext(rd.mapIdVal) ){
            unsigned char idActual = mapNextKey(rd.mapIdVal);

            // string valueActual = *mapNextValue(rd.mapIdVal);
            string valueActual = *mapGet<unsigned char, string>(rd.mapIdVal, idActual);

            string idDesc = *mapGet<unsigned char, string>(rtMap, idActual);

            contactData += idDesc + ": " + valueActual + "\n";
            // cout << idDesc << ": " << valueActual << endl; 

        }
    }
    return contactData;
}

unsigned int generateSerialNumber(){
    string randStr = randomString(5, '0', '9');
    return stringToInt(randStr);
}

unsigned int chooseSerialNumber(){
    unsigned int sn = generateSerialNumber();
    while(sn > MAX_SERIAL_NUMBER){
        sn = generateSerialNumber();
    }
    return sn;
}

void buildRegData(Map<unsigned char, string>& mapRt, RegData& rd){
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
            mapPut<unsigned char, string>(rd.mapIdVal, key, fieldValue);
            rd.compFs++;
        }
    }
}

string arrFilteredContactsToString(Array<RegData> rdArray, Map<unsigned char, string> rtMap){
    string rds = arrContactsToString(rdArray, rtMap);
    rds += "------------------------------\n";
    rds += "Se encontraron " + intToString(arraySize(rdArray)) + " contactos";
    return rds;
}

#endif