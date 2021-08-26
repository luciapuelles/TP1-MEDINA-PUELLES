#pragma once
#include "cCliente.h"
#include "cVehiculo.h"
#include "cFecha.h"
class cAlquiler;


class cAlquiler
{
private:
	cCliente* Cliente;
	cVehiculo* Vehiculo_Alquilado;
	cFecha* fecha_actual;
	cFecha* Fecha_Devolucion;
	int ID;
	int MontoTotal;

public:
	cAlquiler(cCliente* cliente, cVehiculo* vehiculo, int id);
	~cAlquiler();


	int CalcularMontoTotal();
	void ElegirAuto();
	void FinalizarAlquiler();
	int DiasdeReserva();

	
	int getmontototal() { return MontoTotal; };
	int getid() { return ID; };
	string getclientename() { return Cliente->getNombreyapellido(); };
	string getstringcliente() { return Cliente->to_string(); };
	string to_string();
	void imprimir();

};

