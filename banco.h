#ifndef BANCO_H
#define BANCO_H

#include "cheque.h"
#include "cheque_rechazado.h"
#include "pila.h"

class Banco{
    public:
        Banco();
        ~Banco();
        void ProcesarCheque();
        void ProcesarChequeR();
        void RegistroCheque(Cheque);
        void RegistroChequeR(ChequeRechazado);

        //Metodo para respaldar los cheques
        void respaldarCheques(Cheque cheques[], int iCheques);
        void respaldarChequesRec(ChequeRechazado chequesrechazados[], int iChequesRec);

    private:
        Pila<Cheque> Cheques; 
        Pila<ChequeRechazado> ChequesRec;
};

#endif //BANCO_H