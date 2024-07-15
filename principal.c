#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sexo.h"

int main(){

    int tamanhoAtual = 0;
    int capacidade = 5;

    //aloca memória para os pokemons
    Pokemon *pokemons;
    pokemons = malloc(capacidade * sizeof(Pokemon));
    if(pokemons == NULL){
        printf("erro ao alocar\n");
        exit(1);
    }//if

    while(1){

        if(tamanhoAtual == capacidade){
            capacidade+=5;
            pokemons = realloc(pokemons, capacidade * sizeof(Pokemon));
            if(pokemons == NULL){
                printf("erro ao realocar\n");
                free(pokemons);
                exit(1);
            }
        }//if

        printf("Digite o numero do pokemon ou -1 para terminar\n");
        scanf("%d", &pokemons[tamanhoAtual].num);
        setbuf(stdin, NULL);
        

        if(pokemons[tamanhoAtual].num == -1){
            printf("finalizando...");
            break;
        }

        printf("Digite o nome do pokemon\n");
        scanf("%s", pokemons[tamanhoAtual].nome);
        setbuf(stdin, NULL);
        

        printf("Ataque do pokemon\n");
        scanf("%d", &pokemons[tamanhoAtual].ataq);
        setbuf(stdin, NULL);

        printf("defesa do pokemon\n");
        scanf("%d", &pokemons[tamanhoAtual].defesa);
        setbuf(stdin, NULL);

        printf("Especial\n");
        scanf("%d", &pokemons[tamanhoAtual].especial);
        setbuf(stdin, NULL);

        tamanhoAtual++;
    }//while

    //cria binário, escreve e fecha binário
    FILE *arqbi;
    arqbi = fopen("pokemons.dat", "wb");
    if(arqbi == NULL){
        printf("erro ao abrir arquivo");
        free(pokemons);
        exit(1);
    }

    fwrite(pokemons, sizeof(Pokemon), tamanhoAtual, arqbi);
    fclose(arqbi);
    free(pokemons);

//lê binario com o outro pokes
    Pokemon *pokes;
    pokes = malloc(tamanhoAtual * sizeof(Pokemon));
    if (pokes == NULL)
    {
        printf("Deu erro paizao");
        exit(1);
    }
    

    arqbi = fopen("pokemons.dat", "rb");
    if(arqbi == NULL){
        printf("erro ao abrir arquivo");
        free(pokes);
        exit(1);}

    fread(pokes, sizeof(Pokemon), tamanhoAtual, arqbi);

// Abre arquivo CSV

FILE *pokedex_csv;
pokedex_csv = fopen("pokedex.csv", "w");

if (pokedex_csv == NULL) {
    printf("Erro ao abrir o arquivo CSV.\n");
    free(pokes);
    exit(1);
}

fprintf(pokedex_csv, "|Numero  |Nome            |Ataque|Defesa|Especial|\n");
for (int i = 0; i < tamanhoAtual; i++) {
    fprintf(pokedex_csv, "|%5d|%-15s|%5d|%5d|%5d|\n", pokes[i].num,
            pokes[i].nome, pokes[i].ataq, pokes[i].defesa, pokes[i].especial);
}

fclose(pokedex_csv);
free(pokes);

}