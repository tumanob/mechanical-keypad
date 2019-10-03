/*
  Keypad For Alex
*/
#include <Keyboard.h>

#define LED_PIN 15
#define Fn1 10
#define Fn2 16

#define Key11 2
#define Key12 3
#define Key13 4

#define Key21 7
#define Key22 8
#define Key23 9

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(Fn1, INPUT_PULLUP);
  pinMode(Fn2, INPUT_PULLUP);
  
  for (int i = 2; i < 10; ++i) {
    // initilize pins
    pinMode(i, INPUT_PULLUP);
 }
 
  Keyboard.begin();
}

void loop() {
  int fnLayer = 0;
  //FN1 layer//
    if (digitalRead(Fn1) == LOW)
    {
      digitalWrite(LED_PIN, 1);
       fnLayer = 1;
    }
    
    //FNw//
    if (digitalRead(Fn2) == LOW)
    {
      digitalWrite(LED_PIN, 1);
       fnLayer = 2;
    }

   for (int i = 2; i < 10; ++i) {
     // check buttons
     if(readButton(i)) {
        if(fnLayer == 1) {
          doFn1Action(i);
        } else if (fnLayer == 2) {
          doFn2Action(i);
        } else {
          doAction(i); 
        }
     }
   }

    Keyboard.releaseAll();
}


boolean readButton(int pin) {
   // check and debounce buttons
   if (digitalRead(pin) == LOW) {
     delay(10);
   
     if (digitalRead(pin) == LOW) {
        return true;
     }
     
   }
   
   return false;
}

void doAction(int pin) {
   switch (pin) {
   case 2:
      digitalWrite(LED_PIN, 1);
      Keyboard.press(KEY_PAGE_DOWN); // page down
   break;
   case 3:
      digitalWrite(LED_PIN, 1);
      Keyboard.press(KEY_UP_ARROW);
   break;
   case 4:
   Keyboard.press(KEY_PAGE_UP);
   //Keyboard.press('f'); // page up
   break;
   case 7:
      digitalWrite(LED_PIN, 1);
      Keyboard.press(KEY_LEFT_ARROW);
   break;
   case 8:
      digitalWrite(LED_PIN, 1);
      Keyboard.press(KEY_DOWN_ARROW);
   break;
   case 9:
      digitalWrite(LED_PIN, 1);
      Keyboard.press(KEY_RIGHT_ARROW);
   break;
  
   }
   
   delay(100);
   Keyboard.releaseAll();
   digitalWrite(LED_PIN, 0);
 
}

void doFn1Action(int pin) {
   
   switch (pin) {
   case 2:
      digitalWrite(LED_PIN, 1);
      Keyboard.press(KEY_ESC);
   break;
   case 3:
      digitalWrite(LED_PIN, 1);
      Keyboard.press(KEY_UP_ARROW);
   break;
   case 4:
   Keyboard.press(KEY_LEFT_GUI);
   Keyboard.press('p');
   break;
   case 7:
      digitalWrite(LED_PIN, 1);
      Keyboard.press(KEY_LEFT_ARROW);
   break;
   case 8:
      digitalWrite(LED_PIN, 1);
      Keyboard.press(KEY_DOWN_ARROW);
   break;
   case 9:
      digitalWrite(LED_PIN, 1);
      Keyboard.press(KEY_RIGHT_ARROW);
   break;
  
   }
   
   delay(100);
   Keyboard.releaseAll();
   digitalWrite(LED_PIN, 0);
}

/* Xdebug Navigation Layer */
void doFn2Action(int pin) { // left FN
   
   switch (pin) {
   case 2:
      digitalWrite(LED_PIN, 1);
      // next //  alt + cmd + R
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('R');
      //KEY_ESC
   break;
   case 3:
      digitalWrite(LED_PIN, 1);
      // KEY_UP_ARROW
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_F9);
   break;
   case 4:
     Keyboard.press(KEY_LEFT_GUI); // back
     Keyboard.press(KEY_F2);
     //Keyboard.press('t');
   break;
   case 7:
      digitalWrite(LED_PIN, 1);
      //KEY_LEFT_ARROW
      Keyboard.press(KEY_LEFT_SHIFT); 
      Keyboard.press(KEY_F8);
   break;
   case 8:
      digitalWrite(LED_PIN, 1);
      Keyboard.press(KEY_F8); //KEY_DOWN_ARROW
   break;
   case 9:
      digitalWrite(LED_PIN, 1);
      //KEY_RIGHT_ARROW // 
      //Keyboard.press(KEY_LEFT_ALT);
      //Keyboard.press(KEY_LEFT_SHIFT); 
      Keyboard.press(KEY_F7);
   break;
  
   }
   
   delay(100);
   Keyboard.releaseAll();
   digitalWrite(LED_PIN, 0);
}
