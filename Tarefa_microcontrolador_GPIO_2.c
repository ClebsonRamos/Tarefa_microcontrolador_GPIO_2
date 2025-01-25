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
void limpar_o_buffer(void);
void escrever_no_buffer(void);

void animacao_seta_para_direita(void);
void animacao_seta_para_esquerda(void);
void animacao_boneco(void);
void animacao_coracao(void);
void animacao_diagonal(void);
void animacao_horizontal(void);

//-----FUNÇÃO PRINCIPAL-----
int main(void){
	// Inicializa matriz de LEDs NeoPixel.
	inicializacao_maquina_pio(PINO_MATRIZ_LED);
	limpar_o_buffer();

	escrever_no_buffer(); // Escreve os dados nos LEDs.

	// A mágica acontece aqui :)
	while (true){
	}
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
void limpar_o_buffer(void){
	for (uint i = 0; i < CONTADOR_LED; ++i)
		atribuir_cor_ao_led(i, 0, 0, 0);
}

// Escreve os dados do buffer nos LEDs.
void escrever_no_buffer(void){
	// Escreve cada dado de 8-bits dos pixels em sequência no buffer da máquina PIO.
	for (uint i = 0; i < CONTADOR_LED; ++i){
		pio_sm_put_blocking(maquina_pio, variavel_maquina_de_estado, leds[i].G);
		pio_sm_put_blocking(maquina_pio, variavel_maquina_de_estado, leds[i].R);
		pio_sm_put_blocking(maquina_pio, variavel_maquina_de_estado, leds[i].B);
	}
	sleep_us(100); // Espera 100us, sinal de RESET do datasheet.
}

// ADICIONAR AS NOVAS FUNÇÕES A PARTIR DAQUI E INCLUIR O PROTÓTIPO.
void animacao_seta_para_direita(void){
    uint vetor[CONTADOR_LED], i, j, frames = 10;

    for(i = 0; i < CONTADOR_LED; i++)
        vetor[i] = 0;
    
    for(i = 0; i < frames; i++){
        switch(i){
            case 1:
                // Liga
                vetor[14] = 1;
                break;
            case 2:
                // Liga
                vetor[5] = 1;
                vetor[13] = 1;
                vetor[15] = 1;
                break;
            case 3:
                // Liga
                vetor[4] = 1;
                vetor[6] = 1;
                vetor[12] = 1;
                vetor[16] = 1;
                vetor[24] = 1;
                // Desliga
                vetor[14] = 0;
                break;
            case 4:
                // Liga
                vetor[3] = 1;
                vetor[7] = 1;
                vetor[11] = 1;
                vetor[17] = 1;
                vetor[23] = 1;
                // Desliga
                vetor[5] = 0;
                vetor[13] = 0;
                vetor[15] = 0;
                break;
            case 5:
                // Liga
                vetor[2] = 1;
                vetor[8] = 1;
                vetor[10] = 1;
                vetor[18] = 1;
                vetor[22] = 1;
                // Desliga
                vetor[4] = 0;
                vetor[6] = 0;
                vetor[12] = 0;
                vetor[16] = 0;
                vetor[24] = 0;
                break;
            case 6:
                // Liga
                vetor[1] = 1;
                vetor[9] = 1;
                vetor[19] = 1;
                vetor[21] = 1;
                // Desliga
                vetor[3] = 0;
                vetor[7] = 0;
                vetor[11] = 0;
                vetor[17] = 0;
                vetor[23] = 0;
                break;
            case 7:
                // Liga
                vetor[0] = 1;
                vetor[20] = 1;
                // Desliga
                vetor[2] = 0;
                vetor[8] = 0;
                vetor[10] = 0;
                vetor[18] = 0;
                vetor[22] = 0;
                break;
            case 8:
                // Desliga
                vetor[1] = 0;
                vetor[9] = 0;
                vetor[19] = 0;
                vetor[21] = 0;
                break;
            case 9:
                // Desliga
                vetor[0] = 0;
                vetor[20] = 0;
                break;
        }
        for(j = 0; j < CONTADOR_LED; j++){
            if(vetor[j] == 0){
                atribuir_cor_ao_led(j, 0, 0, 0);
            }else{
                atribuir_cor_ao_led(j, 0, 0, 1);
            }
        }
        escrever_no_buffer();
        sleep_ms(100);
    }
}

void animacao_seta_para_esquerda(void){
    uint vetor[CONTADOR_LED], i, j, frames = 10;

    for(i = 0; i < CONTADOR_LED; i++)
        vetor[i] = 0;
    
    for(i = 0; i < frames; i++){
        switch(i){
            case 1:
                // Liga
                vetor[10] = 1;
                break;
            case 2:
                // Liga
                vetor[9] = 1;
                vetor[11] = 1;
                vetor[19] = 1;
                break;
            case 3:
                // Liga
                vetor[0] = 1;
                vetor[8] = 1;
                vetor[12] = 1;
                vetor[18] = 1;
                vetor[20] = 1;
                // Desliga
                vetor[10] = 0;
                break;
            case 4:
                // Liga
                vetor[1] = 1;
                vetor[7] = 1;
                vetor[13] = 1;
                vetor[17] = 1;
                vetor[21] = 1;
                // Desliga
                vetor[9] = 0;
                vetor[11] = 0;
                vetor[19] = 0;
                break;
            case 5:
                // Liga
                vetor[2] = 1;
                vetor[6] = 1;
                vetor[14] = 1;
                vetor[16] = 1;
                vetor[22] = 1;
                // Desliga
                vetor[0] = 0;
                vetor[8] = 0;
                vetor[12] = 0;
                vetor[18] = 0;
                vetor[20] = 0;
                break;
            case 6:
                // Liga
                vetor[3] = 1;
                vetor[5] = 1;
                vetor[15] = 1;
                vetor[23] = 1;
                // Desliga
                vetor[1] = 0;
                vetor[7] = 0;
                vetor[13] = 0;
                vetor[17] = 0;
                vetor[21] = 0;
                break;
            case 7:
                // Liga
                vetor[4] = 1;
                vetor[24] = 1;
                // Desliga
                vetor[2] = 0;
                vetor[6] = 0;
                vetor[14] = 0;
                vetor[16] = 0;
                vetor[22] = 0;
                break;
            case 8:
                // Desliga
                vetor[3] = 0;
                vetor[5] = 0;
                vetor[15] = 0;
                vetor[23] = 0;
                break;
            case 9:
                // Desliga
                vetor[4] = 0;
                vetor[24] = 0;
                break;
        }
        for(j = 0; j < CONTADOR_LED; j++){
            if(vetor[j] == 0){
                atribuir_cor_ao_led(j, 0, 0, 0);
            }else{
                atribuir_cor_ao_led(j, 1, 0, 0);
            }
        }
        escrever_no_buffer();
        sleep_ms(100);
    }
}

void animacao_boneco(void){
    int i, frames;
    uint vetor[CONTADOR_LED] = {
        0, 1, 0, 1, 0,
        0, 0, 1, 0, 0,
        1, 0, 1, 0, 1,
        0, 1, 1, 1, 0,
        0, 0, 1, 0, 0
    };

    for(frames = 0; frames < 9; frames++){
        // Atualiza os LEDs
        switch(frames){
            case 1:
                vetor[10] = 0;
                vetor[19] = 1;
                break;
            case 2:
                vetor[19] = 0;
                vetor[20] = 1;
                break;
            case 3:
                vetor[19] = 1;
                vetor[20] = 0;
                break;
            case 4:
                vetor[19] = 0;
                vetor[10] = 1;
                break;
            case 5:
                vetor[14] = 0;
                vetor[15] = 1;
                break;
            case 6:
                vetor[15] = 0;
                vetor[24] = 1;
                break;
            case 7:
                vetor[24] = 0;
                vetor[15] = 1;
                break;
            case 8:
                vetor[15] = 0;
                vetor[14] = 1;
                break;
        }
        for(i = 0; i < CONTADOR_LED; i++){
            if(vetor[i] == 1){
                atribuir_cor_ao_led(i, 0, 0, 1);
            } else{
                atribuir_cor_ao_led(i, 0, 0, 0);
            }
        }
        escrever_no_buffer();
        sleep_ms(500);
    }
}

void animacao_coracao(void){
    int i, frames;
    uint vetor[CONTADOR_LED] = {
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    };

    for(frames = 0; frames < 6; frames++){
        // Atualiza os LEDs
        switch(frames){
            case 1:
                vetor[12] = 1;
                break;
            case 2:
                vetor[12] = 2;
                vetor[7] = 1;
                vetor[11] = 1;
                vetor[13] = 1;
                vetor[17] = 1;
                break;
            case 3:
                vetor[12] = 3;
                vetor[7] = 2;
                vetor[11] = 2;
                vetor[13] = 2;
                vetor[17] = 2;
                vetor[2] = 1;
                vetor[6] = 1;
                vetor[8] = 1;
                vetor[10] = 1;
                vetor[14] = 1;
                vetor[16] = 1;
                vetor[18] = 1;
                vetor[22] = 1;
                break;
            case 4:
                vetor[15] = 1;
                vetor[19] = 1;
                vetor[21] = 1;
                vetor[23] = 1;
                vetor[16] = 2;
                vetor[18] = 2;
                break;
            case 5:
                vetor[22] = 0;
                vetor[17] = 1;
                break;
        }
        for(i = 0; i < CONTADOR_LED; i++){
            switch(vetor[i]){
                case 0:
                    atribuir_cor_ao_led(i, 0, 0, 0);
                    break;
                case 1:
                    atribuir_cor_ao_led(i, 1, 0, 0);
                    break;
                case 2:
                    atribuir_cor_ao_led(i, 0, 1, 0);
                    break;
                case 3:
                    atribuir_cor_ao_led(i, 0, 0, 1);
                    break;
            }
        }
        escrever_no_buffer();
        sleep_ms(500);
    }
}

void animacao_diagonal(void){
    int i, frames, alternador = 0;
    uint vetor[CONTADOR_LED] = {
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    };

    for(frames = 0; frames < 10; frames++){
        for(i = 0; i < CONTADOR_LED; i++){
            switch(alternador){
                case 0:
                    if(i % 2 == 0){
                        vetor[i] = 1;
                    }else{
                        vetor[i] = 0;
                    }
                    break;
                case 1:
                    if(i % 2 == 1){
                        vetor[i] = 1;
                    }else{
                        vetor[i] = 0;
                    }
                    break;
            }
        }
        for(i = 0; i < CONTADOR_LED; i++){
            if(vetor[i] == 1){
                atribuir_cor_ao_led(i, 0, 0, 0);
            }else{
                atribuir_cor_ao_led(i, 0, 0, 1);
            }
        }
        alternador++;
        if(alternador == 2)
            alternador = 0;
        escrever_no_buffer();
        sleep_ms(500);
    }
}

void animacao_horizontal(void){
    int i, j, frames, alternador = 0;
    uint vetor[CONTADOR_LED] = {
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0
    };

    for(frames = 0; frames < 10; frames++){
        for(i = 0; i < 5; i++){
            for(j = 0; j < 5; j++){
                if(i % 2 == alternador){
                    vetor[i * 5 + j] = 1;
                }else{
                    vetor[i * 5 + j] = 0;
                }
            }
        }
        alternador++;
        if(alternador == 2)
            alternador = 0;
        for(i = 0; i < CONTADOR_LED; i++){
            if(vetor[i] == 0){
                atribuir_cor_ao_led(i, 1, 0, 1);
            }else{
                atribuir_cor_ao_led(i, 1, 1, 0);
            }
        }
        escrever_no_buffer();
        sleep_ms(500);
    }
}