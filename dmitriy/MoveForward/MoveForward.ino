#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

const int outputPin1 = 32;
const int outputPin2 = 33;
const int outputPin3 = 26;
const int outputPin4 = 25;

void setup() {
  SerialBT.begin("ESP32LED");      // Bluetoothシリアルに「ESP32LED」という名前をつけて初期化
  Serial.begin(9600);            // シリアルモニタの初期化

  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);
  pinMode(outputPin3, OUTPUT);
  pinMode(outputPin4, OUTPUT);
}

void loop() {

  Serial.println("4");
  digitalWrite(outputPin1,HIGH);
  digitalWrite(outputPin2,LOW);
  digitalWrite(outputPin3,HIGH);
  digitalWrite(outputPin4,LOW);

}
