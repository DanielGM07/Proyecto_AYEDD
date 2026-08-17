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

#include "arr_tdf_principal.hpp"

// CONSIGNA
// 1. Informar la tabla de posiciones actualizada al día del proceso.
// 2. Informar, para cada estadio, cuántos partidos se jugaron y cuántos de estos partidos resultaron empatados.
// 3. Actualizar las puntuaciones en el archivo EQUIPOS.dat.

void sumarPuntosEquipo(){

}

void punto1Proceso(REquipo reqs[], Resultado r){

}

void punto2Proceso(){
    
}

void punto3Proceso(){
    
}

void punto1Mostrar(){

}

void punto2Mostrar(){
    
}

void punto3Mostrar(){
    
}

void equiposSubir(REquipo reqs[], int& len){
    FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Array_Torneo_de_futbol/EQUIPOS_TDF_20.dat.hpp", "r+b");
    
    // Esta no va porque ys le pasamos el array creado por parametro
    // REquipo reqs[100];
    Equipo eq = read<Equipo>(f);

    while ( !feof(f) ){
        REquipo req = rEquipo(eq, 0);
        add<REquipo>(reqs, len, req);

        eq = read<Equipo>(f);
    }
}

int main(){
    int lenReqs = 0;
    REquipo reqs[100];
    equiposSubir(reqs, lenReqs);

    REstadio rests[100];

    FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Array_Torneo_de_futbol/RESULTADOS_TDF_40.dat.hpp", "r+b");

    Resultado r = read<Resultado>(f);

    // for (int i = 0; !feof(f); i++){    }

    int i = 0;
    while ( !feof(f) ){
        
    }

    fclose(f);
}