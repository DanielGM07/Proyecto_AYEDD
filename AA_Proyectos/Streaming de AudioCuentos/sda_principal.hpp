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

struct Reproduccion
{
	int idUsuario;
	int idCuento;
	int fecha;
	int minutos;
};

struct Cuento
{
	int idCuento;
	int idRelator;
	int idAutor;
	char titulo[50];
	int duracion;
};

struct Relator
{
	int idRelator;
	char nombre[50];
};

// Reproduccion no se wrappea porque es el archivo de novedades

struct RCuento
{
	Cuento c;
    int cont100;
	int cont75a100;
	int cont50a75;
	int cont25a50;
	int cont0a25;
};

struct RRelator
{
	Relator rel;
	int cantRep;
};

string reproduccionToString(Reproduccion x)
{
	char sep = 1;
	string sIdUsuario=to_string(x.idUsuario);
	string sIdCuento=to_string(x.idCuento);
	string sFecha=to_string(x.fecha);
	string sMinutos=to_string(x.minutos);
	return sIdUsuario+sep+sIdCuento+sep+sFecha+sep+sMinutos;
}

Reproduccion reproduccionFromString(string s)
{
	char sep = 1;
	Reproduccion x;
	string t0 = getTokenAt(s,sep,0);
	x.idUsuario=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idCuento=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.fecha=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.minutos=stoi(t3);
	return x;
}

string reproduccionToDebug(Reproduccion x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idUsuario;
	sout << ",";
	sout << x.idCuento;
	sout << ",";
	sout << x.fecha;
	sout << ",";
	sout << x.minutos;
	sout<< "]";
	return sout.str();
}

string reproduccionToDebug(string mssg,Reproduccion x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idUsuario;
	sout << ",";
	sout << x.idCuento;
	sout << ",";
	sout << x.fecha;
	sout << ",";
	sout << x.minutos;
	sout<< "]";
	return sout.str();
}

Reproduccion reproduccion(int idUsuario,int idCuento,int fecha,int minutos)
{
	Reproduccion a;
	a.idUsuario = idUsuario;
	a.idCuento = idCuento;
	a.fecha = fecha;
	a.minutos = minutos;
	return a;
}

bool reproduccionEquals(Reproduccion a,Reproduccion b)
{
	if(a.idUsuario!=b.idUsuario) return false;
	if(a.idCuento!=b.idCuento) return false;
	if(a.fecha!=b.fecha) return false;
	if(a.minutos!=b.minutos) return false;
	return true;
}

string cuentoToString(Cuento x)
{
	char sep = 2;
	string sIdCuento=to_string(x.idCuento);
	string sIdRelator=to_string(x.idRelator);
	string sIdAutor=to_string(x.idAutor);
	string sTitulo=x.titulo;
	string sDuracion=to_string(x.duracion);
	return sIdCuento+sep+sIdRelator+sep+sIdAutor+sep+sTitulo+sep+sDuracion;
}

Cuento cuentoFromString(string s)
{
	char sep = 2;
	Cuento x;
	string t0 = getTokenAt(s,sep,0);
	x.idCuento=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idRelator=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.idAutor=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	strcpy(x.titulo,t3.c_str());
	string t4 = getTokenAt(s,sep,4);
	x.duracion=stoi(t4);
	return x;
}

string cuentoToDebug(Cuento x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idCuento;
	sout << ",";
	sout << x.idRelator;
	sout << ",";
	sout << x.idAutor;
	sout << ",";
	sout << x.titulo;
	sout << ",";
	sout << x.duracion;
	sout<< "]";
	return sout.str();
}

string cuentoToDebug(string mssg,Cuento x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idCuento;
	sout << ",";
	sout << x.idRelator;
	sout << ",";
	sout << x.idAutor;
	sout << ",";
	sout << x.titulo;
	sout << ",";
	sout << x.duracion;
	sout<< "]";
	return sout.str();
}

Cuento cuento(int idCuento,int idRelator,int idAutor,string titulo,int duracion)
{
	Cuento a;
	a.idCuento = idCuento;
	a.idRelator = idRelator;
	a.idAutor = idAutor;
	strcpy(a.titulo,titulo.c_str());
	a.duracion = duracion;
	return a;
}

bool cuentoEquals(Cuento a,Cuento b)
{
	if(a.idCuento!=b.idCuento) return false;
	if(a.idRelator!=b.idRelator) return false;
	if(a.idAutor!=b.idAutor) return false;
	if(a.duracion!=b.duracion) return false;
	return true;
}

string relatorToString(Relator x)
{
	char sep = 3;
	string sIdRelator=to_string(x.idRelator);
	string sNombre=x.nombre;
	return sIdRelator+sep+sNombre;
}

Relator relatorFromString(string s)
{
	char sep = 3;
	Relator x;
	string t0 = getTokenAt(s,sep,0);
	x.idRelator=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.nombre,t1.c_str());
	return x;
}

string relatorToDebug(Relator x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idRelator;
	sout << ",";
	sout << x.nombre;
	sout<< "]";
	return sout.str();
}

string relatorToDebug(string mssg,Relator x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idRelator;
	sout << ",";
	sout << x.nombre;
	sout<< "]";
	return sout.str();
}

Relator relator(int idRelator,string nombre)
{
	Relator a;
	a.idRelator = idRelator;
	strcpy(a.nombre,nombre.c_str());
	return a;
}

bool relatorEquals(Relator a,Relator b)
{
	if(a.idRelator!=b.idRelator) return false;
	return true;
}

string rCuentoToString(RCuento x)
{
	char sep = 1;
	string sC=cuentoToString(x.c);
	string sCont100=to_string(x.cont100);
	string sCont75a100=to_string(x.cont75a100);
	string sCont50a75=to_string(x.cont50a75);
	string sCont25a50=to_string(x.cont25a50);
	string sCont0a25=to_string(x.cont0a25);
	return sC+sep+sCont100+sep+sCont75a100+sep+sCont50a75+sep+sCont25a50+sep+sCont0a25;
}

RCuento rCuentoFromString(string s)
{
	char sep = 1;
	RCuento x;
	string t0 = getTokenAt(s,sep,0);
	x.c=cuentoFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.cont100=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.cont75a100=stoi(t2);
	string t3 = getTokenAt(s,sep,3);
	x.cont50a75=stoi(t3);
	string t4 = getTokenAt(s,sep,4);
	x.cont25a50=stoi(t4);
	string t5 = getTokenAt(s,sep,5);
	x.cont0a25=stoi(t5);
	return x;
}

string rCuentoToDebug(RCuento x)
{
	stringstream sout;
	sout<< "[";
	sout << cuentoToDebug(x.c);
	sout << ",";
	sout << x.cont100;
	sout << ",";
	sout << x.cont75a100;
	sout << ",";
	sout << x.cont50a75;
	sout << ",";
	sout << x.cont25a50;
	sout << ",";
	sout << x.cont0a25;
	sout<< "]";
	return sout.str();
}

string rCuentoToDebug(string mssg,RCuento x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << cuentoToDebug(x.c);
	sout << ",";
	sout << x.cont100;
	sout << ",";
	sout << x.cont75a100;
	sout << ",";
	sout << x.cont50a75;
	sout << ",";
	sout << x.cont25a50;
	sout << ",";
	sout << x.cont0a25;
	sout<< "]";
	return sout.str();
}

RCuento rCuento(Cuento c,int cont100,int cont75a100,int cont50a75,int cont25a50,int cont0a25)
{
	RCuento a;
	a.c = c;
	a.cont100 = cont100;
	a.cont75a100 = cont75a100;
	a.cont50a75 = cont50a75;
	a.cont25a50 = cont25a50;
	a.cont0a25 = cont0a25;
	return a;
}

bool rCuentoEquals(RCuento a,RCuento b)
{
	if(!cuentoEquals(a.c,b.c)) return false;
	if(a.cont100!=b.cont100) return false;
	if(a.cont75a100!=b.cont75a100) return false;
	if(a.cont50a75!=b.cont50a75) return false;
	if(a.cont25a50!=b.cont25a50) return false;
	if(a.cont0a25!=b.cont0a25) return false;
	return true;
}

string rRrelatorToString(RRelator x)
{
	char sep = 5;
	string sRel=relatorToString(x.rel);
	string sCantRep=to_string(x.cantRep);
	return sRel+sep+sCantRep;
}

RRelator rRrelatorFromString(string s)
{
	char sep = 5;
	RRelator x;
	string t0 = getTokenAt(s,sep,0);
	x.rel=relatorFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.cantRep=stoi(t1);
	return x;
}

string rRrelatorToDebug(RRelator x)
{
	stringstream sout;
	sout<< "[";
	sout << relatorToDebug(x.rel);
	sout << ",";
	sout << x.cantRep;
	sout<< "]";
	return sout.str();
}

string rRrelatorToDebug(string mssg,RRelator x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << relatorToDebug(x.rel);
	sout << ",";
	sout << x.cantRep;
	sout<< "]";
	return sout.str();
}

RRelator rRrelator(Relator rel,int cantRep)
{
	RRelator a;
	a.rel = rel;
	a.cantRep = cantRep;
	return a;
}

bool rRrelatorEquals(RRelator a,RRelator b)
{
	if(!relatorEquals(a.rel,b.rel)) return false;
	if(a.cantRep!=b.cantRep) return false;
	return true;
}

#endif
