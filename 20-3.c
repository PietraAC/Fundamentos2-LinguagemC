/*
3) Escreva uma função que receba como parâmetro dois vetores via referência( A e B)
e o tamanho N. A função deve retornar o ponteiro para um vetor C de tamanho N
alocado dinamicamente, em que:
C[i] = A[i] * B[i]
*/

#include <stdio.h>
#include <stdlib.h>

int* multiplicaVetores(const int* A, const int* B, int N) {
    int* C = (int*)malloc(N * sizeof(int));  // Aloca dinamicamente o vetor C

    if (C == NULL) {
        printf("Erro na alocação de memória para o vetor C.\n");
        return NULL;
    }

    for (int i = 0; i < N; i++) {
        C[i] = A[i] * B[i];  // Calcula C[i] = A[i] * B[i]
    }

    return C;
}

int main() {
    int N;

    // Solicita ao usuário o tamanho dos vetores
    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &N);

    int* A = (int*)malloc(N * sizeof(int));  // Aloca dinamicamente o vetor A
    int* B = (int*)malloc(N * sizeof(int));  // Aloca dinamicamente o vetor B

    if (A == NULL || B == NULL) {
        printf("Erro na alocação de memória para os vetores A e B.\n");
        return 1;
    }

    // Solicita ao usuário os elementos dos vetores A e B
    printf("Digite os elementos do vetor A:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    printf("Digite os elementos do vetor B:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }

    int* C = multiplicaVetores(A, B, N);  // Chama a função para multiplicar os vetores

    if (C != NULL) {
        // Imprime o vetor C
        printf("Vetor C (resultado da multiplicação de A e B):\n");
        for (int i = 0; i < N; i++) {
            printf("%d ", C[i]);
        }
        printf("\n");

        // Libera a memória alocada para os vetores
        free(A);
        free(B);
        free(C);
    }

    return 0;
}
