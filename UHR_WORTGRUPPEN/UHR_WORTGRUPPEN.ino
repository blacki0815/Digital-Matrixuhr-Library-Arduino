// Zeilen
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

// Spalten
#define S1 2
#define S2 3
#define S3 5
#define S4 6
#define S5 7
#define S6 8
#define S7 8
#define S8 9
#define S9 10
#define S10 11
#define S11 12

struct Letter {
  uint8_t row;
  uint8_t col;
};

void setLetter(const Letter& L, bool on) {
  digitalWrite(L.row,  on ? HIGH : LOW);
  digitalWrite(L.col,  on ? HIGH : LOW);
}

// Wortgruppen nach Bildmatrix
// Jede Gruppe = zusammen leuchtende Buchstaben

// ES
Letter GRP_ES[] = {
  {Z1, S1}, {Z1, S2}
};

// ISCH
Letter GRP_ISCH[] = {
  {Z1, S3}, {Z1, S4}, {Z1, S5}, {Z1, S6}
};

// VIERTEL
Letter GRP_VIERTEL[] = {
  {Z1, S7}, {Z1, S8}, {Z1, S9}, {Z1, S10}, {Z1, S11}, {Z2, S1}, {Z2, S2}
};

// NACH
Letter GRP_NACH[] = {
  {Z2, S3}, {Z2, S4}, {Z2, S5}, {Z2, S6}
};

// VOR
Letter GRP_VOR[] = {
  {Z2, S7}, {Z2, S8}, {Z2, S9}
};

// FÜNF
Letter GRP_FUENF[] = {
  {Z2, S10}, {Z2, S11}, {Z3, S1}, {Z3, S2}
};

// ZEHN
Letter GRP_ZEHN[] = {
  {Z3, S3}, {Z3, S4}, {Z3, S5}, {Z3, S6}
};

// DREIVIERTEL
Letter GRP_DREI[] = {
  {Z3, S7}, {Z3, S8}, {Z3, S9}, {Z3, S10}
};

// EIN
Letter GRP_EIN[] = {
  {Z3, S11}, {Z4, S1}, {Z4, S2}
};

// ZWO
Letter GRP_ZWO[] = {
  {Z4, S3}, {Z4, S4}, {Z4, S5}
};

// ZWÖLF
Letter GRP_ZWOELF[] = {
  {Z4, S6}, {Z4, S7}, {Z4, S8}, {Z4, S9}, {Z4, S10}
};

// DREI
Letter GRP_DREI_H[] = {
  {Z5, S1}, {Z5, S2}, {Z5, S3}, {Z5, S4}
};

// VIER
Letter GRP_VIER[] = {
  {Z5, S5}, {Z5, S6}, {Z5, S7}, {Z5, S8}
};

// FÜNF (Stunden)
Letter GRP_FUENF_H[] = {
  {Z5, S9}, {Z5, S10}, {Z5, S11}, {Z6, S1}
};

// SECHS
Letter GRP_SECHS[] = {
  {Z6, S2}, {Z6, S3}, {Z6, S4}, {Z6, S5}, {Z6, S6}
};

// SIEBEN
Letter GRP_SIEBEN[] = {
  {Z6, S7}, {Z6, S8}, {Z6, S9}, {Z6, S10}, {Z6, S11}, {Z7, S1}
};

// ACHT
Letter GRP_ACHT[] = {
  {Z7, S2}, {Z7, S3}, {Z7, S4}, {Z7, S5}
};

// NEUN
Letter GRP_NEUN[] = {
  {Z7, S6}, {Z7, S7}, {Z7, S8}, {Z7, S9}
};

// ZEHNE
Letter GRP_ZEHNE[] = {
  {Z7, S10}, {Z7, S11}, {Z8, S1}, {Z8, S2}, {Z8, S3}
};

// ELF
Letter GRP_ELF[] = {
  {Z8, S4}, {Z8, S5}, {Z8, S6}
};

// UHR
Letter GRP_UHR[] = {
  {Z8, S7}, {Z8, S8}, {Z8, S9}
};

template<size_t N>
void activateGroup(const Letter (&grp)[N], bool state) {
  for (size_t i = 0; i < N; i++) setLetter(grp[i], state);
}

void setup() {
  uint8_t zeilen[] = {Z1,Z2,Z3,Z4,Z5,Z6,Z7,Z8,Z9,Z10};
  uint8_t spalten[] = {S1,S2,S3,S4,S5,S6,S7,S8,S9,S10,S11};

  for (uint8_t p : zeilen) pinMode(p, OUTPUT);
  for (uint8_t p : spalten) pinMode(p, OUTPUT);

  for (;;) {
    activateGroup(GRP_ES, true);
    activateGroup(GRP_ISCH, true);
    activateGroup(GRP_VIERTEL, true);
    activateGroup(GRP_NACH, true);
    activateGroup(GRP_VOR, true);
    activateGroup(GRP_FUENF, true);
    activateGroup(GRP_ZEHN, true);
    activateGroup(GRP_DREI, true);
    activateGroup(GRP_EIN, true);
    activateGroup(GRP_ZWO, true);
    activateGroup(GRP_ZWOELF, true);
    activateGroup(GRP_DREI_H, true);
    activateGroup(GRP_VIER, true);
    activateGroup(GRP_FUENF_H, true);
    activateGroup(GRP_SECHS, true);
    activateGroup(GRP_SIEBEN, true);
    activateGroup(GRP_ACHT, true);
    activateGroup(GRP_NEUN, true);
    activateGroup(GRP_ZEHNE, true);
    activateGroup(GRP_ELF, true);
    activateGroup(GRP_UHR, true);
    delay(99999999);
  }
}

void loop() {}
