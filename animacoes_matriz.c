#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"

#define NUM_PIXELS 25
#define WS2812_PIN 7
#define BUTTON_A_PIN 5
#define BUTTON_B_PIN 6

// Variáveis para o Debounce
volatile uint32_t last_time_A = 0;
volatile uint32_t last_time_B = 0;
volatile bool trigger_anim_A = false;
volatile bool trigger_anim_B = false;

// Rotina de interrupção com Debounce por Software (200ms)
void gpio_irq_handler(uint gpio, uint32_t events) {
    uint32_t current_time = to_ms_since_boot(get_absolute_time());

    if (gpio == BUTTON_A_PIN && (current_time - last_time_A > 200)) {
        last_time_A = current_time;
        trigger_anim_A = true;
    } 
    else if (gpio == BUTTON_B_PIN && (current_time - last_time_B > 200)) {
        last_time_B = current_time;
        trigger_anim_B = true;
    }
}

static inline void put_pixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio0, 0, pixel_grb << 8u);
}

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return ((uint32_t)(r) << 8) | ((uint32_t)(g) << 16) | (uint32_t)(b);
}

void clear_matrix() {
    for (int i = 0; i < NUM_PIXELS; i++) put_pixel(0);
}

// Animação 1: Coração Batendo (5 frames)
const uint8_t heart_frames[5][25] = {
    {0,0,0,0,0, 0,0,0,0,0, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0}, // Ponto
    {0,0,0,0,0, 0,1,0,1,0, 0,1,1,1,0, 0,0,1,0,0, 0,0,0,0,0}, // Coração Pequeno
    {0,1,0,1,0, 1,1,1,1,1, 1,1,1,1,1, 0,1,1,1,0, 0,0,1,0,0}, // Coração Grande
    {0,0,0,0,0, 0,1,0,1,0, 0,1,1,1,0, 0,0,1,0,0, 0,0,0,0,0}, // Coração Pequeno
    {0,0,0,0,0, 0,0,0,0,0, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0}  // Ponto
};

// Animação 2: Carinha Feliz (5 frames)
const uint8_t smile_frames[5][25] = {
    {0,0,0,0,0, 0,1,0,1,0, 0,0,0,0,0, 1,0,0,0,1, 0,1,1,1,0}, // Normal
    {0,0,0,0,0, 0,1,0,0,0, 0,0,0,0,0, 1,0,0,0,1, 0,1,1,1,0}, // Piscando
    {0,0,0,0,0, 0,1,0,1,0, 0,0,0,0,0, 1,0,0,0,1, 0,1,1,1,0}, // Normal
    {0,0,0,0,0, 0,1,0,1,0, 0,0,0,0,0, 1,1,1,1,1, 0,0,0,0,0}, // Sorriso grande
    {0,0,0,0,0, 0,1,0,1,0, 0,0,0,0,0, 1,0,0,0,1, 0,1,1,1,0}  // Normal
};

void play_animation(const uint8_t frames[5][25], uint8_t r, uint8_t g, uint8_t b) {
    uint32_t color = urgb_u32(r, g, b);
    for (int frame = 0; frame < 5; frame++) {
        for (int i = 0; i < NUM_PIXELS; i++) {
            if (frames[frame][i]) put_pixel(color);
            else put_pixel(0);
        }
        sleep_ms(250); 
    }
    clear_matrix();
}

int main() {
    stdio_init_all();

    PIO pio = pio0;
    int sm = 0;
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, false);

    gpio_init(BUTTON_A_PIN);
    gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_A_PIN);

    gpio_init(BUTTON_B_PIN);
    gpio_set_dir(BUTTON_B_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_B_PIN);

    gpio_set_irq_enabled_with_callback(BUTTON_A_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled(BUTTON_B_PIN, GPIO_IRQ_EDGE_FALL, true);

    clear_matrix();

    while (1) {
        if (trigger_anim_A) {
            trigger_anim_A = false;
            play_animation(heart_frames, 200, 0, 0); // Coração Vermelho
        }
        if (trigger_anim_B) {
            trigger_anim_B = false;
            play_animation(smile_frames, 0, 0, 200); // Carinha Azul
        }
        sleep_ms(10);
    }
}