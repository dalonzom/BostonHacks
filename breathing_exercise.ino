void breathing_exercise(int buzzer)  {
  //int notes[] = {NOTE_C3,NOTE_G3};
  int notes[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  for(int aa = 0; aa < 3; aa++)  {
    tone(buzzer,notes[0],4000);
    delay(11000);
    
    tone(buzzer,notes[1],8000);
    delay(8000);
  
  } 
  
}
