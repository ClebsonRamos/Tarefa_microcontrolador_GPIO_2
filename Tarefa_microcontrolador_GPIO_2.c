#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "include/frames.c"


// Biblioteca gerada pelo arquivo .pio durante compilação.
#include "ws2818b.pio.h"

// Definição do número de LEDs e pino.
#define CONTADOR_LED 25
#define PINO_MATRIZ_LED 7
#define PINO_BUZZER_A 21
#define PINO_BUZZER_B 10
// #define PINO_BUZZER não sei a porta
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
void atribuir_cor_ao_led(const uint indice, const uint8_t r, const uint8_t g, const uint8_t b, uint8_t intensidade);
void limpar_o_buffer();
void escrever_no_buffer();
void desenho(char letra);
void beep(int frequency);

// ------MATRIZ-----

int tamanho_matriz = 5;

uint matrizint[5][5] = {
    {24, 23, 22, 21, 20},
    {15, 16, 17, 18, 19},
    {14, 13, 12, 11, 10},
    {5, 6, 7, 8, 9},
    {4, 3, 2, 1, 0}
};

uint8_t intensidade = 255; 
//-----FUNÇÃO PRINCIPAL-----
int main(void){
	// Inicializa matriz de LEDs NeoPixel.
	inicializacao_maquina_pio(PINO_MATRIZ_LED);
	gpio_init(PINO_BUZZER_A);
	gpio_set_dir(PINO_BUZZER_A, GPIO_OUT);
	gpio_init(PINO_BUZZER_B);
	gpio_set_dir(PINO_BUZZER_B, GPIO_OUT);
	
	
	
	limpar_o_buffer();
	
	intensidade = 100;
	contador();
	desenho('M');
	escrever_no_buffer();

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
void atribuir_cor_ao_led(const uint indice, const uint8_t r, const uint8_t g, const uint8_t b, uint8_t intensidade) {
    
    if (intensidade > 255) intensidade = 255;
    if (intensidade < 0) intensidade = 0;

    // Ajusta os valores de RGB conforme a intensidade escolhida
    leds[indice].R = (r * intensidade) / 255;
    leds[indice].G = (g * intensidade) / 255;
    leds[indice].B = (b * intensidade) / 255;
}


// Limpa o buffer de pixels.
void limpar_o_buffer(){	
	for (uint i = 0; i < CONTADOR_LED; ++i){
	atribuir_cor_ao_led(i,0,0,0, 255);
	}			
}

void  desenho(char letra){
	char (*matriz)[5];		
		if ( letra == '0'){
			matriz = matriz_0;
		}
		if ( letra == '1'){
			matriz = matriz_1;
		}
		if ( letra == '2'){
			matriz = matriz_2;
		}
		if ( letra == '3'){
			matriz = matriz_3;
		}
		if ( letra == '4'){
			matriz = matriz_4;
		}
		if ( letra == '5'){
			matriz = matriz_5;
		}
		if ( letra == '6'){
			matriz = matriz_6;
		}
		if ( letra == '7'){
			matriz = matriz_7;
		}
		if ( letra == '8'){
			matriz = matriz_8;
		}
		if (letra == 'M'){
		matriz = mario;
		}


	for(int x = 0; x < tamanho_matriz; x++){
		for(int y = 0; y < tamanho_matriz; y++){
			if(matriz[x][y] == 'R'){
				atribuir_cor_ao_led(matrizint[x][y],255,0,0, intensidade);				
			}
			if(matriz[x][y] == 'G'){
				atribuir_cor_ao_led(matrizint[x][y],0,255,0, intensidade);
			}
			if(matriz[x][y] == 'B'){
				atribuir_cor_ao_led(matrizint[x][y],0,0,255, intensidade);
			}  
			if(matriz[x][y] == 'Y'){
				atribuir_cor_ao_led(matrizint[x][y],255,255,0, intensidade);
			}  
			if(matriz[x][y] == 'P'){
				atribuir_cor_ao_led(matrizint[x][y],255,0,255, intensidade);
			}  
			if(matriz[x][y] == 'C'){
				atribuir_cor_ao_led(matrizint[x][y],0,255,255, intensidade);
			}  
			if(matriz[x][y] == 'W'){
				atribuir_cor_ao_led(matrizint[x][y],255,255,255, intensidade);			}  

			if(matriz[x][y] == '*'){
				atribuir_cor_ao_led(matrizint[x][y],0,0,0, intensidade);
			} 
		}			
	}
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
	void beep(int frequency) {
			int period = 1000000 / frequency; // Período em microssegundos
			int half_period = period / 2;

			for (int i = 0; i < 10; i++) {  // Repete 10 vezes para o som
					gpio_put(PINO_BUZZER_A, 1); // Ativa o buzzer
					gpio_put(PINO_BUZZER_B, 1); // Ativa o buzzer
					sleep_us(half_period); // Atraso de meio período

					gpio_put(PINO_BUZZER_A, 0); // Desativa o buzzer
					gpio_put(PINO_BUZZER_B, 0); // Desativa o buzzer
					sleep_us(half_period); // Atraso de meio período
			}
	}
