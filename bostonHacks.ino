
//Set pin numbers
const int light = A0; 
const int temp = A1; 
const int moisture = A3; 
const int accelerometer = A2;  

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
  pinMode(accelerometer, INPUT); 
  


}

void loop() {
  
  // put your main code here, to run repeatedly:
  int lightReading = analogRead(light); 
  int tempReading = analogRead(temp); 
  int moistureReading = analogRead(moisture); 
  int accelerometerReading = analogRead(accelerometer); 
  Serial.println("Light Reading"); 
  Serial.println(lightReading); 
  Serial.println("Temp Reading"); 
  Serial.println(tempReading); 
  Serial.println("Moisture Reading"); 
  Serial.println(moistureReading);
  Serial.println("Accelerometer Reading"); 
  Serial.println(accelerometerReading);  
  runtime = millis(); 
  Serial.println("Time"); 
  Serial.println(runtime); 

  Serial.println("Temp Reading"); 
  Serial.println(lightReading); 

  delay(1000); 


}
