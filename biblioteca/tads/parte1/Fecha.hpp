#ifndef FECHA_H
#define FECHA_H

#include <string>

#include "../../funciones/millis.hpp"

using std::string;
using std::to_string;

// ============================
// Estructura
// ============================

struct Fecha
{
    // pone aqui los atributos que consideres
    int anio,
        mes, 
        dia, 
        hora = 0, 
        minuto = 0, 
        segundo = 0, 
        milisegundo = 0;
};

// 1.1.3.2. Función fecha - Descripción: Función de inicialización que crea una fecha a partir de un timestamp.
// Esta funcion va a recibir un timestamp algo como "2026-05-27 17:51:00" y lo va a convertir en un objeto fecha

Fecha fecha(long long ts)
{
    Fecha x;
    x.anio = _getYear(ts);
    x.mes = _getMonth(ts);
    x.dia = _getDay(ts);
    x.hora = _getHour(ts);
    x.minuto = _getMinute(ts);
    x.segundo = _getSecond(ts);
    x.milisegundo = _getMillis(ts);
    return x;
}

// 1.1.3.3. Función fecha (sobrecarga 1) - Descripción: Función de inicialización que crea una fecha inicializada en este instante.
// Es decir: fecha de hoy, hora actual.
Fecha fecha()
{
    /* Forma 1
    Fecha x = fecha(currTimeMillis());
    return x;
    */

    /* Forma 2
    return fecha(currTimeMillis());
    */

    // Forma 3
    Fecha x;
    long long ts = currTimeMillis();
    millisToAttributes(ts, x.anio, x.mes, x.dia, x.hora, x.minuto, x.segundo, x.milisegundo);
    return x;
}

// 1.1.3.4. Función fecha (sobrecarga 2)
// Descripción: Función de inicialización que crea una fecha inicializada a partir de los
// valores que recibe como parámetro.
Fecha fecha(int anio, int mes, int dia, int hora, int min)
{
    Fecha x;
    x.anio = anio;
    x.mes = mes;
    x.dia = dia;
    x.hora = hora;
    x.minuto = min;

    return x;
}

Fecha fecha(int anio, int mes, int dia, int hora, int min, int seg, int milis)
{
    Fecha x;
    x.anio = anio;
    x.mes = mes;
    x.dia = dia;
    x.hora = hora;
    x.minuto = min;
    x.segundo = seg;
    x.milisegundo = milis;

    return x;
}

// 1.1.3.5. Función fecha (sobrecarga 3)
// Descripción: Función de inicialización que crea una fecha inicializada a partir de los
// valores de year, month y day, dejando la hora, minuto segundos y milisegundos en cero.
Fecha fecha(int anio, int mes, int dia)
{
    Fecha x;
    x.anio = anio;
    x.mes = mes;
    x.dia = dia;
    return x;
}

// 1.1.3.7. Función fechaInMillis
// Descripción: Retorna la fecha f representada como un timestamp.
// Retorna: long long – Retorna el timestamp que se corresponde con f.
long long fechaInMillis(Fecha f)
{
    long long ts = attributesToMillis(f.anio, f.mes, f.dia, f.hora, f.minuto, f.segundo, f.milisegundo);
    return ts;
}

// 1.1.3.8. Función fechaAddSegundos
// Prototipo: Fecha fechaAddSegundos(Fecha f,int n);
// Descripción: Crea y retorna una fecha que resultará de sumarle n segundos a f.
Fecha fechaAddSegundos(Fecha f, int n)
{
    Fecha x;
    long long fechaEnMilisegundos = attributesToMillis(f.anio, f.mes, f.dia, f.hora, f.minuto, ((f.segundo) + n), f.milisegundo);
    millisToAttributes(fechaEnMilisegundos, x.anio, x.mes, x.dia, x.hora, x.minuto, x.segundo, x.milisegundo);
    return x;
}

// 1.1.3.9. Función fechaAddMinutos
// Descripción: Idem anterior pero suma n minutos a la fecha f.
Fecha fechaAddMinutos(Fecha f, int n)
{
    Fecha x;
    long long fechaEnMilisegundos = attributesToMillis(f.anio, f.mes, f.dia, f.hora, ((f.minuto) + n), f.segundo, f.milisegundo);
    millisToAttributes(fechaEnMilisegundos, x.anio, x.mes, x.dia, x.hora, x.minuto, x.segundo, x.milisegundo);
    return x;
}

// 1.1.3.10. Función fechaAddHoras
// Descripción: Idem anterior pero suma n horas a la fecha f.
Fecha fechaAddHoras(Fecha f, int n)
{
    Fecha x;
    long long fechaEnMilisegundos = attributesToMillis(f.anio, f.mes, f.dia, ((f.hora) + n), f.minuto, f.segundo, f.milisegundo);
    millisToAttributes(fechaEnMilisegundos, x.anio, x.mes, x.dia, x.hora, x.minuto, x.segundo, x.milisegundo);
    return x;
}

// 1.1.3.11. Función fechaAddDias
// Descripción: Crea y retorna una fecha que resultará de sumarle n días a f.
Fecha fechaAddDias(Fecha f, int n)
{
    Fecha x;
    long long fechaEnMilisegundos = attributesToMillis(f.anio, f.mes, ((f.dia) + n), f.hora, f.minuto, f.segundo, f.milisegundo);
    millisToAttributes(fechaEnMilisegundos, x.anio, x.mes, x.dia, x.hora, x.minuto, x.segundo, x.milisegundo);
    return x;
}

// 1.1.3.12. Función fechaDiffMillis
// Descripción: Retorna la diferencia expresada en milisegundos entre f1 y f2.
long long fechaDiffMillis(Fecha a, Fecha b)
{   
    long long diff;
    long long fechaAEnMilis = attributesToMillis(a.anio, a.mes, a.dia, a.hora, a.minuto, a.segundo, a.milisegundo);
    long long fechaBEnMilis = attributesToMillis(b.anio, b.mes, b.dia, b.hora, b.minuto, b.segundo, b.milisegundo);
    
    if(fechaAEnMilis >= fechaBEnMilis){
        diff = (fechaAEnMilis - fechaBEnMilis);
    }else{
        diff = (fechaBEnMilis - fechaAEnMilis);
    }
    return diff;
}

// 1.1.3.13. Función fechaDiffDias
// Descripción: Retorna la diferencia en días entre f1 y f2.
int fechaDiffDias(Fecha a, Fecha b)
{
    int dias = _getDay(fechaDiffMillis(a, b));
    return dias;
}

// 1.1.3.14. Función fechaCmp
// Descripción: Función de comparación que permite estabecer si una fecha precede a otra.
// La comparación debe considerar año, mes, día, hora, minuto, segundo y milisegundo.
int fechaCmp(Fecha a, Fecha b)
{
    long long f1EnMilis = fechaInMillis(a);
    long long f2EnMilis = fechaInMillis(b);
    if(f1EnMilis > f2EnMilis){
        return 1;
    }else if(f1EnMilis == f2EnMilis){
        return 0;
    }else{
        return -1;
    }
}

// 1.1.3.15. Función fechaCmpDiaMesAnio
// Descripción: Compara f1 y f2 sin considerar hora, minuto, segundo ni milisegundo.
int fechaCmpDiaMesAnio(Fecha a, Fecha b)
{
    long long fechaAEnMilis = attributesToMillis(a.anio, a.mes, a.dia, 0, 0, 0, 0);
    long long fechaBEnMilis = attributesToMillis(b.anio, b.mes, b.dia, 0, 0, 0, 0);
    if(fechaAEnMilis > fechaBEnMilis){
        return 1;
    }else if(fechaAEnMilis == fechaBEnMilis){
        return 0;
    }else{
        return -1;
    }
    return 0;
}

// 1.1.3.6. Función fechaToString
// Descripción: Función de conversión.
// Retorna: string – Retorna una cadena que representa a la fecha f.
string fechaToString(Fecha f)
{
    long long ts = attributesToMillis(f.anio, f.mes, f.dia, f.hora, f.minuto, f.segundo, f.milisegundo);
    string fechaCadena = millisToString(ts);
    return fechaCadena;
}

// 1.1.3.16. Función fechaEsAnioBisiesto
// Descripción: Indica si un año es bisiesto.
// Retorna: bool – Retorna true o false según a sea un año bisiesto o no.
bool fechaEsAnioBisiesto(int anio)
{
    bool esBisiesto = false;
    if((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)){
        esBisiesto = true;
    }
    return esBisiesto;
}

//1.1.3.17. Función fechaEsAnioBisiesto (sobrecarga)
// Descripción: Indica si el año de la fecha f es bisiesto.
// Retorna: bool – Retorna true o false según el año de la fecha f sea o no bisiesto.
bool fechaEsAnioBisiesto(Fecha f)
{
    /* Forma 1
    long long fechaEnMilis = fechaInMillis(f);
    int anio = _getYear(fechaEnMilis);
    if(fechaEsAnioBisiesto(anio)){
        return true;
    }
    return false;
    */

    // Forma mas eficiente y reducida jejeje
    return fechaEsAnioBisiesto(_getYear(fechaInMillis(f)));
}

// 1.1.3.18. Función fechaDiasEnMes
// Descripción: Indica cuántos días tiene el mes mes.
// Retorna: int – Retorna la cantidad de días que tiene el mes mes según el año anio.
/*
    ENERO       MES 1   : 31 DIAS
    FEBRERO     MES 2   : 28 O 29 DIAS DEPENDE EL ANIO
    MARZO       MES 3   : 31 DIAS
    ABRIL       MES 4   : 30 DIAS
    MAYO        MES 5   : 31 DIAS
    JUNIO       MES 6   : 30 DIAS
    JULIO       MES 7   : 31 DIAS
    AGOSTO      MES 8   : 31 DIAS
    SEPTIEMBRE  MES 9   : 30 DIAS
    OCTUBRE     MES 10  : 31 DIAS
    NOVIEMBRE   MES 11  : 30 DIAS
    DICIEMBRE   MES 12  : 31 DIAS   
*/
int fechaDiasEnMes(int mes, int anio)
{
    if(mes == 2){
        if(fechaEsAnioBisiesto(anio)){
            return 29;
        }
        return 28;
    }else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        return 31;
    }else{
        return 30;
    }
    // ES POSIBLE QUE HAYA OTRA FORMA USANDO LOS MILISEGUNDOS...
}

// 1.1.3.19. Función fechaDiasEnMes (sobrecarga)
// Descripción: Indica cuántos días tiene el mes de la fecha f.
// Retorna: int – Retorna la cantidad de días que tiene el de la fecha f.
int fechaDiasEnMes(Fecha f)
{
    return fechaDiasEnMes(f.mes, f.anio);
}

// 1.1.3.20. Función fechaDiaDelAnio
// Descripción: Retorna a qué número de día del año corresponde la fecha f.
// Retorna: int – Retorna el número del día de la fecha f, que estará entre 1 y 365 o 366.
int fechaDiaDelAnio(Fecha f)
{
    f.dia = f.dia + 1;
    f.hora = 0;
    f.minuto = 0;
    f.segundo = 0;
    f.milisegundo = 0;
    // long long fEnMillis = fechaInMillis(f);
    // long long principioDeAnio = fechaInMillis(fecha(f.anio, 1, 1, 0, 0, 0, 0));
    Fecha principioDeAnio = fecha(f.anio, 1, 1, 0, 0, 0, 0);
    long long diasDiffMillis = fechaDiffMillis(f, principioDeAnio);
    return (diasDiffMillis / 86400000);
}

// 1.1.3.21. Función fechaEsValida
// Descripción: Determina si una fecha es consistente o no lo es.
// Retorna: bool – true si la fecha f es consistente o false si no lo es.
bool fechaEsValida(Fecha f)
{
    int maxDias = fechaDiasEnMes(f);
    if(f.anio >= 1970 && f.anio <= 2030 && 
       f.mes && f.mes >= 1 && f.mes <= 12 &&
       f.dia >= 1 && f.dia <= maxDias && 
       f.hora >= 0 && f.hora < 24 && 
       f.minuto >= 0 && f.minuto < 60 && 
       f.segundo >= 1 && f.segundo < 60 && 
       f.milisegundo >= 0 && f.milisegundo < 1000){
        return true;
       }
    return false;
}

// 1.1.3.22. Función fechaEsHoy
// Descripción: Determina si una fecha coincide con la fecha de hoy (día, mes y año).
// Retorna: bool– true si la fecha f es es la fecha de hoy.
bool fechaEsHoy(Fecha f)
{
    // f.hora = 0;
    // f.minuto = 0;
    // f.segundo = 0;
    // f.milisegundo = 0;
    // Fecha fechaActual = fecha();
    // fechaActual.hora = 0;
    // fechaActual.minuto = 0;
    // fechaActual.segundo = 0;
    // fechaActual.milisegundo = 0;
    Fecha actual = fecha();
    // bool esHoy = (f.anio == fecha().anio && f.mes == fecha().mes && f.dia == fecha().dia);
    return f.anio == actual.anio &&
           f.mes == actual.mes &&
           f.dia == actual.dia;
}

// =================
// Setters y getters
// =================

// Ejercicios desde 1.1.3.23 al 1.1.3.36
int fechaGetAnio(Fecha f)
{
    return f.anio;
}

int fechaGetMes(Fecha f)
{
    return f.mes;
}

int fechaGetDia(Fecha f)
{
    return f.dia;
}

int fechaGetHora(Fecha f)
{
    return f.hora;
}

int fechaGetMinuto(Fecha f)
{
    return f.minuto;
}

int fechaGetSegundo(Fecha f)
{
    return f.segundo;
}

int fechaGetMillis(Fecha& f, int millis)
{
    return f.milisegundo;
}

void fechaSetAnio(Fecha& f, int anio)
{
    f.anio = anio;
}

void fechaSetMes(Fecha& f, int mes)
{
    f.mes = mes;
}

void fechaSetDia(Fecha& f, int dia)
{
    f.dia = dia;   
}

void fechaSetHora(Fecha& f, int hora)
{
    f.hora = hora;
}

void fechaSetMinuto(Fecha& f, int minuto)
{
    f.minuto = minuto;
}

void fechaSetSegundo(Fecha& f, int segundo)
{
    f.segundo = segundo;
}

void fechaSetMillis(Fecha& f, int millis)
{
    f.milisegundo = millis;
}

#endif  // FECHA_H