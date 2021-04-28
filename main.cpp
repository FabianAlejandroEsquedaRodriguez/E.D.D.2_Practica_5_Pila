/*
Equipo #3:

-> Domínguez Martínez Edder Emmanuel
-> Esqueda Rodríguez, Fabián Alejandro.
-> Godoy Rodríguez, Berenice.
-> Gómez Jiménez, Ángel Armando.
-> Gómez Ramírez, Eduardo Fabián.

Sección: D05
Calendario: 2021-A
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include "banco.h"

using namespace std;

void archivoChequesEntrada();
void archivoChequesRecEntrada();

//Variables Globales
size_t op, iCheques = 0, iChequesRec = 0;
Banco MiBanco;

Cheque cheques[3];//Arreglo de cheques
ChequeRechazado chequesRechazados[3];//Arreglo de cheques rechazados

int main(){
    system("color F1");
    system("cls");
    
    //Se llama a la funcion, y aqui se hace la validacion de si el archivo se puedo abrir
    //Si se puso abrir, recupera la informacion. Si no, s eva directo al menu de opciones.
    archivoChequesEntrada();
    
    //Se llama a la funcion, y aqui se hace la validacion de si el archivo se puedo abrir
    //Si se puso abrir, recupera la informacion. Si no, s eva directo al menu de opciones.
    archivoChequesRecEntrada();

    
    //Menu de opciones
    do{
        cout<<"\t\t\tMENU - ADMINISTRACION DE CHEQUES"<<endl<<endl;

        cout<<"1) REGISTRAR CHEQUE (INSERTAR)"<<endl;
        cout<<"2) PROCESAR CHEQUE (ELIMINAR)"<<endl;
        cout<<"3) REGISTRAR CHEQUE RECHAZADO (INSERTAR)"<<endl;
        cout<<"4) PROCESAR CHEQUE RECHAZADO (ELIMINAR)"<<endl;
        cout<<"5) SALIR"<<endl<<endl;

        cout<<"ELIGE LA OPCION QUE DESEAS REALIZAR: ";
        cin>>op;

        system("cls");

        if(op == 1){
            cout<<"\t\t\tREGISTRAR CHEQUE (INSERTAR)"<<endl<<endl;
            int numeroCheque, CuentaADepositar;
            char Banco[10];
            double Monto;

            cout<<"Numero de cheque: ";
            cin>>numeroCheque; cin.ignore();
            cout<<"Nombre del banco: "; 
            cin>>Banco;//getline(cin, Banco); 
            cout<<"Numero de cuenta a depositar: "; 
            cin>>CuentaADepositar;
            cout<<"Monto: $"; 
            cin>>Monto;

            if(iCheques < 3){//Si el contador es menor que 3, se van estableciendo y 
                        //agregando los cheques a la pila, segun la posicion del arreglo en la que vaya
                cheques[iCheques].establecerNumero(numeroCheque);
                cheques[iCheques].establecerBanco(Banco);
                cheques[iCheques].establecerCuentaADepositar(CuentaADepositar);
                cheques[iCheques].establecerMonto(Monto);

                MiBanco.RegistroCheque(cheques[iCheques]);
                iCheques++;//El contador aumenta, para que vaya recorriendo una posicion adelante y escribir en ella
            }
            else{
                cout<<"\n\n\t\tNO SE PUEDE REGISTRAR EL CHEQUE POR FALTA DE ESPACIO. \n\n ";
            }
        }

        if(op == 2){
            cout<<"\t\t\tPROCESAR CHEQUE (ELIMINAR)"<<endl;
            if(iCheques > 0){
                MiBanco.ProcesarCheque();
                iCheques--;//Va disminuyendo, para que al monento de salir del programa, se borren 
                        //del archivo, los que fueron procesados.
            }
            else{
                cout<<"\n\n\t\t\tNO HAY CHEQUES POR PROCESAR.\n\n ";
            }
        }

        if(op == 3){
            cout<<"\t\t\tREGISTRAR CHEQUE RECHAZADO (INSERTAR)"<<endl<<endl;
            int numeroCheque, CuentaADepositar;
            char Banco[10];
            double Monto;

            cout<<"Numero de cheque: "; cin>>numeroCheque;
            cout<<"Nombre del banco: "; cin>>Banco;
            cout<<"Numero de cuenta a depositar: "; cin>>CuentaADepositar;
            cout<<"Monto: $"; cin>>Monto;

            if(iChequesRec < 3){
                chequesRechazados[iChequesRec].establecerNumero(numeroCheque);
                chequesRechazados[iChequesRec].establecerBanco(Banco);
                chequesRechazados[iChequesRec].establecerCuentaADepositar(CuentaADepositar);
                chequesRechazados[iChequesRec].establecerMonto(Monto);
                chequesRechazados[iChequesRec].establecerCargo(Monto);

                MiBanco.RegistroChequeR(chequesRechazados[iChequesRec]);
                iChequesRec++;//El contador aumenta, para que vaya recorriendo una posicion adelante y escribir en ella
            }
            else{
                cout<<"\n\n\t\tNO SE PUEDE REGISTRAR EL CHEQUE RECHAZADO POR FALTA DE ESPACIO. \n\n ";
            }
        }

        if(op == 4){
            cout<<"\t\t\tPROCESAR CHEQUE RECHAZADO (ELIMINAR)"<<endl;
            if(iChequesRec > 0){
                MiBanco.ProcesarChequeR();
                iChequesRec--;//Va disminuyendo, para que al monento de salir del programa, se borren 
                        //del archivo, los que fueron procesados.
            }
            else{
                cout<<"\n\n\t\t\tNO HAY CHEQUES RECHAZADOS POR PROCESAR.\n\n ";
            }
        }

        if(op == 5){
            cout<<"\t\t\tRESPALDANDO LOS DATOS EN UN ARCHIVO"<<endl<<endl;
            
            MiBanco.respaldarCheques(cheques, iCheques);
            
            MiBanco.respaldarChequesRec(chequesRechazados, iChequesRec);
        }

        cout<<"\n\n\n";
        system("pause"); system("cls");

    }while(op != 5);

    return 0;
}

void archivoChequesEntrada(){
    //Abrir el archivo de Cheques, para leer la informacion dentro de el 
    ifstream archivoChequesEntrada("cheques.dat", ios::in | ios::binary);//Archivo logico

    if(archivoChequesEntrada.is_open()){        
        cout<<"\t\t\tRECUPERANDO LOS CHEQUES DESDE EL ARCHIVO"<<endl;
        while(!archivoChequesEntrada.eof()){
            //Posicionar el puntero al incio del archivo
            archivoChequesEntrada.seekg((iCheques) * sizeof(Cheque));
            archivoChequesEntrada.read(reinterpret_cast<char *>(&cheques[iCheques]), sizeof(Cheque));//leer los registros

            if(cheques[iCheques].obtenerNumero() != 0){
                MiBanco.RegistroCheque(cheques[iCheques]);
                iCheques++;//Iterar el contador, para que vaya agregando de uno en uno, a la pila de Cheques
            }
            archivoChequesEntrada.peek();
        }
        cout<<endl<<endl;
        system("pause"); system("cls");
    }
    archivoChequesEntrada.close();
}

void archivoChequesRecEntrada(){
    //Abrir el archivo de Cheques Rechazados, para leer la informacion dentro de el
    ifstream archivoChequesRecEntrada("cheques_rech.dat", ios::in | ios::binary);//Archivo logico

    if(archivoChequesRecEntrada.is_open()){    
        cout<<"\t\t\tRECUPERANDO LOS CHEQUES RECHAZADOS DESDE EL ARCHIVO"<<endl;
        while(!archivoChequesRecEntrada.eof()){
            //Posicionar el puntero al incio del archivo
            archivoChequesRecEntrada.seekg((iChequesRec) * sizeof(ChequeRechazado));
            archivoChequesRecEntrada.read(reinterpret_cast<char *>(&chequesRechazados[iChequesRec]), sizeof(ChequeRechazado));//leer los registros

            if(chequesRechazados[iChequesRec].obtenerNumero() != 0){
                MiBanco.RegistroChequeR(chequesRechazados[iChequesRec]);
                iChequesRec++;//Iterar el contador, para que vaya agregando de uno en uno, a la pila de Cheques
            }
            archivoChequesRecEntrada.peek();
        }
        cout<<endl<<endl;
        system("pause"); system("cls");
    }
    archivoChequesRecEntrada.close();
}