#include "cAlquiler.h"
#include<sstream>

cAlquiler::cAlquiler(cCliente* cliente_, cVehiculo* vehiculo,cFecha* fecha, int id) {
	this->cliente = cliente_;
	Vehiculo_Alquilado = vehiculo;
	Fecha_Devolucion = fecha;
	fecha_actual->setHoy();
	ID = id;
	MontoTotal = 0;
}



cAlquiler::~cAlquiler() {
	if (cliente != NULL) delete cliente;
	if (Vehiculo_Alquilado != NULL) delete Vehiculo_Alquilado;
	if (Fecha_Devolucion != NULL) delete Fecha_Devolucion;
}


float cAlquiler::CalcularMontoTotal() {
	int cantidad_dias_reserva = DiasdeReserva();
	
	MontoTotal = (Vehiculo_Alquilado->getPreciobase() + Vehiculo_Alquilado->getpreciodia()) * cantidad_dias_reserva;
	
	return MontoTotal;
}


void cAlquiler::ElegirAuto() {
	if (cliente->gettipo() == Vehiculo_Alquilado->gettipo()) {
		if (cliente->gettipo() == Tipo_Vehiculo::Camioneta && Vehiculo_Alquilado->getEstado() == false && Vehiculo_Alquilado->getverificado() == true)
		{
			Vehiculo_Alquilado->setestado(true);
		}
	}
}


void cAlquiler::FinalizarAlquiler() {
	if (fecha_actual->getdia() == Fecha_Devolucion->getdia() && fecha_actual->getmes() == Fecha_Devolucion->getmes() && fecha_actual->getanio() == Fecha_Devolucion->getanio())
	{
		cout << "ALQUILER FINALIZADO\n" << endl;
		Vehiculo_Alquilado->setestado(false);
		Vehiculo_Alquilado->VerificacionSeguridadPendiente();
	}
}

int cAlquiler::DiasdeReserva()
{
	
		//inicializo 3 variables para calcular la diferencia entre las dos fechas
		int dias1, dias2, diasreserva;
		//calculamos los dias desde el inicio de la era hasta esa fecha en las dos ocasiones y luego se restan 
		dias1 = ((fecha_actual->getanio() * 365) + ((fecha_actual->getmes() - 1) * 30) + fecha_actual->getdia());
		dias2 = ((Fecha_Devolucion->getanio() * 365) + ((Fecha_Devolucion->getmes() - 1) * 30) + Fecha_Devolucion->getdia());

		diasreserva = dias2 - dias1;

		return diasreserva;
	
}

string cAlquiler::getclientename()
{
	return cliente->getNombreyapellido(); 
}
string cAlquiler::getstringcliente()
{
	return  cliente->to_string();

}

bool cAlquiler::getestadocliente()
{
	return cliente->getEstado();
}

string cAlquiler::to_string()
{
	stringstream ss;

	ss << cliente->to_string() << endl;
	ss << "Vehiculo: " << Vehiculo_Alquilado << endl;
	ss << "Inicio de incio de reserva del vehiculo: " << fecha_actual->to_stringFecha() << endl;
	ss << "Final de incio de reserva del vehiculo: " << Fecha_Devolucion->to_stringFecha() << endl;
	ss << "ID del Alquiler: " << ID << endl;
	ss << "Monto total: " << MontoTotal << endl;

	return ss.str();
	
}

void cAlquiler::imprimir()
{
	string imprimir2 = to_string();
	cout << imprimir2;
}
