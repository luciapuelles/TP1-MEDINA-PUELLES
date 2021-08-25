#include "cAlquiler.h"
cAlquiler::cAlquiler(cCliente* cliente, cVehiculo* vehiculo, int id) {
	Cliente = cliente = NULL;
	Vehiculo_Alquilado = vehiculo = NULL;
	Fecha_Devolucion =  NULL;
	fecha_actual->setHoy();
	ID = id;
	MontoTotal = 0;
}



cAlquiler::~cAlquiler() {
	if (Cliente != NULL) delete Cliente;
	if (Vehiculo_Alquilado != NULL) delete Vehiculo_Alquilado;
	if (Fecha_Devolucion != NULL) delete Fecha_Devolucion;
}





int cAlquiler::CalcularMontoTotal() {
	int cantidad_dias_reserva = DiasdeReserva();
	
	MontoTotal = (Vehiculo_Alquilado->getPreciobase() + Vehiculo_Alquilado->getpreciodia()) * cantidad_dias_reserva;
	
	return MontoTotal;
}


void cAlquiler::ElegirAuto() {
	
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
