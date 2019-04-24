  #include "pitches.h"
  int duration=200;
  const byte Buzzer=5;
  const int rhythm=500;
  char index;
  int SoundLeng;
  char song_tone;
  char chr;
  char *ptr;
  
  int
  pitch[]={0,NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4,
  NOTE_C5,NOTE_D5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_A5,NOTE_B5};
  

  char *morse[]={
    "01","1000","1010","100",
    "0","0010","110","0000",
    "00","0111","101","0100",
    "11","10","111","0110",
    "1101","010","000","1",
    "001","0001","011","1001",
    "1011","1100"};
  

  

  void setup() {
   pinMode(Buzzer,OUTPUT);
   Serial.begin(9600);
  }
  void loop() {
   if (Serial.available()){
     chr = Serial.read();
     Serial.print(chr);
     if((chr-'A')>=0 && (chr-'Z')<=0){
       index=chr-'A';
       ptr=morse[index];
      while(*ptr!='\0'){
        if(*ptr=='0'){
          tone(Buzzer,440,100);
          delay(100);
        }
        else {
          tone(Buzzer,440,300);
          delay(300);
        }  
        ptr++;
        delay(100);
      }
      delay(300);
   }
   }
  }
