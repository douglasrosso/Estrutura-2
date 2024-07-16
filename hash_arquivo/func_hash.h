#include "func_contas.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <list>

#define TAM 5

using namespace std;

class hashContas {
    private:
        list<contaBancaria> contas[TAM];
        string dados[TAM] = {"dados1.txt", "dados2.txt", "dados3.txt", "dados4.txt", "dados5.txt"};

    public:
        hashContas();
        ~hashContas();
        void insere(contaBancaria conta);
        void insereArquivo(contaBancaria conta);
        void remover(int codigoConta);
        void consulta(int codigoConta);
        void imprimirContas();
        void inserirEmMassa();
};

hashContas::hashContas() {}

hashContas::~hashContas() {}

void hashContas::insere(contaBancaria conta) {
    int indice = conta.getCodigoConta() % TAM;
    contas[indice].push_back(conta);
    insereArquivo(conta);
}

void hashContas::insereArquivo(contaBancaria conta) {
    int classe = conta.getCodigoConta() % TAM;
    string fileName = dados[classe];

    ofstream arquivo;
    arquivo.open(fileName.c_str(), ios::app);
    arquivo << "Código da Conta: " << conta.getCodigoConta() << " || Nome do Cliente: " << conta.getNomeCliente()
            << " || Número da Conta: " << conta.getNumeroConta() << " || Saldo: " << conta.getSaldo()
            << " || Email: " << conta.getEmail() << endl;
    arquivo.close();
}

void hashContas::consulta(int codigoConta) {
    for (int i = 0; i < TAM; ++i) {
        string fileName = dados[i];
        ifstream arquivo(fileName.c_str());

        if (arquivo.is_open()) {
            string linha;
            while (getline(arquivo, linha)) {
                stringstream ss(linha);
                string token;
                getline(ss, token, ':');
                int codigo = 0;
                ss >> codigo;
                if (codigo == codigoConta) {
                    cout << linha << endl;
                }
            }
            arquivo.close();
        }
    }
}

void hashContas::inserirEmMassa() {
    ofstream arquivo;
    string fileName;

    int classe = 0;
    fileName = dados[classe];
    arquivo.open(fileName.c_str(), ios::app);
    arquivo << "Código da Conta: 9991" << " || Nome: Douglas Rosso" << " || Número da Conta: 12345" << " || Saldo: 1500.75" << " || Email: douglas@email.com" << endl;
    arquivo << "Código da Conta: 9992" << " || Nome do Cliente: Leonardo Brehm" << " || Número da Conta: 67890" << " || Saldo: 10000.00" << " || Email: leozindaquebrada@email.com" << endl;
    arquivo.close();

    classe = 1;
    fileName = dados[classe];
    arquivo.open(fileName.c_str(), ios::app);
    arquivo << "Código da Conta: 9993" << " || Nome do Cliente: Anderson Witt" << " || Número da Conta: 54321" << " || Saldo: 2500.50" << " || Email: anderson@email.com" << endl;
    arquivo.close();

    classe = 2;
    fileName = dados[classe];
    arquivo.open(fileName.c_str(), ios::app);
    arquivo << "Código da Conta: 9994" << " || Nome do Cliente: Sergio Coral" << " || Número da Conta: 98765" << " || Saldo: 9999999.25" << " || Email: sergiocoral@email.com" << endl;
    arquivo.close();

    classe = 3;
    fileName = dados[classe];
    arquivo.open(fileName.c_str(), ios::app);
    arquivo << "Código da Conta: 9995" << " || Nome do Cliente: Pedro Lima" << " || Número da Conta: 13579" << " || Saldo: 750.30" << " || Email: pedrolima@email.com" << endl;
    arquivo << "Código da Conta: 9996" << " || Nome do Cliente: Carlos Magno" << " || Número da Conta: 13139" << " || Saldo: 1150.30" << " || Email: carlao@email.com" << endl;
    arquivo.close();

    classe = 4;
    fileName = dados[classe];
    arquivo.open(fileName.c_str(), ios::app);
    arquivo << "Código da Conta: 9997" << " || Nome do Cliente: Marcelli Caetano" << " || Número da Conta: 24680" << " || Saldo: 3000.00" << " || Email: devmarcelli@email.com" << endl;
    arquivo.close();
}


void hashContas::remover(int codigoConta) {
    int classe = codigoConta % TAM;
    string fileName = dados[classe];

    ifstream arquivoOriginal(fileName.c_str());
    if (!arquivoOriginal.is_open()) {
        cout << "Erro ao abrir o arquivo para remoção." << endl;
        return;
    }

    string arquivoTemp = fileName + ".temp";
    ofstream arquivoTemporario(arquivoTemp.c_str());

    if (!arquivoTemporario.is_open()) {
        cout << "Erro ao criar arquivo temporário." << endl;
        arquivoOriginal.close();
        return;
    }

    string linha;
    bool encontrado = false;

    while (getline(arquivoOriginal, linha)) {
        stringstream ss(linha);
        string token;
        getline(ss, token, ':');
        int codigo = 0;
        ss >> codigo;

        if (codigo != codigoConta) {
            arquivoTemporario << linha << endl;
        } else {
            encontrado = true;
        }
    }

    arquivoOriginal.close();
    arquivoTemporario.close();

    if (encontrado) {
        remove(fileName.c_str());
        rename(arquivoTemp.c_str(), fileName.c_str());
    } else {
        cout << "Conta com código " << codigoConta << " não encontrada." << endl;
        remove(arquivoTemp.c_str());
    }
}

void hashContas::imprimirContas() {
    string linha;
    for(int i = 0; i<TAM; i++) {
        string fileName = dados[i];
        ifstream arquivo;
        arquivo.open(fileName.c_str());
        if(arquivo.is_open()) {
            while(getline(arquivo, linha)) {
                cout << linha << endl;
            }
        }
        arquivo.close();
    }
}




