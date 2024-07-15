/*
2)Escreva uma função que receba um valor inteiro positivo N por parâmetro e retorne
o ponteiro para um vetor de tamanho N alocado dinamicamente. Se N for negativo ou
igual a zero, um ponteiro nulo deverá ser retornado.
*/

#include <stdio.h>
#include <stdlib.h>

int* alocaVetor(int N) {
    if (N <= 0) {
        return NULL;  // Retorna um ponteiro nulo se N for negativo ou igual a zero
    }

    int* vetor = (int*)malloc(N * sizeof(int));  // Aloca dinamicamente o vetor

    return vetor;
}

int main() {
    int N;
    
    // Solicita ao usuário o valor de N
    printf("Digite um valor inteiro positivo N: ");
    scanf("%d", &N);

    int* vetor = alocaVetor(N);  // Chama a função para alocar o vetor

    if (vetor == NULL) {
        printf("Valor de N inválido. N deve ser um inteiro positivo.\n");
    } else {
        printf("Vetor alocado com sucesso!\n");
        // Agora você pode usar o vetor alocado dinamicamente conforme necessário

        // Não se esqueça de liberar a memória alocada quando não for mais necessária
        free(vetor);
    }

    return 0;
}
