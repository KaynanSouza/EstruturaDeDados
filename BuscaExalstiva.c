
#include <stdio.h>
#include <stdlib.h>

int vetor[1000];
int i = 0;
int busca = 0;
int achei = -1;

void main(){
    for(i = 0; i < 1000; i++){
        vetor[i] = (rand() % 1000);
    }

    printf("Digite o valor a ser buscado:");
    scanf("%i", &busca);

    for(i = 0; i < 1000; i++){
        if(vetor[i] == busca){
            achei = i;
        }
    }

    if (achei == -1)printf("Se fudeu");
        else printf("Achei, na posicao: %i", achei);

}
