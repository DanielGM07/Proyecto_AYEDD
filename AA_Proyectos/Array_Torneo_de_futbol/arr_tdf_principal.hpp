#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "../../biblioteca/funciones/strings.hpp"
#include "../../biblioteca/funciones/tokens.hpp"
#include "../../biblioteca/tads/parte1/Coll.hpp"
using namespace std;

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

struct REquipo
{
	Equipo equipo;
	int acum;
};

struct REstadio
{
	string estadio;
	int partidosJugados;
	int partidosEmpatados;
};

Resultado resultado(int idEq1,int idEq2,int codRes,string estadio)
{
	Resultado a;
	a.idEq1 = idEq1;
	a.idEq2 = idEq2;
	a.codRes = codRes;
	strcpy(a.estadio,estadio.c_str());
	return a;
}

Equipo equipo(int idEq,string nombre,int puntos)
{
	Equipo a;
	a.idEq = idEq;
	strcpy(a.nombre,nombre.c_str());
	a.puntos = puntos;
	return a;
}

REquipo rEquipo(Equipo equipo,int acum)
{
	REquipo b;
	b.equipo = equipo;
	b.acum = acum;
	return b;
}

REstadio rEstadio(string estadio,int partidosJugados,int partidosEmpatados)
{
	REstadio a;
	a.estadio = estadio;
	a.partidosJugados = partidosJugados;
	a.partidosEmpatados = partidosEmpatados;
	return a;
}

#endif
