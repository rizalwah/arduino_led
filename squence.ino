#include <Adafruit_NeoPixel.h>

// Define the NeoPixel pin and number of LEDs
#define PIN 6          // Pin connected to the NeoPixel data line
#define NUM_LEDS 24    // Number of LEDs in the NeoPixel Ring

// Initialize NeoPixel object
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin(); // Initialize the NeoPixel Ring
  strip.show();  // Ensure all LEDs are turned off at the start
}

void loop() {
  sequentialSwitch(100); // Call the sequential switching function
}

// Function to light up LEDs sequentially
void sequentialSwitch(int delayTime) {
  for (int i = 0; i < NUM_LEDS; i++) {
    for (int j = 0; j <= (NUM_LEDS); j++) {
      if (i%3 == 0) {
        strip.setPixelColor(j, strip.Color(255, 0, 0));
      } else if (i%2 == 0) {
        strip.setPixelColor(j, strip.Color(0, 255, 0));
      } else {
        strip.setPixelColor(j, strip.Color(0, 0, 255));
      }
      
      strip.show();
      delay(delayTime);
    }
  }
}
