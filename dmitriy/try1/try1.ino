#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

const uint8_t speeds = 40;

void setup() {
  SerialBT.begin("ESP32LED");      // Bluetoothシリアルに「ESP32LED」という名前をつけて初期化
  Serial.begin(9600);            // シリアルモニタの初期化
}

void loop() {
  while(0){
    if (SerialBT.available()) {      // Bluetoothシリアルに受信したかどうかを調べる
      char ch = SerialBT.read();     // 受信した文字を得る
      Serial.println(ch);            // 受信した文字をシリアルモニタに出力

      analogWrite(32,0);
      analogWrite(33,0);
      analogWrite(26,0);
      analogWrite(25,0);

      if (ch == 'w') {               // 受信した文字が「w」の場合
        analogWrite(32,speeds);
        analogWrite(33,0);
        analogWrite(26,speeds);
        analogWrite(25,0);
        delay(1000);
        break;
      }
      else if (ch == 'a') {          // 受信した文字が「a」の場合
        analogWrite(32,speeds);
        analogWrite(33,0);
        analogWrite(26,0);
        analogWrite(25,0);
        delay(1000);
        break;
      }
      else if (ch == 's') {          // 受信した文字が「s」の場合
        analogWrite(32,0);
        analogWrite(33,speeds);
        analogWrite(26,0);
        analogWrite(25,speeds);
        delay(1000);
        break;
      }
      else if (ch == 'd') {          // 受信した文字が「d」の場合
        analogWrite(32,0);
        analogWrite(33,0);
        analogWrite(26,speeds);
        analogWrite(25,0);
        delay(1000);
        break;
      }
    }
  }
}
