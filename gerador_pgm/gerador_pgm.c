#include <stdio.h>
#include <time.h>
#include "libgerador.h"
#include <stdlib.h>

/*programa para gerar imagens PGM contendo 5 retangulos num fundo branco*/


int main(){

    srand(time(NULL)); 
    gera_fundo(ALTURA,LARGURA);
    for(int i = 0; i < 50; i++){
        gera_linha(ALTURA, LARGURA);
    }

    FILE* pgmimg;
    pgmimg = fopen("pgmimg.pgm", "wb");
  
    /*Writing Magic Number to the File*/
    fprintf(pgmimg, "P2\n"); 
  
    /* Writing Width and Height*/
    fprintf(pgmimg, "%d %d\n", LARGURA, ALTURA); 
  
    /* Writing the maximum gray value*/
    fprintf(pgmimg, "255\n"); 
    int temp = 0;
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            temp = imagem[i][j];
  
            /* Writing the gray values in the 2D array to the file */
            fprintf(pgmimg, "%d ", temp);
        }
        fprintf(pgmimg, "\n");
    }
    fclose(pgmimg);
}