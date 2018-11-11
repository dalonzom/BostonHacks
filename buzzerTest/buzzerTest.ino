const int buzzer = A2; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(buzzer,OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(buzzer, 10); 
  delay(1000); 

}
