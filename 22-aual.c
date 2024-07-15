#include <stdio.h>
#include <stdlib.h>

int main(){

    int vetor [7] = {10, 20, 30, 40, 50, 60, 70};
    float salario = 20500.50;
    char frase[30] = "ablulable";

    FILE* arquivo = fopen("dadosBinarios.dat", "wb");//data

    fwrite(vetor, sizeof(int), 7 , arquivo);
    fwrite(&salario, sizeof(float), 1 , arquivo);
    fwrite(frase, sizeof(char), 30 , arquivo);

    fclose(arquivo);

    return 0;
}//main