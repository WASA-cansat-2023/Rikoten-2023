#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

const int outputPin1 = 32;
const int outputPin2 = 33;
const int outputPin3 = 26;
const int outputPin4 = 25;

const int max_val = 255;

int i = 0;

void forward(uint32_t pwm);
void backward(uint32_t pwm);
void left(uint32_t pwm);
void right(uint32_t pwm);

void setup() {
  SerialBT.begin("ESP32LED");      // Bluetoothシリアルに「ESP32LED」という名前をつけて初期化
  Serial.begin(9600);            // シリアルモニタの初期化

  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);
  pinMode(outputPin3, OUTPUT);
  pinMode(outputPin4, OUTPUT);

  //pwmの設定。最初の引数がchannel,次が周波数,最後が解像度
  ledcSetup(0, 5000, 8);
  ledcSetup(1, 5000, 8);
  ledcSetup(2, 5000, 8);
  ledcSetup(3, 5000, 8);

  //ピンをチャンネルに接続
  ledcAttachPin(outputPin1, 0);
  ledcAttachPin(outputPin2, 1);
  ledcAttachPin(outputPin3, 2);
  ledcAttachPin(outputPin4, 3);

}

void loop() {

  if (SerialBT.available()) {      // Bluetoothシリアルに受信したかどうかを調べる
    char ch = SerialBT.read();     // 受信した文字を得る
    Serial.println(ch);            // 受信した文字をシリアルモニタに出力


    if (ch == 'w') {               // 受信した文字が「w」の場合
      Serial.println("w");
      forward(250);
    }
    else if (ch == 'a') {          // 受信した文字が「a」の場合
      Serial.println("a");
      left(250);
    } 
    else if (ch == 's') {          // 受信した文字が「s」の場合
      Serial.println("s");
      backward(250);
    }
    else if (ch == 'd') {          // 受信した文字が「d」の場合
      Serial.println("d");
      right(250);
    }
    else if (ch == 'x'){           //ジグザグ走行    
      i = 0;
      Serial.println("x");
      while (i < 700){
        right(250);
        delay(2000);
        forward(250);
        delay(2000);
        left(250);
        forward(250);
        delay(2000);
        i++;
      }
    }
    else if (ch == 'y'){              //∩u∩u∩みたいに走る、滑り具合によってdelayの数値変える必要あるかも
      i = 0;
      Serial.println("y");
      while (i < 700){
        right(250);
        delay(1000);
        left(250);
        delay(1000);
      }
    }
    else if (ch == 'z'){                 //前行って後ろを繰り返す
      i = 0;
      Serial.println("z");
      while (i < 700){
        right(250);
        delay(500);
        forward(250);
        delay(500);
      }
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
  ledcWrite(0,0);
  ledcWrite(1,pwm);
  ledcWrite(2,0);
  ledcWrite(3,pwm);
}

void left(uint32_t pwm) {
  ledcWrite(0,pwm);
  ledcWrite(1,0);
  ledcWrite(2,0);
  ledcWrite(3,0);
}

void right(uint32_t pwm) {
  ledcWrite(0,0);
  ledcWrite(1,0);
  ledcWrite(2,pwm);
  ledcWrite(3,0);
}