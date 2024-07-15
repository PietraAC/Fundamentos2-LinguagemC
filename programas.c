#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
    char Nome[20];
    char Raca[20];
    char Classe[20];
    int Nivel;
}Jogador;



int main(){


    int tamanho = 0;
    int capacidade = 5;

    Jogador *jogador = malloc(capacidade * sizeof(Jogador));

    if (jogador == NULL)
    {
        printf("Erro ao alocar a memoria");
        exit(1);
    }

    while (1)
    {
        if (tamanho == capacidade)
        {
            capacidade += 5;
            jogador = realloc(jogador, capacidade * sizeof(Jogador));
            if (jogador==NULL)
            {
                printf("Erro ao realocar a memoria");
                free(jogador);
                exit(1);
            }
            
        }//if

        printf("Digite o seu nivel ou -1 para sair: \n");
        scanf("%d", &jogador[tamanho].Nivel);

        if (jogador[tamanho].Nivel == -1)
        {
            printf("Finalizando..........69696969696969");
            exit(1);
        }
        

        printf("Digite o nome do seu bonequinho: \n");
        scanf("%s",jogador[tamanho].Nome);

        printf("Digite a sua raça: \n");
        scanf("%s",jogador[tamanho].Raca);

        printf("Digite a sua classe: \n");
        scanf("%s",jogador[tamanho].Classe);


        tamanho++;

        
    }

    FILE *nerd_bin = fopen("Nerd_bin.dat","wb");
    if (nerd_bin == NULL)
    {
        printf("Deu merda");
        free(jogador);
        exit(1);
    }

    fwrite(jogador, sizeof(Jogador), tamanho, nerd_bin);
    fclose(nerd_bin);
    free(jogador);



    Jogador *nerds = malloc(tamanho * sizeof(Jogador));

    if (nerds == NULL)
    {
        printf("DEU ERROOOOOO!!!!");
        exit(1);
    }
    
    nerd_bin = fopen("Nerd_bin.dat","rb");
    fread(nerds, sizeof(Jogador), tamanho, nerd_bin);
    fclose(nerd_bin);


    FILE *nerd_excel = fopen("nerd_excel.csv","w");

    if (nerd_excel == NULL)
    {
        printf("ERRO safado 69");
        free(nerds);
        exit(1);
    }

    fprintf(nerd_excel,"|Nivel  |Nome            |Classe|Raça|\n");
    for ( int i = 0; i < tamanho; i++)
    {
            fprintf(nerd_excel, "%d|%s|%s|%s\n" , nerds[i].Nivel, nerds[i].Nome, nerds[i].Classe, nerds[i].Raca);

    }

    fclose(nerd_excel);
    free(nerds);
    
}