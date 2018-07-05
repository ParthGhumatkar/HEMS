#include <Adafruit_Sensor.h>
#include <DHT.h> // library we are using for sensor
#define DHTPIN 2 // Sensor pin    
#define DHTTYPE DHT11 //Sensor we are using   
#define Cooler 6 // pin we connect our relay one 
#define Heater 5 // pin we connect our relay two
int maxTemp = 27; // The max Temperature for heater to turn off and the cooler to turn on
int minTemp = 25; // The max Temperature for heater to turn on and the cooler to turn off

DHT dht(DHTPIN, DHTTYPE); 

void setup() {
  pinMode(Cooler, OUTPUT); //Output pins 
  pinMode(Heater, OUTPUT);
  Serial.begin(9600);// baute rate 
  dht.begin();
}

void loop() {
  
  delay(2000);
    
  float t = dht.readTemperature(); // Math for the sensor or arduino to detect the value
  
  if ( isnan(t)) {
    Serial.println("DHT sensor not working!"); //If the sensor is not connected properly or has some error 
    return;
  }
  
  if( t > maxTemp) {
      digitalWrite(Cooler, HIGH); // to turn on cooler
      digitalWrite(Heater, LOW);
   
  } else {
     digitalWrite(Cooler, LOW);  // to turn on heater
     digitalWrite(Heater, HIGH); 
  }
   Serial.print(" %\t");
  Serial.print("Temperature: "); // this will show the temperature in Serial Moniter  
  Serial.print(t);
  Serial.println();
  
}
