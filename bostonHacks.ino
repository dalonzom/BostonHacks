
//Set pin numbers
/*
const int tempPerson = ; 
const int tempRoom = ; 
const int accelerometer = ;  
*/ 
const int light = ; 
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


}

void loop() {
  
  // put your main code here, to run repeatedly:
  lightReading = analogRead(light); 
  Serial.println("Light Reading"); 
  Serial.println(lightReading); 
  delay(100); 
  runtime = millis(); 
  Serial.println("Time"); 
  Serial.println(time); 


}
