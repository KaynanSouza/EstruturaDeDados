#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MODULO = 3;

struct no{
    int numero;
    struct no *proximoNo;
};

struct diretor{
    int resto;
    struct no *proximoNO;
    struct diretor *proximoDiretor;
};

struct diretor *cabeca = NULL;

struct diretor *procurarDiretor(int resto){
    struct diretor *ponteiro = cabeca;
    while (ponteiro != NULL && ponteiro->resto != resto){
        ponteiro = ponteiro->proximoDiretor;
    }

    if(ponteiro == NULL){
        ponteiro = (struct diretor *) malloc(sizeof(struct diretor));
        ponteiro->resto = resto;
        ponteiro->proximoNO = NULL;
        ponteiro->proximoDiretor = cabeca;

        cabeca = ponteiro;
    }
    return ponteiro;
}

void inserir(int numero){
    struct diretor *ponteiroDiretor = procurarDiretor(numero % MODULO);
    struct no *novoNo = (struct no *)malloc(sizeof (struct no));

    novoNo->numero = numero;
    novoNo->proximoNo = ponteiroDiretor->proximoNO;

    ponteiroDiretor->proximoNO = novoNo;
}

void impromir(){
    struct diretor *ponteiroDiretor = cabeca;
    printf("========== Matriz ============\n");
    while (ponteiroDiretor != NULL){
        struct no *ponteiroNo = ponteiroDiretor->proximoNO;
        printf("%d:\t", ponteiroDiretor->resto);
        while (ponteiroNo != NULL){
            printf("%d\t", ponteiroNo->numero);
            ponteiroNo = ponteiroNo->proximoNo;
        }
        printf("\n");
        ponteiroDiretor = ponteiroDiretor->proximoDiretor;
    }
}

void remover(int numero){
    struct diretor *ponteiroDiretor = procurarDiretor(numero % MODULO);

    if(ponteiroDiretor->proximoNO != NULL){
        if(ponteiroDiretor->proximoNO->numero == numero){
            struct no *ponteiroExcluir = ponteiroDiretor->proximoNO;
            ponteiroDiretor->proximoDiretor = ponteiroDiretor->proximoNO->proximoNo;
            free(ponteiroExcluir);
        } else{
            struct no *ponteiroAnterior = ponteiroDiretor->proximoNO;

            while (ponteiroAnterior->proximoNo != NULL && ponteiroAnterior->proximoNo->numero != numero){
                ponteiroAnterior = ponteiroAnterior->proximoNo;
            }

            if(ponteiroAnterior->proximoNo != NULL){
                struct no *ponteiroExcluir = ponteiroAnterior->proximoNo;
                ponteiroAnterior->proximoNo = ponteiroExcluir->proximoNo;
                free(ponteiroExcluir);
            }
        }
    }
}

int main() {
    time_t t;
    int remove = 0;

    srand((unsigned) time(&t));

    for (int i = 0; i < 4; ++i) {
        inserir(rand());
    }
    impromir();

    printf("Digite um numero para ecluir:");
    scanf("%d", &remove);

    remover(remove);

    impromir();

    return 0;
}
