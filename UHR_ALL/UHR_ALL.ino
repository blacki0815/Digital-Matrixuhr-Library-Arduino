
// Zeilen
#define ZEILE1 22
#define ZEILE2 24
#define ZEILE3 26
#define ZEILE4 28
#define ZEILE5 30
#define ZEILE6 31
#define ZEILE7 32
#define ZEILE8 33
#define ZEILE9 34
#define ZEILE10 35

// Spalten
#define SPALTE1 2
#define SPALTE2 3
#define SPALTE3 4
#define SPALTE4 5
#define SPALTE5 6
#define SPALTE6 7
#define SPALTE7 8
#define SPALTE8 9
#define SPALTE9 10
#define SPALTE10 11
#define SPALTE11 12

int zeilen[] = {
  ZEILE1, ZEILE2, ZEILE3, ZEILE4, ZEILE5,
  ZEILE6, ZEILE7, ZEILE8, ZEILE9, ZEILE10
};

int spalten[] = {
  SPALTE1, SPALTE2, SPALTE3, SPALTE4, SPALTE5,
  SPALTE6, SPALTE7, SPALTE8, SPALTE9, SPALTE10, SPALTE11
};

void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(zeilen[i], OUTPUT);
    digitalWrite(zeilen[i], HIGH);
  }

  for (int i = 0; i < 11; i++) {
    pinMode(spalten[i], OUTPUT);
    digitalWrite(spalten[i], HIGH);
  }
}

void loop() {
}
