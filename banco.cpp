#include "banco.h"

//Declaración del método constructor por omisión.
Banco::Banco(){
    
}

// Declaración del método destructor.
Banco::~Banco(){

}

/* Método que procesa un cheque: lo quita de la pila de cheques e
imprime sus datos. Dado que se usa la plantilla de la clase Pila del
programa 5.2, se debe verificar que la pila no esté vacía antes de
quitar un cheque. */
void Banco::ProcesarCheque(){
    Cheque ChequeCli;
    
    if (!Cheques.PilaVacia()){
        Cheques - &ChequeCli; //Quita el ChequeCli de la pila de cheques
        cout<< "\n\nCHEQUE PROCESADO: "<<endl;
        ChequeCli.ImprimeDatos();
    }
    else{
        cout<<"\n\n\t\t\t\tNO HAY CHEQUES POR PROCESAR.\n\n ";
    }
}

/* Método que procesa un cheque rechazado: lo quita de la pila de
cheques rechazados e imprime sus datos. Dado que se usa la plantilla
de la clase Pila del programa 5.2, se debe verificar que la pila no
esté vacía antes de quitar un cheque rechazado. */
void Banco::ProcesarChequeR(){
    ChequeRechazado ChequeCli;
    if (!ChequesRec.PilaVacia()){
        ChequesRec - &ChequeCli; //Quita el ChequeCli de la pila de cheques rechazados
        cout<< "\n\nCHEQUE RECHAZADO PROCESADO: "<<endl;
        ChequeCli.ImprimeDatos();
    }
    else{
        cout<<"\n\n\t\t\tNO HAY CHEQUES RECHAZADOS POR PROCESAR.\n\n ";
    }
}

/* Método que registra un cheque: imprime sus datos y lo almacena en
la pila de cheques. Dado que se usa la plantilla de la clase Pila del
programa 5.2, se debe verificar que la pila no esté llena antes de
insertar un nuevo cheque. */
void Banco::RegistroCheque(Cheque ChequeCli){
    if (!Cheques.PilaLlena()){
        cout<< "\n\nREGISTRANDO EL CHEQUE: "<<endl;
        ChequeCli.ImprimeDatos();
        Cheques + ChequeCli;//Agrega el cheque recibido a la pila de cheques
    }
    else{
        cout<<"\n\n\t\t\tNO SE PUEDE REGISTRAR EL CHEQUE POR FALTA DE ESPACIO. \n\n ";
    }
}

/* Método que registra un cheque rechazado: imprime sus datos y lo
almacena en la pila de cheques rechazados. Dado que se usa la plantilla
de la clase Pila del programa 5.2, se debe verificar que la pila no
esté llena antes de insertar un nuevo cheque rechazado. */
void Banco::RegistroChequeR(ChequeRechazado ChequeCli){
    if (!ChequesRec.PilaLlena()){
        cout<< "\n\nREGISTRANDO EL CHEQUE RECHAZADO: "<<endl;
        ChequeCli.ImprimeDatos();
        ChequesRec + ChequeCli;//Agrega el cheque recibido, a la pila de cheques rechazados
    }
    else{
    cout<<"\n\n\t\tNO SE PUEDE REGISTRAR EL CHEQUE RECHAZADO POR FALTA DE ESPACIO. \n\n ";
    }
}

void Banco::respaldarCheques(Cheque cheques[], int iCheques){
    int cont;
    //Archivo logico
    fstream archivoChequesSalida("cheques.dat", ios::out | ios::binary);

    if(!archivoChequesSalida){
        cerr<<"\n\n\t\t\tNO SE PUDO ABRIR EL ARCHIVO"<<endl<<endl;
        exit(1);
    }

    for(cont = 0; cont < iCheques; cont++){
        archivoChequesSalida.write(reinterpret_cast<const char *>(&cheques[cont]), sizeof(Cheque));
    }

    archivoChequesSalida.close();
}

void Banco::respaldarChequesRec(ChequeRechazado ChequesRechazados[], int iChequesRec){
    int cont;

    //Archivo Logico
    fstream archivoChequesRecSalida("cheques_rech.dat", ios::out | ios::binary);

    if(!archivoChequesRecSalida){
        cerr<<"\n\n\t\t\tNO SE PUDO ABRIR EL ARCHIVO"<<endl<<endl;
        exit(1);
    }

    for(cont = 0; cont < iChequesRec; cont++){
        archivoChequesRecSalida.write(reinterpret_cast<const char *>(&ChequesRechazados[cont]), 
        sizeof(ChequeRechazado));
    }

}