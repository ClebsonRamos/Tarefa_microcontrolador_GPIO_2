#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"

// Biblioteca gerada pelo arquivo .pio durante compilação.
#include "ws2818b.pio.h"

// Definição do número de LEDs e pino.
#define CONTADOR_LED 25
#define PINO_MATRIZ_LED 7

// Definição de pixel GRB
struct pixel_t {
	uint8_t G, R, B; // Três valores de 8-bits compõem um pixel.
};
typedef struct pixel_t LED_da_matriz;

// Declaração do buffer de pixels que formam a matriz.
LED_da_matriz leds[CONTADOR_LED];

// Variáveis para uso da máquina PIO.
PIO maquina_pio;
uint variavel_maquina_de_estado;

//-----PROTÓTIPOS-----
void inicializacao_maquina_pio(uint pino);
void atribuir_cor_ao_led(const uint indice, const uint8_t r, const uint8_t g, const uint8_t b);
void limpar_o_buffer();
void escrever_no_buffer();
void desenho(char letra);

// ------MATRIZ-----

int tamanho_matriz = 5;

uint matrizint[5][5] = {
    {24, 23, 22, 21, 20},
    {15, 16, 17, 18, 19},
    {14, 13, 12, 11, 10},
    {5, 6, 7, 8, 9},
    {4, 3, 2, 1, 0}
};

 char matriz_B[5][5]={
  {'*','B','B','*','*'},
  {'*','B','*','B','*'},
  {'*','B','B','*','*'},
  {'*','B','*','B','*'},
  {'*','B','B','*','*'}
 };

char matriz_A[5][5]={
  {'*','*','R','*','*'},
  {'*','R','*','R','*'},
  {'*','R','R','R','*'},
  {'*','R','*','R','*'},
  {'*','R','*','R','*'}
};  
char matriz_C[5][5]={
  {'*','*','G','*','*'},
  {'*','G','*','G','*'},
  {'*','G','*','*','*'},
  {'*','G','*','G','*'},
  {'*','*','G','*','*'}
};  
char matriz_MARIO[5][5]={
  {'R','R','R','R','R'},
  {'R','P','P','P','P'},
  {'R','B','R','R','B'},
  {'B','B','B','B','B'},
  {'Y','Y','*','Y','Y'}
};  

char arcoiris[5][5]={
	{'R','R','Y','Y','Y'},
  {'P','R','R','Y','G'},
  {'P','P','W','G','G'},
  {'P','B','C','C','G'},
  {'B','B','B','C','C'}
};
char mosaico[5][5]={
{ '*', '*', 'R', '*', '*' },
{ '*', 'R', '*', 'B', '*' },
{ '*', 'G', '*', 'Y', '*' },
{ '*', 'B', '*', 'G', '*' },
{ '*', '*', 'C', '*', '*' }
};


//-----FUNÇÃO PRINCIPAL-----
int main(void){
	// Inicializa matriz de LEDs NeoPixel.
	inicializacao_maquina_pio(PINO_MATRIZ_LED);
	
	limpar_o_buffer();
    for(int i = 1; i < 4; i++){
    switch (i)
    {
    case 1:
        limpar_o_buffer();
        desenho('A');
        break;
    case 2: 
        limpar_o_buffer();
        desenho('B');
        break;
    case 3: 
        limpar_o_buffer();
        desenho('C');
    
    default:
        break;
    }
    sleep_ms(3000);
    }
	
		
	escrever_no_buffer(); // Escreve os dados nos LEDs.

	// A mágica acontece aqui :)
	while (true){
		
	}
	return 0;
}

//-----FUNÇÕES COMPLEMENTARES-----
// Inicializa a máquina PIO para controle da matriz de LEDs.
void inicializacao_maquina_pio(uint pino){
	uint programa_pio, i;
	// Cria programa PIO.
	programa_pio = pio_add_program(pio0, &ws2818b_program);
	maquina_pio = pio0;

	// Toma posse de uma máquina PIO.
	variavel_maquina_de_estado = pio_claim_unused_sm(maquina_pio, false);
	if (variavel_maquina_de_estado < 0) {
		maquina_pio = pio1;
		variavel_maquina_de_estado = pio_claim_unused_sm(maquina_pio, true); // Se nenhuma máquina estiver livre, panic!
	}

	// Inicia programa na máquina PIO obtida.
	ws2818b_program_init(maquina_pio, variavel_maquina_de_estado, programa_pio, pino, 800000.f);

	// Limpa buffer de pixels.
	for (i = 0; i < CONTADOR_LED; ++i) {
		leds[i].R = 0;
		leds[i].G = 0;
		leds[i].B = 0;
	}
}

// Atribui uma cor RGB a um LED.
void atribuir_cor_ao_led(const uint indice, const uint8_t r, const uint8_t g, const uint8_t b){
	leds[indice].R = r;
	leds[indice].G = g;
	leds[indice].B = b;
}

// Limpa o buffer de pixels.
void limpar_o_buffer(){	
	for (uint i = 0; i < CONTADOR_LED; ++i){
	atribuir_cor_ao_led(i,0,0,0);
	}			
}

void  desenho(char letra){
	char (*matriz)[5];
	if (letra == 'A') {
        matriz = matriz_A;
    } 
		if (letra == 'B') {
        matriz = matriz_B;
    }
		if (letra == 'C') {
        matriz = matriz_C;
    }
		if ( letra == 'M'){
			matriz = matriz_MARIO;
		}
		if ( letra == '#'){
			matriz = arcoiris;
		}
		if ( letra == '@'){
			matriz = mosaico;
		}

	for(int x = 0; x < tamanho_matriz; x++){
		for(int y = 0; y < tamanho_matriz; y++){
			if(matriz[x][y] == 'R'){
				atribuir_cor_ao_led(matrizint[x][y],1,0,0);				
			}
			if(matriz[x][y] == 'G'){
				atribuir_cor_ao_led(matrizint[x][y],0,1,0);
			}
			if(matriz[x][y] == 'B'){
				atribuir_cor_ao_led(matrizint[x][y],0,0,1);
			}  
			if(matriz[x][y] == 'Y'){
				atribuir_cor_ao_led(matrizint[x][y],1,1,0);
			}  
			if(matriz[x][y] == 'P'){
				atribuir_cor_ao_led(matrizint[x][y],1,0,1);
			}  
			if(matriz[x][y] == 'C'){
				atribuir_cor_ao_led(matrizint[x][y],0,1,1);
			}  
			if(matriz[x][y] == 'W'){
				atribuir_cor_ao_led(matrizint[x][y],1,1,1);			}  

			if(matriz[x][y] == '*'){
				atribuir_cor_ao_led(matrizint[x][y],0,0,0);
			} 
		}			
	}
}

	
void colorir(char cor){

}

// Escreve os dados do buffer nos LEDs.
void escrever_no_buffer(){
	// Escreve cada dado de 8-bits dos pixels em sequência no buffer da máquina PIO.
	for (uint i = 0; i < CONTADOR_LED; ++i){
		pio_sm_put_blocking(maquina_pio, variavel_maquina_de_estado, leds[i].G);
		pio_sm_put_blocking(maquina_pio, variavel_maquina_de_estado, leds[i].R);
		pio_sm_put_blocking(maquina_pio, variavel_maquina_de_estado, leds[i].B);
	}
	sleep_us(100); // Espera 100us, sinal de RESET do datasheet.
}

// ADICIONAR AS NOVAS FUNÇÕES A PARTIR DAQUI E INCLUIR O PROTÓTIPO.
