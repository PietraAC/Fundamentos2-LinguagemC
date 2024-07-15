/*
3) Crie uma função que retorne x elevado a y através de operação de
multiplicação. A função recebe x e y por parâmetro
*/

#include <stdio.h>
#include <stdlib.h>

int potencia(int x, int y) {
    if (y == 0) {
        return 1;
    } else {
        return x * potencia(x, y - 1);
    }
}

int main() {
    int base, expoente, resultado;

    printf("Digite a base: ");
    scanf("%d", &base);

    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    resultado = potencia(base, expoente);

    printf("%d elevado a %d é igual a %d\n", base, expoente, resultado);

    return 0;
}
