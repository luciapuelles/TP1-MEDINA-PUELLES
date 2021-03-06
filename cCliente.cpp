#include "cCliente.h"
#include<sstream>

cCliente::cCliente(string dni, string email, string NombreyApe, int telf, tipo tipo_) {
	DNI = dni;
	Email = email;
	Fecha_Nacimiento = NULL;
	NombreyApellido = NombreyApe;
	Telefono = telf;
	Tipo_Vehiculo = tipo_;
	Estado_pagado = false;
}

cCliente::~cCliente() {
	if (Fecha_Nacimiento != NULL) delete Fecha_Nacimiento;
}

void cCliente::Pagar(cAlquiler* alquiler) {

	if (alquiler->getclientename() == getNombreyapellido())
	{
		getEstado() == true;
		cout << "PAGADO\n" << endl;
	}
	else
	{
		getEstado() == false;
		cout << "NO ESTA PAGO\n" << endl;
	}
}

string cCliente::to_string()
{
	stringstream ss;

	ss << "CLIENTE: " << endl;

	ss << "DNI: " << DNI << endl;
	ss << "Email: " << Email << endl;
	ss << "Fecha de Nacimiento:  " << Fecha_Nacimiento->to_stringFecha() << endl;
	ss << "Nombre y Apellido: " << NombreyApellido << endl;
	ss << "Telefono: " << Telefono << endl;
	//ss << "Tipo de vehiculo: " << Tipo_Vehiculo << endl;

	return ss.str();
}

void cCliente::imprimir()
{
	string imprimir2 = to_string();
	cout << imprimir2;
}