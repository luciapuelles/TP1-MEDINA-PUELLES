#pragma once
#include "cFecha.h"
#include "cAlquiler.h"
#include "tipo.h"
#include<string>
#include<iostream> 

using namespace std;
class cCliente
{
private:
	//Atributos del cliente

	string DNI;
	string Email;''
	cFecha* Fecha_Nacimiento;
	string NombreyApellido;
	int Telefono;
	tipo Tipo_Vehiculo;
	bool Estado_pagado; // true : pagado , false: no esta pagado

public:

	//Inicializamos los atributos
	cCliente(string dni, string email, string NombreyApe, int telf, tipo tipo_);
	//Verificamos que la fecha no sea NULL
	~cCliente();

	//Verifica que el Alquiler sea del cliente y si es cambia el estado a "pagado"
	void Pagar(cAlquiler* alquiler);

	//getters de los atributos
	string getdni() { return DNI; };
	tipo gettipo() { return Tipo_Vehiculo; };
	string getNombreyapellido() { return NombreyApellido; };
	bool getEstado() { return Estado_pagado; };

	//imprimimos
	string to_string();
	void imprimir();
};

