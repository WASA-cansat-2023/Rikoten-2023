#include <BluetoothSerial.h>

#define outputPin0 32
#define outputPin1 33
#define outputPin2 26
#define outputPin3 25

BluetoothSerial SerialBT;

void forward(uint32_t pwm);
void backward(uint32_t pwm);
void left(uint32_t pwm);
void right(uint32_t pwm);
void stop(void);
void nothing(void);
void zigzag(void);
void nunun(void);
void eight(void);
void boost(void);


uint32_t pwm = 200;
bool boostMode = false;

void setup() {
  SerialBT.begin("ESP32_2");      // Bluetoothシリアルに「ESP32_1」という名前をつけて初期化 // 2つ目の機体は「ESP32_2」に変更
  Serial.begin(115200);            

  pinMode(outputPin0, OUTPUT);
  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);
  pinMode(outputPin3, OUTPUT);

  ledcSetup(0, 5000, 8);
  ledcSetup(1, 5000, 8);
  ledcSetup(2, 5000, 8);
  ledcSetup(3, 5000, 8);

  ledcAttachPin(outputPin0, 0);
  ledcAttachPin(outputPin1, 1);
  ledcAttachPin(outputPin2, 2);
  ledcAttachPin(outputPin3, 3);

}

void loop() {
  if (SerialBT.available()) {      // Bluetoothシリアルに受信したかどうかを調べる
    char ch = SerialBT.read();     // 受信した文字を得る
    Serial.println(ch);            // 受信した文字をシリアルモニタに出力


    if (ch == '0') {
      forward(pwm);
    }
    else if (ch == '1') {
      backward(pwm);
    }
    else if (ch == '2') {
      left(pwm);
    }
    else if (ch == '3') {
      right(pwm);
    }
    else if (ch == '4') {
      zigzag();
    }
    else if (ch == '5') {
      nunun();
    }    
    else if (ch == '6') {
      eight();
    }    
    else if (ch == '7') {
      boost();
    }
    else{
      stop();
    }
  }else{
    delay(10);
    stop();
  }
}

void forward(uint32_t pwm) {
  ledcWrite(0,pwm);
  ledcWrite(1,0);
  ledcWrite(2,pwm);
  ledcWrite(3,0);
}

void backward(uint32_t pwm) {
  ledcWrite(0,0);
  ledcWrite(1,pwm);
  ledcWrite(2,0);
  ledcWrite(3,pwm);
}

void left(uint32_t pwm) {
  ledcWrite(0,pwm);
  ledcWrite(1,0);
  ledcWrite(2,0);
  ledcWrite(3,pwm);
}

void right(uint32_t pwm) {
  ledcWrite(0,0);
  ledcWrite(1,pwm);
  ledcWrite(2,pwm);
  ledcWrite(3,0);
}

void stop(void){
  ledcWrite(0,250);
  ledcWrite(1,250);
  ledcWrite(2,250);
  ledcWrite(3,250);
}

void nothing(void){
  ledcWrite(0,0);
  ledcWrite(1,0);
  ledcWrite(2,0);
  ledcWrite(3,0);
}

void zigzag(void){
  for(int i = 1; i<4; i++){
    if(i%2!=0){
        right(pwm);
        delay(250);
        stop();
        forward(pwm);
        delay(500);
        stop();
        left(pwm);
        delay(500);
        stop();
        forward(pwm);
        delay(1000);
        stop();
        right(pwm);
        delay(500);
        stop();
        forward(pwm);
        delay(500);
        stop();
        left(pwm);
        delay(250);
        stop();
    }
    else{
        left(pwm);
        delay(250);
        stop();
        forward(pwm);
        delay(500);
        stop();
        right(pwm);
        delay(500);
        stop();
        forward(pwm);
        delay(1000);
        stop();
        left(pwm);
        delay(500);
        stop();
        forward(pwm);
        delay(500);
        stop();
        right(pwm);
        delay(250);
        stop();
    }
  }
}

void nunun(void){
  for(int i = 0; i<2; i++){
  ledcWrite(0,0);
  ledcWrite(1,0);
  ledcWrite(2,pwm);
  ledcWrite(3,0);
  delay(2000);
  stop();
  delay(100);
  ledcWrite(0,pwm);
  ledcWrite(1,0);
  ledcWrite(2,0);
  ledcWrite(3,0);
  delay(2000);
  stop();
  delay(100);
  }
}

void eight(void){
  for(int i = 0; i<2; i++){
  ledcWrite(0,0);
  ledcWrite(1,pwm/2);
  ledcWrite(2,pwm);
  ledcWrite(3,0);
  delay(2100);
  stop();
  ledcWrite(0,pwm);
  ledcWrite(1,0);
  ledcWrite(2,0);
  ledcWrite(3,pwm/2);
  delay(4200);
  stop();
  ledcWrite(0,0);
  ledcWrite(1,pwm/2);
  ledcWrite(2,pwm);
  ledcWrite(3,0);
  delay(2100);
  stop();
  }
}
  
void boost(void){
  if(boostMode == false){
    pwm = 250;
    boostMode = true;
  }
  else{
    pwm = 200;
    boostMode = false;
  }
}