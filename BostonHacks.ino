

//Set pin numbers
const int light = A0; 
const int temp = A1; 
const int moisture = A3; 


float* light_array[500];
float* temperature_array[500];
float* moisture_array[500];
float* gx_array[500];
float* gy_array[500];
float* gz_array[500];

int runtime = 0; 
void setup() {
  // put your setup code here, to run once:
  /*
  pinMode(tempPerson, INPUT); 
  pinMode(tempRoom, INPUT);
  pinMode(accelerometer, INPUT);
  */ 
  Serial.begin(9600); 
  pinMode(light, INPUT);
  pinMode(temp, INPUT); 
  pinMode(moisture, INPUT); 
  


}

void loop() {
  //set loop count
  int count = 0;
  
  // Take analog sensor readings
  float light_percent = light_map(analogRead(light)); 
  float temperature = temp_conversion(analogRead(temp)); 
  float moisture_val = float(analogRead(moisture)); 
  
  light_array[count] = &light_percent;
  temperature_array[count] = &temperature;
  moisture_array[count] = &moisture_val;
  
  float avg_light = running_avg(*light_array,count);
  float avg_temp = running_avg(*temperature_array,count);
  float avg_moisture = running_avg(*moisture_array,count);
  
  //Print to serial port
  runtime = millis(); 
  Serial.println("Time"); 
  Serial.println(runtime); 
  
  Serial.print("temp: ");
  Serial.print(temperature);
  Serial.print(" avg_temp: ");
  Serial.println(avg_temp);
  
  delay(2000); 


}
