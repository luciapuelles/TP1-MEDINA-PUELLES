#include "cAlquiler.h"
cAlquiler::cAlquiler(cCliente* cliente, cVehiculo* vehiculo, cFecha* fecha, int id) {
	Cliente = cliente = NULL;
	Vehiculo_Alquilado = vehiculo = NULL;
	Fecha_Devolucion = fecha = NULL;
	ID = id;
	MontoTotal = 0;
}



cAlquiler::~cAlquiler() {
	if (Cliente != NULL) delete Cliente;
	if (Vehiculo_Alquilado != NULL) delete Vehiculo_Alquilado;
}





int cAlquiler::CalcularMontoTotal() {


}


void cAlquiler::ElegirAuto() {

}


void cAlquiler::FinalizarAlquiler() {

}