
void Mode_test(void) {

  // *********** Test for  mode ***********
  if ((Mode.indexOf("Solid") >= 0) ) {

    // Strip the mode from text leaving only the colour value
    String Colour = Mode;
    Colour.replace("Solid", "");

    // Convert message to int
    int Colour_Value = Colour.toInt();
    // Test if value is in range 1-255
    if (Colour_Value > 0 && Colour_Value < 256) {

      LEDS_Light_All(Colour_Value, Intensity, 1);
    }

  } // End of test



  // *********** Test for  mode ***********
  if ((Mode.indexOf("Off") >= 0) ) {
    LEDS_Light_All(0, 255, 1);  // Colour (0=black), Brightness, update speed
  }



  // *********** Test for  mode ***********
  if ((Mode.indexOf("Random") >= 0) ) {

    int Colour = random8(); int Digit = random16(NUM_LEDS);

    leds[Digit] = CHSV( Colour, 255, Intensity); // Set Colour, Saturation, Brightness
    FastLED.show(); // Update display

  } // End of test



  // *********** Test for  mode ***********
  if ((Mode.indexOf("Scan") >= 0) ) {

    scan();

  } // End of test



  // *********** Test for  mode ***********
  if ((Mode.indexOf("Confetti") >= 0) ) {

    confetti(Intensity);

  } // End of test



  // *********** Test for  mode ***********
  if ((Mode.indexOf("Rainbow") >= 0) ) {

    rainbow();

  } // End of test



  // *********** Test for  mode ***********
  if ((Mode.indexOf("Glitter") >= 0) ) {

    rainbowWithGlitter();

  } // End of test



  // *********** Test for  mode ***********
  if ((Mode.indexOf("Juggle") >= 0) ) {

    juggle();

  } // End of test



  // *********** Test for  mode ***********
  if ((Mode.indexOf("Sweep") >= 0) ) {

    if (gHue >= Animation_Speed) {
      gHue = 0;

      Sweep_Colour++; // next colour

      // Sweep_Colour is only 8 bits so after 255 will role to 0
      if (Sweep_Colour == 0) {
        Sweep_Colour = 1;
      }

      LEDS_Light_All(Sweep_Colour, Intensity, 1);   // Set all LED's to this colour, Intensity, update this fast

    } // End of sweep gHue test

  } // End of test



} // End of function
