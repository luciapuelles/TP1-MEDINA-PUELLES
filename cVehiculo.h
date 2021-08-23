#pragma once
#include <iostream>
#include <string>
#include "cEnum.h"
using namespace std;
class cVehiculo
{
	private:
		int Cant_Pasajeros;
		float Precio_Base;
		float Precio_Dia;
		bool Estado;
		bool Verificado;
		string Patente;
		Color color; 
		Tipo_Vehiculo tipo;


	public:
		cVehiculo(Color color_, string patente, float precioDia, Tipo_Vehiculo tipo);
		~cVehiculo();

		void VerificacionSeguridad();
		void VerificacionSeguridadPendiente();
		bool VerificarAlquiler();

		void setestado(bool estado_) { Estado = estado_; }
		int getCantPasajeros() { return Cant_Pasajeros; };
		Color getcolor() { return color; };
		bool getEstado() { return Estado; };
		string getpatente() { return Patente; };
		float getPreciobase() { return Precio_Base; };
		float getpreciodia() { return Precio_Dia; };
		Tipo_Vehiculo gettipo() { return tipo; };

		string To_String();
		string To_string_Vehiculo();
		string To_String_Color();
		void imprimir();


};

