#include <Adafruit_NeoPixel.h>

// On définit le pin où est connecté la patte DATA du bandeau
#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)



// * SD card attached to SPI bus as follows:
// ** MOSI - pin 11
// ** MISO - pin 12
// ** CLK - pin 13
// ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

#include <SPI.h>
#include <SD.h>

File root;
File myFile;

int number_of_leds = 31;
//Ici, le 150 correspond au nombre de led
Adafruit_NeoPixel strip = Adafruit_NeoPixel(number_of_leds, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
   Serial.begin(9600);
  strip.begin();
  strip.show(); // Initialise toute les led à 'off'
  strip.setBrightness(10);

  // Open serial communications and wait for port to open:
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  myFile = SD.open("output.txt");


}

void loop() {
  //led strip commence a zero
  int i = 0;
  
  if (myFile) {
     while (myFile.available()) {
      if (i == (number_of_leds-1)) {
        i=0;
        strip.show();
        delay(100);
        
        }

        
      int red = myFile.parseInt();
      int green = myFile.parseInt();
      int blue = myFile.parseInt();
      strip.setPixelColor(i, red, green, blue);
      i++;
      
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
//  rainbow();
//  strip.show();
//  delay(30000);
}
    

void rainbow () {
    for(int i = 0; i < number_of_leds; i++ ) { // On fait une boucle pour définir la couleur de chaque led
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


void sinusoide(int speed_delay) {
  int middle = round(number_of_leds/2);
  for(int i = middle; i < number_of_leds; i++ ) { 
      strip.setPixelColor(i, 255, 255, 255);
      strip.show();
      int distance = 4*(i-middle)+10;  
      delay(distance);
      
    }

  for(int i = number_of_leds; i > middle; i-- ) {
      strip.setPixelColor(i, 0, 0, 0);
      strip.show();
      int distance = 4*(i - middle)+10;  
      delay(distance);
    }  

 for(int i = middle; i >= 0; i-- ) { 
      strip.setPixelColor(i, 255, 255, 255);
      strip.show();
      int distance = 4*(middle-i)+10;  
      delay(distance);
    }  

 for(int i = 0; i < middle; i++ ) { 
      strip.setPixelColor(i, 0, 0, 0);
      strip.show();
      int distance = 4*(middle-i)+10;  
      delay(distance);
    }  
}


void ClearStrip() {
  int x;
  for(x=0;x<number_of_leds;x++) {
    strip.setPixelColor(x, 0);
  }
  strip.show();
}

