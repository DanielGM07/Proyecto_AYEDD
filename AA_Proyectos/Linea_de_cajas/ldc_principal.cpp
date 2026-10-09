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

#include "ldc_principal.hpp"

#include <cassert>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::to_string;

struct Mov
{
   int caja;
   char tipo; // 'E' => Entra, 'S' => Sale
   int min;   // de 0 a 1440
};

struct Caja
{
    // punto 1
    Queue<int> q;
    int acum;
    int cont;

    // punto 2
    int inicTO;
    int acumTO;

    // punto 3
    int max;
};

// ESTA FUNCION ES LA IMPORTANTE !
void movimientoProcesar(Mov m,Map<int,Caja>& mCajas)
{
    // descubro la caja
    Caja* c = mapDiscover<int,Caja>(mCajas, m.caja, {queue<int>(),
                                                    0,      //acum
                                                    0,      //cont
                                                    0,      //inicTO
                                                    0,      //acumTO
                                                    0});    //max

    if(m.tipo=='E')
    {
        // encolo
        queueEnqueue<int>(c->q,m.min);

        // tamanio de la cola
        int n = queueSize<int>(c->q);

        // punto 2
        if( n==1 && m.min >= 540 && m.min <= 1260)
        {
            int tiempoOcioso = m.min-c->inicTO;
            c->acumTO+=tiempoOcioso;
        }

        // punto 3
        if( n>c->max )
        {
            c->max = n;
        }
    }   
    else
    {
        // desencolo
        int minEntrada = queueDequeue<int>(c->q);
        int minSalida = m.min;
        
        // punto 1
        int tiempoEncola = minSalida-minEntrada;
        c->acum+=tiempoEncola;
        c->cont++;

        // punto 2
        if( queueIsEmpty(c->q) )
        {
            c->inicTO = m.min;
        }
    } 
}

double tiempoEspera(Caja c){
    return c.acum / c.cont;
}

// 1. Tiempo promedio de espera por caja.
void punto1Mostrar(Map<int,Caja> mCajas)
{
    mapReset(mCajas);
    while(mapHasNext(mCajas)){
        int id = mapNextKey(mCajas);
        Caja* c = mapGet(mCajas, id);

        cout << "Caja: " << id << endl;
        cout << "Tiempo espera promedio: " << tiempoEspera(*c) << " mins" << endl;
        cout << endl;
    }
}

// 2. Sumatoria del tiempo ocioso por caja.
void punto2Mostrar(Map<int,Caja> mCajas)
{
    mapReset(mCajas);
    while ( mapHasNext(mCajas) ){
        int id = mapNextKey(mCajas);
        Caja* c = mapGet(mCajas, id);

        cout << "Caja: " << id << endl;
        cout << "Tiempo Ocioso: " << c->acumTO << " mins" << endl;
        cout << endl;
    }
}

// Longitud máxima a la llegó la cola de cada caja
void punto3Mostrar(Map<int,Caja> mCajas)
{
    mapReset(mCajas);
    while ( mapHasNext(mCajas) ){
        int id = mapNextKey(mCajas);
        Caja* c = mapGet(mCajas, id);

        cout << "Caja: " << id << endl;
        cout << "Maximo de cola: " << c->max << " clientes" << endl;
        cout << endl;
    }
}



int main()
{
    FILE*f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Linea_de_cajas/MOVIMIENTOS.dat","r+b");
    Map<int,Caja> mCajas = map<int,Caja>();

    Mov m = read<Mov>(f);
    while( !feof(f) )
    {
        movimientoProcesar(m,mCajas);

        m = read<Mov>(f);
    }

    punto1Mostrar(mCajas);
    cout << "========================" << endl;
    punto2Mostrar(mCajas);
    cout << "========================" << endl;
    punto3Mostrar(mCajas);


    fclose(f);
    return 0;
}