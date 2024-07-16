#include <string>
#include <iostream>

using namespace std;

class contaBancaria {
   private:
      int codigoConta;
      string nomeCliente;
      string numeroConta;
      double saldo;
      string email;

   public:
      contaBancaria();
      contaBancaria(int codigoConta, string nomeCliente, string numeroConta, double saldo, string email);
      ~contaBancaria();
      int getCodigoConta();
      void setCodigoConta(int codigoConta);
      string getNomeCliente();
      void setNomeCliente(string nomeCliente);
      string getNumeroConta();
      void setNumeroConta(string numeroConta);
      double getSaldo();
      void setSaldo(double saldo);
      string getEmail();
      void setEmail(string email);
      void imprimir();
};

contaBancaria::contaBancaria() {}

contaBancaria::contaBancaria(int codigoConta, string nomeCliente, string numeroConta, double saldo, string email) {
    this->codigoConta = codigoConta;
    this->nomeCliente = nomeCliente;
    this->numeroConta = numeroConta;
    this->saldo = saldo;
    this->email = email;
}

contaBancaria::~contaBancaria() {}

int contaBancaria::getCodigoConta() {
    return codigoConta;
}

void contaBancaria::setCodigoConta(int codigoConta) {
    this->codigoConta = codigoConta;
}

string contaBancaria::getNomeCliente() {
    return nomeCliente;
}

void contaBancaria::setNomeCliente(string nomeCliente) {
    this->nomeCliente = nomeCliente;
}

string contaBancaria::getNumeroConta() {
    return numeroConta;
}

void contaBancaria::setNumeroConta(string numeroConta) {
    this->numeroConta = numeroConta;
}

double contaBancaria::getSaldo() {
    return saldo;
}

void contaBancaria::setSaldo(double saldo) {
    this->saldo = saldo;
}

string contaBancaria::getEmail() {
    return email;
}

void contaBancaria::setEmail(string email) {
    this->email = email;
}

void contaBancaria::imprimir() {
    cout << "Código da Conta: " << codigoConta << endl
         << "Nome do Cliente: " << nomeCliente << endl
         << "Número da Conta: " << numeroConta << endl
         << "Saldo: " << saldo << endl
         << "Email: " << email << endl;
}

