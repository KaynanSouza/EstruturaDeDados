#include <stdio.h>
#include <stdlib.h>
int vetor[1000];
int i = 0,j = 0;

void main(){
    for(i = 0; i < 1000; i++){
        vetor[i] = (rand() % 1000);
    }
    printf("Desordenado");
    for(i = 0; i < 1000; i++){
        printf("%i\n", vetor[i]);
    }
    for(i = 0; i < 999; i++){
        for(j = (i + 1); j < 1000; j++){
            if( vetor[i] > vetor[j]){
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
    printf("Ordenado\n");
    for(i = 0; i < 1000; i++){
        printf("%i\n", vetor[i]);
    }

}
