
//All code for accelerometer taken from https://github.com/Seeed-Studio/Accelerometer_MMA7660.git
#include <Wire.h>
#include "MMA7660.h"
MMA7660 accelemeter;

//Set pin numbers
const int light = A0; 
const int temp = A1; 
const int moisture = A3; 


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
  int temperature = temp_conversion(analogRead(temp)); 
  int moisture_val = analogRead(moisture); 
  //Serial.println(temperature);
  light_array[count] = light_percent;
  Serial.println(light_array[count]);
  temperature_array[count] = temperature;
  moisture_array[count] = moisture_val;
  Serial.println(moisture_array[count]);

  int8_t x;
  int8_t y;
  int8_t z;
  float ax,ay,az;
  accelemeter.getXYZ(&x,&y,&z);
  accelemeter.getAcceleration(&ax,&ay,&az);
  gx_array[count] = ax; 
  Serial.println(gx_array[count]);
  gy_array[count] = ay; 
  gz_array[count] = ax; 
  
  
  /*
  int avg_light = running_avg(light_array,count);
  int avg_temp = running_avg(temperature_array,count);
  int avg_moisture = running_avg(moisture_array,count);
  
  //Print to serial port
  runtime = millis(); 
  Serial.println("Time"); 
  Serial.println(runtime); 
  
  Serial.print("temp: ");
  Serial.print(temperature);
  Serial.print(" avg_temp: ");
  Serial.println(avg_temp);
  */
  delay(2000); 

  count++;

}
