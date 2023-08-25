#include <stdio.h>
#include <stdlib.h>

struct no {
    int numero;
    struct no *anterior;
    struct no *proximo;
};

struct no *cabeca = NULL;

void inserir(int numero){
    struct no *novoNo = (struct no *) malloc(sizeof (struct no));
    novoNo->numero = numero;
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;

    if(cabeca == NULL)
        //Lista vazia
        cabeca = novoNo;
    else {
        struct no *ponteiro = cabeca;
        //ultimo no da lista
        while (ponteiro->proximo != NULL){
            ponteiro = ponteiro->proximo;
        }
        ponteiro->proximo = novoNo;
        novoNo->anterior = ponteiro;
    }
}

void imprimir(){
    struct no *ponteiro = cabeca;
    while (ponteiro != NULL){
        printf("%d\n", ponteiro->numero);
        ponteiro = ponteiro->proximo;
    }
    printf("+--------------------------+\n");
}

void remover(int numero){
        struct no *ponteiro = cabeca;

        while(ponteiro != NULL){
            if (ponteiro->numero == numero){
                if(ponteiro->anterior == NULL){
                    cabeca = cabeca->proximo;
                    if (cabeca != NULL)
                        cabeca->anterior = NULL;
                    free(ponteiro);
                    ponteiro = cabeca;
                }else if(ponteiro->proximo == NULL){
                    struct no *temp = ponteiro;
                    ponteiro = ponteiro->anterior;
                    ponteiro->proximo = NULL;
                    free(temp);
                } else{
                    struct no *temp = ponteiro;
                    ponteiro = ponteiro->anterior;
                    temp->anterior->proximo = temp->proximo;
                    temp->proximo->anterior = temp->anterior;
                    free(temp);
                }
            }
            ponteiro = ponteiro->proximo;
        }
        if (ponteiro != NULL)
            ponteiro = ponteiro->proximo;
}

int main() {
    imprimir();
    remover(1);
    inserir(1);
    imprimir();

    inserir(1);
    remover(1);

    inserir(2);
    remover(2);


    inserir(3);
    inserir(4);
    inserir(5);
    remover(5);
    imprimir();
    return 0;
}
