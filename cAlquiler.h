#pragma once
#include "cVehiculo.h"
#include "cFecha.h"
#include "cCliente.h"
#include <ctime>

class cAlquiler
{
private:
	cCliente* Cliente;
	cVehiculo* Vehiculo_Alquilado;
	tm* fecha_actual;
	tm* fecha_devolucion;
	int ID;
	int MontoTotal;

public:
	cAlquiler(cCliente* cliente, cVehiculo* vehiculo, tm* fecha_devolucion, int id);
	~cAlquiler();


	void CalcularMontoTotal();
	void ElegirAuto();
	void FinalizarAlquiler();
	int DiasdeReserva();
	
	int getmontototal() { return MontoTotal; };
	int getid() { return ID; };
	string getclientename() { return Cliente->getNombreyapellido(); };
	string getstringcliente() { return Cliente->to_string(); };
	bool getestadocliente() { return Cliente->getEstado(); };
	string To_string();
	void imprimir();

};


