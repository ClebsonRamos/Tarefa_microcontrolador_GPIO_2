#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/pwm.h"
#include "include/frames.c"
#

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
void inicializar_pwm(uint gpio,float clk_div ,uint16_t freq_pwm);

// ------MATRIZ-----

int tamanho_matriz = 5;

uint matrizint[5][5] = {
    {24, 23, 22, 21, 20},
    {15, 16, 17, 18, 19},
    {14, 13, 12, 11, 10},
    {5, 6, 7, 8, 9},
    {4, 3, 2, 1, 0}
};

 

void animar(int x, int y){
	char temp;
	temp = boneco[x][y];
	boneco[x][y] = '*';
	x = x + 2;
	boneco[x][y] = temp;

}

//-----FUNÇÃO PRINCIPAL-----
int main(void){
	// Inicializa matriz de LEDs NeoPixel.
	inicializacao_maquina_pio(PINO_MATRIZ_LED);
	
	
	
	limpar_o_buffer();
	atribuir_cor_ao_led(0,0,255,0);
	escrever_no_buffer(); // Escreve os dados nos LEDs.
	sleep_ms(3000);
	limpar_o_buffer();
	atribuir_cor_ao_led(0,0,500,0);
	escrever_no_buffer(); // Escreve os dados nos LEDs.


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



// a função inicialar pwm precisa ser congigurada com o GPIO que vai ser ultilizado(led, ou buzzer) antes
// frequencia deles é diferente e depois será configurada para uso
void inicializar_pwm(uint gpio,float clk_div ,uint16_t wrap){
	gpio_set_function(gpio,GPIO_FUNC_PWM);
	uint slice_num = pwm_gpio_to_slice_num(gpio);
	pwm_set_clkdiv(slice_num,clk_div);
	pwm_set_wrap(slice_num,wrap);
	pwm_set_enabled(slice_num,true);
}

// Atribui uma cor RGB a um LED.
void atribuir_cor_ao_led(const uint indice, const uint8_t r, const uint8_t g, const uint8_t b) {
    // Aplica redução de 50% na intensidade das cores
    leds[indice].R = (r * 128) / 255;  // Reduz a intensidade pela metade
    leds[indice].G = (g * 128) / 255;
    leds[indice].B = (b * 128) / 255;
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
		if ( letra == '1'){
			matriz = matriz_1;
		}
		if (letra == '8')
		{
			matriz = boneco;
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
