//Library
#include <WiFi.h>    
#include <HTTPClient.h>
#include <UrlEncode.h>

//Koneksi Wi-Fi
const char* ssid = "";
const char* password = "";

//Nomor HP dan API Key-nya
String phoneNumber = "";
String apiKey = "9961588";

String phoneNumber1 = "";
String apiKey1 = "";

String phoneNumber2 = "";
String apiKey2 = "";

//Subfungsi Pengiriman Pesan ke Device 1
void sendMessage(String message){
  // Data to send with HTTP POST
  String url = "https://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);    
  HTTPClient http;
  http.begin(url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200){
    Serial.print("Message 1 sent successfully");
  }
  else{
    Serial.println("Error sending the message 1");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();
}

//Subfungsi Pengiriman Pesan ke Device 2
void sendMessage1(String message){

  // Data to send with HTTP POST
  String url = "https://api.callmebot.com/whatsapp.php?phone=" + phoneNumber1 + "&apikey=" + apiKey1 + "&text=" + urlEncode(message);    
  HTTPClient http;
  http.begin(url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200){
    Serial.print("Message 2 sent successfully");
  }
  else{
    Serial.println("Error sending the message 2");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();
}

//Subfungsi Pengiriman Pesan ke Device 3
void sendMessage2(String message){

  // Data to send with HTTP POST
  String url = "https://api.callmebot.com/whatsapp.php?phone=" + phoneNumber2 + "&apikey=" + apiKey2 + "&text=" + urlEncode(message);    
  HTTPClient http;
  http.begin(url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200){
    Serial.print("Message 3 sent successfully");
  }
  else{
    Serial.println("Error sending the message 3");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();
}

void setup() {
  Serial.begin(115200);
  pinMode(27, INPUT_PULLUP);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  int reading = digitalRead(27);
  // Send Pesan to WhatsAPP
  if (reading == LOW){
  sendMessage("!!! PERINGATAN LANSIA BUTUH BANTUAN !!!");
  }
}
