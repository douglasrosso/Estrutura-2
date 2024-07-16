#include "func_lista_enc.h"
#include <iostream>
#include <string>

using namespace std;

no *criarLista(){
    return NULL;
}

no *recriarLista(no *lista){
    while (lista != NULL) {
        no *temp = lista;
        lista = lista->prox;
        delete temp;
    }
    return NULL;
}

int listavazia(no *lista){
    return lista == NULL ? 1 : 0;
}

no *insereInicio(no *lista, int info){
    no *novoNo = new no;
    novoNo->info = info;
    novoNo->prox = lista;
    return novoNo;
}

no *removerInicio(no *lista){
    if (lista != NULL) {
        no *temp = lista;
        lista = lista->prox;
        delete temp;
    }
    return lista;
}

void consultaValores(no *lista){
    no *temp = lista;
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->prox;
    }
    cout << endl;
}

int consultaprimeirolista(no *lista){
    if (lista != NULL) {
        return lista->info;
    } else {
        cout << "Lista vazia." << endl;
        return -1;
    }
}

no *consultaendprimeirolista(no *lista){
    return lista;
}

int consultanlista(no *lista){
    int count = 0;
    no *temp = lista;
    while (temp != NULL) {
        count++;
        temp = temp->prox;
    }
    return count;
}

no *ordenaAsc(no *lista){
    return lista;
}

no *buscaUltimo(no *lista){
    no *temp = lista;
    while (temp != NULL && temp->prox != NULL) {
        temp = temp->prox;
    }
    return temp;
}

no *insereFinal(no *lista, int info){
    no *novoNo = new no;
    novoNo->info = info;
    novoNo->prox = NULL;
    
    if (lista == NULL) {
        return novoNo;
    }
    
    no *ultimo = buscaUltimo(lista);
    ultimo->prox = novoNo;
    
    return lista;
}

no *removerFinal(no *lista){
    if (lista == NULL) {
        return NULL;
    } else if (lista->prox == NULL) {
        delete lista;
        return NULL;
    } else {
        no *temp = lista;
        while (temp->prox->prox != NULL) {
            temp = temp->prox;
        }
        delete temp->prox;
        temp->prox = NULL;
        return lista;
    }
}

no *insereOrdemCrescente(no *lista, int info){
    no *novoNo = new no;
    novoNo->info = info;
    novoNo->prox = NULL;
    
    if (lista == NULL || info < lista->info) {
        novoNo->prox = lista;
        return novoNo;
    }
    
    no *atual = lista;
    while (atual->prox != NULL && atual->prox->info < info) {
        atual = atual->prox;
    }
    
    novoNo->prox = atual->prox;
    atual->prox = novoNo;
    
    return lista;
}

no *removerElemento(no *lista, int valor){
    if (lista == NULL) {
        return NULL;
    } else if (lista->info == valor) {
        no *temp = lista->prox;
        delete lista;
        return temp;
    } else {
        no *anterior = lista;
        no *atual = lista->prox;
        while (atual != NULL && atual->info != valor) {
            anterior = atual;
            atual = atual->prox;
        }
        if (atual != NULL) {
            anterior->prox = atual->prox;
            delete atual;
        }
        return lista;
    }
}

