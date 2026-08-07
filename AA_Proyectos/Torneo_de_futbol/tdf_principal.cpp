#include "../../biblioteca/funciones/millis.hpp"
#include "../../biblioteca/funciones/files.hpp"
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"

#include "../../biblioteca/tads/parte1/Fecha.hpp"
#include "../../biblioteca/tads/parte1/Timer.hpp"
#include "../../biblioteca/tads/parte1/Coll.hpp"

#include "../../biblioteca/tads/parte2/Array.hpp"
#include "../../biblioteca/tads/parte2/List.hpp"
#include "../../biblioteca/tads/parte2/Map.hpp"
#include "../../biblioteca/tads/parte2/Queue.hpp"
#include "../../biblioteca/tads/parte2/Stack.hpp"

#include "tdf_principal.hpp"

/*
struct Resultado                        
{                       
	int idEq1;                      
	int idEq2;                      
	int codRes;                     
	char estadio[20];                       
};

struct Equipo
{
	int idEq;
	char nombre[20];
	int puntos;
};

struct REquipo
{
	Equipo equipo;
	int acum;
};

struct REstadio
{
	Resultado res;
	int partidosJugados;
	int partidosEmpatados;
};
*/

int cmpReqId(REquipo req, int id){
    return req.equipo.idEq - id;
}

int cmpEquipoPuntosAsc(REquipo a, REquipo b){
    return (a.equipo.puntos + a.acum) - (b.equipo.puntos + b.acum);
}

int cmpEquipoPuntosDesc(REquipo a, REquipo b){
    return (b.equipo.puntos + b.acum) - (a.equipo.puntos + a.acum);
}

void sumarPuntosEquipo(Coll<REquipo>& reqs, int idEq, int puntos){
    int pos = collFind<REquipo>(reqs,
                                idEq,
                                cmpReqId,
                                rEquipoFromString);
    
    if(pos >= 0){
        REquipo req = collGetAt<REquipo>(reqs,
                                        pos,
                                        rEquipoFromString);
        req.acum += puntos;

        collSetAt<REquipo>(reqs,
                           req,
                           pos,
                           rEquipoToString);
    }
}

// Informar la tabla de posiciones actualizada al día del proceso.
void punto1Proceso(Coll<REquipo>& reqs, Resultado r){
    // Vamos a tener que haber analizado todos los resultados, en base a 
    // los resultados, asignarles cierta cantidad de puntos al acum de cada REquipo
    // Y despues ordenar la coll de REquipo por atributo acum

    /*El valor del campo codRes (código de resultado) indica qué 
    equipo ganó el partido. Si codRes<0 significa que ganó el 
    equipo identificado con idEq1. Si codRes>0 el ganador fue el 
    equipo identificado con idEq2. Finalmente, si codRes es 0 (cero) el partido resultó en empate.*/
    if (r.codRes == 0){
        sumarPuntosEquipo(reqs, r.idEq1, 1);
        sumarPuntosEquipo(reqs, r.idEq2, 1);
    } else if (r.codRes < 0){
        sumarPuntosEquipo(reqs, r.idEq1, 3);
    } else{
        sumarPuntosEquipo(reqs, r.idEq2, 3);
    }

}

void punto1Mostrar(Coll<REquipo> reqs){
    collSort<REquipo>(reqs,
                      cmpEquipoPuntosDesc,
                      rEquipoFromString,
                      rEquipoToString);
    
    collReset<REquipo>(reqs);

    cout << "Nombre\t\t\t" << "| Puntos \n";
    while( collHasNext(reqs) ){
        REquipo req = collNext<REquipo>(reqs, rEquipoFromString);
        
        int totalPuntos = req.equipo.puntos + req.acum;
        
        cout << "------------------------------------------\n";
        cout << req.equipo.nombre << "\t\t | " << totalPuntos << "\n";
    }
}

int cmpRestEst(REstadio rest, string est){
    return cmpString(rest.estadio, est);
}

int estadioExiste(Coll<REstadio> rests, string est){
    int pos = collFind<REstadio>(rests,
                                 est,
                                 cmpRestEst,
                                 rEstadioFromString);
    
    return pos;
}



// Informar, para cada estadio, cuántos partidos 
// se jugaron y cuántos de estos partidos resultaron empatados.
void punto2Proceso(Coll<REstadio>& rests, Resultado r){
    string estadio = r.estadio;
    int posEst = estadioExiste(rests, estadio);

    if( posEst >= 0){
        REstadio rest = collGetAt<REstadio>(rests,
                                            posEst,
                                            rEstadioFromString);
        rest.partidosJugados++;
        if(r.codRes == 0){
            rest.partidosEmpatados++;
        }
        
        collSetAt<REstadio>(rests,
                            rest,
                            posEst,
                            rEstadioToString);
    }else{
        REstadio newEst = rEstadio(estadio, 0, 0);
        
        newEst.partidosJugados++;
        if(r.codRes == 0){
            newEst.partidosEmpatados++;
        }

        collAdd<REstadio>(rests,
                          newEst,
                          rEstadioToString);
        
    }
}

// Informar, para cada estadio, cuántos partidos 
// se jugaron y cuántos de estos partidos resultaron empatados.
void punto2Mostrar(Coll<REstadio> rests){
    collReset<REstadio>(rests);

    cout << "Estadio\t\t\t" << "\t | Jugados \t | Empatados\n";

    while ( collHasNext<REstadio>(rests) ){
        REstadio rest = collNext<REstadio>(rests, 
                                           rEstadioFromString);
                
        cout << "------------------------------------------\n";
        cout << rest.estadio << "\t\t\t | " << rest.partidosJugados 
             << "\t\t | " << rest.partidosEmpatados << "\n";        
    }
}

// Actualizar las puntuaciones en el archivo EQUIPOS.dat.
void punto3Proceso(Coll<REquipo> reqs){
    FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Torneo_de_futbol/EQUIPOS_TDF_20.dat", "r+b");

    collReset<REquipo>(reqs);

    while( collHasNext<REquipo>(reqs) ){
        REquipo req = collNext<REquipo>(reqs, rEquipoFromString);
        req.equipo.puntos += req.acum;
        write<Equipo>(f, req.equipo);
    }

    fclose(f);
}

Coll<REquipo> equiposSubir(){
    FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Torneo_de_futbol/EQUIPOS_TDF_20.dat", "r+b");

    Coll<REquipo> reqs = coll<REquipo>();
    Equipo eq = read<Equipo>(f);

    while ( !feof(f) ){
        REquipo req = rEquipo(eq, 0);
        collAdd<REquipo>(reqs,
                        req,
                        rEquipoToString);

        eq = read<Equipo>(f);
    }

    fclose(f);

    return reqs;
}

/*
    El valor del campo codRes (código de resultado) indica qué equipo ganó el partido. Si codRes<0 significa que ganó el equipo identificado con idEq1. Si codRes>0 el ganador fue el equipo identificado con idEq2. Finalmente, si codRes es 0 (cero) el partido resultó en empate.

    El equipo ganador acumula 3 puntos. Si empataron le corresponde 1 punto cada uno. El perdedor no recibe puntos.

    Se pide:
    Informar la tabla de posiciones actualizada al día del proceso.
    Informar, para cada estadio, cuántos partidos se jugaron y cuántos de estos partidos resultaron empatados.
    Actualizar las puntuaciones en el archivo EQUIPOS.dat.
*/

int main(){

    Coll<REquipo> reqs = equiposSubir();
    Coll<REstadio> rests = coll<REstadio>();

    FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Torneo_de_futbol/RESULTADOS_TDF_40.dat", "r+b");
    Resultado r = read<Resultado>(f);

    while ( !feof(f) ){
        punto1Proceso(reqs, r);
        punto2Proceso(rests, r);
        r = read<Resultado>(f);
    };

    punto1Mostrar(reqs);
    punto2Mostrar(rests);
    punto3Proceso(reqs);
    fclose(f);
}