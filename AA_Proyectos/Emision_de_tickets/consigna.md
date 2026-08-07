Emisión de tickets
 4th October 2024 at 3:17pm
Un comercio vende productos clasificados en diferentes rubros. Algunos rubros pueden estar en promoción, razón por la cual sus productos se ofrecerán al público por debajo de su valor habitual.

Disponemos de los archivos: PRODUCTOS.dat, con la información de cada uno de los productos comercializados, y RUBROS.dat, que describe los rubros y sus promociones.

struct Producto
{
   int idProd;
   char descr[20];
   double precio;
   int idRub;
};

struct Rubro
{
   int idRub; 
   char descr[20]; 
   double promo; 
};

Por cada cliente se ingresará su idCli, y varios pares {idProd, cant}. Un idProd=0 indicará el final de la compra del cliente. Un idCli=0 indicará la finalización de la operatoria del comercio.

Se pide:

1.
Por cada venta, emitir un ticket, con el formato que se detalla a continuación, agrupando los productos y sumando sus cantidades, ordenando los ítems alfabéticamente según la descripción de los productos.

Número de ticket: 99999
Producto	    Precio	c/Dto.	Cant.	Total
xxxxxxxxxxxxxxx	999,99	999,99	999	    99999,99
xxxxxxxxxxxxxxx	999,99	999,99	999	    99999,99
                                Total: $99999,99
Ahorro por rubro
Rubro	Total
xxxxxxxxxxxxx	999,99
xxxxxxxxxxxxx	999,99
TOTAL: $999,99

2.
Informar cuáles fueron los 10 productos más demandados, ordenando el listado decrecientemente según la cantidad demandada.