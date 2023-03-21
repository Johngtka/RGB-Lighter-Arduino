#include <Keypad.h>

// led pins set
int ledPinR = 8;
int ledPinG = 9; 
int ledPinB = 10;

// set the row and col space values
const byte ROWS = 4; 
const byte COLS = 4;

// appointment the keypad pins 
byte rowPins[ROWS] = {22, 23, 24, 25};
byte colPins[COLS] = {26, 27 ,28 ,29};

// setting up an array of values based on designated spaces
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

//maping process (value from space array)
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
}

void loop() {
  
// boosting Red led up
 for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPinR, fadeValue);
    delay(30);
  }
  
//  reducing Red led down
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(ledPinR, fadeValue);
    delay(30);
  }
  
// boosting Green led up
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPinG, fadeValue);
    delay(30);
  }
  
//  reducing Green led down
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(ledPinG, fadeValue);
    delay(30);
  }
  
// boosting Blue led up
   for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPinB, fadeValue);
    delay(30);
  }
  
//  reducing Blue led down
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(ledPinB, fadeValue);
    delay(30);
  }
  
//getting the key value from map which was pressed
  char key = keypad.getKey();
  if (key != NO_KEY){
    Serial.println(key);
  }
}
