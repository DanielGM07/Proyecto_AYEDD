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


struct Caract
{
   int idCaract; 
   char descr[100];
};

struct Casa
{
   int idCasa;
   char direcc[50];
   int idDueno;
   int caractMask;
   int idUsr;
};

struct Busqueda
{
   int idUsr;
   int caractMask;
   int dias;
   double tolerancia;
};

Array<Caract> leerCaracteristicas(){
    FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Hospedaje_en_casas_de_familia/CARACTERISTICAS.dat", "r+b");
    assert(f != NULL && "El archivo no existe o la ruta esta mal especificada.");
    Array<Caract> arrCar = array<Caract>();

    Caract c = read<Caract>(f);

    while ( !feof(f) ){
        arrayAdd(arrCar, c);

        c = read<Caract>(f);
    }

    fclose(f);

    return arrCar;
}

void mostrarCaracteristicas(Array<Caract>& crs){    
    arrayReset(crs);
    while( arrayHasNext(crs) ){
        Caract* c = arrayNext(crs);
        cout << c->idCaract << ". " << c->descr << endl;
    }
}

// Retorna un registro con los parametros de busqueda indicados por el usuario
Busqueda leerBusqueda(Array<Caract> crs){
    Busqueda busq;
    cout << "Ingrese id usuario: " << endl;
    cin >> busq.idUsr;

    cout << "CARACTERISTICAS DISPONIBLES" << endl;
    mostrarCaracteristicas(crs);
    cout << "\nIngrese la suma de las caracteristicas deseadas.\nEjemplo: 6 = Aire acondicionado + Parrilla." << endl;
    
    cout << "\nIngrese mascara de caracteristicas: " << endl;
    cin >> busq.caractMask;
    while(busq.caractMask == 0){
        cout << "Seleccione al menos una caracteristica: " << endl;
        cin >> busq.caractMask;
    }

    cout << "\nIngrese dias de estadia: " << endl;
    cin >> busq.dias;
    while(busq.dias <= 0){
        cout << "\nLos dias de estadia deben ser positivos: " << endl;
        cin >> busq.dias;
    }

    cout << "\nIngrese tolerancia (0.00 - 1.00): " << endl;
    cin >> busq.tolerancia;
    while(busq.tolerancia < 0.00 || busq.tolerancia > 1.00){
        cout << "\nLa tolerancia debe estar entre 0.00 y 1.00: " << endl;
        cin >> busq.tolerancia;
    }

    return busq;
} 

// Indica si quedan mas busquedas por procesar
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

Array<Casa> subirCasas(){
    FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Hospedaje_en_casas_de_familia/CASAS.dat", "r+b");
    assert(f != NULL && "El archivo no existe o la ruta esta mal especificada.");

    Casa c = read<Casa>(f);
    Array<Casa> cs = array<Casa>();

    while ( !feof(f) ){
        arrayAdd(cs, c);
        c = read<Casa>(f);
    }

    fclose(f);

    return cs;
}

int cmpIdCasa(Casa c, int id){
    return c.idCasa - id;
}

Casa buscarCasa(int idCasa, Array<Casa> cs){
    int pos = arrayFind(cs, idCasa, cmpIdCasa);
    assert(pos >= 0 && "No se encontro la casa.");
    return cs.arr[pos];
}

bool casaDisponible(Casa c){
    return c.idUsr == 0;
}

string disponibilidadToString(Casa c){
    return casaDisponible(c) ? "Disponible" : "Ocupado";
}

Array<Caract> maskCasaToCaracts(Array<Caract> crs, int maskCasa){
    
    Array<Caract> crsCasa = array<Caract>();
    arrayReset(crs);

    while ( arrayHasNext(crs) ){
        Caract* cr = arrayNext(crs);
        if((cr->idCaract & maskCasa) != 0){
            arrayAdd(crsCasa, *cr);
        }
    }

    return crsCasa;
}

int bitsEncendidos(int bits){
    int bitsEnc = 0;
    for (int i = 0; i < 32; i++){
        unsigned int mask = 1u << i;
        if( (mask & bits) != 0){
            bitsEnc++;
        }
    }
    return bitsEnc;
}

int maskBusqEnCasaMask(int mask, int casaMask){
    return mask & casaMask;
}

// La función concordancia compara las características de una casa
// con las carácterísticas que desea el potencial inquilino, y retorna 
// un porcentaje de coincidencia; siendo 1 el 100%, 0,8 el 80%, etcétera.
double concordancia(int idCasa, int mask, Casa c){
    // Casa c = buscarCasa(idCasa, cs);
    assert(mask != 0 && "La mascara de busqueda no puede ser cero.");

    int busquedaMask = bitsEncendidos(mask);
    int coincidencias = bitsEncendidos(maskBusqEnCasaMask(mask, c.caractMask));

    return (double)coincidencias / (double)busquedaMask;
}

// Muestra por pantalla la casa especificada
void mostrarCasa(int idCasa, Array<Casa> cs, Array<Caract> crs, Busqueda busq){
    Casa c = buscarCasa(idCasa, cs);
    Array<Caract> crsCasa = maskCasaToCaracts(crs, c.caractMask);

    cout << "===== Casa #" << c.idCasa << " =====" << endl;
    cout << "Concordancia: " << concordancia(c.idCasa, busq.caractMask, c)*100 << "% " << endl;
    cout << "ID Casa: " << c.idCasa << endl;
    cout << "Direccion: " << c.direcc << endl;
    cout << "Estado: " << disponibilidadToString(c) << endl;
    cout << endl;
    mostrarCaracteristicas(crsCasa);
}

// Por cada búsqueda, emitir un listado (ordenado decrecientemente 
// por el porcentaje de concordancia) de todas las casas disponibles 
// cuya concordancia está por encima del valor tolerancia del registro 
// de la búsqueda. Por cada casa, se debe invocar a la función 
// mostrarCasa, que mostrará en la página Web las fotos, detalles y 
// demás datos que resultarán de interés para el usuario.
Array<Casa> casasDisponiblesPorConcordancia(Array<Casa> cs, Busqueda busq){
    arrayReset(cs);
    Array<Casa> csDisp = array<Casa>();

    while( arrayHasNext(cs) ){
        Casa* c = arrayNext<Casa>(cs);

        if( concordancia(c->idCasa, busq.caractMask, *c) >  busq.tolerancia && casaDisponible(*c)){
            arrayAdd<Casa>(csDisp, *c);
        }
    }

    return csDisp;
}

int cmpConcord(double concA, double concB){
    return concB > concA ? 1 : 
           concB < concA ? -1 : 
           0;
}

void ordenarPorConcordancia(Array<Casa>& cs, Busqueda busq){
    for (int i = 0; i < arraySize(cs); i++){
        bool sorted = true;

        for (int j = 0; j < arraySize(cs) - 1; j++){
            Casa c1 = cs.arr[j];
            Casa c2 = cs.arr[j+1];

            double concC1 = concordancia(c1.idCasa, busq.caractMask, c1);
            double concC2 = concordancia(c2.idCasa, busq.caractMask, c2);

            if(cmpConcord(concC1, concC2) > 0){
                cs.arr[j] = c2;
                cs.arr[j+1] = c1;
                sorted = false;
            }
        }

        if(sorted) return;
    }
}

void mostrarListaCasas(Array<Casa> cs, Array<Caract> crs, Busqueda busq){
    arrayReset(cs);
    while( arrayHasNext(cs) ){
        Casa* c = arrayNext(cs);

        cout << "======================================" << endl;
        mostrarCasa(c->idCasa, cs, crs, busq);
        cout << "======================================" << endl;
        cout << endl;
    }
}

#endif