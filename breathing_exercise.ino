void breathing_exercise(int buzzer)  {
  int notes[] = { 1915, 1700};
  Serial.println("Breathing Exercise"); 
  for(int aa = 0; aa < 3; aa++)  {
    tone(buzzer,notes[0],4000);
    delay(11000);
    
    tone(buzzer,notes[1],8000);
    delay(8000);
  
  } 
  
}
