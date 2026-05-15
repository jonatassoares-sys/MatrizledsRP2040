# RP2040 — Geração de Animações em Matriz de LEDs 5x5

## Objetivo
Criação de um sistema de animações interativas para uma matriz de LEDs WS2812 (5x5), utilizando o microcontrolador Raspberry Pi Pico W. O controle é realizado através dos botões A e B da placa BitDogLab, com integração ao simulador Wokwi. O projeto inclui o tratamento de bouncing via software para os botões e a possibilidade de interface sonora via buzzer.

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
- Botões: GPIO 5 (A) e GPIO 6 (b)
- Linguagem: C
- Ambiente: VS Code + Pico SDK + simulador Wokwi
- Debounce por software implementado
- Código modular com função `desenho_pio` para exibição de frames

---

## Como Executar
1. Clone este repositório:
    ```bash
   git clone https://github.com/jonatassoares-sys/MatrizledsRP2040.git
    ```

2. Compile o projeto com o **Pico SDK**.
3. Execute a simulação no **Wokwi** ou grave o firmware no Raspberry Pi Pico W.
4. Pressione o botão **A** para executar a animação do coração.
5. Pressione o botão **B** para executar a animação do fogo de carinha feliz.

---

## Organização da Equipe
- **Líder de Projeto:** [JÔNATAS DE SOUSA SOARES DA CRUZ] — responsável pelo gerenciamento do repositório e revisão dos pull requests.
- **Desenvolvedor 1:** [NATAN ÉDER VALERIANO] — responsável pela animação Coração.
- **Desenvolvedor 2:** [JÔNATAS DE SOUSA SOARES DA CRUZ] — responsável pela animação Fogo de Artifício.

---

## Demonstração em Vídeo
Assista ao vídeo demonstrando o funcionamento das animações:

 [Link para o vídeo]

---

## Conclusão
A atividade foi concluída com sucesso, implementando as animações propostas, debounce por software, e integração completa com a matriz de LEDs WS2812. O código está versionado no GitHub, e o vídeo de apresentação demonstra o resultado final.

---

## Licença
Este projeto é destinado exclusivamente para fins acadêmicos na disciplina **ELET0021 — Microcontroladores e Microprocessadores**.

---


