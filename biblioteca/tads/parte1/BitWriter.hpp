
#ifndef _BITWRITER_
#define _BITWRITER_

#include <iostream>
#include "../../funciones/files.hpp"
#include "../../funciones/strings.hpp"

using std::string;

struct BitWriter
{
    string buff;
    FILE* f;
};

// inicializa el TAD
BitWriter bitWriter(FILE* f)
{
    BitWriter bw;
    bw.buff = "";
    bw.f = f;
    return bw;
}

// graba el bit en el archivo encapsulado por el TAD
void bitWriterWrite(BitWriter& bw,int bit)
{
    bw.buff = bw.buff + intToString(bit);
    if(length(bw.buff) == 8){
        unsigned char n = stringToInt(bw.buff, 2);
        write(bw.f, n);
        bw.buff = "";
    }
    // bw.buff += intToString(bit);
}

// graba cada uno de los bit contenidos en la cadena bits,
// la cual solo contiene 1s y 0s. Ej.: "1100111001111"
void bitWriterWrite(BitWriter& bw,string bits)
{
    // bw.buff = bw.buff + bits;
    for(int i = 0; i < length(bits); i++){
        bitWriterWrite(bw, charToInt(bits[i]) );
    }
}

// indica que no habra mas bits y se deben grabar los que estan en el buffer
int bitWriterFlush(BitWriter bw)
{
    int ceros = 0;
    while( (length(bw.buff) % 8) != 0){
        bitWriterWrite(bw, 0);
        // bw.buff += "0";
        ceros++;
    }
    return ceros;
}

#endif
