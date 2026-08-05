
#ifndef _TTIMER_
#define _TTIMER_

#include "../../../biblioteca/funciones/millis.hpp"

struct Timer
{
    long long timerInicio;
    long long timerFinal;
};

// funcion de inicializacion
// 1.1.4.3. Función timer
// Descripción: Función de inicialización del timer.
// Retorna: Timer.
Timer timer()
{
    Timer t;
    return t;
}

// 1.1.4.4. Función timerStart
// Descripción: Comienza la cuenta de tiempo del timer t.
// Parámetro: Timer t – El timer que comenzará a contar.
// Retorna: void.
// instante inicial (i)
void timerStart(Timer& t)
{
    t.timerInicio = currTimeMillis();
}

// 1.1.4.5. Función timerStop
// Prototipo: void timerStop(Timer& t);
// Descripción: Finaliza la cuenta de tiempo del timer t.
// Parámetro: Timer t – El timer que finalizará de contar.
// Retorna: void.
// instante final (f)
void timerStop(Timer& t)
{
    t.timerFinal = currTimeMillis();
}

// 1.1.4.6. Función timerElapsedTime
// Prototipo: long long timerElapsedTime(Timer t);
// Descripción: Retorna la cantidad de milisegundos transcurridos entre el start y el stop
// del timer t.
// Parámetro: Timer t – El timer.
// Retorna: long long – Cuántos milisegundos transcurrieron.
// retorna el tiempo transcurrido entre f e i,
// expresado en milisegundos
long long timerElapsedTime(Timer t)
{
    return (t.timerFinal - t.timerInicio);
}

#endif
