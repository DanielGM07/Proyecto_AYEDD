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

#include "pdf_principal.hpp"

struct Predio
{
   int idPredio;
   char nombre[100];
   char direccion[100];
   int cantCanchas;
   int idBarrio;
};

struct Reserva
{
   int idReserva; 
   int idCliente; 
   int idPredio; 
   int diaMes; // 1 a 31
   char turno; // 'M,'T','N'
   char celContacto[50]; 
};

struct Cancha
{
   int idPredio; 
   int nroCancha;
   double precio;
   int flgCubierta;
   char obs[200];
};

struct Rechazo
{
   Reserva reserva; 
   int motivoRechazo; 
};

int main(){

}