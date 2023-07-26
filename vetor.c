#include <stdio.h>

void main(){

    int matriz[2][3];
    int matriz2[3][2];
    int resposta[2][2];

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            matriz[i][j] = 0;
        }
    }for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            matriz2[i][j] = 0;
        }
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            resposta[i][j] = 0;
        }
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            printf("%d %d:", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            printf("%d %d:", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }
    for (int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for (int k = 0; k < 3; k++){
                resposta[i][j] += (matriz[i][k] * matriz2[k][j]);
            }
        }
    }
    for (int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%d\n",resposta[i][j]);
        }
    }

}
