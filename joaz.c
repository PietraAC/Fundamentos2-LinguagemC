#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct{
    char pais[20];
    char cidade[20];
    int servidor_up;
    int servidor_down;
} Notificacao;

//Recebe os nomes digitados
void Recebeinfo(char nome[20]){
    fgets(nome, 20, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    return;
}

//Verifica se o País é valido ou não
int VerificaPais(char pais_recebido[20],char paises_possiveis[6][20]){
    for (int i = 0; i < 6; i++){
        if (strcasecmp(pais_recebido, paises_possiveis[i]) == 0){
            return 1;//Encontrou país disponivel
        }
    }
   
    return 0;//Não é um país disponivel 
}

void CriaBinario(Notificacao Notifica[], int tam){

    //Cria arquivo binario
    FILE *arqbi;
    arqbi = fopen("notifications.dat", "wb");
    if (arqbi == NULL){
        perror("Erro ao abrir arquivo");
        free(Notifica);
        exit(1);
    }

    //Escreve no arquivo
    fwrite(Notifica, sizeof(Notificacao), tam, arqbi);
    fclose(arqbi);
    free(Notifica);

    return;
}

void LeBinario(Notificacao Report[], int tam){

    FILE *arqbi;
    arqbi = fopen("notifications.dat", "rb");
    if (arqbi == NULL){
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    fread(Report, sizeof(Notificacao), tam, arqbi);
    fclose(arqbi);
    return;
}

void ExibeRelatorio(Notificacao Report[], int tam, char pais_disp[6][20]){

    int somaup[6] = {0, 0, 0, 0, 0, 0};
    int somadown[6] = {0, 0, 0, 0, 0, 0};
    int somador[6]; 
    float porcentagem[6];

    FILE *arqtxt;
    arqtxt = fopen("relatorio.txt", "w");
    if (arqtxt == NULL){
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    
    
    fprintf(arqtxt, "|Pais           |UP   |DOWN |RATE |\n");
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < tam; j++){
            if (strcasecmp(Report[j].pais, pais_disp[i]) == 0){
                somaup[i] += Report[j].servidor_up;
                somadown[i] += Report[j].servidor_down;
            }
            
        }
        somador[i] = somaup[i] + somadown[i];
        porcentagem[i] = (somadown[i] * 100.0) / somador[i];
        fprintf(arqtxt, "|%-15s|%5d |%5d |%2.0f %%\n", pais_disp[i], somaup[i], somadown[i], porcentagem[i]);
    }
    
    fclose(arqtxt);


    return;
}

int main() {

    char paises_disp [6][20] = {"Brasil", "EUA", "Franca", "Inglaterra", "China", "Japao"};
    int tamanho_atual = 0;
    int capacidade = 5;

    //Alocando memoria com nome Notific e retorna erro caso nao consiga
    Notificacao *Notific;
    Notific = malloc(capacidade * sizeof(Notificacao));
    if (Notific == NULL){
        perror("Erro ao alocar memoria\n");
        exit(1);
    }

    while (1){
        
        //Realoca memoria caso necessario para +5 de capacidade
        if (tamanho_atual == capacidade){
            capacidade += 5; 
            Notific = realloc(Notific,capacidade * sizeof(Notificacao));
            if (Notific == NULL){
                free(Notific);
                perror("Erro ao alocar memoria\n");
                exit(1);
            }
        }

        printf("Digite o nome do Pais disponivel ou a 'Fim' para encerrar o programa\n");
        printf("opcoes: Brasil, EUA, Franca, Inglaterra, China, Japao\n");
        Recebeinfo(Notific[tamanho_atual].pais);

        //Verifica se a pessoa quer sair do programa independente de digitar com letra maiuscula ou minuscula
        if (strcasecmp(Notific[tamanho_atual].pais, "fim") == 0) {
            printf("Finalizando programa...\n");
            break;
        }
        
        //Chama função e compara pra ver se pais esta disponivel
        if (VerificaPais(Notific[tamanho_atual].pais, paises_disp) == 0){
            printf("Pais não encontrado... digite novamente\n");
            continue;
        }
        
        printf("Digite o nome da cidade\n");
        Recebeinfo(Notific[tamanho_atual].cidade);

        printf("Digite a quantidade de servidores ativo\n");
        scanf("%d", &Notific[tamanho_atual].servidor_up);
        setbuf(stdin, NULL);

        printf("Digite a quantidade de servidores inativos\n");
        scanf("%d", &Notific[tamanho_atual].servidor_down);
        setbuf(stdin, NULL);

        tamanho_atual++;
    }

    Notificacao *Relatorio;
    Relatorio = malloc(tamanho_atual * sizeof(Notificacao));
    if (Relatorio == NULL){
        perror("Erro ao abrir arquivo");
        free(Notific);
        exit(1);
    }

    CriaBinario(Notific, tamanho_atual);
    LeBinario(Relatorio, tamanho_atual);
    ExibeRelatorio(Relatorio, tamanho_atual, paises_disp);


    free(Relatorio);
    return 0;
}