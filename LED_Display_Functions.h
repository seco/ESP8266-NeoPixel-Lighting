// Turn off all LED's
void LEDS_Light_All(int Colour, int Brightness, int Update_Speed) {

  // Loop for each LED
  for (int i = 0; i < NUM_LEDS; i++) {

    if (Colour > 0) {
      leds[i] = CHSV( Colour, 255, Brightness); // Set Colour, Saturation, Brightness
      //   Serial.println(Brightness);
    }
    else {
      leds[i] = CRGB::Black;
    }
    FastLED.show(); // Update display
    delay(Update_Speed);

  } //LED update loop
} // End of LED update


// Light only one LED
void Single_LED(int i,int Colour, int Brightness) {
  leds[i] = CHSV( Colour, 255, Brightness); // Set Colour, Saturation, Brightness
  FastLED.show(); // Update display
}

void scan()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);

  // Scan section below needs to be one less than the number of LED's else it crashes
  int pos = beatsin16(13,0,(NUM_LEDS-1));
//  Serial.println(pos);
  leds[pos] += CHSV( gHue, 255, 192);
}


void confetti(int Brightness)
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( gHue + random8(64), 200, Brightness);
  //  FastLED.show(); // Update display

}


void addGlitter( fract8 chanceOfGlitter)
{
  if ( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}


void rainbow()
{
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
}

void rainbowWithGlitter()
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}

void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16(i+7,0,(NUM_LEDS-1))] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}



