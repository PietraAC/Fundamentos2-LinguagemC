/*
1) Elabore um programa que leia do usuário o tamanho de um vetor a ser lido. Em
seguida, faça a alocação dinâmica desse vetor. Por fim, leia o vetor do usuário e o
imprima.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
    
    // Solicita ao usuário o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    // Aloca dinamicamente espaço para o vetor
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    
    // Verifica se a alocação foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }
    
    // Lê os elementos do vetor do usuário
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
    
    // Imprime o vetor
    printf("Vetor lido:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    // Libera a memória alocada
    free(vetor);
    
    return 0;
}
