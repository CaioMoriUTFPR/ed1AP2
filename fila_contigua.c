#include "fila.h"
#include "string.h"

#define TAM_INICIAL 100

/**************************************
* DADOS
**************************************/
struct _fila {
	TipoElemento* vetor;
	int tamVetor;
	int inicio;
	int fim;
	int qtdeElementos;
};


/**************************************
* FUNÇÕES AUXILIARES
**************************************/

bool fila_ehValida(Fila* f){
    return (f != NULL? true: false);
    
}

int fila_tamVetor(Fila* f){
    return f->tamVetor;
}

/**************************************
* IMPLEMENTAÇÃO
**************************************/


/**
 * Copia para o endereço de memória recebido por parâmetro uma versão
 * textual da fila [n1,n2,n3]
 * Parâmetro f: Endereço de memória da Fila
 * Parâmetro m: Endereço de memória onde será devolvido a string
 * RETORNO: true se a cópia foi realizada com sucesso e false caso contrário
 */
bool fila_toString(Fila* f, char* str){
    if(!fila_ehValida(f)) return false;

    str[0] = '\0';
    char elemento[50];
    strcat(str, "[");
    for (int i = 0; i < f->qtdeElementos; i++)
    {
        sprintf(elemento, "%d", f->vetor[i]);
        strcat(str, elemento);

        if (i < f->qtdeElementos - 1) strcat(str, ",");
    }
    strcat(str, "]");
    
    return true;
}

/**
 * Devolve a posição de um determinado elemento na fila.
 * As posições da fila iniciam em 0 (zero)
 * Parâmetro f: Endereço de memória da Fila
 * Parâmetro elemento: Elemento a ser encontrado na fila
 * RETORNO: posição do elemento na fila ou -1 caso ele não seja encontrado
 */
int fila_posicao(Fila* f, TipoElemento elemento){
   

}


/****************************************************************************************/
Fila* fila_criar(){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->vetor = (TipoElemento*) calloc(TAM_INICIAL, sizeof(TipoElemento));
    f->tamVetor = TAM_INICIAL;
    f->qtdeElementos = 0;
    f->inicio = f->fim = 0;
}

void fila_destruir(Fila** enderecoFila){
    if (enderecoFila == NULL) return;
    if(!fila_ehValida(*enderecoFila)) return;

    Fila* f = *enderecoFila;
    free(f->vetor);
    free(f);
    *enderecoFila = NULL;
}

bool fila_inserir(Fila* f, TipoElemento elemento){
    if(!fila_ehValida(f)) return false;

    f->vetor[f->fim] = elemento;
    f->fim = (f->fim + 1) % f->tamVetor;
    f->qtdeElementos++;

    return true;
}

bool fila_remover(Fila* f, TipoElemento* saida){ // estratégia do scanf
    if(!fila_ehValida(f)) return false;
    if(fila_vazia(f)) return false;

    TipoElemento elemento = f->vetor[f->inicio];
    f->inicio = (f->inicio+1) % f->tamVetor;
    *saida = elemento;
    f->qtdeElementos--;

    return true;
}

bool fila_primeiro(Fila* f, TipoElemento* saida){ // estratégia do scanf
    if(!fila_ehValida(f)) return false;
    if(fila_vazia(f)) return false;

    *saida = f->vetor[f->inicio];
    return true;
}

bool fila_vazia(Fila* f){
    if(!fila_ehValida(f)) return true;

    return (f->qtdeElementos == 0 ? true : false);
}

int fila_tamanho(Fila* f){
    if(!fila_ehValida(f)) return 0;

    return f->qtdeElementos;
}





