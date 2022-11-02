#include <stdlib.h>
#include <stdio.h>
#include "libgerador.h"


/*gera numero aleatorio entre n1 e n2, retorna 0 se numeros forem iguais */
int alet(int n1, int n2){

    if (n1 == n2)
        return 0;

    int num;

    num = (rand() % (n2 - n1 + 1)) + n1;
    return num;
}


void gera_fundo(int altura, int largura){

    int cor;

    for (int x = 0; x<altura; x++){
        for (int y = 0; y < largura; y++){
            cor = alet(200,255);
            imagem[x][y] = cor;
        }
    }
}

void gera_linha(int altura, int largura){

    int x = alet(0, altura);
    int y = alet(0, largura);
    int cor = alet(0,100);
    int direcao = rand() % 100;

    int i;
    /*vai para cima*/
    if(direcao <= 25){
        for(i=x; i< altura; i++){
            x = i;
            imagem[x][y] = cor;
        }
    }/*vai para baixo*/
    else if(direcao > 25 && direcao <= 50){
        for(i=x; i > 0; i--){
            x = i;
            imagem[x][y] = cor;
        }
    }/*vai para esquerda*/
    else if(direcao > 50 && direcao <= 75){
        for(i=y; i > 0; i--){
            y = i;
            imagem[x][y] = cor;
        }
    }/*vai para direita*/
    else{
        for(i=y; i < largura; i++){
            y = i;
            imagem[x][y] = cor;
        }
    }
}

void gera_labirinto(int altura, int largura, int x, int y){
    static int qtd = 0;

    if(qtd == 500)
        return;
    int direcao = rand()%100;
    int i;
    int end;
    
    /*vai para cima*/
    if(direcao <= 25){
        end = alet(x, altura);
        for(i=x; i< end; i++){
            x = i;
            imagem[x][y] = 0;
        }
        qtd++;
        gera_labirinto(altura, largura, x, y);
    }/*vai para baixo*/
    else if(direcao > 25 && direcao <= 50){
        end = alet(0,x);
        for(i=x; i > end; i--){
            x = i;
            imagem[x][y] = 0;
        }
        qtd++;
        gera_labirinto(altura, largura, x, y);
    }/*vai para esquerda*/
    else if(direcao > 50 && direcao <= 75){
        end = alet(0,y);
        for(i=y; i > end; i--){
            y = i;
            imagem[x][y] = 0;
        }
        qtd++;
        gera_labirinto(altura, largura, x, y);
    }/*vai para direita*/
    else{
        end = alet(y, largura);
        for(i=y; i < largura; i++){
            y = i;
            imagem[x][y] = 0;
        }
        qtd++;
        gera_labirinto(altura, largura, x, y);
    }
}


void gera_retangulo(int altura, int largura){

    int esq = alet(0, largura);
    int top = alet(0, altura);
    int cor = alet(0, 100);
    
    for(int x = top; x < altura; x++){
        for(int y = esq; y < altura; y++){
            imagem[x][y] = cor;
        }
    }
}

void gera_imagem(int num){

    char nome[12];
    snprintf(nome, 12, "%d.pgm", num);

    FILE* pgmimg;
    pgmimg = fopen(nome, "wb");
  
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