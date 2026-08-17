Predios de fútbol
 22nd November 2024 at 2:42pm
Un estudio administrativo que gestiona predios con varios canchas de fútbol cada uno, requiere un programa que procese la reserva de canchas para el mes próximo.

Los clientes reservan una cancha en un predio para un determinado día del mes, en alguno de los tres turnos disponibles: turno mañana (de 10 a 14 hs.), turno tarde (de 14 a 18 hs.) y turno noche (de 18 a 22 hs.).

Disponemos de los siguientes archivos: PREDIOS.dat, RESERVAS.dat y CANCHAS.dat, con las siguientes estructuras:

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
Lo partidos siempre comienzan a una hora exacta y duran 50 minutos. Los 10 minutos restantes se utilizan para el recambio de judadores (salen los que jugaron e ingresan los que van a jugar) y, de ser necesario, tareas de mantenimiento.

La asignación de la cancha así como la hora de inicio del partido queda a criterio del programador. Es decir, el cliente sólo indica un predio y un turno. Qué cancha (dentro del predio) y qué hora (dentro del turno) lo establece el programa.

Se pide:
Generar el archivo RECHAZOS.dat, con la siguiente estructura de registro, para aquellas reservas que no serán aceptadas.
struct Rechazo
{
   Reserva reserva; 
   int motivoRechazo; 
};
Los motivos del rechazo de la reserva podrían ser: Cancha no disponible (motivoRechazo = 1) o Predio inexistente (motivoRechazo = 2).

Notificar a los clientes sobre la aceptación o rechazo de su reserva. En caso de rechazo, se debe informar el motivo del mismo. En caso de aceptación, informar el número de cancha y la hora (dentro del turno) asignada. Para esto se puede utilizar la función enviarMensaje cuyo prototipo es el siguiente:
void inviarMensaje(string nroCelular,string mensaje);
Emitir un listado detallando, para cada barrio, cuántas reservas fueron aceptadas y cuántas rechazadas por cada turno.