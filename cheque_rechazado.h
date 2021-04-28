#ifndef CHEQUE_RECHAZADO_H
#define CHEQUE_RECHAZADO_H

#include "cheque.h"
//#define MAX 3//Maximo 3 cheques en la Pila

//Esta es la SubClase (La cual hereda los atributos de la clase Cheque)
class ChequeRechazado : public Cheque{//Esta heredando de manera publica
    public:
        ChequeRechazado();
        ChequeRechazado(int, char[], int, double);
        ~ChequeRechazado();
        void ImprimeDatos();

        void establecerCargo(double Monto);
        double obtenerCargo() const;

    private:
        double Cargo;
};

#endif //CHEQUE_RECHAZADO_H
