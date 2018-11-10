void trigger_wakeup(int buzzer)  {
  int notes[] = {NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3, NOTE_C4};
 for(int aa = 0; aa < 8; aa ++)  {
   tone(buzzer,notes[aa],2000);
   delay(2000);
 }
}
