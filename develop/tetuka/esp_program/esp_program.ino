#include <BluetoothSerial.h>

#define LED_PIN 5

BluetoothSerial SerialBT;

void setup() {
  SerialBT.begin("ESP32LED");      // Bluetoothシリアルに「ESP32LED」という名前をつけて初期化
  Serial.begin(9600);            // シリアルモニタの初期化
  pinMode(LED_PIN, OUTPUT);        // LED用のピンの初期化
}

void loop() {
  if (Serial.available()) {      // Bluetoothシリアルに受信したかどうかを調べる
    SerialBT.write(Serial.read());            // 受信した文字をシリアルモニタに出力
    
  }
}
