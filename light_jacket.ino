/**
  * LED fader for ATtiny85
  *
  * Given an RGB led or led strip, this sketch fades the colors.
  * This was written to work for ATtiny85 pin numbers, but could
  * just as well work with any supported chip.
  *
  *          ---
  *   Reset | o | VCC
  *   Pin 3 |   | Pin 2
  *   Pin 4 |   | Pin 1
  *     GND |   | Pin 0
  *          ---
  *
  */

/* Pin # for red, green, and blue LED */
const int RED_LED = 4;
const int GREEN_LED = 0;
const int BLUE_LED = 1;

/* Speed at which colors change; low numbers create a more "jumpy" feel */
const int fadeSpeed = 40;

/* Starting brightness values of R, G, B */
int R_val = 0;
int G_val = 0;
int B_val = 0;

void setup() {
  pinMode(RED_LED, OUTPUT); 
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void fade_color(int ledPin, int *brightness) {
  int r = random(0, 256);
  
  if (r > *brightness) {
    for (; *brightness <= r; *brightness+=5) {
      analogWrite(ledPin, *brightness);
      delay(fadeSpeed);
    }
  } else if (r < *brightness) {
    for (; *brightness >= r; *brightness-=5) {
      analogWrite(ledPin, *brightness);
      delay(fadeSpeed);
    }
  }  
}

void loop() {
  fade_color(RED_LED, &R_val);
  fade_color(GREEN_LED, &G_val);
  fade_color(BLUE_LED, &B_val);
}
