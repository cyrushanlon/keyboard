#include <Keyboard.h>
  
// JP1 is an input
byte rows[] = {4, 5, 6};
const int rowCount = sizeof(rows)/sizeof(rows[0]);
 
// JP2 and JP3 are outputs
byte cols[] = {8, 9};
const int colCount = sizeof(cols)/sizeof(cols[0]);
 
byte keys[colCount][rowCount];
char vals[colCount][rowCount] = {
  {'q', 'w', 'e'},
  {'a', 's', 'd'}
};
 
void setup() {
    Serial.begin(9600);
    while (!Serial) ;
 
    for(int x=0; x<rowCount; x++) {
        Serial.print(rows[x]); Serial.println(" as input");
        pinMode(rows[x], INPUT);
    }
 
    for (int x=0; x<colCount; x++) {
        Serial.print(cols[x]); Serial.println(" as input-pullup");
        pinMode(cols[x], INPUT_PULLUP);
    }

    Keyboard.begin();
}
 
void readMatrix() {
    // iterate the columns
    for (int colIndex=0; colIndex < colCount; colIndex++) {
        // col: set to output to low
        byte curCol = cols[colIndex];
        pinMode(curCol, OUTPUT);
        digitalWrite(curCol, LOW);
 
        // row: interate through the rows
        for (int rowIndex=0; rowIndex < rowCount; rowIndex++) {
            byte rowCol = rows[rowIndex];
            pinMode(rowCol, INPUT_PULLUP);
            keys[colIndex][rowIndex] = digitalRead(rowCol);
            pinMode(rowCol, INPUT);
        }
        // disable the column
        pinMode(curCol, INPUT);
    }
}
 
void printMatrix() {
  for (int rowIndex=0; rowIndex < rowCount; rowIndex++) {
    for (int colIndex=0; colIndex < colCount; colIndex++) {  
      char key = vals[colIndex][rowIndex];
      if (keys[colIndex][rowIndex] == 0) {
        Keyboard.press(key);
      } else {
        Keyboard.release(key);
      }
    }   
  }
}
 
void loop() {
    readMatrix();
    //if (Serial.read()=='!')
       printMatrix();
}
