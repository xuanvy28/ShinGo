#include <BTAddress.h>
#include <BTAdvertisedDevice.h>
#include <BTScan.h>
#include <BluetoothSerial.h>

BluetoothSerial BT;

#define IN1 14
#define IN2 27
#define IN3 26
#define IN4 25

int speed = 0 ;



void setup() {
  Serial.begin(115200);
  BT.begin("Shin");



  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  STOP();
}

void loop() {
  if(BT.available()){
    char c = BT.read();
    Serial.println(c);
    delay(5);
    if(BT.available()){
      speed = BT.read();
      Serial.println(speed);
    }

    if (c == 'U'){
      UP(speed);
    }
    
    if (c == 'D'){
      DOWN(speed);
    }
    
    if (c == 'L'){
      LEFT(speed);
    }
    
    if (c == 'R'){
      RIGHT(speed);
    }
    
    if (c == 'S'){
      STOP();
    }
  }


}

void UP(int spd){
  analogWrite(IN1, 0); // 5V
  analogWrite(IN2, spd);

  analogWrite(IN3, 0); // 5V
  analogWrite(IN4, spd);
}

void DOWN(int spd){
  analogWrite(IN1, spd); // 5V
  analogWrite(IN2, 0);
  
  analogWrite(IN3, spd); // 5V
  analogWrite(IN4, 0);
}

void LEFT(int spd){
  analogWrite(IN1, 0); // 5V
  analogWrite(IN2, spd);

  analogWrite(IN3, spd); // 5V
  analogWrite(IN4, 0);
}

void RIGHT(int spd){
  analogWrite(IN1, spd); // 5V
  analogWrite(IN2, 0);
  
  analogWrite(IN3, 0); // 5V
  analogWrite(IN4, spd);
}

void STOP(){
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);

  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}