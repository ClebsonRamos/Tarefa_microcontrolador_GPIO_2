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


void corrida(){
  
  int time = 150;
  desenho('0');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(time);
	limpar_o_buffer();
	
	desenho('1');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(time);
	limpar_o_buffer();
	
	desenho('2');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(time);
	limpar_o_buffer();

	desenho('3');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(time);
	limpar_o_buffer();
	
	desenho('4');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(time);
	limpar_o_buffer();

	desenho('5');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(time);
	limpar_o_buffer();
	
	desenho('6');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(time);
	limpar_o_buffer();

	desenho('7');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(time);
	limpar_o_buffer();

	desenho('8');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(time);
	limpar_o_buffer();

	desenho('9');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(time);
	limpar_o_buffer();

	desenho('A');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(time);
	limpar_o_buffer();

	desenho('B');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(time);
	limpar_o_buffer();

	desenho('C');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(50);
	limpar_o_buffer();
  
}

  char matriz_0[5][5]={
  {'W','*','R','*','Y'},
  {'Y','*','*','*','W'},
  {'W','R','*','*','Y'},
  {'Y','R','B','R','W'},
  {'W','*','B','R','Y'}

 };
char matriz_1[5][5]={
  {'W','*','R','*','Y'},
  {'Y','*','R','*','W'},
  {'W','*','*','*','Y'},
  {'Y','R','B','*','W'},
  {'W','R','B','R','Y'}
 };
char matriz_2[5][5]={
  {'W','*','*','*','Y'},
  {'Y','*','R','*','W'},
  {'W','*','R','*','Y'},
  {'Y','*','*','B','W'},
  {'W','R','*','B','Y'}
 };
char matriz_3[5][5]={
  {'W','*','*','*','Y'},
  {'Y','*','*','*','W'},
  {'W','*','R','*','Y'},
  {'Y','*','R','B','W'},
  {'W','*','*','B','Y'}
 };
char matriz_4[5][5]={
  {'W','*','*','R','Y'},
  {'Y','*','*','*','W'},
  {'W','*','*','*','Y'},
  {'Y','*','R','B','W'},
  {'W','*','R','B','Y'}	
 };

char matriz_5[5][5]={
  {'W','*','R','R','Y'},
  {'Y','*','*','R','W'},
  {'W','*','*','*','Y'},
  {'Y','*','*','B','W'},
  {'W','*','R','B','Y'}	
 };

 char matriz_6[5][5]={
  {'W','*','R','*','Y'},
  {'Y','*','R','R','W'},
  {'W','*','*','R','Y'},
  {'Y','*','*','B','W'},
  {'W','*','*','B','Y'}	
 };

 char matriz_7[5][5]={
  {'W','*','*','*','Y'},
  {'Y','*','R','*','W'},
  {'W','*','R','R','Y'},
  {'Y','*','B','R','W'},
  {'W','*','B','*','Y'}
 };
 char matriz_8[5][5]={
  {'W','*','*','R','Y'},
  {'Y','*','*','*','W'},
  {'W','*','R','*','Y'},
  {'Y','B','R','R','W'},
  {'W','B','*','R','Y'}
 };

 char matriz_9[5][5]={
  {'W','R','*','R','Y'},
  {'Y','*','*','R','W'},
  {'W','*','*','*','Y'},
  {'Y','B','R','*','W'},
  {'W','B','R','R','Y'}
 };
 
char matriz_10[5][5]={
  {'W','R','*','*','Y'},
  {'Y','R','*','R','W'},
  {'W','*','*','R','Y'},
  {'Y','B','*','*','W'},
  {'W','B','R','*','Y'}
};

char matriz_11[5][5]={
  {'W','*','*','*','Y'},
  {'Y','R','*','*','W'},
  {'W','R','*','R','Y'},
  {'Y','B','*','R','W'},
  {'W','B','*','*','Y'}
};

char matriz_12[5][5]={
  {'W','*','R','*','Y'},
  {'Y','*','*','*','W'},
  {'W','R','*','*','Y'},
  {'Y','R','B','R','W'},
  {'W','*','B','R','Y'}
};

char mario[5][5]={
  {'R','R','R','R','R'},
  {'R','Y','Y','Y','Y'},
  {'R','B','R','R','B'},
  {'B','B','B','B','B'},
  {'P','P','*','P','P'}
};




