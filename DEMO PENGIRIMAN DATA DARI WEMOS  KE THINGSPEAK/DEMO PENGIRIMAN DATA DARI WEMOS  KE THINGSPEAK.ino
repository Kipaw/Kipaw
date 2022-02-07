//--------------- DEMO PENGIRIMAN DATA DARI WEMOS  KE THINGSPEAK ------------
//--------------------- Update 16 September 2021---------------------

//---------------- Include Library ---------------------------------

#include <DHT.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h> 

//-------------- Pengaturan API KEY, dan Koneksi Internet ------------------
// ------------- API Key, sesuaikan dengan API Key masing - masing----------------------
// ------------- SSID dan Password, sesuaikan dengan seting koneksi internet masing-masing
String apikey = "5PXQPJ4IB5365GX3"; // API KEY DARI THINGS SPEAK, Sesuai akun dan kanal masing masing
const char* ssid = "MAKERINDO2";       // SSID
const char* pass = "makerindo2019";       // PSW
const char* server = "api.thingspeak.com";  // SERVER THING SPEAK
WiFiClient client;
unsigned long myChannelNumber = 1648541; 
const char* myWriteAPIKey = "5PXQPJ4IB5365GX3";

//----------------------- VARIABEL ---------------------
#define DHTPIN 4 // Terhubung ke PIN 4 digital
DHT dht (DHTPIN, DHT11); // Tipenya adalah DHT 11 

//---------------------- SETUP -------------------------------- 
void setup() 
{
       Serial.begin(9600);
       delay(10);
       dht.begin();
       Serial.println("Terhubung ke ");
       Serial.println(ssid);
       WiFi.begin(ssid, pass);
       ThingSpeak.begin(client);

       while (WiFi.status() != WL_CONNECTED) 
{
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("Sudah terhubung ke WiFi ");
}
 
void loop() 
{
// ----------------------- Aktifkan ini jika menggunakan data dummy -------------------------------
      float h = 70;
      float t = 40;
                    if (isnan(h) || isnan(t)) 
                 {
                     Serial.println("Gagal membaca data dari DHT 11!");
                      return;
                 }
//-------------------- kirim ke web -------------
                 ThingSpeak.writeField(myChannelNumber, 1,t, myWriteAPIKey);
                 ThingSpeak.writeField(myChannelNumber, 2,h, myWriteAPIKey);
                 delay(100);
                 //ThingSpeak.read();
      Serial.print("Temperatur: ");
      Serial.print(t);
      Serial.print(" Derajat Celsius , Kelembapan: ");
      Serial.print(h);
      Serial.println();
      Serial.println("Mengirim data ke Thingspeak");
}
