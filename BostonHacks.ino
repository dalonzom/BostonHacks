
//All code for accelerometer taken from https://github.com/Seeed-Studio/Accelerometer_MMA7660.git
#include <Wire.h>
#include "MMA7660.h"
MMA7660 accelemeter;

//Set pin numbers
const int light = A0; 
const int temp = A1; 
const int moisture = A3; 
const int buzzer = A2; 

int light_array[50];
int temperature_array[50];
int moisture_array[50];
int accel_array[50];
unsigned long overallTime[50]; 


int count = 0;
unsigned long runtime = 0;
int overallCount = 0; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  //Serial.println("waiting");
  while(Serial.available() <= 0) {};
  //Serial.println("found");
  accelemeter.init();  
  pinMode(light, INPUT);
  pinMode(temp, INPUT); 
  pinMode(moisture, INPUT);
  pinMode(buzzer, OUTPUT);
  breathing_exercise(buzzer); 
}

void loop() {
  //set loop count
  // Take analog sensor readings
  runtime = millis(); 
  overallTime[count] = runtime; 
  Serial.print(runtime);
  Serial.print(","); 
  int light_percent = light_map(analogRead(light)); 
  Serial.print(light_percent);
  Serial.print(","); 
  int temperature = temp_conversion(analogRead(temp)); 
  Serial.print(temperature);
  Serial.print(","); 
  int moisture_val = analogRead(moisture); 
  Serial.print(moisture_val);
  Serial.print(","); 
  
  light_array[count] = light_percent;
  //Serial.println(light_array[count]);
  temperature_array[count] = temperature;
  moisture_array[count] = moisture_val;
 // Serial.println(moisture_array[count]);

  int8_t x;
  int8_t y;
  int8_t z;
  float ax,ay,az;
  accelemeter.getXYZ(&x,&y,&z);
  accelemeter.getAcceleration(&ax,&ay,&az);
  ax = 100*ax; ay = 100*ay; az = 100*az;
  
  int composite_accel = sqrt(ax*ax+ay*ay+az*az);
  accel_array[count] = composite_accel;
  Serial.print(composite_accel);
  Serial.println("");
  
  int avg_light = running_avg(light_array,count, overallCount);
  int avg_temp = running_avg(temperature_array,count, overallCount);
  int avg_moisture = running_avg(moisture_array,count, overallCount); 
  int avg_accel = running_avg(accel_array,count, overallCount);
  
  if(composite_accel - avg_accel > 30 || moisture_val - avg_moisture > 100 && (overallCount != 0))  {
    trigger_wakeup(buzzer);
    breathing_exercise(buzzer);
  }
  
  delay(5000); 
 
  count++;
  if(count >= 50)
  {
    count = 0;
    overallCount++; 
  }   

}
