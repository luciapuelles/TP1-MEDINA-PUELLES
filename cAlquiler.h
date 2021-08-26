#pragma once
#include "cCliente.h"
#include "cVehiculo.h"
#include "cFecha.h"

class cAlquiler
{
private:

	cCliente* cliente;
	cVehiculo* Vehiculo_Alquilado;
	cFecha* fecha_actual;
	cFecha* Fecha_Devolucion;
	int ID;
	float MontoTotal;

public:
	cAlquiler(cCliente* cliente_, cVehiculo* vehiculo,cFecha* fecha, int id);
	~cAlquiler();


	float CalcularMontoTotal();
	void ElegirAuto();
	void FinalizarAlquiler();
	int DiasdeReserva();

	
	float getmontototal() { return MontoTotal; };
	int getid() { return ID; };
	string getclientename();
	string getstringcliente();
	bool getestadocliente();
	string to_string();
	void imprimir();

};

