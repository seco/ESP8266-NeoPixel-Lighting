/* Updated version using ESP8266WebServer.h for the web server. This send the correct status code of 200 and formats OK for Noed-RED

*/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>       // Github for this library https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WebServer

ESP8266WebServer server(80);

#include <FastLED.h>                // FastLED used to write to LED's https://github.com/FastLED/FastLED

#include "Custom_Settings_IP181.h"  // Custom and Wifi Connection and board details.

// LED version
#include "Received_Data_Test_LED.h" // Custom receive data test, LED or Relay?
// Global variables
#define LED_TYPE    WS2812          // LED type
#define COLOR_ORDER GRB             // Colour order
CRGB leds[NUM_LEDS];                // Array for led data
uint8_t gHue = 0;                   // Rotating "base color" used by many of the patterns
uint8_t Sweep_Colour = 1;           // Sweep colour value 1-255
#include "LED_Display_Functions.h"  // LED display functions
#include "Mode_test_function.h"     // Mode test

#include "Network_Functions.h"      // Read wifi data


void setup(void) {

  /*  Wifi needs to be started soon after reset. With the 150 pixel string it would take too long to
      Set to black before starting wifi. This is a problem because I wanted a green/red status LED with the other
      LED's left off. Solved using fadeToBlackBy
  */

  // This beloe needs to complete fast before starting the Wifi, else Wifi does not connect to AP
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // Fast LED off then signal red/green for status
  fadeToBlackBy( leds, NUM_LEDS, 20); // This works very fast and does not hang the 150 pixel string. (leds, num_leds, fadeBy)
  Single_LED(0, 1, 100);              // Light Red LED
  Get_Wifi();                         // Connect to WiFi, try upto 4 Access Points. This needs tobe very soone after reset!
  Single_LED(0, 96, 100);             // Light Green LED

}

void loop(void) {

  // Timebase for animations, update the TCP read every 1 millisecond
  for (int i = 0; i <= Animation_Speed; i++) {
    server.handleClient();
    delay(1);
  }

  // Inc the animation counter and update the display
  gHue++; FastLED.show();

  Mode_test();

}
