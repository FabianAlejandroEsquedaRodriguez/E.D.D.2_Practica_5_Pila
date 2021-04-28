#include "cheque_rechazado.h"

/* Declaración del método constructor por omisión. */
ChequeRechazado::ChequeRechazado(){}

/* Declaración del método constructor con parámetros. Invoca al
➥constructor de la clase base. */
ChequeRechazado::ChequeRechazado (int NumCta, char *NomBco, int Cta, double Mon): 
                                    Cheque(NumCta, NomBco, Cta, Mon){
    /* Calcula el valor del atributo Cargo como el 10% del Monto del
    ➥cheque. */
    Cargo= Mon*0.10;
}

/* Declaración del método destructor. */
ChequeRechazado::~ChequeRechazado(){}

/* Método que despliega los valores de los atributos de un cheque
➥rechazado. */
void ChequeRechazado::ImprimeDatos(){
    Cheque::ImprimeDatos();
    cout<<"\nCargo por rechazo: " <<Cargo<<endl;
}

void ChequeRechazado::establecerCargo(double Monto){
    Cargo = Monto * 0.10;
}
double ChequeRechazado::obtenerCargo() const{
    return Cargo;
}