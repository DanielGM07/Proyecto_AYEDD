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

struct RProducto
{
	Producto prod;
	int cantDemanda;
};

struct RRubro
{
	Rubro rubro;
	double ahorro;
};

string productoToString(Producto x)
{
	char sep = 1;
	string sIdProd=to_string(x.idProd);
	string sDescr=x.descr;
	string sPrecio=to_string(x.precio);
	string sIdRub=to_string(x.idRub);
	return sIdProd+sep+sDescr+sep+sPrecio+sep+sIdRub;
}

Producto productoFromString(string s)
{
	char sep = 1;
	Producto x;
	string t0 = getTokenAt(s,sep,0);
	x.idProd=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.descr,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.precio=stod(t2);
	string t3 = getTokenAt(s,sep,3);
	x.idRub=stoi(t3);
	return x;
}

string productoToDebug(Producto x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idProd;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.precio;
	sout << ",";
	sout << x.idRub;
	sout<< "]";
	return sout.str();
}

string productoToDebug(string mssg,Producto x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idProd;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.precio;
	sout << ",";
	sout << x.idRub;
	sout<< "]";
	return sout.str();
}

Producto producto(int idProd,string descr,double precio,int idRub)
{
	Producto a;
	a.idProd = idProd;
	strcpy(a.descr,descr.c_str());
	a.precio = precio;
	a.idRub = idRub;
	return a;
}

bool productoEquals(Producto a,Producto b)
{
	if(a.idProd!=b.idProd) return false;
	if(a.precio!=b.precio) return false;
	if(a.idRub!=b.idRub) return false;
	return true;
}

string rubroToString(Rubro x)
{
	char sep = 2;
	string sIdRub=to_string(x.idRub);
	string sDescr=x.descr;
	string sPromo=to_string(x.promo);
	return sIdRub+sep+sDescr+sep+sPromo;
}

Rubro rubroFromString(string s)
{
	char sep = 2;
	Rubro x;
	string t0 = getTokenAt(s,sep,0);
	x.idRub=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	strcpy(x.descr,t1.c_str());
	string t2 = getTokenAt(s,sep,2);
	x.promo=stod(t2);
	return x;
}

string rubroToDebug(Rubro x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idRub;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.promo;
	sout<< "]";
	return sout.str();
}

string rubroToDebug(string mssg,Rubro x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idRub;
	sout << ",";
	sout << x.descr;
	sout << ",";
	sout << x.promo;
	sout<< "]";
	return sout.str();
}

Rubro rubro(int idRub,string descr,double promo)
{
	Rubro a;
	a.idRub = idRub;
	strcpy(a.descr,descr.c_str());
	a.promo = promo;
	return a;
}

bool rubroEquals(Rubro a,Rubro b)
{
	if(a.idRub!=b.idRub) return false;
	if(a.promo!=b.promo) return false;
	return true;
}

string rProductoToString(RProducto x)
{
	char sep = 3;
	string sProd=productoToString(x.prod);
	string sCantDemanda=to_string(x.cantDemanda);
	return sProd+sep+sCantDemanda;
}

RProducto rProductoFromString(string s)
{
	char sep = 3;
	RProducto x;
	string t0 = getTokenAt(s,sep,0);
	x.prod=productoFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.cantDemanda=stoi(t1);
	return x;
}

string rProductoToDebug(RProducto x)
{
	stringstream sout;
	sout<< "[";
	sout << productoToDebug(x.prod);
	sout << ",";
	sout << x.cantDemanda;
	sout<< "]";
	return sout.str();
}

string rProductoToDebug(string mssg,RProducto x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << productoToDebug(x.prod);
	sout << ",";
	sout << x.cantDemanda;
	sout<< "]";
	return sout.str();
}

RProducto rProducto(Producto prod,int cantDemanda)
{
	RProducto a;
	a.prod = prod;
	a.cantDemanda = cantDemanda;
	return a;
}

bool rProductoEquals(RProducto a,RProducto b)
{
	if(!productoEquals(a.prod,b.prod)) return false;
	if(a.cantDemanda!=b.cantDemanda) return false;
	return true;
}

string rRubroToString(RRubro x)
{
	char sep = 4;
	string sRubro=rubroToString(x.rubro);
	string sAhorro=to_string(x.ahorro);
	return sRubro+sep+sAhorro;
}

RRubro rRubroFromString(string s)
{
	char sep = 4;
	RRubro x;
	string t0 = getTokenAt(s,sep,0);
	x.rubro=rubroFromString(t0);
	string t1 = getTokenAt(s,sep,1);
	x.ahorro=stod(t1);
	return x;
}

string rRubroToDebug(RRubro x)
{
	stringstream sout;
	sout<< "[";
	sout << rubroToDebug(x.rubro);
	sout << ",";
	sout << x.ahorro;
	sout<< "]";
	return sout.str();
}

string rRubroToDebug(string mssg,RRubro x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << rubroToDebug(x.rubro);
	sout << ",";
	sout << x.ahorro;
	sout<< "]";
	return sout.str();
}

RRubro rRubro(Rubro rubro,double ahorro)
{
	RRubro b;
	b.rubro = rubro;
	b.ahorro = ahorro;
	return b;
}

bool rRubroEquals(RRubro a,RRubro b)
{
	if(!rubroEquals(a.rubro,b.rubro)) return false;
	if(a.ahorro!=b.ahorro) return false;
	return true;
}

#endif
