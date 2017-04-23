/* Connection detials for WiFi and board functions 

** Commands **
/REBOOT         =   Device reboot. Only works when either reset button pressed or power up, not working correctly if just program uploaded
/Speed=123      =   Animation speed set to 123
/Bright=50      =   Set Brightness to 50
/Mode=Off       =   Mode set to off
/Mode=Solid123  =   Set solid colour 123
/Mode=Glitter   =   Set to glitter mode
/Mode=Scan      =   Set to Scan mode
/Mode=Confetti  =   Set to Confetti mode
/Mode=Rainbow   =   Set to Rainbow mode
/Mode=Juggle    =   Set to Juggle mode
/Mode=Sweep     =   Sweeps through the colour range at the speed set by Speed= command
*/

// Add Access point SSID and Passphrase
const char* SSID_1 = "";
const char* Password_1 = "";

const char* SSID_2 = "";
const char* Password_2 = "";

const char* SSID_3 = "";
const char* Password_3 = "";

const char* SSID_4 = "";
const char* Password_4 = "";


// Set Local IP Address
IPAddress ip(192, 168, 1, 181);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

// LED Display settings
#define DATA_PIN    2               // Connection for WS2812 LED data
#define NUM_LEDS    150             // Number of LED's

// Custom default values
String WiFi_SSID = "TBA";           // SSID string
volatile int Intensity = 255;       // Default brightness
String Mode = "None";               // Default mode
volatile int Animation_Speed = 50;  // Speed for Animation such as the Glitter mode


