/*
4) Faça uma função recursiva que retorne o n-ésimo termo da sequência de
Fibonacci, sendo que n é recebido por parâmetro. Utilize essa função para
desenvolver um programa que mostre no main() os n termos dessa
sequência na tela, a partir do valor de n recebido pelo teclado. Sabe-se que
o 1º termo é 0 e o 2º termo é 1.
*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n, i;

    printf("Digite o valor de n para os termos da sequência de Fibonacci: ");
    scanf("%u", &n);

    if (n < 1) {
        printf("Por favor, insira um valor positivo para n.\n");
        return 1;
    }

    printf("Os primeiros %u termos da sequência de Fibonacci são:\n", n);

    for (i = 1; i <= n; i++) {
        printf("%u ", fibonacci(i));
    }

    printf("\n");

    return 0;
}
