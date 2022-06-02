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
            cor = alet(230,255);
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