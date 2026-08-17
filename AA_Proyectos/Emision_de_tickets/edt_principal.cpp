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

#include "edt_principal.hpp"

int cmpProdProd(RProducto rproA, RProducto rproB){
    return cmpString(rproB.prod.descr, rproA.prod.descr);
}

// Si el cliente ingresa 0 termina la venta
// Si el id del cliente es 0 se termina la operatoria (se cierra el programa)

// Por cada venta, emitir un ticket, con el formato que se detalla 
// a continuación, agrupando los productos y sumando sus cantidades, 
// ordenando los ítems alfabéticamente según la descripción de los productos.
void punto1Proceso(Coll<RProducto>& ticket){
    collSort<RProducto>(ticket,
                        cmpProdProd,
                        rProductoFromString,
                        rProductoToString);
    
}

void punto1Mostrar(){

}

void punto2Mostrar(){

}

int cmpRProdIdPro(RProducto rpro, int idProd){
    return rpro.prod.idProd - idProd;
}

int posProd(Coll<RProducto> collDeProds, int idProd){
    return collFind<RProducto>(collDeProds, idProd, cmpRProdIdPro, rProductoFromString);
}

void acumCantTotalXProducto(int cantidad, int idPro, Coll<RProducto>& prods){
    int pos = posProd(prods, idPro);
    RProducto rpro = collGetAt<RProducto>(prods, pos, rProductoFromString);
    rpro.cantDemanda += cantidad;
}

// Informar cuáles fueron los 10 productos más demandados, 
// ordenando el listado decrecientemente según la cantidad demandada.
void punto2Proceso(int cantidad, int idPro, Coll<RProducto>& prods){
    int pos = posProd(prods, idPro);
    RProducto rpro = collGetAt<RProducto>(prods, pos, rProductoFromString);
    rpro.cantDemanda += cantidad;
}

Coll<RProducto> subirProductos(){
    FILE* f = fopen("C:/vscode/Workspace/Proyecto_AYEDD/AA_Proyectos/Emision_de_tickets/PRODUCTOS.dat", "r+b");

    Coll<RProducto> rpros = coll<RProducto>();

    Producto prod = read<Producto>(f);

    while ( !feof(f) ){
        RProducto rpro = rProducto(prod, 0);
        collAdd<RProducto>(rpros, 
                           rpro, 
                           rProductoToString);

        prod = read<Producto>(f);
    }

    fclose(f);
}

// int estaEnElTicket(Coll<RProducto> ticket, int idProd){
//     return collFind<RProducto>(ticket, idProd, cmpRProdIdPro, rProductoFromString);
// }

void armarTicket(Coll<RProducto> prods, Coll<RProducto>& ticket, int idProd, int cant){
    int posEnProds = posProd(prods, idProd);

    int posEnTicket = posProd(ticket, idProd);
    
    if(posEnTicket >= 0){
        RProducto rpro = collGetAt<RProducto>(ticket, posEnTicket, rProductoFromString);
        rpro.cantDemanda += cant;
        collSetAt<RProducto>(ticket, rpro, posEnTicket, rProductoToString);
    }else{
        RProducto newProd = collGetAt<RProducto>(prods, posEnProds, rProductoFromString);
        newProd.cantDemanda += cant;
        collAdd<RProducto>(ticket, newProd, rProductoToString);
    }
}

int main(){
    int idCli = -1;
    int idProd = -1;
    int cantidad = 0;

    Coll<RProducto> ticket = coll<RProducto>();
    Coll<RProducto> prods = subirProductos();

    cout << "Ingrese su id de cliente: ";
    cin >> idCli;
    while (idCli != 0){

        while (idProd != 0){
            cantidad = 0;
            cout << "ID Producto: ";
            cin >> idProd;
            if(idProd!=0){
                cout << "Cantidad: ";
                cin >> cantidad;
                armarTicket(prods, ticket, idProd, cantidad);
            }
            cout << "\n";
        }
        
        cout << "Ingrese su id de cliente: ";
        cin >> idCli;
        cout << "\n";
    }
}