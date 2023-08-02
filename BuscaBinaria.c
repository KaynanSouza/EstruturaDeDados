
#include <stdio.h>

int vetor[1000];
int i = 0;
int busca = 0;
int inicio = 0;
int fim = 0;
int meio = 0;

void main(){
    for(i = 0; i < 1000; i++){
        vetor[i] = i;
    }

    printf("Digite o valor a ser buscado:");
    scanf("%i", &busca);

    fim = 999;
    while(fim >= inicio){
        meio = (inicio + fim) / 2;
        if(busca == vetor[meio]){
            printf("achei porra");
            break;
        }else if(busca > vetor[meio])inicio = meio + 1;
        else fim = meio - 1;
    }

    printf("se fudeu");

}

