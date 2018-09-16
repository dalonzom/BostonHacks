// Open a serial connection and launch data collection

void setup(){
  // Open serial connection.
  Serial.begin(9600);
  Serial.write('1'); 
}

void loop(){ 
//S  Serial(println("waiting...");
  
  if(Serial.available() > 0){   
    Serial.println("Signal Received");
    int BostonHacks();
    Serial.write('0');
  }
} 
