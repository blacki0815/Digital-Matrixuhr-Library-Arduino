#define Z1 22
#define Z2 24
#define Z3 26
#define Z4 28
#define Z5 30
#define Z6 31
#define Z7 32
#define Z8 33
#define Z9 34
#define Z10 35

#define S1 2
#define S2 3
#define S3 4
#define S4 5
#define S5 6
#define S6 7
#define S7 8
#define S8 9
#define S9 10
#define S10 11
#define S11 12

const uint8_t ROWS = 10;
const uint8_t COLS = 11;

uint8_t rowPins[ROWS] = {Z1,Z2,Z3,Z4,Z5,Z6,Z7,Z8,Z9,Z10};
uint8_t colPins[COLS] = {S1,S2,S3,S4,S5,S6,S7,S8,S9,S10,S11};

uint8_t buffer[ROWS][COLS] = {0};

void setLED(uint8_t r, uint8_t c, bool on) {
  buffer[r][c] = on ? 1 : 0;
}

void scanMatrix() {
  for (uint8_t r = 0; r < ROWS; r++) {

    digitalWrite(rowPins[r], HIGH);

    for (uint8_t c = 0; c < COLS; c++) {
      digitalWrite(colPins[c], buffer[r][c] ? LOW : HIGH);
    }

    delayMicroseconds(500);

    digitalWrite(rowPins[r], LOW);

    for (uint8_t c = 0; c < COLS; c++) {
      digitalWrite(colPins[c], HIGH);
    }
  }
}

void fillTest() {
  for (uint8_t r = 0; r < ROWS; r++)
    for (uint8_t c = 0; c < COLS; c++)
      setLED(r, c, true);
}

void setup() {
  for (uint8_t r = 0; r < ROWS; r++) {
    pinMode(rowPins[r], OUTPUT);
    digitalWrite(rowPins[r], LOW);
  }

  for (uint8_t c = 0; c < COLS; c++) {
    pinMode(colPins[c], OUTPUT);
    digitalWrite(colPins[c], HIGH);
  }

  fillTest();
}

void loop() {
  scanMatrix();
}
