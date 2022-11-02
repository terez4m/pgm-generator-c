#include <stdio.h>
#include <time.h>
#include "libgerador.h"
#include <stdlib.h>

/*programa para gerar imagens PGM contendo 5 retangulos num fundo branco*/

int main(){

    srand(time(NULL)); 
    gera_fundo(ALTURA,LARGURA);
    int x = alet(0, ALTURA);
    int y = alet(0, LARGURA);
    
    gera_labirinto(ALTURA, LARGURA, x, y);
    gera_imagem(64);
}