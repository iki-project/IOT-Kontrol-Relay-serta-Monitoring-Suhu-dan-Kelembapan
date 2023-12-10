#include "DHT.h"
#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>
#define DHTPIN D8     //Pin apa yang digunakan
 
#define DHTTYPE DHT11   // DHT 11
 
DHT dht(DHTPIN, DHTTYPE);
 
FirebaseData dhanfirebase;
String a;
int b;
float c;
 
 
void konekwifi(){
  Serial.println("Starting Wifi, Please Wait");
  WiFi.begin("INI_WIFI","bismillah27"); //Name WIfi and Pass Wifi
  while(!(WiFi.status() == WL_CONNECTED)){
    delay(500);
    Serial.print("...");
  }
  Serial.println("");
  Serial.println("connected");
}
 
 void setup() {
  Serial.begin(9600);
  dht.begin();
  konekwifi();
  Firebase.begin("monitoring-7762f.firebaseio.com","xyGPrwvo2pCEotSvwu2f4SGimHfBAPLKjUV1XoNW");
 
}
 
void loop() {
  Firebase.setFloat(dhanfirebase,"Humidity", dht.readHumidity());
  Firebase.setFloat(dhanfirebase,"Temperatur", dht.readTemperature());
  Firebase.getFloat(dhanfirebase,"Temperatur");
  a = dhanfirebase.floatData();
  Firebase.getFloat(dhanfirebase,"Humidity");
  b = dhanfirebase.floatData();
  Serial.print(" Temperatur = ");
  Serial.println(a);
  Serial.print(" Humidity = ");
  Serial.println(b);
  Serial.print("}\n");
 
  delay(20000);
}
