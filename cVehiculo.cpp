#include "cVehiculo.h"
cVehiculo::cVehiculo(int cant_pasajeros, color color_, bool estado, string patente, int precioBase, int PrecioDia, tipo_vehiculo tipoVehiculo) {
	Cant_Pasajeros = cant_pasajeros;
	Color = color_;
	Estado = estado = false;
	Patente = patente;
	Precio_Base = precioBase;
	Precio_Dia = PrecioDia;
	Tipo_vehiculo = tipoVehiculo;
}



cVehiculo::~cVehiculo() {

}

string cVehiculo::to_string()
{
}

void cVehiculo::imprimir()
{
}

bool cVehiculo::VerificacionSeguridad(cVehiculo* Vehiculo)
{
	if (VerificarAlquiler(Vehiculo))
	{
		cout << "El vehiculo es seguro" << endl;
		Vehiculo->Estado = true;
		return true;
	}
	else
	{
		cout << "El vehiculo no es seguro" << endl;
		return false;
	}
}


void cVehiculo::VerificacionSeguridadPendiente(cVehiculo* Vehiculo) {

}


bool cVehiculo::VerificarAlquiler(cVehiculo* vehiculo) {

}