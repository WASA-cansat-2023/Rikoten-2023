#include <BluetoothSerial.h>

#define outputPin1 32
#define outputPin2 33
#define outputPin3 26
#define outputPin4 25

BluetoothSerial SerialBT;

void forward(uint32_t pwm);
void backward(uint32_t pwm);
void left(uint32_t pwm);
void right(uint32_t pwm);

void setup() {
  SerialBT.begin("ESP32_1");      // Bluetoothシリアルに「ESP32_1」という名前をつけて初期化 // 2つ目の機体は「ESP32_2」に変更
  Serial.begin(115200);            

  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin1, OUTPUT);
}

void loop() {
  if (SerialBT.available()) {      // Bluetoothシリアルに受信したかどうかを調べる
    char ch = SerialBT.read();     // 受信した文字を得る
    Serial.println(ch);            // 受信した文字をシリアルモニタに出力


    if (ch == '0') {               // 受信した文字が「0」の場合
      
    }
    else if (ch == '1') {          // 受信した文字が「1」の場合
      
    }
  }
}
