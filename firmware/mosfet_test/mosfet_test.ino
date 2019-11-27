byte led = 8;
byte fet = 9;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  
  pinMode(led, OUTPUT);
  pinMode(fet, OUTPUT);

  digitalWrite(led, HIGH);
}

bool flip = false;

void loop() {
  Serial.print(flip);
  
  flip = !flip;

  if (flip) {
    digitalWrite(fet, HIGH);
  } else {
    digitalWrite(fet, LOW);
  }
  delay(1000);
}
