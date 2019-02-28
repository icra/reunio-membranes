// First we include the libraries
#include <OneWire.h> 
#include <DallasTemperature.h>

// Data wire is plugged into pin 2 on the Arduino 
#define ONE_WIRE_BUS 2 

// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS); 

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup(void) { 
  // start serial port 
  Serial.begin(9600); 
  Serial.println("Dallas Temperature IC Control Library Demo"); 
  // Start up the library 
  sensors.begin(); 
  pinMode(12,OUTPUT);
} 

void loop(void) { 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus 
  Serial.print(" Requesting temperatures..."); 
  sensors.requestTemperatures(); // Send the command to get temperature readings 
  Serial.println("DONE"); 
  Serial.print("Temperature is: ");

  float temp=sensors.getTempCByIndex(0);
  // You can have more than one DS18B20 on the same bus.  
  // 0 refers to the first IC on the wire 
  Serial.print(temp);

  //light led if temperature is above a limit or light off if below
  if(temp>25){
    digitalWrite(12,HIGH);
  }else{
    digitalWrite(12,LOW);
  }
  delay(1000); 

} 
