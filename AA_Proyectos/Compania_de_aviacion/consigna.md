Una compañía de aviación requiere implementar un programa que, basado en un sistema de acumulación de millas, promueva la fidelización de sus clientes.

Cada vez que un cliente vuela a través de la compañía recibe una cantidad de millas acumulables que podrá canjear por vuelos sin costo a diferentes destinos. Cuanto mayor sea la cantidad de millas acumuladas, más importante serán los destinos o premios por los cuales las podrá canjear.

La compañía cuenta con los siguientes archivos: CIUDADES.dat, que contiene la descripción de las ciudades a las que vuela, VUELOS.dat, con la información de los vuelos que conectan las diferentes ciudades, y RESERVAS.dat, con las reservas que realizaron los clientes para volar en los diferentes vuelos.

La estructura de cada uno de estos archivos la vemos a continuación:

struct Ciudad
{
   int idCiu;
   char descr[20];
   int millas;
};

struct Vuelo
{
   int idVue; 
   int cap; 
   int idOri; // idCiu origen
   int idDes; // idCiu origen
};

struct Reserva
{
   int idCli;
   int idVue; 
   int cant;
};

La operatoria es la siguiente: un pasajero que vuela de una ciudad a otra acumula una cantidad de millas equivalente a la diferencia entre las millas establecidas para cada una de esas ciudades, multiplicado por la cantidad de plazas reservadas. Esto será así siempre y cuando su reserva sea aceptada.

Sólo se aceptarán las reservas de aquellos pasajeros que requieran una cantidad de plazas menor o igual a la disponibilidad actual del vuelo en cuestión. De lo contrario la reserva completa será rechazada.

Se pide:
- Informar, para cada ciudad, la cantidad de grupos (familias) que eligieron de destino.
- Indicar, por cada vuelo, la cantidad de plazas que fueron rechazadas, indicando también si el vuelo saldrá completo o incompleto.
- Mostrar, por cada cliente, el total de millas que acumuló.