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

#include "sda_principal.hpp"


/*
1.  Un listado ordenado por cuento, indicando cuántas reproducciones completas tuvo. 
    Cuántas estuvieron entre el 75% y el 100%, cuántas entre el 50% y el 75%, cuántas entre el 25% y el 50%, 
    y cuántas reproducciones duraron menos del 25% del total del cuento.
2.  Los 10 relatores cuyas lecturas tuvieron la mayor cantidad de reproducciones entre el 75% y 100%, 
    ordenado de mayor a menor por dicha cantidad.
*/

int cmpRCuentoId(RCuento rc, int idReproduccion)
{
    return rc.c.idCuento - idReproduccion;
}

void sumTipoRep(RCuento rc, Reproduccion r){
    if ( ( ((float) r.minutos / rc.c.duracion) * 100) == 100){
        rc.cont100++;
    } 
    
    else if ( ( (float) (r.minutos / rc.c.duracion) * 100) >= 75){
        rc.cont75a100++;
    } 
    
    else if ( ( (float) (r.minutos / rc.c.duracion) * 100) >= 50){
        rc.cont50a75++;
    } 
    
    else if ( ( (float) (r.minutos / rc.c.duracion) * 100) >= 25){
        rc.cont25a50++;;
    }

    else{      
        rc.cont0a25++;   
    }
}

void sumarReproducciones(Coll<RCuento>& rcs, Reproduccion r){
    int pos = collFind<RCuento,int>(
        rcs,
        r.idCuento,
        cmpRCuentoId,
        rCuentoFromString
    );

    if( pos >= 0 )
    {
        RCuento rc = collGetAt<RCuento>(
            rcs,
            pos,
            rCuentoFromString
        );

        sumTipoRep(rc, r);

        collSetAt<RCuento>(
            rcs,
            rc,
            pos,
            rCuentoToString
        );
    }
}

// 1.  Un listado ordenado por cuento, indicando cuántas reproducciones completas tuvo. 
//     Cuántas estuvieron entre el 75% y el 100%, cuántas entre el 50% y el 75%, cuántas entre el 25% y el 50%, 
//     y cuántas reproducciones duraron menos del 25% del total del cuento.
void punto1Procesar(Coll<RCuento>& rcs, Reproduccion r)
{
    sumarReproducciones(rcs, r);
    // ordenarListaPorReps(rcs, r);
}

void punto2Procesar(){

}

void punto1Mostrar(){

}

void punto2Mostrar(){

}

Coll<RCuento> cuentosSubir(){

}

Coll<RRelator> relatoresSubir(){
    
}

int main(){
    Coll<RCuento> rcs = cuentosSubir();
    Coll<RRelator> rrs = relatoresSubir();
    
    FILE* f = fopen("C:/vscode/Workspace/AlgoritmosAFondo_EMPTY_v2.7.36/ARCHIVOADEFINIR.dat","r+b"); 
    
    Reproduccion r = read<Reproduccion>(f);
    while( !feof(f) ){

    }

}