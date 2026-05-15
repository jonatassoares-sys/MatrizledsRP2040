# RP2040 — Geração de Animações em Matriz de LEDs 5x5

## Objetivo
Criação de sistemas visuais interativos em matriz de LEDs 5x5 (WS2812) utilizando o microcontrolador Raspberry Pi Pico W. O projeto foca no controle via botões A e B da placa BitDogLab dentro do ambiente de simulação Wokwi, incorporando algoritmos de debounce para tratamento de sinais e integração sonora opcional via buzzer.

---

## Descrição das Animações

### Animação 1 — Desenho Coração
Animação em 5 frames representando um coração na cor vermelha que simula um batimento cardíaco, expandindo-se a partir de um ponto central para um coração pequeno, atingindo seu tamanho máximo e retraindo novamente para gerar o efeito de pulsação, acionada pelo botão A (GPIO 5).

### Animação 2 — Carinha Feliz
Animação em 5 frames representando um rosto sorridente na cor azul, que executa expressões interativas através das mudanças de quadros, simulando o movimento de piscar o olho direito e, em seguida, a ampliação do sorriso, acionada pelo botão B (GPIO 6).

---

## Especificações Técnicas
- Microcontrolador: Raspberry Pi Pico W
- Matriz de LEDs: 5x5 WS2812
- Botões: GPIO 5 (A) e GPIO 6 (B)
- Linguagem: C
- Ambiente: VS Code + Pico SDK + simulador Wokwi
- Debounce por software implementado
- Código modular com função desenho_pio para exibição de frames

---

## Como Executar
1. Clone este repositório:
    bash
    git clone https://github.com/jonatassoares-sys/MatrizledsRP2040.git
    

2. Compile o projeto com o *Pico SDK*.
3. Execute a simulação no *Wokwi* ou grave o firmware no Raspberry Pi Pico W.
4. Pressione o botão *A* para executar a animação do coração.
5. Pressione o botão *B* para executar a animação da Carinha Feliz.

---

## Organização da Equipe
- *Líder de Projeto:* [JÔNATAS DE SOUSA SOARES DA CRUZ] — responsável pelo gerenciamento do repositório e revisão dos pull requests.
- *Desenvolvedor 1:* [NATAN ÉDER VALERIANO] — responsável pela animação Coração.
- *Desenvolvedor 2:* [JÔNATAS DE SOUSA SOARES DA CRUZ] — responsável pela animação carinha feliz.

---

## Demonstração em Vídeo
Assista ao vídeo demonstrando o funcionamento das animações:

 [Link para o vídeo]

---

## Conclusão
O projeto foi finalizado com êxito, consolidando as animações planejadas, o tratamento de debounce via software e a plena operação da matriz WS2812. Todo o ciclo de desenvolvimento está registrado no GitHub, com o vídeo demonstrativo comprovando a funcionalidade da solução.
---

## Licença
Este projeto é destinado exclusivamente para fins acadêmicos na disciplina *ELET0021 — Microcontroladores e Microprocessadores*.
