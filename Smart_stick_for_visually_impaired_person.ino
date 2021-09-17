Ultra sonic and object detection code: 
 // defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance; 
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2); 
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW); 
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH); 
// Calculating the distance
distance= duration*0.034/64; 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}

GPS and GSM Code: 
#include <SoftwareSerial.h>
#include <TinyGPS.h>
int state = 0;
const int pin = 10;
float gpslat, gpslon;
TinyGPS gps;
SoftwareSerial sgps(4, 5);
SoftwareSerial sgsm(2, 3);
void setup()
{
  sgsm.begin(9600);
  sgps.begin(9600);
}
void loop()
{
  while (sgps.available())
  {
    int c = sgps.read();
    if (gps.encode(c))
    {
      gps.f_get_position(&gpslat, &gpslon);
    }
  }
    if (digitalRead(pin) == HIGH && state == 0) {
      sgsm.print("\r");
      delay(1000);
      sgsm.print("AT+CMGF=1\r");
      delay(1000);
      /*Replace XXXXXXXXXX to 10 digit mobile number &
        ZZ to 2 digit country code*/
      sgsm.print("AT+CMGS=\"+8801673077335\"\r");
      delay(1000);
      //The text of the message to be sent.
      sgsm.print("https://www.google.com/maps/?q=");
      sgsm.print(gpslat, 6);
      sgsm.print(",");
      sgsm.print(gpslon, 6);
      delay(1000);
      sgsm.write(0x1A);
      delay(1000);
      state = 1;
    }
  if (digitalRead(pin) == LOW) {
      state = 0; }
  }

Moister sensor code: 
int sensorPin = A0; 
int sensorValue;  
int limit = 300; 
void setup() {
 Serial.begin(9600);
 pinMode(13, OUTPUT);
}
void loop() {
 sensorValue = analogRead(sensorPin); 
 Serial.println("Analog Value : ");
 Serial.println(sensorValue);
 if (sensorValue<limit) {
 digitalWrite(13, HIGH); 
 }
 else {
 digitalWrite(13, LOW); 
 }
  delay(1000); 
}
    
// this code it will get the value from moister sensor and send the value to Arduino and if value is >300 then Arduino will start the buzzer.
