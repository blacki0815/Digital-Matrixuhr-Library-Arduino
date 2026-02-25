// Row-mapping Test — jede Zeile nacheinander komplett aufleuchten
const int rowPins[11] = { 22,24,26,28,30,31,32,33,34,35,36 };
const int colPins[11] = { 2,3,4,5,6,7,8,9,10,11,12 };

void setup() {
  Serial.begin(115200);
  for (int i=0;i<11;i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH); // Zeile off (Typ B: HIGH = off)
  }
  for (int c=0;c<11;c++) {
    pinMode(colPins[c], OUTPUT);
    digitalWrite(colPins[c], LOW); // Spalten LOW => all columns on when line active
  }

  Serial.println("Row mapping test start");
  delay(500);
}

void loop() {
  for (int r = 0; r < 11; r++) {
    // turn all rows off
    for (int i=0;i<11;i++) digitalWrite(rowPins[i], HIGH);
    // activate current row
    Serial.print("Activating logical row index: ");
    Serial.println(r);
    digitalWrite(rowPins[r], LOW);     // active (Typ B)
    delay(700);                        // sichtbar: 700 ms
    digitalWrite(rowPins[r], HIGH);    // off
    delay(200);
  }
  Serial.println("One pass finished. Repeat in 2s...");
  delay(2000);
}
