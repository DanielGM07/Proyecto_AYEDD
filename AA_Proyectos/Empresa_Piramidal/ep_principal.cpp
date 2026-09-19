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

#include "ep_principal.hpp"

// Se pide:
// 1. Imprimir un listado, ordenado por idSocio, detallando su nombre, fecha de ingreso, 
// liquidación anterior, liquidación actual (la que surge de procesar las ventas), 
// porcentaje de incremento o decremento de la liquidación actual respecto a la anterior, 
// y el total de acumulado desde su ingreso a la empresa.
// 2. Actualice los campos liquidacionAnterior, liquidacionAcumulada y totalVentasAcumuladas 
// del archivo SOCIOS.dat.

struct Venta
{
    int idSocio;
    int idProducto;
    char observ[100];
    int fecha;
    double importe;
};

struct Socio
{
    int idSocio;
    char nombre[50];
    int idSocioRef;  // socio referente
    int fechaIngreso;
    double totalVentasAcumuladas;
    double liquidacionAnterior;
    double liquidacionesAcumuladas;
};

struct RSocio
{
    Socio s;
    double sumLiqAct;
};

RSocio rSocio(Socio socio, double sumLiqAct){
    RSocio rs;
    rs.s = socio;
    rs.sumLiqAct = sumLiqAct;
    return rs;
}

//  
// 
//

// ESTE ES EL TRABAJO !!!
// socio
// socio
//   ^ le da el 30%   
// socio <--- venta
// socio
// key value
// key2 value2
void ventaProcesar(Venta v, Map<int, RSocio>& mSoc)
{
    int id = v.idSocio;
    double imp = v.importe;

    RSocio* rs = mapGet<int, RSocio>(mSoc, id);

    while( rs->s.idSocioRef != -1 ){
        double imp30 = (double)imp*(0.3);
        double imp30Ref = (double)imp30*(0.3);

        rs->sumLiqAct += imp30-imp30Ref;

        rs = mapGet<int, RSocio>(mSoc, rs->s.idSocioRef);

        imp = imp30Ref;
    }
    
    
}

Map<int, RSocio> sociosSubir()
{
    FILE* f = fopen("ruta", "r+b");
    Socio s = read<Socio>(f);
    Map<int, RSocio> mapRs = map<int, RSocio>();

    while ( !feof(f) ){
        int idSoc = s.idSocio;
        RSocio rs = rSocio(s, 0);

        mapPut<int, RSocio>(mapRs, idSoc, rs);
        s = read<Socio>(f);
    }

    fclose(f);
    return mapRs;
}

// La key que guarda el map es el mismo id que esta contenido dentro de algun
// rsocio-socio
void punto1Mostrar(Map<int,RSocio> mSoc)
{
}

int main()
{
    // subo los socios a memoria
    Map<int, RSocio> mSoc = sociosSubir();
    // recorro ventas
    FILE* f = fopen("VENTAS.dat", "r+b");
    Venta v = read<Venta>(f);

    while( !feof(f) )
    {
        // proceso la venta
        ventaProcesar(v, mSoc);
        // leo la siguiente venta
        v = read<Venta>(f);
    }

    // muestro los resultados
    punto1Mostrar(mSoc);
    fclose(f);
    return 0;
}