
#ifndef _BITREADER_
#define _BITREADER_

#include <iostream>
#include "../../funciones/files.hpp"
#include "../../funciones/strings.hpp"

using std::string;

struct BitReader
{
    FILE* f;
    // string buff;
    string* buff;
};

// inicializa el TAD
BitReader bitReader(FILE* f)
{
    BitReader br;
    br.buff = new string;
    br.f = f;
    return br;
}

string _binToString(unsigned char c)
{
    // THIS IS BULLSHHHHHHHHHHHIT
    // string b = intToString(stringToInt(charToString(c), 2));
    // string b8 = lpad(b, 8, '0');
    string b8 = "";
    unsigned char mask = 128;
    for (int i = 0; i < 8; i++){
        if( (mask&c) != 0){
            b8 = b8 + "1";
        }else{
            b8 = b8 + "0";
        }
        mask = mask>>1;
    }
    return b8;
}

// lee el siguiente bit desde el archivo encapsulado por el TAD
// int bitReaderRead(BitReader& br)
// {
//     if(length(br.buff) == 0){
//         unsigned char c = read<unsigned char>(br.f);
//         br.buff = _binToString(c);
//     }
//     int bit = charToInt(br.buff[0]);
//     br.buff = removeAt(br.buff, 0);
//     return bit;
// }

int bitReaderRead(BitReader br)
{
    if(length(*br.buff) == 0){
        unsigned char c = read<unsigned char>(br.f);
        *br.buff = _binToString(c);
    }
    int bit = charToInt((*br.buff)[0]);
    *br.buff = removeAt(*br.buff, 0);
    return bit;
}

#endif
