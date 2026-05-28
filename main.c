#include <stdio.h>
#include <stdlib.h>


#define LINHAS 5
#define COLUNAS 8

int main(){

    int matriz[LINHAS][COLUNAS] = {
    { 0, -1,  0, -1, -1,  0, -1,  0},
    { 0,  0,  0,  0, -1,  0,  0,  0},
    { 0,  0, -1, -1,  0,  0, -1,  0},
    {-1,  0,  0,  0,  0, -1,  0,  0},
    { 0,  0, -1,  0,  0,  0, -1, -1}
};


    int contador = 0;


    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            
            if (matriz[i][j] == 0)
            {

                //Vertical
                if (i == 0 || matriz[i-1][j] == -1)
                {
                    if (matriz[i+1][j] != -1)
                    {
                        contador++;
                        matriz[i][j] = contador;
                    }
                    
                }

                //Horizontal
                if (j == 0 || matriz[i][j-1] == -1)
                {
                    if (matriz[i][j+1] != -1)
                    {
                      
                        contador++;
                        matriz[i][j] = contador;
                        
                    }
                    
                }
                



                
            }

        }
        
    }

}