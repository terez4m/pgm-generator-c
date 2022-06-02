#ifndef GER_H_
#define GER_H_

/*Definindo largura, altura e adicionando matriz*/
#define LARGURA 640
#define ALTURA 480
int imagem[480][640];

/*gera numero aleatorio entre n1 e n2, retorna 0 se numeros forem iguais */
int alet(int n1, int n2);

void gera_fundo(int altura, int largura);

void gera_linha(int altura, int largura);

void gera_retangulo(int altura, int largura);

#endif
