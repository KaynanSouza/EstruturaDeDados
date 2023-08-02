#include <stdio.h>
#include <stdlib.h>
int vetor[1000];
int i = 0, trq = 0;

void main(){
    for(i = 0; i < 1000; i++){
        vetor[i] = (rand() % 1000);
    }
    printf("Desordenado");
    for(i = 0; i < 1000; i++){
        printf("%i\n", vetor[i]);
    }

    trq = 1;
    while(trq){
        trq = 0;
        for(i = 0; i < 999; i++){
            if(vetor[i] > vetor[i+1]){
                int temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
                trq = 1;
            }
        }
    }

    printf("Ordenado\n");
    for(i = 0; i < 1000; i++){
        printf("%i\n", vetor[i]);
    }

}
