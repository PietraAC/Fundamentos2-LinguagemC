/*Na tarde de ontem, 06 de dezembro, alguns servidores da Amazon (AWS) pararam de funcionar. Com isso, diversos serviços ficaram indisponíveis. Dentre eles, os servidores da Riot responsáveis pelos jogos League of Legends, Valorant e Wild Rift.
Você foi convocado em uma missão de emergência para ajudar a identificar os locais das falhas e gerar os relatórios para os técnicos responsáveis por reestabelecer os serviços.

Para isso, a central da Amazon está recebendo as notificações de falhas ao redor do mundo. Você devera implementar um sistema para salvar e processar essas notificações. Para isso:

a) (5 pontos) Aloque dinamicamente um vetor de Notificações de tamanho 5. Cada Notificação é uma estrutura que contém:
* Pais (string tam: 20):
* Cidade(string tam: 20):
* Quantidade de Servidores UP - ativos (inteiro)
* Quantidade de Servidores Down - com problemas (inteiro)

Os países possíveis são: Brasil, EUA, França, Londres, China e Japão

b) (10 pontos) Receba os dados de diversas notificações de falhas e vá armazenando neste vetor de Notificações. A cada vez que o tamanho do vetor se tornar insuficiente, realoque seu tamanho aumentando o vetor em 5 unidades.
Ao receber o valor "fim" como entrada de um pais, o sistema de entradas deverá parar e o vetor tamanho do vetor ajustado ao tamanho exato da quantidade de relatórios.

c) (5 pontos) Salve os dados em um aquivo BINÁRIO chamado "notifications.dat". Feche o arquivo e libere a memória utilizada pelo vetor;

d) (5 pontos) Abra o arquivo gerado anteriormente, carregue os dados em um vetor de Relatórios alocado dinamicamente.

e) (5 pontos) Calcule o total de servidores ativos e com problemas em cada país. Exiba os dados na tela e gere um arquivo MODO TEXTO chamado "report.txt" no seguinte formato:
PAIS       |  UP |DOWN |  RATE|
Brasil     |   80|   30|   25%|
EUA        |  200|   50|   20%|
França     |   80|    5|    6%|
Inglaterra |  100|   12|   11%|
China      |  117|    3|    3%|
Japão      |   45|    5|   10%| 


Obs: Caso você tenha problemas com a alocação dinâmica, faça um vetor estático de tamanho 10 e prossiga nos códigos, você perderá os pontos dessa parte mas prosseguirá normalmente com a nota da parte de arquivos.

Dados de exemplo:

PAIS       |CIDADE     |UP  |DOWN |
EUA        |New York   | 100|   30|
Brasil     |Sao Paulo  |  50|   20|
Inglaterra |Londres    |  70|    8|
Brasil     |Brasilia   |  20|    5|
Brasil     |Fortaleza  |  10|    5|
Japão      |Tokyo      |  45|    5|
EUA        |Boston     |  25|    5|
EUA        |Los Angeles|  50|   10|
França     |Paris      |  50|    4|
China      |Pequim     | 117|    3|
França     |Nice       |  30|    1|
Inglaterra |Manchester |  30|    4|
EUA        |Orlando    |  25|    5|*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Notificacao {
    char pais[20];
    char cidade[20];
    int servidores_up;
    int servidores_down;
};

struct Relatorio {
    char pais[20];
    int total_up;
    int total_down;
};

void realocar(struct Notificacao **vetor, int *tamanho, int *capacidade) {
    *capacidade += 5;
    *vetor = realloc(*vetor, (*capacidade) * sizeof(struct Notificacao));
    if (*vetor == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int capacidade = 5;
    int tamanho = 0;
    struct Notificacao *vetor = malloc(capacidade * sizeof(struct Notificacao));

    if (vetor == NULL) {
        printf("Erro na alocação de memória.\n");
        return EXIT_FAILURE;
    }

    // Receber os dados
    while (1) {
        if (tamanho == capacidade) {
            realocar(&vetor, &tamanho, &capacidade);
        }

        printf("Informe o país (ou 'fim' para encerrar): ");
        fgets(vetor[tamanho].pais, sizeof(vetor[tamanho].pais), stdin);
        vetor[tamanho].pais[strcspn(vetor[tamanho].pais, "\n")] = '\0';

        if (strcmp(vetor[tamanho].pais, "fim") == 0) {
            break;
        }

        printf("Informe a cidade: ");
        fgets(vetor[tamanho].cidade, sizeof(vetor[tamanho].cidade), stdin);
        vetor[tamanho].cidade[strcspn(vetor[tamanho].cidade, "\n")] = '\0';

        printf("Informe a quantidade de servidores UP: ");
        scanf("%d", &vetor[tamanho].servidores_up);

        printf("Informe a quantidade de servidores DOWN: ");
        scanf("%d", &vetor[tamanho].servidores_down);

        tamanho++;

        while (getchar() != '\n'); // Limpar o buffer do teclado
    }



    // Salvar em arquivo binário
    FILE *arquivo_binario = fopen("notifications.dat", "wb");
    if (arquivo_binario == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return EXIT_FAILURE;
    }

    fwrite(vetor, sizeof(struct Notificacao), tamanho, arquivo_binario);
    fclose(arquivo_binario);
    free(vetor);

    // Abrir o arquivo binário e carregar os dados em um vetor de Relatórios
    struct Relatorio *relatorios = malloc(tamanho * sizeof(struct Relatorio));
    if (relatorios == NULL) {
        printf("Erro na alocação de memória.\n");
        return EXIT_FAILURE;
    }

    arquivo_binario = fopen("notifications.dat", "rb");
    if (arquivo_binario == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return EXIT_FAILURE;
    }

    fread(vetor, sizeof(struct Notificacao), tamanho, arquivo_binario);
    fclose(arquivo_binario);

    // Calcular o total de servidores ativos e com problemas em cada país
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (strcmp(vetor[i].pais, relatorios[j].pais) == 0) {
                relatorios[j].total_up += vetor[i].servidores_up;
                relatorios[j].total_down += vetor[i].servidores_down;
                break;
            }
        }
    }

    // Exibir os dados na tela e gerar o arquivo de relatório em modo texto
    FILE *arquivo_texto = fopen("report.txt", "w");
    if (arquivo_texto == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return EXIT_FAILURE;
    }

    fprintf(arquivo_texto, "PAIS       |  UP |DOWN |  RATE|\n");

    for (int i = 0; i < tamanho; i++) {
        float taxa = (float)relatorios[i].total_down / relatorios[i].total_up * 100;

        fprintf(arquivo_texto, "%-11s|%5d|%5d|%6.0f%%|\n", relatorios[i].pais, relatorios[i].total_up, relatorios[i].total_down, taxa);
        printf("%-11s|%5d|%5d|%6.0f%%|\n", relatorios[i].pais, relatorios[i].total_up, relatorios[i].total_down, taxa);
    }

    fclose(arquivo_texto);
    free(relatorios);

    return EXIT_SUCCESS;
}

