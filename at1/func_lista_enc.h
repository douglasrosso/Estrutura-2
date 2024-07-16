
struct no{
       int info;
       no *prox;//aponta para a proxima posia��o de mem�ria que cont�m a vari�vel alocada
};

//cria uma nova lista
no *criarLista();


//insere no in�cio da lista
no *insereInicio(no *lista, int info);

/*busca o �ltimo elemento da lista*/
no *buscaUltimo(no *lista);

//insere no final da lista e retorna o elemento inserido
no *insereFinal(no *lista, int info);

void consultaValores(no *lista);

/*remove o in�cio da lista*/
no *removerInicio(no *lista);

/*remove o �ltimo elemento da lista*/
no *removerFinal(no *lista);

/*insere um elemento na ordem crescente*/
no *insereOrdemCrescente(no *lista, int info);

/*remove um elemento da lista conforme o valor passado por par�metro*/
no *removerElemento(no *lista, int valor);

/*recria a lista desalocando todos os elementos da mem�ria*/
no *recriarLista(no *lista);

// 6 -i- Consulta numero de elementos na lista

int listavazia(no *lista);

int consultaprimeirolista(no *lista);

no *consultaendprimeirolista(no *lista);

/*retorna o n�mero de elementos contidos na lista*/
int consultanlista(no *lista);

no *ordenaAsc(no *lista);



