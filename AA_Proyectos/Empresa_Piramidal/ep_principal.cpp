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

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::to_string;

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
    double totalVentasAcumuladas; // importes
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

// Funcion recursiva del profesor
// Esta funcion no la usamos, pero la logica principal es la misma que ventaProcesar
void comisionLiquidar(int idSoc, double comBruta, Map<int,RSocio>& mSoc)
{
    if(idSoc>=0)
    {
        RSocio* rs = mapGet <int,RSocio> (mSoc, idSoc);
        double comNeta = comBruta*.7;
        double comRef = comBruta*.3;

        rs->sumLiqAct+=comNeta;
        int idRef = rs->s.idSocioRef;

        if(idRef<0)
        {
            rs->sumLiqAct+=comRef;
        }

        comisionLiquidar(idRef, comRef, mSoc);
    }
}

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
    int idSoc = v.idSocio;
    double imp = v.importe;
    double comBruta = (double)imp*(0.3);

    RSocio* rs = mapGet<int, RSocio>(mSoc, idSoc);

    if(rs == NULL){
        cout << "NO EXISTE SOCIO: " << idSoc << endl;
        return;
    }

    rs->s.totalVentasAcumuladas += imp;

    while(idSoc >= 0){
        double cb70 = (double)comBruta*(0.7);
        double cb30Ref = (double)comBruta*(0.3);

        rs->sumLiqAct += cb70;
    
        if(rs->s.idSocioRef < 0){
            rs->sumLiqAct += cb30Ref;
        }

        idSoc = rs->s.idSocioRef;

        if(idSoc >= 0){
            rs = mapGet<int, RSocio>(mSoc, idSoc);
            if(rs == NULL){
                cout << "NO EXISTE SOCIO: " << idSoc << endl;
                return;
            }
        }
        
        comBruta = cb30Ref;
    }
}

void sumLiqActAlTotal(RSocio& rs){
    rs.s.liquidacionesAcumuladas += rs.sumLiqAct;
}

double tasaCambioEntreLiquidaciones(RSocio rs){
    double acumLiqAct = rs.sumLiqAct;
    double liqAnt = rs.s.liquidacionAnterior;

    double dif = acumLiqAct - liqAnt;

    if(liqAnt == 0){
        return 0;
    }

    double tasaCambio = (dif * 100) / liqAnt;

    return tasaCambio;
}

Map<int, RSocio> sociosSubir()
{
    FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Empresa_Piramidal/SOCIOS.dat", "r+b");
    
    cout << "Cantidad socios archivo: " << fileSize<Socio>(f) << endl;
    
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

int cmpInt(int a, int b){
    return a-b;
}

// La key que guarda el map es el mismo id que esta contenido dentro de algun
// rsocio-socio
void sumLiqsASusTotales(Map<int,RSocio>& mSoc){
    mapReset(mSoc);
    while( mapHasNext(mSoc) ){
        int idSoc = mapNextKey(mSoc);
        RSocio* rs = mapGet(mSoc, idSoc);
        sumLiqActAlTotal(*rs);
    }
}

void punto1Mostrar(Map<int,RSocio> mSoc)
{
    mapSortByKeys(mSoc, cmpInt);
    mapReset(mSoc);
    // Imprimir un listado, ordenado por idSocio, detallando su nombre, 
    // fecha de ingreso, liquidación anterior, liquidación actual (la que 
    // surge de procesar las ventas), porcentaje de incremento o decremento 
    // de la liquidación actual respecto a la anterior, y el total de 
    // acumulado desde su ingreso a la empresa.

    while( mapHasNext(mSoc) ){
        int idSoc = mapNextKey(mSoc);
        RSocio* rs = mapGet(mSoc, idSoc);
        double tasCamb = tasaCambioEntreLiquidaciones(*rs);

        cout << "Nombre: " << rs->s.nombre << endl;
        cout << "Fecha ingreso: " << rs->s.fechaIngreso << endl;
        cout << "Liquidacion anterior: " << rs->s.liquidacionAnterior << endl;
        cout << "Liquidacion actual: " << rs->sumLiqAct << endl;
        cout << "Porcentaje de cambio: " << tasCamb << endl;
        cout << "Total liquidaciones acumuladas: " << rs->s.liquidacionesAcumuladas << endl;
        cout << "Total ventas acumuladas: " << rs->s.totalVentasAcumuladas << endl;
        cout << "-----------------------------------------" << endl;
    }
}

void mostrarArchivo(Map<int,RSocio> mSoc){
    mapReset(mSoc);
    while( mapHasNext(mSoc) ){
        int idSoc = mapNextKey(mSoc);
        RSocio* rs = mapGet(mSoc, idSoc);
        // double tasCamb = tasaCambioEntreLiquidaciones(*rs);

        cout << "Nombre: " << rs->s.nombre << endl;
        cout << "Fecha ingreso: " << rs->s.fechaIngreso << endl;
        cout << "Liquidacion anterior: " << rs->s.liquidacionAnterior << endl;
        cout << "Liquidacion actual: " << rs->sumLiqAct << endl;
        cout << "Porcentaje de cambio: " << 0 << endl;
        cout << "Total liquidaciones acumuladas: " << rs->s.liquidacionesAcumuladas << endl;
        cout << "Total ventas acumuladas: " << rs->s.totalVentasAcumuladas << endl;
        cout << "-----------------------------------------" << endl;
    }
}


// 2. Actualice los campos liquidacionAnterior, liquidacionAcumulada y totalVentasAcumuladas 
// del archivo SOCIOS.dat.
void punto2Procesar(Map<int, RSocio> mSoc){
    mapReset(mSoc);

    FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Empresa_Piramidal/SOCIOS.dat", "r+b");
    Socio s = read<Socio>(f);
    while( !feof(f) ){
        int pos = filePos<Socio>(f) - 1;

        RSocio* rs = mapGet(mSoc, s.idSocio);

        rs->s.liquidacionAnterior = rs->sumLiqAct;
        rs->sumLiqAct = 0;
        // LiquidacionAcumulada y totalVentasAcumuladas ya las actualice en el punto 1
        // por lo que estan guardadas actualizadas en el map, solo queda escribirlas
        
        // Si bien el puntero del archivo ya esta en la pos 0, es necesario
        // colocarnos sobre el nuevamente de manera explicita con seek
        seek<Socio>(f, pos);
        write<Socio>(f, rs->s);

        // Aca lo mismo, si bien al escribir en el archivo con write ya avanzamos
        // una posicion en el puntero, nos volvemos a colocar sobre la misma posicion
        // con seek de manera explicita
        seek<Socio>(f, pos + 1);
        s = read<Socio>(f);

        // read() y write() avanzan el indicador de posición del archivo.
        // Como el archivo está abierto con "r+b" y alternamos escritura y lectura,
        // usamos seek() entre ambas operaciones para reposicionar/sincronizar el cursor
        // y continuar leyendo desde el registro correcto.
    }

    fclose(f);
}

// Este codigo de punto2Procesar con bucle for me lo dio chat gpt
// Resulta que la razon por la que me tiraba error el programa es porque al mezclar
// escritura y lectura al abrir el archivo mediante r+b se corrompe y es preferible
// que antes de escribir y leer siempre se haga el posicionamiento con seek de 
// manera explicita
// void punto2Procesar(Map<int, RSocio> mSoc)
// {
//     FILE* f = fopen(
//         "C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Empresa_Piramidal/SOCIOS.dat",
//         "r+b"
//     );

//     int cant = fileSize<Socio>(f);

//     for(int i=0; i<cant; i++)
//     {
//         seek<Socio>(f, i);
//         Socio s = read<Socio>(f);

//         RSocio* rs = mapGet(mSoc, s.idSocio);

//         rs->s.liquidacionAnterior = rs->sumLiqAct;
//         rs->sumLiqAct = 0;

//         seek<Socio>(f, i);
//         write<Socio>(f, rs->s);
//     }

//     fclose(f);
// }

int main()
{
    // subo los socios a memoria
    Map<int, RSocio> mSoc = sociosSubir();
    // recorro ventas
    mostrarArchivo(mSoc);

    cout << "\n===============================================\n===============================================\n" << endl;

    FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Empresa_Piramidal/VENTAS.dat", "r+b");
    Venta v = read<Venta>(f);

    while( !feof(f) )
    {
        // proceso la venta
        ventaProcesar(v, mSoc);

        // leo la siguiente venta
        v = read<Venta>(f);
    }


    sumLiqsASusTotales(mSoc);

    // muestro los resultados
    
    punto1Mostrar(mSoc);
    punto2Procesar(mSoc);

    fclose(f);

    return 0;

}