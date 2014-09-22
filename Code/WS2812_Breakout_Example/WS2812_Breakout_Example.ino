/*

  Modified by Ankit Daftery ( @ankitdaf )
  date : September 20,2014

  SparkFun Electronics
  date: July 25, 2013
  license: GNU GENERAL PUBLIC LICENSE

  Requires the Adafruit NeoPixel library. It's awesome, go get it.
  https://github.com/adafruit/Adafruit_NeoPixel

  This simple example code runs three sets of animations on a group of WS2812
  breakout boards. The more boards you link up, the better these animations
  will look.

  For help linking WS2812 breakouts, checkout our hookup guide:
  https://learn.sparkfun.com/tutorials/ws2812-breakout-hookup-guide

  Before uploading the code, make sure you adjust the two defines at the
  top of this sketch: PIN and LED_COUNT. Pin should be the Arduino pin
  you've got connected to the first pixel's DIN pin. By default it's
  set to Arduino pin 4. LED_COUNT should be the number of breakout boards
  you have linked up.
*/

#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"

#define PIN 4
#define LED_COUNT 1

// Create an instance of the Adafruit_NeoPixel class called "leds".
// That'll be what we refer to from here on...
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  leds.begin();  // Call this to start up the LED strip.
  clearLEDs();   // This function, defined below, turns all LEDs off...
  leds.show();   // ...but the LEDs don't actually update until you call this.
  leds.setPixelColor(0, 0x0000FF);
  leds.show();
}

void loop()
{
  bridge(20);
}



// Sets all LEDs to off, but DOES NOT update the display;
// call leds.show() to actually turn them off after this.
void clearLEDs()
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    leds.setPixelColor(i, 0);
  }
}


void fader() {
  for (int i = 0; i < 0xFF; ++i) {
    clearLEDs();
    leds.setPixelColor(0, i, 0, 0);
    leds.show();
    delay(20);
  }
  for (int i = 0; i < 0xFF; ++i) {
    clearLEDs();
    leds.setPixelColor(0, 0, i, 0);
    leds.show();
    delay(20);
  }

  for (int i = 0; i < 0xFF; ++i) {
    clearLEDs();
    leds.setPixelColor(0, 0, 0, i);
    leds.show();
    delay(20);
  }
}

void blinker(long time) {
  clearLEDs();
  leds.setPixelColor(0, 0, 255, 0);
  leds.show();
  delay(time);
  clearLEDs();
  leds.show();
  delay(time);
}

void ledoff() {
  clearLEDs();
  leds.show();
}

void bridge(long time) {
  int r, g, b;
  r = 0;
  g = 0;
  b = 0;
  // Fade up red
  for (int i = 0; i < 0xFF; ++i) {
    clearLEDs();
    r = i;
    leds.setPixelColor(0, r, g, b);
    leds.show();

    delay(5);
  }

  // Fade up green
  for (int i = 0; i < 0xFF; ++i) {
    clearLEDs();
    g = i;
    leds.setPixelColor(0, r, g, b);
    leds.show();
    delay(5);
  }

  // Fade down red

  for (int i = 255; i > 0; --i) {
    clearLEDs();
    r = i;
    leds.setPixelColor(0, r, g, b);
    leds.show();

    delay(5);
  }


  // Fade up blue
  for (int i = 0; i < 0xFF; ++i) {
    clearLEDs();
    b = i;
    leds.setPixelColor(0, r, g, b);
    leds.show();
    delay(5);
  }


  // Fade down green
  for (int i = 255; i > 0; --i) {
    clearLEDs();
    g = i;
    leds.setPixelColor(0, r, g, b);
    leds.show();
    delay(5);
  }

  // Fade up red
  for (int i = 0; i < 0xFF; ++i) {
    clearLEDs();
    r = i;
    leds.setPixelColor(0, r, g, b);
    leds.show();

    delay(5);
  }

  // Fade down blue

  for (int i = 255; i > 0; --i) {
    clearLEDs();
    b = i;
    leds.setPixelColor(0, r, g, b);
    leds.show();
    delay(5);
  }


  // Fade down red

  for (int i = 255; i > 0; --i) {
    clearLEDs();
    r = i;
    leds.setPixelColor(0, r, g, b);
    leds.show();
    delay(5);
  }
  ledoff();
  delay(5000);

}
