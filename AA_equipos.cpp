
#include <iostream>
#include "biblioteca/funciones/millis.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/parte1/Fecha.hpp"
#include "biblioteca/tads/parte1/Timer.hpp"
#include "biblioteca/tads/parte1/Coll.hpp"
#include "biblioteca/tads/parte2/Array.hpp"
#include "biblioteca/tads/parte2/List.hpp"
#include "biblioteca/tads/parte2/Map.hpp"
#include "biblioteca/tads/parte2/Queue.hpp"
#include "biblioteca/tads/parte2/Stack.hpp"

#include "AA_equipos.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;

// 1. Informar la tabla de posiciones actualizada al día del proceso.
// 2. Informar, para cada estadio, cuántos partidos se jugaron y cuántos de estos partidos resultaron empatados.
// 3. Actualizar las puntuaciones en el archivo EQUIPOS.dat.

int cmpREquipoPuntos(REquipo a, REquipo b){
    return (b.e.puntos + b.acum) - (a.e.puntos + a.acum);
}

int cmpREquipoId(REquipo re, int id)
{
    return re.e.idEq - id;
}

int cmpREstadioEstadio(REstadio rest, string est){
    return cmpString(rest.est, est);
}

void sumarPuntosEquipo(Coll<REquipo>& cEq, int idEq, int puntos)
{
    int pos = collFind<REquipo,int>(
        cEq,
        idEq,
        cmpREquipoId,
        rEquipoFromString
    );

    if( pos >= 0 )
    {
        REquipo re = collGetAt<REquipo>(
            cEq,
            pos,
            rEquipoFromString
        );

        re.acum += puntos;

        collSetAt<REquipo>(
            cEq,
            re,
            pos,
            rEquipoToString
        );
    }
}

// Punto 3
// Coll<REquipo> equiposSubir()
// {
//     // abro EQUIPOS.dat
//     // creo una Coll<REquipo> vacia
//     // lo recorro del primero al ultimo
//     // le agrego REquipos a la coll vacia
//     // cierro el archivo
//     // retorno la coll 
//     return {};
// }

void punto1Procesar(Resultado r, Coll<REquipo>& cEq)
{
    // veo que equipo gano
    // lo busco en cEq y le sumo 3
    // si hubo empate => busco ambos equipos y les sumo 1 a c/u
    if(r.codRes == 0){
        sumarPuntosEquipo(cEq, r.idEq1, 1);
        sumarPuntosEquipo(cEq, r.idEq2, 1);
    }else{
        if(r.codRes < 0){
            sumarPuntosEquipo(cEq, r.idEq1, 3);
        }else{
            sumarPuntosEquipo(cEq, r.idEq2, 3);
        }
    }
}

bool estadioEncontrado(Coll<REstadio>& cEs, string estadio){
    int pos = collFind<REstadio, string>(
        cEs,
        estadio,
        cmpREstadioEstadio,
        rEstadioFromString
    );
    if (pos >= 0){
        return true;
    }
    return false;
}

void estadioModifCpjCpe(Coll<REstadio>& cEs, Resultado r){
    string est = r.estadio;

    int pos = collFind<REstadio, string>(
        cEs,
        est,
        cmpREstadioEstadio,
        rEstadioFromString
    );

    REstadio rest = collGetAt<REstadio>(
            cEs,
            pos,
            rEstadioFromString
        );

    rest.cpj += 1;

    if(r.codRes == 0){
        rest.cpe += 1; 
    }

    collSetAt<REstadio>(
        cEs,
        rest,
        pos,
        rEstadioToString
    );

}

// Redundante esta funcion
// void estadioSumarPartidos(Coll<REstadio>& cEs, Resultado r){
//     string est = r.estadio;

//     if( estadioEncontrado(cEs, est) )
//     {
//         estadioModifCpjCpe(cEs, r);
//     }
//     else
//     {
//         REstadio newEstadio = rEstadio(est, 0, 0);
//         collAdd<REstadio>(cEs, newEstadio, rEstadioToString);
//         estadioModifCpjCpe(cEs, r);
//     }
// }

void punto2Procesar(Resultado r, Coll<REstadio>& cEs)
{
    // descubro el estadio (lo busco en cEs y si no lo encuentro => lo agrego)
    // le sumo 1 al cpj (CANTIDAD PARTIDOS JUGADOS)
    // si corresponde le sumo 1 al cpe (CANTIDAD PARTIDOS EMPATADOS)

    string est = r.estadio;

    if( estadioEncontrado(cEs, est) )
    {
        estadioModifCpjCpe(cEs, r);
    }
    else
    {
        REstadio newEstadio = rEstadio(est, 0, 0);
        collAdd<REstadio>(cEs, newEstadio, rEstadioToString);
        estadioModifCpjCpe(cEs, r);
    }
}

void punto1Mostrar(Coll<REquipo> cEq)
{
    // ordeno cEq por puntos+acum decreciente
    // recorro y muestro
    collSort<REquipo>(cEq, 
                      cmpREquipoPuntos, 
                      rEquipoFromString, 
                      rEquipoToString);
    
    collReset<REquipo>(cEq);

    while ( collHasNext<REquipo>(cEq) ){
        REquipo req = collNext<REquipo>(cEq, rEquipoFromString);
        string nomEq = req.e.nombre;
        int totalPuntos = req.e.puntos + req.acum;

        cout << "----------------------" << endl;
        cout << nomEq << endl;
        cout << "Puntos: " << totalPuntos << endl;
        cout << "----------------------" << endl;
    }
}

void punto2Mostrar(Coll<REstadio> cEs)
{
    // recorro y muestro
    collReset<REstadio>(cEs);

    while ( collHasNext<REstadio>(cEs) ){
        REstadio res = collNext<REstadio>(cEs, rEstadioFromString);
        string nomEs = res.est;
        int partJug = res.cpj;
        int partEmp = res.cpe;

        cout << "----------------------" << endl;
        cout << nomEs << endl;
        cout << "Partidos Jugados: " << partJug << endl;
        cout << "Partidos Empatados: " << partEmp << endl;
        cout << "----------------------" << endl;
    }
}

// Para pasar los equipos del archivo a una coll
Coll<REquipo> equiposSubir()
{
    // abro EQUIPOS.dat
    // creo una Coll<REquipo> vacia
    // lo recorro del primero al ultimo
    // le agrego REquipos a la coll vacia
    // cierro el archivo
    // retorno la coll 

    Coll<REquipo> eqs = coll<REquipo>();
    FILE* f = fopen("C:/vscode/Workspace/AlgoritmosAFondo_EMPTY_v2.7.36/EQUIPOS.dat", "r+b");

    Equipo eq = read<Equipo>(f);

    while ( !feof(f) ){
        REquipo req = rEquipo(eq, 0); 
        collAdd<REquipo>(eqs, req, rEquipoToString);
        eq = read<Equipo>(f);
    }
    
    fclose(f);

    return eqs;
}

// Vamos a tener que actualizar las puntuaciones de los equipos
// en el archivo de EQUIPOS.dat, por lo que tendremos que acceder
// a cada uno de los Equipo en el archivo y modificar sus puntos 
// en base a acum de REquipo que contiene a ese equipo
void equiposActualizar(Coll<REquipo> cEq){
    FILE* f = fopen("C:/vscode/Workspace/AlgoritmosAFondo_EMPTY_v2.7.36/EQUIPOS.dat", "r+b");
    
    collReset<REquipo>(cEq);

    while ( collHasNext<REquipo>(cEq) ){
        REquipo req = collNext<REquipo>(cEq, rEquipoFromString);
        req.e.puntos += req.acum;
        write<Equipo>(f, req.e);
    }
    fclose(f);
}

int main()
{
    Coll<REquipo> cEq = equiposSubir();
    Coll<REstadio> cEs = coll<REstadio>();

    FILE* f = fopen("C:/vscode/Workspace/AlgoritmosAFondo_EMPTY_v2.7.36/RESULTADOS.dat","r+b");    

    Resultado r = read<Resultado>(f);
    while( !feof(f) )
    {
        punto1Procesar(r,cEq);
        punto2Procesar(r,cEs);
        r = read<Resultado>(f);
    }

    punto1Mostrar(cEq);
    cout << "\n\n\n";
    punto2Mostrar(cEs);

    equiposActualizar(cEq);

    fclose(f);
    return 0;
}