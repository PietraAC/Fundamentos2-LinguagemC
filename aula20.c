#include <stdio.h>
#include <stdlib.h>

int main(){
    int** matriz = (int**) malloc(3 * sizeof(int*));
    for(int l = 0; l< 3; l++){
        matriz[l] = (int*) malloc(5 * sizeof(int));
    }//for

    return 0;

    for(int l = 0; l < 3; l++){
        for (int c = 0; c < 5; c++){
            printf("%02d", matriz [l][c]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++){
        
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}