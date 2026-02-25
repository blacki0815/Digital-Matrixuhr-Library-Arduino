#define ROW 22
#define COL 2

void setup() {
  pinMode(ROW, OUTPUT);
  pinMode(COL, OUTPUT);

  digitalWrite(ROW, LOW);
  digitalWrite(COL, HIGH);
}

void loop() {}
