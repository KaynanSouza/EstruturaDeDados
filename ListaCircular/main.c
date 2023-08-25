#include <stdio.h>
#include <stdlib.h>

struct no{
    int numero;
    struct no *proximo;
};

struct no *cabeca;

void inserir(int numero){
    struct no *novoNo = (struct no *) malloc(sizeof (struct no));
    novoNo->numero = numero;
    novoNo->proximo = cabeca;
    if (cabeca == NULL){
        cabeca = novoNo;
        novoNo->proximo = cabeca;
    }else{
        struct no *ponteiro = cabeca;
        while (ponteiro->proximo != cabeca)
            ponteiro = ponteiro->proximo;
        ponteiro->proximo = novoNo;
    }
}

void imprimir(){
    struct no *ponteiro = cabeca;
    if (ponteiro != NULL){
        while (1){
            printf("%d\n", ponteiro->numero);
            ponteiro = ponteiro->proximo;
            if (ponteiro == cabeca)
                break;
        }
    }
}

void remover(int numero){
    if (cabeca != NULL){
        if (cabeca->numero == numero){
            if (cabeca->proximo == cabeca){
                free(cabeca);
                cabeca = NULL;
            }else {
                struct no *ponteiroExcluir = cabeca;
                cabeca = cabeca->proximo;
                struct no *ponteiroAnterior = cabeca;
                while (ponteiroAnterior->proximo != ponteiroExcluir)
                    ponteiroAnterior = ponteiroAnterior->proximo;
                ponteiroAnterior->proximo = cabeca;
                free(ponteiroExcluir);
            }
        }else{
            struct no *ponteiroAnterio = cabeca;

            while ((ponteiroAnterio->proximo != cabeca) && (ponteiroAnterio->proximo->numero != numero)){
                ponteiroAnterio = ponteiroAnterio->proximo;
            }
            if (ponteiroAnterio->proximo != cabeca){
                struct no *ponterioExcluir = ponteiroAnterio ->proximo;
                ponteiroAnterio->proximo = ponterioExcluir->proximo;
                free(ponterioExcluir);
            }
        }
    }
}

int main() {
    inserir(1);
    inserir(2);
    inserir(3);
    remover(3);
    imprimir();
    return 0;
}
