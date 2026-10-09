#ifndef _MAINHPP
#define _MAINHPP
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <sstream>
#include <string>

#include <cassert>

#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/tads/parte2/Array.hpp"
#include "../../biblioteca/tads/parte2/List.hpp"

#include "../../biblioteca/funciones/millis.hpp"
#include "../../biblioteca/funciones/files.hpp"

#include "../../biblioteca/tads/parte1/Fecha.hpp"
#include "../../biblioteca/tads/parte1/Timer.hpp"
#include "../../biblioteca/tads/parte1/Coll.hpp"

#include "../../biblioteca/tads/parte2/Map.hpp"
#include "../../biblioteca/tads/parte2/Queue.hpp"
#include "../../biblioteca/tads/parte2/Stack.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;

struct Obra
{
   int idObra;
   char titulo[100];
   int fEstreno; // aaaammdd
   int idTeatro;
};

struct Teatro
{
   int idTeatro;
   char direccion[50];
   int capacidad;
   int sectores;
};

struct Funcion
{
   int idFuncion; 
   int diaSem;  // 1=>Lunes, 2=>Martes, ...
   int hora;   // hhmm
};

struct Reserva
{
   int idCliente;
   int idObra;
   int idFuncion;
   int sector; // sector de la sala; ej: Pullman,Platea...
   int cant;
};

Array<Obra> obrasSubir(){
    FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Obras_de_teatro/OBRAS.dat", "r+b");

    Array<Obra> obs = array<Obra>();
    Obra ob = read<Obra>(f);

    while (!feof(f) ){
        arrayAdd(obs, ob);
        ob = read<Obra>(f);
    }

    fclose(f);

    return obs;
}

Array<Teatro> teatrosSubir(){
    FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Obras_de_teatro/TEATROS.dat", "r+b");

    Array<Teatro> tts = array<Teatro>();
    Teatro tt = read<Teatro>(f);

    while (!feof(f) ){
        arrayAdd(tts, tt);
        tt = read<Teatro>(f);
    }

    fclose(f);

    return tts;
}

List<Funcion> funcionesProgramadas(int idObra){

}

 // Retorna la reserva de un cliente
Reserva leerReserva();

// Indica si quedan mas reservas por procesar
// Copiamos el de hospedaje en casas de familias
bool continuarOperando(){
    cout << "¿Continuar operando?" << endl;

    cout << "1 - Si" << endl;
    cout << "0 - No" << endl;

    int op;
    cin >> op;
    while(op != 0 && op != 1){
        cout << "Ingrese 1 o 0: " << endl;
        cin >> op;
    }

    return op == 1;
}

int capacidadSector(int idTeatro,int sector);

#endif