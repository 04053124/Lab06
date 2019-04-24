#include <Keypad.h>
#include "pitches.h"
 const byte ROWS=4;
 const byte COLS=4;
 int duration = 500;
 char keys[ROWS][COLS]={
 {'7','8','9','C'},
 {'4','5','6','D'},
 {'1','2','3','E'},
 {'0','A','B','F'}
 };
 byte rowPins[ROWS]={10,11,12,13};
 byte colPins[COLS]={6,7,8,9};

 Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS,
 COLS); 
void setup(){
  Serial.begin(9600); 
}
  
void loop(){
  // 讀取 Keypad 的輸入
  char key = keypad.getKey();
  
  // NO_KEY 代表沒有按鍵被按下
  if (key != NO_KEY){      // 假如有按鍵被按下，就印出按鍵對應的字元
      switch (key) {
     case '1':    
       tone(5, NOTE_C5, duration);
       break;
     case '2':    
       tone(5, NOTE_D5, duration);
       break;
     case '3':    
       tone(5, NOTE_E5, duration);
       break;
     case '4':    
       tone(5, NOTE_F5, duration);
       break;
     case '5':    
       tone(5, NOTE_G5, duration);
       break;
     case '6':    
       tone(5, NOTE_A5, duration);
       break;
     case '7':    
       tone(5, NOTE_B5, duration);
       break;       
     default:
       tone(5, NOTE_C8, duration);
     }
    Serial.println(key);
  }
}
