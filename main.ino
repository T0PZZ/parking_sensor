#define B1 0
#define B2 1  //buttons
#define B3 2
#define B4 3

#define Left_blinkers 10
#define Right_blinkers 9  // blinkers

#define right 11  //lights
#define left 12

#define echo 6  // hc-sr04
#define trig 5

#include "U8glib.h"
#define SCK A5
#define SDA A4
#define RES A3  // oled
#define DC A2
#define CS A1


#define Buzzer 4

int i = 0;
long duration;
int distance;
int x = 0;

U8GLIB_SH1106_128X64 u8g(SCK, SDA, CS, DC, RES);
void draw(void) {

  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(100, 12, "[cm]");
  u8g.drawStr(3, 12, "Distance:");
  u8g.setPrintPos(75, 12);
  u8g.print(distance);
}

void setup() {
  pinMode(B1, INPUT_PULLUP);  // Light switch

  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
  digitalWrite(left, LOW);  // lights
  digitalWrite(right, LOW);

  pinMode(Right_blinkers, OUTPUT);  // blinkers
  pinMode(Left_blinkers, OUTPUT);
  digitalWrite(Right_blinkers, LOW);
  digitalWrite(Left_blinkers, LOW);

  pinMode(B2, INPUT_PULLUP);  //  right blinkers switch
  pinMode(B3, INPUT_PULLUP);  //  left blinkers switch

  pinMode(B4, INPUT_PULLUP);  // Enable parking sensor 

  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);  // HC-SR04
}

void loop() {
  if (digitalRead(B1) == LOW && i == 0) {  // LIGHTS ON
    delay(500);
    i = 1;
    digitalWrite(left, HIGH);
    digitalWrite(right, HIGH);
    delay(500);
  }
  if (digitalRead(B1) == LOW && i == 1) {  // LIGHTS OFF
    delay(500);
    i = 0;
    digitalWrite(left, LOW);
    digitalWrite(right, LOW);
    delay(500);
  }
  if (digitalRead(B2) == LOW) {
    for (int n = 0; n <= 7; n++) {
      delay(300);
      digitalWrite(Right_blinkers, HIGH);  // right blinkers
      delay(300);
      digitalWrite(Right_blinkers, LOW);
    }
  }

  if (digitalRead(B3) == LOW) {
    for (int n = 0; n <= 7; n++) {
      delay(300);  // left blinkers
      digitalWrite(Left_blinkers, HIGH);
      delay(300);
      digitalWrite(Left_blinkers, LOW);
    }
  }
  digitalWrite(trig, LOW);  // HC-SR04
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delay(50);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  if (distance > 200) { distance = 999; }

  u8g.print(distance);  // oled displaying Distance = int distance [cm]
  u8g.firstPage();
  do {
    draw();
  } while (u8g.nextPage());
  delay(50);

  if (digitalRead(B4) == LOW && x == 0) {  // reverse gear loop
    x = 1;
    delay(500);
  }
  if (x == 1) {


    if (distance > 100) {  //Buzzer on
      delay(50);
      noTone(Buzzer);
    } else if (distance <= 100 && distance > 50) {
      tone(Buzzer, 1000);
      delay(500);
      noTone(Buzzer);
    } else if (distance < 50) {
      tone(Buzzer, 1000);
    }
  }
  if (digitalRead(B4) == LOW && x == 1) {  //Buzzer off
    delay(1000);
    noTone(Buzzer);
    x = 0;
  }
}
