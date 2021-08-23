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
	

	
	

}


void cAlquiler::ElegirAuto() {

}


void cAlquiler::FinalizarAlquiler() {

}

int cAlquiler::DiasdeReserva()
{
	
		//inicializo 3 variables para calcular la diferencia entre las dos fechas
		int dias1, dias2, diasreserva;
		//calculamos los dias desde el inicio de la era hasta esa fecha en las dos ocasiones y luego se restan 
		dias1 = ((fecha_actual->geanio() * 365) + ((fecha_actual->getmes() - 1) * 30) + fecha_actual->getdia());
		dias2 = ((Fecha_Devolucion->geanio() * 365) + ((Fecha_Devolucion->getmes() - 1) * 30) + Fecha_Devolucion->getdia());

		diasreserva = dias2 - dias1;

		return diasreserva;
	
}
