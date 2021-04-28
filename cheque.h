#ifndef CHEQUE_H
#define CHEQUE_H

#include <string.h>//Para hacer uso del metodo strcpy()

#include <iostream>
#include <fstream>

using namespace std;

//Esta es la SuperClase
class Cheque{
    public:
        Cheque();//Constructor
        Cheque(int, char [], int, double);//Constructor parametrizado
        ~Cheque();//Destructor
        void ImprimeDatos();

        //Metodos getters y setters
        void establecerNumero(int Numero);
        int obtenerNumero() const;

        void establecerCuentaADepositar(int CuentaADepositar);
        int obtenerCuentaADepositar() const;

        void establecerBanco(const string banco);
        string obtenerBanco() const;

        void establecerMonto(double Monto);
        double obtenerMonto() const;

    private:
        int Numero, CuentaADepositar;
        char Banco[10];
        double Monto;
};

#endif //CHEQUE_H