/*
5) Um problema típico em ciência da computação consiste em
converter um número da sua forma decimal para binária. Crie um
algoritmo recursivo para resolver esse problema.
 Solução trivial: x=0 quando o número inteiro já foi convertido para
binário
 Passo da recursão: saber como x/2 é convertido. Depois, imprimir um
dígito (0 ou 1) dado o sucesso da divisão.
*/

#include <stdio.h>
#include <stdlib.h>
void decimalParaBinario(int n) {
    if (n == 0) {
        return; // Caso base: Quando o número já foi completamente convertido.
    } else {
        decimalParaBinario(n / 2); // Chamada recursiva com n dividido por 2.
        printf("%d", n % 2); // Imprime o último dígito (0 ou 1) da conversão.
    }
}

int main() {
    int numero;

    printf("Digite um número decimal: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Por favor, insira um número decimal não negativo.\n");
        return 1;
    }

    printf("A representação binária de %d é: ", numero);
    if (numero == 0) {
        printf("0"); // Caso especial para 0 decimal.
    } else {
        decimalParaBinario(numero);
    }
    printf("\n");

    return 0;
}
