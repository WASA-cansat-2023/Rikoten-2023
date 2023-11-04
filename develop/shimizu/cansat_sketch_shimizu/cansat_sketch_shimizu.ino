#include <BluetoothSerial.h>

BluetoothSerial SerialBT;
const int outputPin1 = 1;
const int outputPin2 = 3;
const int outputPin3 = 10;
const int outputPin4 = 13;
 //ModePinはunconnctedにしてIN/INModeにする

void setup() {
  SerialBT.begin("ESP32LED");      // Bluetoothシリアルに「ESP32LED」という名前をつけて初期化
  Serial.begin(115200);            // シリアルモニタの初期化
  pinMode(1, OUTPUT); //左モータXin1
  pinMode(3, OUTPUT); //左モータXin2
  pinMode(10, OUTPUT); //右モータXin1
  pinMode(13, OUTPUT); //右モータXin2
}

void loop() {
  if (SerialBT.available()) {      // Bluetoothシリアルに受信したかどうかを調べる
    char ch = SerialBT.read();     // 受信した文字を得る
    Serial.println(ch);            // 受信した文字をシリアルモニタに出力
    if (ch == 'w') {               // 受信した文字が「w」の場合
       digitalWrite(1,HIGH);
       digitalWrite(3,LOW); //左モータ前進
       digitalWrite(10,HIGH);
       deditalWrite(13,LOW);// 右モータ前進
       //前進
    }
    else if (ch == 'a') {          // 受信した文字が「a」の場合
       digitalWrite(1,HIGH);
       digitalWrite(3,HIGH); //左モータ停止
       digitalWrite(10,LOW);
       digitalWrite(13,HIGH); //右モータ前進
       // 左折
    }
    else if (ch == 's') {          // 受信した文字が「s」の場合
       digitalWrite(1,LOW); 
       digitalWrite(3,HIGH);//左モータ後進
       digitalWrite(10,LOW);
       digitalWrite(13,HIGH);//右モータ後進
       // 後退
    }
    else if (ch == 'd') {          // 受信した文字が「d」の場合
      digitalWrite(10,HIGH);
      digitalWrite(10,LOW);//左モータ前進
      digitalWrite(10,HIGH);
      digitalWrite(10,HIGH);//右モータ停止
       // 右折
    }
  }
}

