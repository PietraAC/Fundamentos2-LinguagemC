/*
4) Escreva uma função que receba como parâmetro um valor L e um valor C e retorne
o ponteiro para uma matriz alocada dinamicamente contendo L linhas e C colunas.
Essa matriz deve ser inicializada com o valor 0 em todas as suas posições.
*/

#include <stdio.h>
#include <stdlib.h>

int** alocaMatriz(int L, int C) {
    // Aloca dinamicamente um array de ponteiros para int
    int** matriz = (int**)malloc(L * sizeof(int*));

    if (matriz == NULL) {
        printf("Erro na alocação de memória para a matriz (linhas).\n");
        return NULL;
    }

    for (int i = 0; i < L; i++) {
        // Para cada linha, aloca dinamicamente um array de int para as colunas
        matriz[i] = (int*)malloc(C * sizeof(int));

        if (matriz[i] == NULL) {
            printf("Erro na alocação de memória para a matriz (colunas).\n");

            // Se ocorrer um erro na alocação, libera a memória alocada até o momento
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);

            return NULL;
        }

        // Inicializa os elementos da linha com 0
        for (int j = 0; j < C; j++) {
            matriz[i][j] = 0;
        }
    }

    return matriz;
}

int main() {
    int L, C;

    // Solicita ao usuário o número de linhas e colunas
    printf("Digite o número de linhas: ");
    scanf("%d", &L);
    printf("Digite o número de colunas: ");
    scanf("%d", &C);

    int** matriz = alocaMatriz(L, C);  // Chama a função para alocar a matriz

    if (matriz != NULL) {
        // Imprime a matriz
        printf("Matriz alocada e inicializada com 0:\n");
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < C; j++) {
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }

        // Libera a memória alocada para a matriz
        for (int i = 0; i < L; i++) {
            free(matriz[i]);
        }
        free(matriz);
    }

    return 0;
}
