Torneo de fútbol
 4th October 2024 at 3:17pm
Se requiere un programa que informe sobre la posición actual de cada uno de los equipos que participan de un torneo de fútbol.

Contamos con archivos: RESULTADOS.dat, con los resultados de los partidos que se jugaron durante la última fecha, y EQUIPOS.dat, que contiene la información de los equipos que participan en el torneo.

La estructura de cada uno de estos archivos la vemos a continuación:

struct Resultado
{
   int idEq1;
   int idEq2;
   int codRes;
   char estadio[20];
};
struct Equipo
{
   int idEq; 
   char nombre[20]; 
   int puntos; 
};
El valor del campo codRes (código de resultado) indica qué equipo ganó el partido. Si codRes<0 significa que ganó el equipo identificado con idEq1. Si codRes>0 el ganador fue el equipo identificado con idEq2. Finalmente, si codRes es 0 (cero) el partido resultó en empate.

El equipo ganador acumula 3 puntos. Si empataron le corresponde 1 punto cada uno. El perdedor no recibe puntos.

Se pide:
Informar la tabla de posiciones actualizada al día del proceso.
Informar, para cada estadio, cuántos partidos se jugaron y cuántos de estos partidos resultaron empatados.
Actualizar las puntuaciones en el archivo EQUIPOS.dat.