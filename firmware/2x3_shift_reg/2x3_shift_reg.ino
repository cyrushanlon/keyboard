#include <Keyboard.h>
  
// JP1 is an input
byte rows[] = {4, 5, 6};
const int rowCount = sizeof(rows)/sizeof(rows[0]);
 
// JP2 and JP3 are outputs
const int colCount = 2;
 
byte keys[colCount][rowCount];
char vals[colCount][rowCount] = {
  {'q', 'w', 'e'},
  {'a', 's', 'd'}
};

int latchPin = 7;
int clockPin = 9;
int dataPin = 8;
 
void setup() {
    Serial.begin(9600);
    while (!Serial);
 
    for(int x=0; x<rowCount; x++) {
        Serial.print(rows[x]); Serial.println(" as input");
        pinMode(rows[x], INPUT);
    }
 
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);

    Keyboard.begin();
}

void readMatrix() {
    for (int i=0; i < 8; i++) {
        
        digitalWrite(latchPin, LOW);
        //shiftOut(dataPin, clockPin, LSBFIRST, i);

        if (i == 0) {
          digitalWrite(dataPin, HIGH);
        } else {
          digitalWrite(dataPin, LOW);
        }
        
        digitalWrite(clockPin, HIGH);
        digitalWrite(clockPin, LOW);  
        
        digitalWrite(latchPin, HIGH);
 
        // row: interate through the rows
        for (int rowIndex=0; rowIndex < rowCount; rowIndex++) {
            byte row = rows[rowIndex];
            pinMode(row, INPUT_PULLUP);
            keys[i][rowIndex] = digitalRead(row);
            pinMode(row, INPUT);
        }
    }
}
 
void printMatrix() {
  for (int rowIndex=0; rowIndex < rowCount; rowIndex++) {
    //Serial.println("");
    for (int colIndex=0; colIndex < colCount; colIndex++) {  
      char key = vals[colIndex][rowIndex];
      //Serial.print(keys[colIndex][rowIndex]);
      if (keys[colIndex][rowIndex] == 0) {
        Keyboard.press(key);
      } else {
        Keyboard.release(key);
      }
    }   
  }
}
 
void loop() {
  while (!Serial);
  readMatrix();
  printMatrix();
}
