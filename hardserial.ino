#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
int motorPin = 16;
int sensor_pin = A0;
int output_value ;
int moisture_percentage;
String moisture,station,postData;
const int min_moisture = 40;

/* Set these to your desired credentials. */
//const char *ssid = "ACCURATE";  //ENTER YOUR WIFI SETTINGS
//const char *password = "h41d4rku";

const char *ssid = "innovate";  //ENTER YOUR WIFI SETTINGS
const char *password = "44444444";

//Web/Server address to read/write from 
const char *host = "192.168.1.4";   //https://circuits4you.com website or IP address of server

void setup() {
  // put your setup code here, to run once:
  delay(1000);
  pinMode(motorPin, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
}

void loop() {
  // put your main code here, to run repeatedly:
  HTTPClient http; //Declare object of class HTTPClient

  output_value = analogRead(sensor_pin);
  moisture_percentage = ( 100 - ( (output_value/1023.00) * 100 ) );
  moisture = String(moisture_percentage);
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage);
  Serial.print("%\n\n");
  if(moisture_percentage < min_moisture) {
     PumpWater();
     station = "ON"; 
    } 
  else{
    StopPump();
    station = "OFF";
  }

//  postData = "$humidity=" + moisture + "&waterPump=" + station ;
  postData = "humidity=" + moisture + "&waterPump=" + station ;
  
  http.begin("http://192.168.1.4/irrigating/postdemo.php");              //Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header

  int httpCode = http.POST(postData);   //Send the request
  String payload = http.getString();    //Get the response payload

  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload

  http.end();  //Close connection
  
  delay(15000);  //Post Data at every 5 seconds
}
void PumpWater(){
   digitalWrite(motorPin, HIGH);
  delay(10000);
  digitalWrite(motorPin, LOW);
}
void StopPump(){
  digitalWrite(motorPin, LOW);
  delay(1000);
}
