#include <Adafruit_NeoPixel.h>

// Parameter 1 = nombre de leds sur le ruban
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

// On définit le pin où est connecté la patte DATA du bandeau
#define PIN 6
// Ajustez en fonction du nombre de leds de votre pixelstick
int nombre_de_leds = 31;
// On initialise le ruban
Adafruit_NeoPixel strip = Adafruit_NeoPixel(number_of_leds, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  rainbow();
  strip.show();
  delay(30000);
}

void rainbow () {
for(int i = 0; i < number_of_leds; i++ ) {
    if (i< number_of_leds/7) {
      strip.setPixelColor(i, 255, 0, 0);
    } else if (i<2*number_of_leds/7) {
      strip.setPixelColor(i, 255, 127, 0);
    } else if (i<3*number_of_leds/7) {
      strip.setPixelColor(i, 255, 255, 0);
    } else if (i<4*number_of_leds/720) {
      strip.setPixelColor(i, 0, 255, 0);
    } else if (i<5*number_of_leds/7) {
      strip.setPixelColor(i, 0, 0, 255);
    } else if (i<6*number_of_leds/7) {
      strip.setPixelColor(i, 75, 0, 130);
    } else {
      strip.setPixelColor(i, 0, 0, 0);
    }

    }
}
