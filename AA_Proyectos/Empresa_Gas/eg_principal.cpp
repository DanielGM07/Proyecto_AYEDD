#include "eg_principal.hpp"

#include <cassert>
#include <iostream>

#include "../../biblioteca/funciones/files.hpp"
#include "../../biblioteca/funciones/millis.hpp"
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/tads/parte1/Coll.hpp"
#include "../../biblioteca/tads/parte1/Fecha.hpp"
#include "../../biblioteca/tads/parte1/Timer.hpp"
#include "../../biblioteca/tads/parte2/Array.hpp"
#include "../../biblioteca/tads/parte2/List.hpp"
#include "../../biblioteca/tads/parte2/Map.hpp"
#include "../../biblioteca/tads/parte2/Queue.hpp"
#include "../../biblioteca/tads/parte2/Stack.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::to_string;

Map<int,RCategoria> categoriasSubir()
{
    return {};
}

void medicionProcesar(Medicion m, FILE* fCli, Map<int, RCategoria>& mCat)
{
    // 1. Busco el cliente (con la funcion que nos dieron)
    // 2. Calculo el consumo actual del cliente
    // 3. Calculo el consumo anual del cliente (en funcion del actual y del historial de consumos)



}

void categoriasMostrarNuevosClientes(Map<int,RCategoria> mCat,FILE* fCli)
{
}

int main()
{
    // subimos las categorias
    Map<int,RCategoria> mCat = categoriasSubir();

    // abro archivos    
    FILE* fCli = fopen("CLIENTES.dat","r+b");
    FILE* fMed = fopen("MEDICIONES.dat","r+b");
    
    // recorro las mediciones
    Medicion m = read<Medicion>(fMed);
    while( !feof(fMed) )
    {
        // proceso la medicion
        medicionProcesar(m,fCli,mCat);

        // leo la siguiente medicion
        m = read<Medicion>(fMed);
    }

    // muestro el listado del punto 1
    categoriasMostrarNuevosClientes(mCat,fCli);



    fclose(fMed);
    fclose(fCli);
    return 0;
}