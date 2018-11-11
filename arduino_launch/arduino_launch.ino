// Open a serial connection and launch data collection

void setup(){
  // Open serial connection.
  Serial.begin(9600);
  Serial.write('1'); 
}

void loop(){ 
  if(Serial.available() > 0){      // if data present, blink
    int BostonHacks();
    Serial.write('0');
  }
} 
