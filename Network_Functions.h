
// Reboot function
void Reboot_ESP() {
  // Send report
  String Report = "Rebooting....."; Serial.println("Status Report = " + Report);
  server.send(200, "text/plain", Report);
  delay(1000);
  ESP.reset();
} // Function end



// Status request "/"
void Send_Status() {
  // Send report
  String Report = Status_Report(); Serial.println("Status Report = " + Report);
  server.send(200, "text/plain", Report);
} // Function end



// Other message, maybe a mode or other command
void Other_Message() {
  String message = server.uri();

  // Test received data for command, mode etc
  RX_Test_Function(message);

  // Send status
  String Report = Status_Report(); Serial.println("Status Report = " + Report);
  server.send(200, "text/plain", Report);
} // Function end



void WiFi_Startup(const char* ssid, const char* password) {

  WiFi_SSID = ssid;               // Set Access point name used by report

  Serial.print("Connecting to "); Serial.print(ssid); Serial.print("  ");

  // Static IP Setup
  WiFi.config(ip, gateway, subnet);

  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  int TimeOut = 0;  // Reset timeout counter

  // Loop while not connected and timeout timer still running
  while (WiFi.status() != WL_CONNECTED & TimeOut < 10) {
    // Print connection progress ticker
    delay(500);
    Serial.print(".");
    TimeOut ++;
  }

  // Timed out or connected?
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected");

    // Print the IP address
    Serial.println(WiFi.localIP());
  }

  else {
    Serial.println(" No Wifi Connection!");
  } // End of else

  /* Either we receive a / (root) which is a status only request, or we receive data.
    Never do we never send a 404 as the uri received is also the message. Or maybe a REBOOT command*/
  server.on("/REBOOT", Reboot_ESP);
  server.on("/", Send_Status);
  server.onNotFound(Other_Message);
  // Start the server
  server.begin(); Serial.println("HTTP server started");
  Serial.println("----------------------------------------------");

} // End of wifi startup



void Get_Wifi() {

  Serial.begin(115200);

  Serial.println(""); Serial.println(""); Serial.println("* Starting up *");

  //While not connected to wifi
  while (WiFi.status() != WL_CONNECTED) {

    if (WiFi.status() != WL_CONNECTED) {
      Serial.print("Trying 1 - "); WiFi_Startup(SSID_1, Password_1);      // WiFi start
    }

    if (WiFi.status() != WL_CONNECTED) {
      Serial.print("Trying 2 - "); WiFi_Startup(SSID_2, Password_2);      // WiFi start
    }

    if (WiFi.status() != WL_CONNECTED) {
      Serial.print("Trying 3 - "); WiFi_Startup(SSID_3, Password_3);      // WiFi start
    }

    if (WiFi.status() != WL_CONNECTED) {
      Serial.print("Trying 4 - "); WiFi_Startup(SSID_4, Password_4);      // WiFi start
    }

    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("Trying access points finished trying again!");
    }

  } // End of while loop

} // End of function



