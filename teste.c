/*

//ativ 1 

#include <stdio.h>
#include <stdlib.h>

int main(){
    int tamanho;

    printf("DIgite o tamanho desejado do vetor:\n ");
    scanf("%i", &tamanho);

    printf("tamanho: %i", tamanho);

    //alocando dinamicamente o espaço do vetor
    int *vetor = (int*) malloc(tamanho * sizeof(int));

    //verifica se ta certo
    if(vetor == NULL){
        printf("erro");
        return 1;
    }

    //preenche o vetor
     for(int i = 0; i < tamanho; i++){
        printf("Digite o numero %i de seu vetor:\n ", i+1);
        scanf("%d", &vetor[i]);

     }//for

     //exibe vetor
     for ( int i = 0; i < tamanho; i++){
        printf("%i \n", vetor [i]);
     }//for

    free(vetor);

    return 0;
}*/


//ativ 2 

/*#include <stdio.h>
#include <stdlib.h>

//função
int* alocarVetor (int n){
    if (n <= 0){

        return NULL; //retorna nulo se for menor ou igual a 0
    }

    int* vetor = (int*) malloc( n * sizeof(int));//aloca na memoria o espaço para o tamanho do vetor

    return vetor;
} //alocarVetor

int main(){

    int n;

    printf("digite o tamanho do vetor:\n ");
    scanf("%i", &n);
     
    int* vetor = alocarVetor(n);//chama a função que aloca e retorna o tamanho do vetor

    if (vetor == NULL){
        printf("vetor nulo: %d \n", vetor);
    }else {
        printf("Vetor alocado: %d", vetor);
        free(vetor);
    }

    return 0;

}//main */

//ativ 3 
/*
#include <stdio.h>
#include <stdlib.h>

int multiplicaVetor(int* A, int* B, int n ){

    //alocar dinamicamente o vetor c 
    int* c = (int*) malloc ( n * sizeof(int));

    if(c==NULL){

        printf("Erro!!");
        return NULL;
    }

    for(int i = 0; i < n; i++){
        c[i] = A[i] * B[i];//realiza a multiplicação
    }

    return c;
}//multiplicaVetor

int main(){

    int n;

    printf("digite o tamanho dos vetores:\n");
    scanf("%d", &n);

    int* A = (int*) malloc (n * sizeof(int));
    int* B = (int*) malloc (n * sizeof(int));


    //verifica se foi alocado
    if(A == NULL || B == NULL){
        printf("erro");
        return 1;
    }//if

    for(int i = 0; i < n; i++){
        printf("digite o valor %i do vetor A", i+1);
        scanf("%d", &A[i]);
    }//for do vetor A

    for(int i = 0; i < n; i++){
        printf("digite o valor %i do vetor B", i+1);
        scanf("%d", &B[i]);
    }//for do vetor B

    int* c = multiplicaVetor(A, B, n);

    if(c != NULL){
        for(int i = 0; i < n; i++){
            printf("%d  ", c[i]);
        }//exibir vetor
    }else {
        printf("erro2");

        free(A);
        free(B);
        free(c);
    }//if
    return 0;
}*/

//ativ 4
/*
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
}*/


