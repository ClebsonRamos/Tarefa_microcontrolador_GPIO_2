# Projeto: Animações em Matriz de LEDs 5x5 com Raspberry Pi Pico W

Este repositório contém a implementação de animações em uma matriz de LEDs 5x5 WS2812 utilizando o microcontrolador Raspberry Pi Pico W. O projeto foi desenvolvido com simulação no ambiente [Wokwi](https://wokwi.com/) e programação em C utilizando o Pico SDK.

## Índice

- [Projeto: Animações em Matriz de LEDs 5x5 com Raspberry Pi Pico W](#projeto-animações-em-matriz-de-leds-5x5-com-raspberry-pi-pico-w)
  - [Índice](#índice)
  - [Objetivo](#objetivo)
  - [Pré-requisitos](#pré-requisitos)
  - [Configuração do Projeto](#configuração-do-projeto)
  - [Funcionalidades](#funcionalidades)
  - [Contribuição](#contribuição)
  - [Testes](#testes)
  - [Apresentação](#apresentação)

## Objetivo

Implementar um sistema que controle animações em uma matriz de LEDs 5x5 com base em comandos de um teclado matricial 4x4, conforme especificado abaixo:

- *Teclas numéricas (0 a 9):* Executam diferentes animações.
- *Teclas especiais:*
  - A: Desliga todos os LEDs.
  - B: Liga todos os LEDs na cor *azul* com intensidade máxima.
  - C: Liga todos os LEDs na cor *vermelha* com 80% de intensidade.
  - D: Liga todos os LEDs na cor *verde* com 50% de intensidade.
  - #: Liga todos os LEDs na cor *branca* com 20% de intensidade.

## Pré-requisitos

- *Software necessário:*
  - Visual Studio Code com extensão C/C++
  - Pico SDK configurado com extensão Raspberry Pi Pico
  - Simulador Wokwi integrado ao VS Code
  - Git para controle de versão
- *Componentes simulados:*
  - Matriz de LEDs WS2812 5x5
  - Teclado matricial 4x4
  - Buzzer 
## Configuração do Projeto

1. Clone este repositório:
   ```bash
   git clone https://github.com/ClebsonRamos/Tarefa_microcontrolador_GPIO_2.git

## Configuração do Ambiente

2. Configure o ambiente do Pico SDK e Wokwi no VS Code:
   - Certifique-se de que o Pico SDK está instalado e configurado no seu sistema.
   - Configure o simulador Wokwi no VS Code seguindo as instruções do site oficial.

3. Compile e execute o projeto no simulador Wokwi:
   - Utilize o comando de build do CMake para compilar o projeto.
   - Carregue a configuração do simulador Wokwi (arquivo wokwi.json) para testar o funcionamento do sistema.

## Estrutura do Repositório
```
Tarefa_microcontrolador_GPIO_2/
├── .vscode/                           # Função principal e inicialização
├── incluir/                           # Adiciona suporte a PWM
├── .gitignore                         # Arquivo de configuração do Git
├── CMakeLists.txt                     # Adicionado função para framework CMake
├── README.md                          # Documentação do projeto
├── Tarefa_microcontrolador_GPIO_2.c   # Código principal com mudanças sobre o pino
├── pico_sdk_import.cmake              # Função principal e inicialização do SDK
├── WS2818B.PIO                        # Função principal e inicialização
```

## Funcionalidades

1. *Animações personalizadas*:
   - 9 animações diferentes controladas pelas teclas numéricas.
   - Cada animação possui pelo menos 5 quadros com FPS definido.
   - A tecla númerica "1" gera um sinal sonoro com o buzzer junto com a animação.

2. *Modo de controle*:
   - Alteração do estado da matriz de LEDs com base nas teclas especiais.

## Contribuição

- Cada membro do grupo possui um branch específico para suas alterações.
- Alterações são realizadas via *pull requests* e revisadas pelo líder do projeto.
- *Commits regulares* com mensagens descritivas são obrigatórios para manter o controle do projeto.

## Testes

Testes básicos foram implementados para verificar:
- Funcionamento do teclado.
- Controle de LEDs.
- Execução de animações.

## Apresentação

Confira o vídeo com a demonstração do projeto:  
[...](#)
