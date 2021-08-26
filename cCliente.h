#pragma once
#include "cFecha.h"
#include "cAlquiler.h"
#include"cEnum.h"
#include<string>
#include<iostream> 


using namespace std;
class cCliente
{ 
private:
	//Atributos del cliente

	string DNI;
	string Email;
	cFecha* Fecha_Nacimiento;
	string NombreyApellido;
	int Telefono;
	Tipo_Vehiculo tipo;
	bool Estado_pagado; // true : pagado , false: no esta pagado

public:

	//Inicializamos los atributos
	cCliente(string dni, string email, string NombreyApe, int telf, Tipo_Vehiculo tipo_);
	//Verificamos que la fecha no sea NULL
	~cCliente();

	//Verifica que el Alquiler sea del cliente y si es cambia el estado a "pagado"
	void Pagar(cAlquiler* alquiler);

	//getters de los atributos
	string getdni() { return DNI; };
	Tipo_Vehiculo gettipo() { return tipo; };
	string getNombreyapellido() { return NombreyApellido; };
	bool getEstado() { return Estado_pagado; };
	

	//imprimimos
	string to_string();
	void imprimir();
};

