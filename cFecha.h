#pragma once
#include<time.h>
#include<iostream>
#include<string>

using namespace std;

class cFecha
{
private:
	int anio;
	int dia;
	int mes;

public:
	cFecha(int anio_, int dia_, int mes_);
	~cFecha();

	int getdia() { return dia; };
	int getmes() { return mes; };
	int geanio() { return anio; };

	void setHoy();
	void setActualizar(int dia, int mes, int anio);

	string to_stringFecha();
	void ImprimirFecha();

};

