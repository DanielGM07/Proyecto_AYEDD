#ifndef _MAINHPP
#define _MAINHPP
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <sstream>
#include <string>

#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/tads/parte2/Array.hpp"
#include "../../biblioteca/tads/parte2/List.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;

struct Categoria
{
    int idCat;
    char descrip[50];
    int m3Desde;  // mts cubicos anuales
    int m3Hasta;  // mts cubicos anuales
    double valorM3;
};

struct RCategoria
{
    Categoria c;
    List<int> clientes;
};

struct Cliente
{
    int idCli;  // ordenado
    char nombre[100];
    char direccion[200];
    int idCatAnt;
    int lecturaAnterior;
    char consumos[36];
};

struct Medicion
{
    int idCli;
    int lecturaActual;
    int fecha;  // aaaammdd
};

struct Consumo
{
    int m3Consumidos;
    int fecha;  // aaaammdd
};

int buscarCliente(int idCli, FILE* fCli)
{
    return 0;
}

int calcularConsumoAnual(int consumoActual, Array<Consumo>& consumos)
{
    return 0;
}

Array<Consumo> decodeConsumo(char consumos[])
{
    return {};
}

char* encodeConsumo(Array<Consumo> arr)
{
    return NULL;
}

#endif