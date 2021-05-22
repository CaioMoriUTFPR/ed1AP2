#include <stdio.h>
#include <string.h>

#include "fila.h"
#include "tad_teste.h"

int main(){

    Teste* t1 = teste_criar("Teste da FILA");
    char str[200];
    TipoElemento elemento;


    /**************************************
    * Teste fila_toString
    **************************************/
    Fila* f = fila_criar();
    fila_toString(f, str);
    teste_verificar(t1, strcmp(str, "[]")==0, "Teste toString 1/2");

    fila_inserir(f, 10);
    fila_inserir(f, 20);
    fila_inserir(f, 30);
    fila_toString(f, str);
    teste_verificar(t1, strcmp(str, "[10,20,30]")==0, "Teste toString 2/2");
    fila_destruir(&f);

    /**************************************
    * Teste fila_posicao
    **************************************/    
    int pos;
    f = fila_criar();

    pos = fila_posicao(f, 20);
    teste_verificar(t1, pos == -1, "Teste posicao 1");
    
    fila_inserir(f, 20);
    fila_inserir(f, 40);
    fila_inserir(f, 60);
    fila_inserir(f, 80);
    fila_inserir(f, 100);
    fila_toString(f, str);
    
    
    pos = fila_posicao(f, 20);
    teste_verificar(t1, pos == 0, "Teste posicao 2");

    pos = fila_posicao(f, 40);
    teste_verificar(t1, pos == 1, "Teste posicao 3");

    pos = fila_posicao(f, 60);
    teste_verificar(t1, pos == 2, "Teste posicao 4");

    pos = fila_posicao(f, 80);
    teste_verificar(t1, pos == 3, "Teste posicao 5");

    pos = fila_posicao(f, 100);
    teste_verificar(t1, pos == 4, "Teste posicao 6");

    pos = fila_posicao(f, 30);
    teste_verificar(t1, pos == -1, "Teste posicao 7");

    pos = fila_posicao(f, -50);
    teste_verificar(t1, pos == -1, "Teste posicao 8");

    pos = fila_posicao(NULL, 10);
    teste_verificar(t1, pos == -1, "Teste posicao 9");
    

    
    
    teste_relatorio(t1);    
    teste_desalocar(&t1);

}
