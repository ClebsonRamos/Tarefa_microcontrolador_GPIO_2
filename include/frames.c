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


void contador(){
  
   
  desenho('0');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(1000);
	limpar_o_buffer();
	
	desenho('1');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(1000);
	limpar_o_buffer();
	
	desenho('2');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(1000);
	limpar_o_buffer();

	desenho('3');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(1000);
	limpar_o_buffer();
	
	desenho('4');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(1000);
	limpar_o_buffer();

	desenho('5');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(1000);
	limpar_o_buffer();
	
	desenho('6');
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(1000);
	limpar_o_buffer();
  
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
  {'R','R','R','R','R'},
  {'R','Y','Y','Y','R'},
  {'R','Y','G','Y','R'},
  {'R','Y','Y','Y','R'},
  {'R','R','R','R','R'}
 };
 char matriz_8[5][5]={
  {'Y','Y','Y','Y','Y'},
  {'Y','G','G','G','Y'},
  {'Y','G','C','G','Y'},
  {'Y','G','G','G','Y'},
  {'Y','Y','Y','Y','Y'}
 };

 char matriz_9[5][5]={
  {'G','G','G','G','G'},
  {'G','C','C','C','G'},
  {'G','C','B','C','G'},
  {'G','C','C','C','G'},
  {'G','G','G','G','G'}
 };
 
char mario[5][5]={
  {'R','R','R','R','R'},
  {'R','Y','Y','Y','Y'},
  {'R','B','R','R','B'},
  {'B','B','B','B','B'},
  {'P','P','*','P','P'}
};




