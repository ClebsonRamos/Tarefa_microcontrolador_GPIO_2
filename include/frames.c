#include "frames.h"
/*
R = vermelho
G = verde
B = azul
Y = amarelo
P = rosa
C = ciano
w = brando
* = apagado

*/


void contador_valter(){
  
  int time = 1000;
  for(int i = 0; i < 9; i++){
    char num = '0' + 1;
    desenho(num);
    escrever_no_buffer(); // Escreve os dados nos LEDs.
    sleep_ms(time);
    limpar_o_buffer();
  }
  }

  char matriz_0[5][5]={
  {'*','Y','Y','Y','*'},
  {'*','Y','*','Y','*'},
  {'*','Y','*','Y','*'},
  {'*','Y','*','Y','*'},
  {'*','Y','Y','Y','*'}
 };
char matriz_1[5][5]={
  {'*','*','W','*','*'},
  {'*','W','W','*','*'},
  {'*','*','W','*','*'},
  {'*','*','W','*','*'},
  {'*','W','W','W','*'}
 };
char matriz_2[5][5]={
  {'*','B','B','B','*'},
  {'*','*','*','B','*'},
  {'*','B','B','B','*'},
  {'*','B','*','*','*'},
  {'*','B','B','B','*'}
 };
char matriz_3[5][5]={
  {'*','R','R','R','*'},
  {'*','*','*','R','*'},
  {'*','*','R','R','*'},
  {'*','*','*','R','*'},
  {'*','R','R','R','*'}
 };
char matriz_4[5][5]={
  {'*','G','*','G','*'},
  {'*','G','*','G','*'},
  {'*','G','G','G','*'},
  {'*','*','*','G','*'},
  {'*','*','*','G','*'}
 };

char matriz_5[5][5]={
  {'*','P','P','P','*'},
  {'*','P','*','*','*'},
  {'*','P','P','P','*'},
  {'*','*','*','P','*'},
  {'*','P','P','P','*'}
 };

 char matriz_6[5][5]={
  {'*','C','C','C','*'},
  {'*','C','*','*','*'},
  {'*','C','C','C','*'},
  {'*','C','*','C','*'},
  {'*','C','C','C','*'}
 };

 char matriz_7[5][5]={
  {'*','Y','Y','Y','*'},
  {'*','*','*','Y','*'},
  {'*','*','*','Y','*'},
  {'*','*','*','Y','*'},
  {'*','*','*','Y','*'}
 };
 char matriz_8[5][5]={
  {'*','W','W','W','*'},
  {'*','W','*','W','*'},
  {'*','W','W','W','*'},
  {'*','W','*','W','*'},
  {'*','W','W','W','*'}
 };

 char matriz_9[5][5]={
  {'*','G','G','G','*'},
  {'*','G','*','G','*'},
  {'*','G','G','G','*'},
  {'*','*','*','G','*'},
  {'*','G','G','G','*'}
 };






