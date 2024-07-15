/*
 6) Considerando a estrutura ranking do exercício anterior,
escreva um programa que leia o arquivo gerado contendo
os dados dos 5 jogadores.
*/

#include <stdio.h>

// Definição da estrutura do ranking
struct Ranking {
    char nome[50];
    int pontuacao;
};

int main() {
    // Abre o arquivo para leitura
    FILE *arquivo = fopen("ranking.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    struct Ranking jogadores[5];

    // Lê os dados dos jogadores do arquivo
    for (int i = 0; i < 5; i++) {
        char buffer[100]; // Buffer temporário para leitura de linhas
        fgets(buffer, sizeof(buffer), arquivo); // Lê o nome
        sscanf(buffer, "Nome: %s", jogadores[i].nome);

        fgets(buffer, sizeof(buffer), arquivo); // Lê a pontuação
        sscanf(buffer, "Pontuação: %d", &jogadores[i].pontuacao);

        // Ignora a linha em branco
        fgets(buffer, sizeof(buffer), arquivo);
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Exibe os dados lidos
    for (int i = 0; i < 5; i++) {
        printf("Jogador %d:\n", i + 1);
        printf("Nome: %s\n", jogadores[i].nome);
        printf("Pontuação: %d\n", jogadores[i].pontuacao);
        printf("\n");
    }

    return 0;
}

