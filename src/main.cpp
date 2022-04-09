// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID           "TMPLljOxNZV6"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "OFkOkwDgBGleX-coZVkQxJqPL9DY1td6"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Arduino.h>
#include <LiquidCrystal.h> 
#include <SoftwareSerial.h> 
#include <TinyGPS.h> 
#include <String.h>

char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.
const char* ssid = "Paulina";
const char* pass = "clapeyron";
BlynkTimer timer;

float lat = 28.5458, lon = 77.1703; // create variable for latitude and longitude object  
SoftwareSerial gpsSerial(3, 1);//rx,tx 
LiquidCrystal lcd(22, 21, D2, D3, D8, D9);
TinyGPS gps; // create gps object 
int i = 0;
bool connected = false;
std::string loc = "";


// This function is called every time t /.he device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
}

void setup() {
  Serial.begin(9600); // connect serial 
  gpsSerial.begin(9600); // connect gps sensor 
  lcd.begin(16, 2);
  lcd.print("GPS tracker");
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
  lcd.setCursor(0, 1);
}

void loop() {
  Blynk.run();
  timer.run();
  while (gpsSerial.available() > 0) { // check for gps data 
    Serial.println("a");
    if (gps.encode(gpsSerial.read()))// encode gps data 
    {
      gps.f_get_position(&lat, &lon); // get latitude and longitude 
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("GPS Signal");
      lcd.setCursor(1, 0);
      lcd.print("LAT:");
      lcd.setCursor(5, 0);
      lcd.print(lat);
      lcd.setCursor(0, 1);
      lcd.print(" LON:");
      lcd.setCursor(5, 1);
      lcd.print(lon);
      String latitude = String(lat, 6);
      String longitude = String(lon, 6);
      Blynk.virtualWrite(V1, "lat:" + latitude + " lon:" + longitude); //sending to Blynk
      connected = true;
    }
  }
  if (connected == false)
  {
    lcd.clear();
    lcd.print("Waiting for");
    lcd.setCursor(1, 1);
    lcd.print("signal...");
    lcd.setCursor(12, 1);
    lcd.print(i);
    i++;
  }
  delay(1000);
}
