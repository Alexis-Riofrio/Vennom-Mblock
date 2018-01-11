#include <SoftwareSerial.h>

SoftwareSerial Serial_extra(9, 8); // RX, TX

const int S1 = 3;
const int S2 = 5;
const int S3 = 10;
const int S4 = 11;
const int led1 = 12;
const int led2 = 13;
char ch = ' ';
//String respuesta = "vennom";
char r = 'v';

void setup() {
  Serial.begin(115200);
  Serial_extra.begin(115200);
  delay(100);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(S1, LOW);
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  digitalWrite(S4, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void loop() {
  unsigned long currentMillis = millis();

  if (Serial_extra.available() > 0) {
    ch = Serial_extra.read();
    Serial.write(ch);  // depuración.

    if (ch == '?') {
      delay(500);
      Serial_extra.println(r);
      Serial_extra.flush();
    }
    
    if (ch == '1') {
      digitalWrite(S1, LOW);
      digitalWrite(S2, HIGH);
      digitalWrite(S3, LOW);
      digitalWrite(S4, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      //Serial.println(" DERECHA");
      ch = ' ';
    }
    else {
      if (ch == '2') {
        digitalWrite(S1, HIGH);
        digitalWrite(S2, LOW);
        digitalWrite(S3, HIGH);
        digitalWrite(S4, LOW);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        //Serial.println(" IZQUIERDA");
        ch = ' ';
      }
      else {
        if (ch == '3') {
          digitalWrite(S1, LOW);
          digitalWrite(S2, HIGH);
          digitalWrite(S3, HIGH);
          digitalWrite(S4, LOW);
          digitalWrite(led1, HIGH);
          digitalWrite(led2, HIGH);
          //Serial.println(" ARRIBA");
          ch = ' ';
        }
        else {
          if (ch == '4') {
            digitalWrite(S1, HIGH);
            digitalWrite(S2, LOW);
            digitalWrite(S3, LOW);
            digitalWrite(S4, HIGH);
            //Serial.println(" ABAJO");
          }
          else {
            if (ch == '0') {
              Serial_extra.flush();
              digitalWrite(S1, LOW);
              digitalWrite(S2, LOW);
              digitalWrite(S3, LOW);
              digitalWrite(S4, LOW);
              digitalWrite(led1, LOW);
              digitalWrite(led2, LOW);
              ch = ' ';
            }
          }
        }
      }
    }
  }


}


