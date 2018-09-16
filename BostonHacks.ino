

//Set pin numbers
const int light = A0; 
const int temp = A1; 
const int moisture = A3; 


int light_array[100];
int temperature_array[100];
int moisture_array[100];
//int gx_array[500];
//int gy_array[500];
//int gz_array[500];

int count = 0;
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
