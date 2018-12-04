// Sensor:

int LM35 = A0;
float SensorValue = 0;
float temperatur = 0;
float temp[5];

#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8

TFT TFTscreen = TFT(cs, dc, rst);

char sensorPrintout[4];

// relay
#define RELAY1  7                       
#define RELAY2  6                       
#define RELAY3  5                       
#define RELAY4  4

void setup() {
Serial.begin(9600);

  TFTscreen.begin();

  TFTscreen.background(0, 0, 0);

  TFTscreen.stroke(255, 255, 255);
  TFTscreen.setTextSize(2);
  TFTscreen.text("Sensor Value :\n ", 0, 0);
  TFTscreen.setTextSize(8);
  
  pinMode(RELAY1, OUTPUT);       
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
}

void loop() {
  {
SensorValue = analogRead(LM35);
temp[1] = (5.0 * analogRead(LM35) * 100.0) / 1024;
delay(1000); // 1 Sekunde Pause zwischen den Messungen machen
temp[2] = (5.0 * analogRead(LM35) * 100.0) / 1024;
delay(1000);
temp[3] = (5.0 * analogRead(LM35) * 100.0) / 1024;
delay(1000);
temp[4] = (5.0 * analogRead(LM35) * 100.0) / 1024;
delay(1000);
temp[5] = (5.0 * analogRead(LM35) * 100.0) / 1024;

temperatur = (temp[1] + temp[2] + temp[3] + temp[4] + temp[5])/5; //Mittelwert aus 5 Messungen bilden

Serial.print(temperatur, 1); //Ausgabe der Temperatur mit einer Nachkommastelle
Serial.println("Grad Celsius");
}
{
  TFTscreen.begin();
  
  String sensorVal = String(temperatur);
  sensorVal.toCharArray(sensorPrintout, 4);
  
  delay(1000);
  
  TFTscreen.background(0, 0, 255);

  TFTscreen.stroke(0, 255, 0);
  TFTscreen.setTextSize(2);
  TFTscreen.text("Grad Celsius :\n ", 0, 0);
  TFTscreen.setTextSize(5);
  
  TFTscreen.stroke(255,255,255);
  TFTscreen.text(sensorPrintout, 0, 20);
  }
  {
//relay
  
   digitalWrite(RELAY1,LOW);           // Turns ON Relays 1
   delay(2000);                                      // Wait 2 seconds
   digitalWrite(RELAY1,HIGH);          // Turns Relay Off
 
}
}
