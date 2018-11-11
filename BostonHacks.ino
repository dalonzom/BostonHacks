
//All code for accelerometer taken from https://github.com/Seeed-Studio/Accelerometer_MMA7660.git
#include <Wire.h>
#include "MMA7660.h"
MMA7660 accelemeter;

//Set pin numbers
const int light = A0; 
const int temp = A1; 
const int moisture = A3; 
const in buzzer = A2; 


int light_array[50];
int temperature_array[50];
int moisture_array[50];
int gx_array[50];
int gy_array[50];
int gz_array[50];

int count = 0;
int runtime = 0;

void setup() {
  // put your setup code here, to run once:
  accelemeter.init();  
  Serial.begin(9600); 
  pinMode(light, INPUT);
  pinMode(temp, INPUT); 
  pinMode(moisture, INPUT);

}

void loop() {
  //set loop count
  // Take analog sensor readings
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
  gx_array[count] = ax*100; 
  Serial.print(gx_array[count]);
  Serial.print(","); 
  gy_array[count] = ay*100;
  Serial.print(gy_array[count]);
  Serial.print(",");  
  gz_array[count] = ax*100; 
  Serial.print(gz_array[count]);
  Serial.print(","); 
  Serial.println(); 

  int avg_light = running_avg(light_array,count);
  int avg_temp = running_avg(temperature_array,count);
  int avg_moisture = running_avg(moisture_array,count);
  int avg_gx = running_avg(gx_array,count);
  int avg_gy = running_avg(gy_array,count);
  int avg_gz = running_avg(gz_array,count);
  
  delay(2000); 
  count++;
  if(count >= 50)
    count = 0;

}
