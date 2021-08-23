#include "cFecha.h"
cFecha::cFecha(int anio_, int dia_, int mes_) {
	anio = anio_;
	dia = dia_;
	mes = mes_;
}



cFecha::~cFecha() {

}

void cFecha::setHoy()
{
	time_t t = time(0);
	tm* now = localtime(&t);
	setActualizar(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
}

void cFecha::setActualizar(int dia_, int mes_, int anio_)
{

	dia = dia_;
	mes = mes_;
	anio = anio_;
}

string cFecha::to_stringFecha()
{
	string s = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
	return s;
}

void cFecha::ImprimirFecha()
{
	string s = to_stringFecha();
	cout << s << endl;
}