#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

// 一つ目のモーター(右)
int motor1Pin1 = 27; //モータードライバーのINPUTを27Pinに接続
int motor1Pin2 = 26; //モータードライバーのINPUTを26Pinに接続
int enable1Pin = 14; //モータードライバーのENAを14Pinに接続, PWM?

// 二つ目のモーター（左）
int motor2Pin1 = 33; //モータードライバーのINPUTを33Pinに接続
int motor2Pin2 = 32; //モータードライバーのINPUTを32Pinに接続
int enable2Pin = 13; //モータードライバーのENAを13Pinに接続, PWM?


void setup() {
  SerialBT.begin("ESP32LED");      // Bluetoothシリアルに「ESP32LED」という名前をつけて初期化
  Serial.begin(115200);            // シリアルモニタの初期化

  // ピンのセットアップ
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);

  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);
  //モーターのPinモードをOUTPUTにしないと信号が受け付けてくれないのでOUTPUTにする
}

//モーター制御変更時0.5sだけ停止
void stop(){
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    delay(500);
}

void loop() {
  if (SerialBT.available()) {      // Bluetoothシリアルに受信したかどうかを調べる
    char ch = SerialBT.read();     // 受信した文字を得る
    Serial.println(ch);            // 受信した文字をシリアルモニタに出力
    if (ch == 'w') {               // 受信した文字が「w」の場合
      // 前進
      stop();
      Serial.println("Moving Forward");
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
    
      delay(500);
    }
    else if (ch == 'a') {          // 受信した文字が「a」の場合
      // 左折
      stop();
      Serial.println("Turning Left");
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
     
    }
    else if (ch == 's') {          // 受信した文字が「s」の場合
      // 後退
      stop();
      Serial.println("Moving Backwards");
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      delay(500);                  //0.5秒そのまま
    }
    else if (ch == 'd') {          // 受信した文字が「d」の場合
      // 右折
      stop();
      Serial.println("Turning Right");
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      delay(500);
    }
    else if (ch == 'Z') {          // 受信した文字が「Z」の場合
      // ジグザグ走行
      stop();
      Serial.println("Zigzag Mode");

      //右折
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      delay(500);
      //前進
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      delay(500);
      //左折
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
      delay(500);
      //前進
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      delay(500);


    }    
  }
}

