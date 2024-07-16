#include "func_hash.h"
#include <locale>
#include <iostream>
#include <cstdlib>

using namespace std;

void listamenu(){
    system("cls");
    cout << "Cadastro conta Bancária - Financy" << endl;
    cout<<"1 - Inserir"<<endl;
    cout<<"2 - Remover"<<endl;
    cout<<"3 - Consultar por código"<<endl;
    cout<<"4 - Listar"<<endl;
    cout<<"5 - Inserir dados em massa" <<endl;
    cout<<"0 - Sair"<<endl<<endl;
}


void testarHashContas() {
    hashContas *tabela = new hashContas();

    int opcao;
    contaBancaria conta;
    int codigoConta;
    string nomeCliente;
    string numeroConta;
    double saldo;
    string email;

    do {
        listamenu();

        cout << "Informe a opção: ";
        cin >> opcao;

        switch(opcao) {
            case 0:
                exit(0);
                break;

            case 1:
                cout << "Informe o código da conta: ";
                cin >> codigoConta;
                cin.ignore();
                cout << "Informe o nome do cliente: ";
                getline(cin, nomeCliente);
                cout << "Informe o número da conta: ";
                getline(cin, numeroConta);
                cout << "Informe o saldo da conta: ";
                cin >> saldo;
                cin.ignore();
                cout << "Informe o email do cliente: ";
                getline(cin, email);

                conta.setCodigoConta(codigoConta);
                conta.setNomeCliente(nomeCliente);
                conta.setNumeroConta(numeroConta);
                conta.setSaldo(saldo);
                conta.setEmail(email);

                tabela->insere(conta);
                break;

            case 2:
                cout << "Informe o código da conta: ";
                cin >> codigoConta;

                tabela->remover(codigoConta);
                break;

            case 3:
                cout << "Informe o código da conta: ";
                cin >> codigoConta;

                tabela->consulta(codigoConta);
                break;

            case 4:
                tabela->imprimirContas();
                break;

            case 5:
                tabela->inserirEmMassa();
                break;

            default:
                cout << "Opção inválida" << endl;
        }

        system("PAUSE");
    } while(opcao != 0);
}




int main()
{
	setlocale(LC_ALL, "");
    testarHashContas();

    return EXIT_SUCCESS;
}
