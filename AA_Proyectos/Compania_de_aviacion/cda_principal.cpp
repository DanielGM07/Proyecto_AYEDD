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

#include "cda_principal.hpp"

void punto1Proceso(){

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

Coll<RVuelo> vuelosSubir(){
    FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Compania_de_aviacion/VUELOS.dat", "r+b");

    Vuelo vuelo = read<Vuelo>(f);
    Coll<RVuelo> rvues = coll<RVuelo>();

    while( !feof(f) ){
        RVuelo rvue = rVuelo(vuelo, 0, 0);

        collAdd<RVuelo>(rvues, rvue, rVueloToString);

        vuelo = read<Vuelo>(f);
    }

    fclose(f);

    return rvues;
}

Coll<RCiudad> ciudadesSubir(){

    FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Compania_de_aviacion/CIUDADES.dat", "r+b");

    Ciudad ciudad = read<Ciudad>(f);
    Coll<RCiudad> rcius = coll<RCiudad>();

    while( !feof(f) ){
        RCiudad rciu = rCiudad(ciudad, 0);

        collAdd<RCiudad>(rcius, rciu, rCiudadToString);

        ciudad = read<Ciudad>(f);
    }

    fclose(f);

    return rcius;
}

int main(){

    Coll<RVuelo> vuelos = vuelosSubir();
    Coll<RCiudad> ciudades = ciudadesSubir();
    Coll<RCliente> clientes = coll<RCliente>();

    FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Compania_de_aviacion/RESERVAS.dat", "r+b");

    Reserva reserva = read<Reserva>(f);
    
    while( !feof(f) ){

    }

}