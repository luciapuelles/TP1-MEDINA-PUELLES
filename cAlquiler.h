#pragma once
#include "cCliente.h"
#include "cVehiculo.h"
#include "cFecha.h"

class cAlquiler
{
private:
	cCliente* Cliente;
	cVehiculo* Vehiculo_Alquilado;
	cFecha* Fecha_Devolucion;
	int ID;
	int MontoTotal;

public:
	cAlquiler(cCliente* cliente, cVehiculo* vehiculo, cFecha* fecha, int id);
	~cAlquiler();


	int CalcularMontoTotal();
	void ElegirAuto();
	void FinalizarAlquiler();

	int setmontototal(int num_) { MontoTotal = num_; }
	int getmontototal() { return MontoTotal; };
	int getid() { return ID; };
	string getclientename() { return Cliente->getNombreyapellido(); };

};

