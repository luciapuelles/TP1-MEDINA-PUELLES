#include "cAlquiler.h"
#include<sstream>
#define _CRT_SECURE_NO_WARNINGS

cAlquiler::cAlquiler(cCliente* cliente, cVehiculo* vehiculo, tm* fecha_devolucion, int id)
{
	Cliente = cliente;
	Vehiculo_Alquilado = vehiculo;
	ID = id;
	MontoTotal = 0;
	this->fecha_devolucion = fecha_devolucion;

	//fecha actual
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	fecha_actual = timeinfo;

}



cAlquiler::~cAlquiler() {

}


void cAlquiler::CalcularMontoTotal() {
	int cantidad_dias_reserva = DiasdeReserva();
	MontoTotal = Vehiculo_Alquilado->getPreciobase() + (Vehiculo_Alquilado->getpreciodia() * cantidad_dias_reserva);
	cout << "El monto total a pagar es: " << MontoTotal << endl;
}


void cAlquiler::ElegirAuto() {
	if (Cliente->gettipo() == Vehiculo_Alquilado->gettipo()&& Vehiculo_Alquilado->getEstado() == false && Vehiculo_Alquilado->getverificado() == true)
		Vehiculo_Alquilado->setestado(true);

}


void cAlquiler::FinalizarAlquiler() {
	fecha_actual->tm_mon = fecha_devolucion->tm_mon;
	fecha_actual->tm_mday = fecha_devolucion->tm_mday;
	fecha_actual->tm_year = fecha_devolucion->tm_year;//lo igualo para probar que funcione
	if (fecha_actual->tm_mday == fecha_devolucion->tm_mday && fecha_actual->tm_mon == fecha_devolucion->tm_mon && fecha_actual->tm_year == fecha_devolucion->tm_year)
	{
		cout << "ALQUILER FINALIZADO\n" << endl;
		Vehiculo_Alquilado->setestado(false);
		Vehiculo_Alquilado->VerificacionSeguridadPendiente();
	}
}

int cAlquiler::DiasdeReserva()
{
		int diasreserva;
		int dia = fecha_actual->tm_mday;
		int mes = fecha_actual->tm_mon+1;
		int anio = fecha_actual->tm_year+1900;

		//calculamos los dias desde el inicio de la era hasta esa fecha en las dos ocasiones y luego se restan 
		long int dias1 = (anio * 365) + (mes * 30) + dia;
		long int dias2 = ((fecha_devolucion->tm_year) * 365) + ((fecha_devolucion->tm_mon)*30) + fecha_devolucion->tm_mday;
		diasreserva = dias2 - dias1;
		cout << "El cliente alquila el auto por " << diasreserva << " dias" << endl;
		return diasreserva;
	
}

void cAlquiler::Ejecutar_Alquiler()
{
	ElegirAuto();
	CalcularMontoTotal();
	Cliente->Pagar(this);
	FinalizarAlquiler();
}



string cAlquiler::To_string()
{
	stringstream ss;

	ss << Cliente->to_string() << endl;
	ss << "Vehiculo: " << Vehiculo_Alquilado << endl;
	//ss << "Inicio de reserva del vehiculo: " << to_string(fecha_actual.tm_mday) + "/" + to_string(fecha_actual.tm_mon) + "/" + to_string(fecha_actual.tm_year) << endl;
	//ss << "Final de incio de reserva del vehiculo: " << to_string(fecha_devolucion.tm_mday) + "/" + to_string(fecha_devolucion.tm_mon) + "/" + to_string(fecha_devolucion.tm_year) << endl;
	ss << "ID del Alquiler: " << ID << endl;
	ss << "Monto total: " << MontoTotal << endl;

	return ss.str();
	
}

void cAlquiler::imprimir()
{
	string imprimir2 = To_string();
	cout << imprimir2;
}
