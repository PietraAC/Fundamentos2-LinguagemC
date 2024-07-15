/*
 2) Crie uma função que retorne x*y através de operação de soma. A função
recebe x e y por parâmetro
*/

#include <stdio.h>
#include <stdlib.h>

// Protótipo da função para calcular o produto de x e y através de soma
int calcularProduto(int x, int y);

int main() {
    int x, y, resultado;

    // Solicita ao usuário que insira dois números inteiros
    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &x);
    printf("Digite o segundo número inteiro: ");
    scanf("%d", &y);

    resultado = calcularProduto(x, y);

    printf("O produto de %d e %d é %d\n", x, y, resultado);

    return 0;
}

// Definição da função para calcular o produto de x e y através de soma de forma recursiva
int calcularProduto(int x, int y) {
    // Caso base: Se y for igual a 0, o produto é 0
    if (y == 0) {
        return 0;
    }
    // Caso geral: Somamos x ao resultado do produto de x e y-1
    else {
        return x + calcularProduto(x, y - 1);
    }
}
