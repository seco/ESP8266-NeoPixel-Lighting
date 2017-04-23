// Compose report to return as required, LED and Relay not the same!
String Status_Report()  {

  // WiFi Version
  long rssi = WiFi.RSSI();

  // LED Version status report, note the server send function adds the \n so no need to add in text string
  String Report = Mode + ", " + String(Intensity) + ", " + String(Animation_Speed) + ", " + WiFi_SSID + ", " + rssi + "dB" ;//+ "\n";

  return Report;

} // End of function



// ***************** Testing received message for known command *********************
void RX_Test_Function(String RX_Data) {


  // *********** Test for speed ***********
  if ((RX_Data.indexOf("Speed=") >= 0) ) {

    RX_Data.replace("/Speed=", "");  // Remove the command string characters

    // Convert message to int and range check
    Animation_Speed = RX_Data.toInt();
    // Test if value is in range 0-255
    if (Animation_Speed >= 0 && Animation_Speed < 256) {
    }
    else {
      Animation_Speed = 255;
    }

    Serial.print("Speed set to "); Serial.println(Animation_Speed);

  } // End of test


  // *********** Test for Brightness ***********
  if ((RX_Data.indexOf("Bright=") >= 0) ) {

    RX_Data.replace("/Bright=", "");  // Remove the command string characters

    // Convert message to int and range check
    Intensity = RX_Data.toInt();
    // Test if value is in range 1-255
    if (Intensity > 0 && Intensity < 256) {
    }
    else {
      Intensity = 255;
    }

  } // End of test


  // *********** Test for Mode ***********
  if ((RX_Data.indexOf("Mode=") >= 0) ) {

    RX_Data.replace("/Mode=", "");  // Remove the command string characters

    Mode = RX_Data;

  } // End of test

} // End of function


