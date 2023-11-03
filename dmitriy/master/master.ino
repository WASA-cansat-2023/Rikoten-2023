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

  ledcSetup(0, 5000, 8);
  ledcSetup(1, 5000, 8);
  ledcSetup(2, 5000, 8);
  ledcSetup(3, 5000, 8);

  ledcAttachPin(outputPin1, 0);
  ledcAttachPin(outputPin2, 1);
  ledcAttachPin(outputPin3, 2);
  ledcAttachPin(outputPin4, 3);
}

void loop() {
  if (SerialBT.available()) {      // Bluetoothシリアルに受信したかどうかを調べる
    char ch = SerialBT.read();     // 受信した文字を得る
    Serial.println(ch);            // 受信した文字をシリアルモニタに出力


    if (ch == '4') {               // 受信した文字が「0」の場合
      forward(250);
      delay(1000);
    }
    else if (ch == '5') {          // 受信した文字が「1」の場合
      backward(250);
      delay(1000);
    }
    else if (ch == '6') {          // 受信した文字が「1」の場合
      left(250);
      delay(1000);
    }
    else if (ch == '7') {          // 受信した文字が「1」の場合
      right(250);
      delay(1000);
    }
    else{
      ledcWrite(0,0);
      ledcWrite(1,0);
      ledcWrite(2,0);
      ledcWrite(3,0);
    }
  }
  else{
    ledcWrite(0,0);
    ledcWrite(1,0);
    ledcWrite(2,0);
    ledcWrite(3,0);
  }
}

void forward(uint32_t pwm) {
  ledcWrite(0,pwm);
  ledcWrite(1,0);
  ledcWrite(2,pwm);
  ledcWrite(3,0);
}

void backward(uint32_t pwm) {
  ledcWrite(0, 0);
  ledcWrite(1, pwm);
  ledcWrite(2, 0);
  ledcWrite(3, pwm);
}

void left(uint32_t pwm) {
  ledcWrite(0, pwm);
  ledcWrite(1, 0);
  ledcWrite(2, 0);
  ledcWrite(3, 0);
}

void right(uint32_t pwm) {
  ledcWrite(0, 0);
  ledcWrite(1, 0);
  ledcWrite(2, pwm);
  ledcWrite(3, 0);
}
