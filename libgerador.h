#ifndef GER_H_
#define GER_H_

/*Definindo largura, altura e adicionando matriz*/
#define LARGURA 1400
#define ALTURA 1400
int imagem[1400][1400];

/*gera numero aleatorio entre n1 e n2, retorna 0 se numeros forem iguais */
int alet(int n1, int n2);

void gera_fundo(int altura, int largura);

void gera_linha(int altura, int largura);

void gera_retangulo(int altura, int largura);

void gera_labirinto(int altura, int largura, int x, int y);

int nao_da_pra_desenhar(int altura, int largura, int x, int y);

void gera_imagem(int num);

#endif
