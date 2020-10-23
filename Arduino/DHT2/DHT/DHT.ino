// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"
//beep yuan cheng ying ping huo zhe liao tian hysm
#define DHTPIN 2     // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(13,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(13,HIGH);
  dht.begin();
//  analogWrite(10, 150);///
}
int count=0;
char commond;
void loop() {
////  Serial.write(Serial.read());
//  if(Serial.read()=='b')
//  {
//    analogWrite(10, 150);
//    analogWrite(10, 0);
//  }
//   if(Serial.read()=='s')//yao liang ge s ying wei read le jiu 
//  {
//    analogWrite(10, 0);
//  }
//   if(Serial.readStringUntil("0")=="StopBeep") //yanchi? mei fen zhong ping jun
//  {
//    analogWrite(10, 0);
//  }
  // Wait a few seconds between measurements.
//  delay(2000);
  commond=Serial.read();

    if(commond=='b')
  {
    analogWrite(10, 150);
//    analogWrite(10, 0);
  }
   if(commond=='s')//yao liang ge s ying wei read le jiu 
  {
    analogWrite(10, 0);
  }

  Serial.print("Light Index:");
  Serial.println(analogRead(A0));
  count++;
  if(count==100){  
    count=0;
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
 
  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  }
}
