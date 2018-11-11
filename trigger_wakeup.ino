void trigger_wakeup(int buzzer)  {
  //int notes[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  int notes[] = {1136, 1136, 1275, 1519};
  //Serial.println("Trigger Wakeup"); 
 for(int aa = 0; aa < 4; aa ++)  {
   tone(buzzer,notes[aa],1000);
   delay(1300);
 }
}
