//Libraries
#include <Keypad.h>

//Constants
#define ROWS 4
#define COLS 4

//Parameters
const char kp4x4Keys[ROWS][COLS]  = {{'1', '4', '7', '*'}, {'2', '5', '8', '0'}, {'3', '6', '9', '#'}, {'A', 'B', 'C', 'D'}};
byte rowKp4x4Pin [4] = {9, 8, 7, 6};
byte colKp4x4Pin [4] = {5, 4, 3, 2};

//Variables
Keypad kp4x4  = Keypad(makeKeymap(kp4x4Keys), rowKp4x4Pin, colKp4x4Pin, ROWS, COLS);

void setup() {
  //Init Serial USB
  Serial.begin(9600);
}

void loop() {
  readKp4x4();
}

void readKp4x4() { /* function readKp4x4 */
  //// Read button states from keypad
  char customKey = kp4x4.getKey();
  if (customKey) {
    Serial.println(customKey);
  }
}
