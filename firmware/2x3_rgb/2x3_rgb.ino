#include <Keyboard.h>

// LEDs
byte ledr[] = {4, 16, 19};
byte ledg[] = {5, 14, 18};
byte ledb[] = {6, 8, 9};

// JP1 is an input
byte col[] = {7, 15, 20};
const int colCount = sizeof(col)/sizeof(col[0]);
 
// JP2 and JP3 are outputs
byte row[] = {21, 10};
const int rowCount = sizeof(row)/sizeof(row[0]);
 
byte keys[rowCount][colCount];
char vals[rowCount][colCount] = {
  {'q', 'w', 'e'},
  {'a', 's', 'd'}
};

void setup() {
    Serial.begin(9600);
    while (!Serial);
    Serial.print("hello there");

    // LED setup
    for(int x=0; x<colCount; x++) {
        pinMode(ledr[x], OUTPUT);
        pinMode(ledg[x], OUTPUT);
        pinMode(ledb[x], OUTPUT);
    }
    
    // Keyboard Setup
    for(int x=0; x<colCount; x++) {
        pinMode(col[x], INPUT);
    }

    // Pullup setup
    for (int x=0; x<rowCount; x++) {
        pinMode(row[x], INPUT_PULLUP);
    }

    Keyboard.begin();
}

void colour(int x, int y, int r, int g, int b)
{
  for (int i=0; i<colCount; i++) {
    digitalWrite(col[i], LOW);
  }

  byte cr = row[y];

  pinMode(cr, OUTPUT);

  analogWrite(ledr[x], r);
  analogWrite(ledg[x], g);
  analogWrite(ledb[x], b);
  digitalWrite(cr, HIGH);
  
  for (int i=0; i<rowCount; i++) {
    if (i != y) {
      digitalWrite(row[i], LOW);
    }
  }
  
  pinMode(cr, INPUT);
}
 
void readMatrix() {
    // iterate the columns
    for (int colIndex=0; colIndex < rowCount; colIndex++) {
        // col: set to output to low
        byte curCol = row[colIndex];
        pinMode(curCol, OUTPUT);
        digitalWrite(curCol, LOW);
 
        // row: interate through the col
        for (int rowIndex=0; rowIndex < colCount; rowIndex++) {
            byte rowCol = col[rowIndex];
            pinMode(rowCol, INPUT_PULLUP);
            keys[colIndex][rowIndex] = digitalRead(rowCol);
            pinMode(rowCol, INPUT);
        }
        // disable the column
        pinMode(curCol, INPUT);
    }
}
 
void executeMatrix() {
  for (int rowIndex=0; rowIndex < colCount; rowIndex++) {
    for (int colIndex=0; colIndex < rowCount; colIndex++) {  
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
  colour(0, 0, 255, 0, 0);
  delay(200);
  //colour(1, 1, 255, 0, 0);
  delay(200);
  
  //readMatrix();
  //executeMatrix();
  
  while (!Serial);
}
