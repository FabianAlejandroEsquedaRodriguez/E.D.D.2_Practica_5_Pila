#include "cheque.h"

//Constructor
Cheque::Cheque(){
    
}

//Constructor parametrizado
Cheque::Cheque(int NumCta, char *NomBco, int Cta, double Mon){
    Numero = NumCta;
    CuentaADepositar = Cta;
    Monto = Mon;
    strcpy(Banco, NomBco);
}

//Destructor
Cheque::~Cheque(){
}

/* Método que despliega en pantalla los valores de todos los atributos
de un cheque. */
void Cheque::ImprimeDatos(){
    cout<< "\nNumero de cheque: " << Numero;
    cout<< "\nDel banco: " << Banco;
    cout<< "\nDepositado en la cuenta: " << CuentaADepositar;
    cout<< "\nMonto: $" << Monto<<endl;
}

void Cheque::establecerNumero(int Numero){
    this -> Numero = Numero;
}
int Cheque::obtenerNumero() const{
    return Numero;
}

void Cheque::establecerCuentaADepositar(int CuentaADepositar){
    this -> CuentaADepositar = CuentaADepositar;
}
int Cheque::obtenerCuentaADepositar() const{
    return CuentaADepositar;
}

void Cheque::establecerBanco(const string banco){
    //Convertir la string a arreglo de caracteres

    const char *bancoTemporal = banco.data();//Convierte el valor de esa string en un arreglo
    int longitud = banco.size();//Saber cual es el tamaño
    longitud = (longitud < 10)*longitud + (longitud >= 10)*9;//Si tengo caracteres de mas o de menos,
                                                            // solo contará los del tamaño del arreglo
    strncpy(Banco,bancoTemporal,longitud);//Copiar el valor del bancoTemporal al atributo Banco
    Banco[longitud] = '\0'; // adjunta un carácter nulo a apellidoPaterno
}
string Cheque::obtenerBanco() const{
    return Banco;
}

void Cheque::establecerMonto(double Monto){
    this -> Monto = Monto;
}
double Cheque::obtenerMonto() const{
    return Monto;
}