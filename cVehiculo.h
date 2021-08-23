#pragma once
#include<string>
#include<iostream>
#include"color.h"
#include"tipo_vehiculo.h"

using namespace std;

class cVehiculo
{
private:
	int Cant_Pasajeros;
	color Color;
	bool Estado;
	string Patente;
	int Precio_Base;
	int Precio_Dia;
	tipo_vehiculo Tipo_vehiculo;

public:
	cVehiculo(int cant_pasajeros, color color_, bool estado, string patente, int precioBase, int PrecioDia, tipo_vehiculo tipoVehiculo);
	~cVehiculo();

	void VerificacionSeguridad(cVehiculo* Vehiculo);
	void VerificacionSeguridadPendiente(cVehiculo* Vehiculo);
	bool VerificarAlquiler(cVehiculo* vehiculo);

	int getCantPasajeros() { return Cant_Pasajeros; };
	color getcolor() { return Color; };
	bool getEstado() { return Estado; };
	void setestado(bool estado_) { Estado = estado_; }
	string getpatente() { return Patente; };
	int getPreciobase() { return Precio_Base; };
	int getpreciodia() { return Precio_Dia; };
	tipo_vehiculo gettipo() { return Tipo_vehiculo; };

	string to_string();
	void imprimir();
};

