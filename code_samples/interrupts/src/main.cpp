#include <Arduino.h>

#define LED_PIN 10
#define BUTTON_PIN 8

// Create a button pressed state
volatile bool button_pressed; // volatile can change in ISR
volatile bool led_state;

// bool led_state;

// Declare an ISR
void button_isr(void);

void setup() {
  pinMode(LED_PIN, OUTPUT);
  led_state = false;
  digitalWrite(LED_PIN, led_state);

  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(BUTTON_PIN, button_isr, FALLING);
}

void loop() {
  // If the button has been pressed, flip LED state
  // if (button_pressed) {
  //   led_state = !led_state;
  //   button_pressed = false; // reset the button flag
  // }

  // // Write the new led state
  // digitalWrite(LED_PIN, led_state);
}

// put function definitions here:
void button_isr(void) {
  button_pressed = true;
  led_state = !led_state;
  digitalWrite(LED_PIN, led_state);
}
