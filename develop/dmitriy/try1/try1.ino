#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

const int outputPin1 = 32;
const int outputPin2 = 33;
const int outputPin3 = 26;
const int outputPin4 = 25;

char ch;

void setup() {
  SerialBT.begin("ESP32LED");      // Bluetoothシリアルに「ESP32LED」という名前をつけて初期化
  Serial.begin(9600);            // シリアルモニタの初期化

  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);
  pinMode(outputPin3, OUTPUT);
  pinMode(outputPin4, OUTPUT);
}

void loop() {
  if (SerialBT.available()) {      // Bluetoothシリアルに受信したかどうかを調べる
    ch = SerialBT.read();     // 受信した文字を得る
    //Serial.println(ch);            // 受信した文字をシリアルモニタに出力

    if (ch == 'w') {               // 受信した文字が「w」の場合
      Serial.println("w");
      digitalWrite(outputPin1,HIGH);
      digitalWrite(outputPin2,LOW);
      digitalWrite(outputPin3,HIGH);
      digitalWrite(outputPin4,LOW);
    }
    else if (ch == 'a') {          // 受信した文字が「a」の場合
      Serial.println("a");
      digitalWrite(outputPin1,HIGH);
      digitalWrite(outputPin2,LOW);
      digitalWrite(outputPin3,LOW);
      digitalWrite(outputPin4,LOW);
    }
    else if (ch == 's') {          // 受信した文字が「s」の場合
      Serial.println("s");
      digitalWrite(outputPin1,LOW);
      digitalWrite(outputPin2,HIGH);
      digitalWrite(outputPin3,LOW);
      digitalWrite(outputPin4,HIGH);
    }
    else if (ch == 'd') {          // 受信した文字が「d」の場合
      Serial.println("d");
      digitalWrite(outputPin1,LOW);
      digitalWrite(outputPin2,LOW);
      digitalWrite(outputPin3,HIGH);
      digitalWrite(outputPin4,LOW);
    }
    else{
      digitalWrite(outputPin1,LOW);
      digitalWrite(outputPin2,LOW);
      digitalWrite(outputPin3,LOW);
      digitalWrite(outputPin4,LOW);
    }
  }
  else{
    digitalWrite(outputPin1,LOW);
    digitalWrite(outputPin2,LOW);
    digitalWrite(outputPin3,LOW);
    digitalWrite(outputPin4,LOW);
  }

}
