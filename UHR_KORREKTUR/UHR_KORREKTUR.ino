const int rowPins[11] = {
  22,24,26,28,30,31,32,33,34,35,36  // ggf. letzte Zeile anpassen
};

const int colPins[11] = {
  2,3,4,5,6,7,8,9,10,11,12
};

// Framebuffer: 11 Zeilen × 11 Spalten
uint16_t fb[11];

void clearFB() {
  for (int i=0; i<11; i++) fb[i] = 0;
}

void setPixel(int r, int c) {
  fb[r] |= (1 << c);
}

// Wortgruppen manuell definieren (Koordinaten aus deinem Layout)

void set_ES() {
  setPixel(0,9);
  setPixel(0,10);
}

void set_ISCH() {
  setPixel(0,7);
  setPixel(0,6);
  setPixel(0,5);
  setPixel(0,4);
}

void set_DREIVIERTL() {
  setPixel(1,1);
  setPixel(1,2);
  setPixel(1,3);
  setPixel(1,4);
  setPixel(1,5);
  setPixel(1,6);
  setPixel(1,7);
  setPixel(1,8);
  setPixel(1,9);
  setPixel(1,10);
}

void set_VIERTL() {
  setPixel(1,1);
  setPixel(1,2);
  setPixel(1,3);
  setPixel(1,4);
  setPixel(1,5);
  setPixel(1,6);
}

void set_ZEHN() {
  setPixel(2,7);
  setPixel(2,8);
  setPixel(2,9);
  setPixel(2,10);
}

void set_FUENF_minute() {
  setPixel(2,0);
  setPixel(2,1);
  setPixel(2,2);
  setPixel(2,3);
}

void set_VOR() {
  setPixel(3,0);
  setPixel(3,1);
  setPixel(3,2);
}

void set_NACH() {
  setPixel(3,7);
  setPixel(3,8);
  setPixel(3,9);
  setPixel(3,10);
}

void set_HALB() {
  setPixel(4,7);
  setPixel(4,8);
  setPixel(4,9);
  setPixel(4,10);
}

void set_FUENF_hour() {
  setPixel(4,1);
  setPixel(4,2);
  setPixel(4,3);
  setPixel(4,4);
  setPixel(4,5);
}

void set_OISE_hour() {
  setPixel(5,7);
  setPixel(5,8);
  setPixel(5,9);
  setPixel(5,10);
}

void set_SECHSE_hour() {
  setPixel(5,3);
  setPixel(5,4);
  setPixel(5,5);
  setPixel(5,6);
  setPixel(5,7);
  setPixel(5,8);
}

void set_ELFE_hour() {
  setPixel(5,0);
  setPixel(5,1);
  setPixel(5,2);
  setPixel(5,3);
}

void set_ZWOIE_hour() {
  setPixel(6,6);
  setPixel(6,7);
  setPixel(6,8);
  setPixel(6,9);
  setPixel(6,10);
}

void set_ACHTE_hour() {
  setPixel(6,1);
  setPixel(6,2);
  setPixel(6,3);
  setPixel(6,4);
  setPixel(6,5);
}

void set_ZWOELFE_hour() {
  setPixel(7,0);
  setPixel(7,1);
  setPixel(7,2);
  setPixel(7,3);
  setPixel(7,4);
  setPixel(7,5);
}

void set_DREIE_hour() {
  setPixel(7,6);
  setPixel(7,7);
  setPixel(7,8);
  setPixel(7,9);
  setPixel(7,10);
}

void set_ZEHNE_hour() {
  setPixel(8,6);
  setPixel(8,7);
  setPixel(8,8);
  setPixel(8,9);
  setPixel(8,10);
}

void set_NEUNE_hour() {
  setPixel(8,3);
  setPixel(8,4);
  setPixel(8,5);
  setPixel(8,6);
  setPixel(8,7);
  setPixel(8,8);
}

void set_VIERE_hour() {
  setPixel(9,0);
  setPixel(9,1);
  setPixel(9,2);
  setPixel(9,3);
  setPixel(9,4);
}

void set_SIEBENE_hour() {
  setPixel(9,5);
  setPixel(9,6);
  setPixel(9,7);
  setPixel(9,8);
  setPixel(9,9);
  setPixel(9,10);
}

void scan() {
  for (int r=0; r<11; r++) {

    for (int i=0; i<11; i++)
      digitalWrite(rowPins[i], HIGH);

    for (int c=0; c<11; c++) {
      if (fb[r] & (1<<c)) digitalWrite(colPins[c], HIGH);
      else digitalWrite(colPins[c], LOW);
    }

    digitalWrite(rowPins[r], LOW);

    delayMicroseconds(300);

    digitalWrite(rowPins[r], HIGH);
  }
}

void renderTime(int h, int m) {
  clearAll();

  set_ES();
  set_ISCH();

  int displayHour = h;

  if (m < 5) {
    // exakt volle Stunde
    // keine Minutenwörter
  }
  else if (m < 10) {
    set_FUENF_minute();
    set_NACH();
  }
  else if (m < 15) {
    set_ZEHN();
    set_NACH();
  }
  else if (m < 20) {
    set_VIERTL();
    set_NACH();
  }
  else if (m < 25) {
    set_ZEHN();
    set_VOR();
    set_HALB();
    displayHour = (h + 1) % 12;
  }
  else if (m < 30) {
    set_FUENF_minute();
    set_VOR();
    set_HALB();
    displayHour = (h + 1) % 12;
  }
  else if (m < 35) {
    set_HALB();
    displayHour = (h + 1) % 12;
  }
  else if (m < 40) {
    set_FUENF_minute();
    set_NACH();
    set_HALB();
    displayHour = (h + 1) % 12;
  }
  else if (m < 45) {
    set_ZEHN();
    set_NACH();
    set_HALB();
    displayHour = (h + 1) % 12;
  }
  else if (m < 50) {
    set_VIERTL();
    set_VOR();
    displayHour = (h + 1) % 12;
  }
  else if (m < 55) {
    set_ZEHN();
    set_VOR();
    displayHour = (h + 1) % 12;
  }
  else {
    set_FUENF_minute();
    set_VOR();
    displayHour = (h + 1) % 12;
  }

  switch(displayHour) {
    case 1: set_OISE_hour(); break;
    case 2: set_ZWOIE_hour(); break;
    case 3: set_DREIE_hour(); break;
    case 4: set_VIERE_hour(); break;
    case 5: set_FUENF_hour(); break;
    case 6: set_SECHSE_hour(); break;
    case 7: set_SIEBENE_hour(); break;
    case 8: set_ACHTE_hour(); break;
    case 9: set_NEUNE_hour(); break;
    case 10: set_ZEHNE_hour(); break;
    case 11: set_ELFE_hour(); break;
    case 12: set_ZWOELFE_hour(); break;
    case 0: set_ZWOELFE_hour(); break;
  }
}

void setup() {
  for(int i=0; i<11; i++) pinMode(rowPins[i], OUTPUT);
  for(int i=0; i<11; i++) pinMode(colPins[i], OUTPUT);
}

void clearAll() {
  for (int z = 1; z <= 11; z++) {
    for (int s = 1; s <= 11; s++) {
      fb[z-1][s-1] = 0;
    }
  }
}

void loop() {
  int h = 5;
  int m = 30;

  renderTime(h, m);
  scan();
}