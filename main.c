#include <stdio.h>
#include <stdlib.h>

#define LINHAS 5
#define COLUNAS 8

void printarMatriz(int matriz[LINHAS][COLUNAS]) {
    printf("\n--- MATRIZ DE PALAVRAS CRUZADAS ---\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            // %3d serve para alinhar os números com até 3 casas decimais
            printf("%3d ", matriz[i][j]);
        }
        printf("\n"); // Quebra de linha ao fim de cada linha da matriz
    }
    printf("-----------------------------------\n");
}

int main(){

    int matriz[LINHAS][COLUNAS] = {
    { 0, -1,  0, -1, -1,  0, -1,  0},
    { 0,  0,  0,  0, -1,  0,  0,  0},
    { 0,  0, -1, -1,  0,  0, -1,  0},
    {-1,  0,  0,  0,  0, -1,  0,  0},
    { 0,  0, -1,  0,  0,  0, -1, -1}
};

    printarMatriz(matriz);

    int contador = 0;

    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            if (matriz[i][j] == 0)
            {
                int ja_numerou = 0;

                //Vertical
                if (i == 0 || matriz[i-1][j] == -1)
                {
                    if (i + 1 < LINHAS && matriz[i+1][j] != -1)
                    {
                        contador++;
                        matriz[i][j] = contador;
                        ja_numerou = 1; 
                    }
                }

                //Horizontal
                if (j == 0 || matriz[i][j-1] == -1)
                {
                    if (j + 1 < COLUNAS && matriz[i][j+1] != -1)
                    {
                        if (!ja_numerou) {
                            contador++;
                            matriz[i][j] = contador;
                        }
                    }
                }
            }
        }
    }

    printarMatriz(matriz);

    return 0;
}