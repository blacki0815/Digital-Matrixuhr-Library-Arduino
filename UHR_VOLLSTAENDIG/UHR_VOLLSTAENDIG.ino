// -------------------------------------------------------------
// LED-MATRIX TREIBER (TYP B – Zeile HIGH + Spalte LOW = LED an)
// -------------------------------------------------------------

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


// -------------------------------------------------------------
// Treiber-Funktionen
// -------------------------------------------------------------

void setLED(uint8_t r, uint8_t c, bool on) {
  buffer[r][c] = on ? 1 : 0;
}

void clearBuffer() {
  for (uint8_t r = 0; r < ROWS; r++)
    for (uint8_t c = 0; c < COLS; c++)
      buffer[r][c] = 0;
}

void scanMatrix() {
  for (uint8_t r = 0; r < ROWS; r++) {

    digitalWrite(rowPins[r], HIGH);

    for (uint8_t c = 0; c < COLS; c++)
      digitalWrite(colPins[c], buffer[r][c] ? LOW : HIGH);

    delayMicroseconds(500);

    digitalWrite(rowPins[r], LOW);

    for (uint8_t c = 0; c < COLS; c++)
      digitalWrite(colPins[c], HIGH);
  }
}


// -------------------------------------------------------------
// Wortgruppen
// -------------------------------------------------------------

struct L { uint8_t r; uint8_t c; };


// ES
L ES[] = {
  {0,0},{0,1}
};

// ISCH
L ISCH[] = {
  {0,2},{0,3},{0,4},{0,5}
};

// VIERTEL
L VIERTEL[] = {
  {0,6},{0,7},{0,8},{0,9},{0,10}, {1,0},{1,1}
};

// NACH
L NACH[] = {
  {1,2},{1,3},{1,4},{1,5}
};

// VOR
L VOR[] = {
  {1,6},{1,7},{1,8}
};

// FÜNF (Minuten)
L FUENF_M[] = {
  {1,9},{1,10},{2,0},{2,1}
};

// ZEHN (Minuten)
L ZEHN_M[] = {
  {2,2},{2,3},{2,4},{2,5}
};

// DREIVIERTEL
L DREI_V[] = {
  {2,6},{2,7},{2,8},{2,9}
};

// EIN
L EIN_H[] = {
  {2,10},{3,0},{3,1}
};

// ZWO
L ZWO_H[] = {
  {3,2},{3,3},{3,4}
};

// ZWÖLF
L ZWOELF_H[] = {
  {3,5},{3,6},{3,7},{3,8},{3,9}
};

// DREI
L DREI_H[] = {
  {4,0},{4,1},{4,2},{4,3}
};

// VIER
L VIER_H[] = {
  {4,4},{4,5},{4,6},{4,7}
};

// FÜNF (Stunden)
L FUENF_H[] = {
  {4,8},{4,9},{4,10},{5,0}
};

// SECHS
L SECHS_H[] = {
  {5,1},{5,2},{5,3},{5,4},{5,5}
};

// SIEBEN
L SIEBEN_H[] = {
  {5,6},{5,7},{5,8},{5,9},{5,10},{6,0}
};

// ACHT
L ACHT_H[] = {
  {6,1},{6,2},{6,3},{6,4}
};

// NEUN
L NEUN_H[] = {
  {6,5},{6,6},{6,7},{6,8}
};

// ZEHNE
L ZEHNE_H[] = {
  {6,9},{6,10},{7,0},{7,1},{7,2}
};

// ELF
L ELF_H[] = {
  {7,3},{7,4},{7,5}
};

// UHR
L UHR[] = {
  {7,6},{7,7},{7,8}
};


template <size_t N>
void add(const L (&grp)[N]) {
  for (uint8_t i = 0; i < N; i++)
    setLED(grp[i].r, grp[i].c, true);
}


// -------------------------------------------------------------
// Zeitlogik (Testzeit statt RTC)
// -------------------------------------------------------------

uint8_t testHour = 10;
uint8_t testMin  = 42;

void showTime(uint8_t h, uint8_t m) {
  clearBuffer();

  add(ES);
  add(ISCH);

  uint8_t block = (m + 2) / 5;   // runden auf 5er

  switch(block) {

    case 0: // "Uhr"
      add(UHR);
      break;

    case 1: add(FUENF_M);  add(NACH); break;
    case 2: add(ZEHN_M);  add(NACH); break;
    case 3: add(VIERTEL); add(NACH); break;
    case 4: add(DREI_V);  add(NACH); break;
    case 5: add(FUENF_M);  add(VOR);  h++; break;
    case 6: add(ZEHN_M);  add(VOR);  h++; break;
    case 7: add(VIERTEL); add(VOR);  h++; break;
    case 8: add(DREI_V);  add(VOR);  h++; break;

    default: break;
  }

  if (h > 12) h -= 12;

  switch(h) {
    case 1:  add(EIN_H);  break;
    case 2:  add(ZWO_H);  break;
    case 3:  add(DREI_H); break;
    case 4:  add(VIER_H); break;
    case 5:  add(FUENF_H); break;
    case 6:  add(SECHS_H); break;
    case 7:  add(SIEBEN_H); break;
    case 8:  add(ACHT_H); break;
    case 9:  add(NEUN_H); break;
    case 10: add(ZEHNE_H); break;
    case 11: add(ELF_H); break;
    case 12: add(ZWOELF_H); break;
  }
}


// -------------------------------------------------------------
// Setup
// -------------------------------------------------------------

void setup() {
  for (uint8_t r = 0; r < ROWS; r++) {
    pinMode(rowPins[r], OUTPUT);
    digitalWrite(rowPins[r], LOW);
  }
  for (uint8_t c = 0; c < COLS; c++) {
    pinMode(colPins[c], OUTPUT);
    digitalWrite(colPins[c], HIGH);
  }
}


// -------------------------------------------------------------
// Loop
// -------------------------------------------------------------

void loop() {
  showTime(testHour, testMin);
  scanMatrix();
}
