
#ifndef _AGENDAFILES_
#define _AGENDAFILES_

#include <iostream>

// Libreria para utilizar la funcion rand() y sus derivados
#include <stdlib.h>

#include "../../biblioteca/tads/parte1/BitWriter.hpp"
#include "../../biblioteca/tads/parte1/BitReader.hpp"
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/tads/parte1/Fecha.hpp"
#include "../../biblioteca/tads/parte2/Map.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::to_string;

// === ESTRUCTURA REGTYPE ===
struct RegType{
    unsigned char id;
    string desc;
};

// === FUNCION INICIALIZACION REGTYPE ===
RegType regType(){
    RegType rt;
    rt.id = 0;
    rt.desc = "";
    return rt;
}

// === ESTRUCTURA REGDATA ===
struct RegData{
    unsigned char compFs;
    Map<unsigned char, string> mapIdVal;
};

// === FUNCION INICIALIZACION REGDATA ===
RegData regData(){
    RegData rd;
    rd.compFs = 0;
    rd.mapIdVal = map<unsigned char, string>();
    return rd;
}

// === === === FUNCIONES PRINCIPALMENTE PARA AGALL === === ===
unsigned char readByte(FILE* f){
    unsigned char byte = read<unsigned char>(f);
    return byte;
}

unsigned int readInteger(FILE* f){
    unsigned char byte1 = readByte(f);
    unsigned char byte2 = readByte(f);

    // Recordar que el archivo guarda los bytes en LITTLE ENDIAN, lo que quiere decir que guarda primero los
    // bytes menos significativos y despues los mas significativos, basicamente, invierte los bytes de lugar
    // por eso lo que hacemos aca es agarrar el 2do byte que leimos, y lo movemos 8 lugares a la izquierda
    // quedandonos algo asi como XXXX XXXX - 0000 0000
    // Finalmente usamos el operador logico OR con el primer byte (menos significativo y se juntan ambos bytes)
    // byte2 | byte1 = xxxx xxxx xxxx xxxx
    unsigned int integer = (byte2 << 8) | byte1;

    return integer;
}

unsigned int readSerialNumber(FILE* f){
    return readInteger(f);
}

int readStringLength(FILE* f){
    int length = readByte(f);
    if(length == 255){
        length = readInteger(f);
    }
    return length;
}

string readString(FILE* f){
    string stringChar = "";
    int l = readStringLength(f);
    for (int i = 0; i < l; i++){
        unsigned char c = readByte(f);
        stringChar += charToString(c);
    }
    return stringChar;
}

string readFileName(FILE* f){
    return readString(f);
}

Fecha readDate(FILE* f){
    unsigned int fullDate = readInteger(f);

    // unsigned int maskDay = 31;
    // unsigned int maskMonth = 480;
    // unsigned int maskYear = 65024;

    unsigned int maskDay = 0x1F;
    unsigned int maskMonth = 0x1E0;
    unsigned int maskYear = 0xFE00;
    
    int day = fullDate & maskDay;
    int month = (fullDate & maskMonth) >> 5;
    int year = (fullDate & maskYear) >> 9;

    year = (year < 100) ? 2000 + year : (1999 - year + 100);

    Fecha date = fecha(year, month, day);

    return date;
}

Fecha readLastAccessDate(FILE* f){
    return readDate(f);
}

unsigned int readFieldCount(FILE* f){
    return readInteger(f);
}

RegType readRegType(FILE* f){
    RegType rt = regType();
    rt.id = readByte(f);
    rt.desc = readString(f);
    return rt;
}

// template<typename K, typename V>
Map<unsigned char, string> readRegTypes(FILE* f, int fieldCount){
    
    Map<unsigned char, string> rtMap = map<unsigned char, string>();
    
    for (int i = 0; i < fieldCount; i++){
        RegType rt  = readRegType(f);
        mapPut(rtMap, rt.id, rt.desc);
    }

    return rtMap;
}

unsigned int readContactCount(FILE* f){
    return readInteger(f);
}

RegData readRegData(FILE* f){
    RegData rd = regData();
    rd.compFs = readByte(f);
    for(int i = 0; i < rd.compFs; i++){
        unsigned char id = readByte(f);
        string value = readString(f);
        mapPut(rd.mapIdVal, id, value);
    }
    return rd;
}

// Leemos todos los contactos y sus datos
Array<RegData> readContacts(FILE* f, int contactCount){
    Array<RegData> rdArray = array<RegData>();
    for (int i = 0; i < contactCount; i++){
        RegData rd = readRegData(f);
        arrayAdd<RegData>(rdArray, rd);
    }
    return rdArray;
}

// === === === FIN FUNCIONES PRINCIPALMENTE PARA AGALL === === ===

// === === === FUNCIONES PRINCIPALMENTE PARA AGMK === === ===

void writeByte(FILE* f, unsigned char byte){
    write<unsigned char>(f, byte);
}

void writeInteger(FILE* f, unsigned int integer){
    unsigned char lessSigByte = integer & 0xFF;
    unsigned char mostSigByte = (integer >> 8) & 0xFF;
    writeByte(f, lessSigByte);
    writeByte(f, mostSigByte);
}

void writeSerialNumber(FILE* f, unsigned int sn){
    writeInteger(f, sn);
}

void writeCharacters(FILE* f, string str){
    for (int i = 0; i < length(str); i++){
        writeByte(f, str[i]);
    }
}

void writeStringAgenda(FILE* f, string str){
    if(length(str) < 255){
        writeByte(f, length(str));
        writeCharacters(f, str);
    }
    else{
        writeByte(f, 255);
        writeInteger(f, length(str));
        writeCharacters(f, str);
    }
}

void writeFileName(FILE* f, string fileName){
    writeStringAgenda(f, fileName);
}

Fecha getCurrentDate(){
    Fecha currDate = fecha();
    return currDate;
}

void writeDate(FILE* f, Fecha date){
    int day = fechaGetDia(date);
    int month = fechaGetMes(date);
    int year = fechaGetAnio(date);

    year = year >= 2000 ? year - 2000: 1999 - year + 100;

    unsigned int fullDate = (year << 9) | (month << 5) | day;

    writeInteger(f, fullDate);
}

unsigned int fieldCount(unsigned int argc){
    return argc - 2;
}

void writeFieldCount(FILE* f, unsigned int fieldCount){
    writeInteger(f, fieldCount);
}

void writeRegType(FILE* f, unsigned char idRt, string descRt){
    // RegType rt = regType();
    // rt.id = idRt;
    // rt.desc = descRt;
    writeByte(f, idRt);
    writeStringAgenda(f, descRt);
}

void mapRegType(Map<unsigned char, string>& mapRt, 
                unsigned char idRt,
                string descRt){
    mapPut<unsigned char, string>(mapRt, idRt, descRt);
}

void writeRegTypes(FILE* f, Map<unsigned char, string>& mapRt){
    mapReset(mapRt);
    while( mapHasNext(mapRt) ){
        unsigned char key = mapNextKey(mapRt);
        string value = *mapGet(mapRt, key);
        
        writeRegType(f, key, value);
    }
}

void writeContactCount(FILE* f, unsigned int contactCount){
    writeInteger(f, contactCount);
}


// === === === FIN FUNCIONES PRINCIPALMENTE PARA AGMK === === ===



// === === === FUNCIONES PRINCIPALMENTE PARA AGADD === === ===

// Leo todo lo anterior a la cantidad de campos configurados y lo descarto (mejor dicho, 
// no lo guardo en ningun lugar) y asi me posiciono justamente en la cant. de campos 
// configurados. Esto lo hacemos debido a que el archivo no es de una longitud fija
void moveToFieldCount(FILE* f){
    readSerialNumber(f);
    readFileName(f);
    readDate(f);
}

void moveToContactCount(FILE* f){
    // readSerialNumber(f);
    // readFileName(f);
    // readDate(f);
    moveToFieldCount(f);
    unsigned int fc = readFieldCount(f);
    readRegTypes(f, fc);
}

void writeRegData(FILE* f, RegData rd){
    writeByte(f, rd.compFs);

    mapReset(rd.mapIdVal);

    while ( mapHasNext( rd.mapIdVal )){
        unsigned char key = mapNextKey(rd.mapIdVal);
        string fieldValue = *mapGet(rd.mapIdVal, key);

        writeByte(f, key);
        writeStringAgenda(f, fieldValue);
    }
}

void incrementContactCountByOne(FILE* f){
    seek<unsigned char>(f, 0);
    moveToContactCount(f);
    int posCc = filePos<unsigned char>(f);
    unsigned int cc = readContactCount(f);
    seek<unsigned char>(f, posCc);
    writeContactCount(f, (cc + 1));
}

// === === === FIN FUNCIONES PRINCIPALMENTE PARA AGADD === === ===



// === === === FUNCIONES PRINCIPALMENTE PARA AGASK === === ===

Map<unsigned char, string> moveToCCAndReturnMapRegTypes(FILE* f){
    moveToFieldCount(f);
    unsigned int fc = readFieldCount(f);
    Map<unsigned char, string> mapRt = readRegTypes(f, fc);
    return mapRt;
}

void moveToFirstRegData(FILE* f){
    moveToContactCount(f);
    readContactCount(f);
}

Map<unsigned char, string> moveToFirstRegDataAndReturnMapRegTypes(FILE* f){
    Map<unsigned char, string> mapRt = moveToCCAndReturnMapRegTypes(f);
    readContactCount(f);
    return mapRt;
}

// void getRegDatas(FILE* f){
//     readContacts(f, 0);
// }

Map<unsigned char, string> getMapIdVal(RegData rd){
    Map<unsigned char, string> mapRet = rd.mapIdVal;
    return mapRet;
}

Map<unsigned char, string> regTypesInRegData(RegData rd, Map<unsigned char, string> mapRt){
    Map<unsigned char, string> rtsInRd = map<unsigned char, string>();
    while ( mapHasNext(rd.mapIdVal) ){

    }
}

void searchBy(FILE* f, unsigned int cc, Map<unsigned char, string> fieldAndValue){
    Map<unsigned char, string> mapRt = moveToFirstRegDataAndReturnMapRegTypes(f);
    Map<unsigned char, string> rtsInRd = map<unsigned char, string>();
    Array<RegData> rdArr = readContacts(f, cc);

    while ( arrayHasNext(rdArr) ){
        RegData rd = *arrayNext<RegData>(rdArr);
        Map<unsigned char, string> mapIdVal = rd.mapIdVal;

        // if (){
        // }
    }


}

// === === === FIN FUNCIONES PRINCIPALMENTE PARA AGASK === === ===


#endif