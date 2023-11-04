#include <BluetoothSerial.h>

#define outputPin0 32
#define outputPin1 33
#define outputPin2 26
#define outputPin3 25

BluetoothSerial SerialBT;

void forward(void);
void backward(void);
void left(void);
void right(void);
void stop(void);
void nothing(void);

void setup() {
  SerialBT.begin("ESP32_1");      // Bluetoothシリアルに「ESP32_1」という名前をつけて初期化 // 2つ目の機体は「ESP32_2」に変更
  Serial.begin(115200);            

  pinMode(outputPin0, OUTPUT);
  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);
  pinMode(outputPin3, OUTPUT);
}

void loop() {
  if (SerialBT.available()) {      // Bluetoothシリアルに受信したかどうかを調べる
    char ch = SerialBT.read();     // 受信した文字を得る
    Serial.println(ch);            // 受信した文字をシリアルモニタに出力


    if (ch == '4') {               // 受信した文字が「0」の場合
      forward();
    }
    else if (ch == '5') {          // 受信した文字が「1」の場合
      backward();
    }
    else if (ch == '6') {          // 受信した文字が「1」の場合
      left();
    }
    else if (ch == '7') {          // 受信した文字が「1」の場合
      right();
    }
    else{
      stop();
    }
  }else{
    delay(10);
    stop();
  }
}

void forward(void) {
  digitalWrite(outputPin0,1);
  digitalWrite(outputPin1,0);
  digitalWrite(outputPin2,1);
  digitalWrite(outputPin3,0);
}

void backward(void) {
  digitalWrite(outputPin0, 0);
  digitalWrite(outputPin1, 1);
  digitalWrite(outputPin2, 0);
  digitalWrite(outputPin3, 1);
}

void left(void) {
  digitalWrite(outputPin0, 1);
  digitalWrite(outputPin1, 0);
  digitalWrite(outputPin2, 0);
  digitalWrite(outputPin3, 1);
}

void right(void) {
  digitalWrite(outputPin0, 0);
  digitalWrite(outputPin1, 1);
  digitalWrite(outputPin2, 1);
  digitalWrite(outputPin3, 0);
}

void stop(void){
  digitalWrite(outputPin0, 1);
  digitalWrite(outputPin1, 1);
  digitalWrite(outputPin2, 1);
  digitalWrite(outputPin3, 1);
}

void nothing(void){
  digitalWrite(outputPin0, 0);
  digitalWrite(outputPin1, 0);
  digitalWrite(outputPin2, 0);
  digitalWrite(outputPin3, 0);
}
