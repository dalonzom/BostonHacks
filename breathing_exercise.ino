void breathing_exercise(int buzzer)  {
  int notes[] = {1136, 1014};
  //Serial.println("Breathing Exercise"); 
  for(int aa = 0; aa < 3; aa++)  {
    tone(buzzer,notes[0],2000);
    delay(4000);
    
    tone(buzzer,notes[1],4000);
    delay(6000);
  
  } 
  
}
