#include <pitches.h>
#include <TimedAction.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
#define ENABLE 5
#define DIRA 3
#define DIRB 4
#define R_ENABLE 9
#define R_DIRA 6 
#define R_DIRB 7
void sensor_control(); 
void buzzer_control();
void motor_control();

LiquidCrystal_I2C lcd(0x27,16,2);
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN); 
long a;
boolean sensor_flag = false;
int i;
int kaihi = 0;
int buzz = 0;
int cnt = 0;
int alarm_cnt = 0;
int precnt = 0;
int motor_cnt = 0;

int melody[] = {
NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, 
NOTE C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, 
NOTE C6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_G6, NOTE_A6, NOTE_B6, 
NOTE C7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_G7, NOTE_A7, NOTE_B7}; 
int duration = 500;

int musicset [60][2] = {
{melody [4], 350}, 
{melody [4], 200}, 
{melody [7], duration}, 
{melody [8], duration},
{melody [9], duration}, 
{melody [10], duration}, 
{melody [11], duration},
{melody [14], 1000}, 
{melody[13], 400}, 
{melody [12], 200},
{melody[12], 700},
{melody [11], 500},
{740, 250},
{740, 250},
{melody [12], 250},
{melody [11], duration},
{melody [9], 1000},

{melody [2], 340},
{melody [2], 250},
{melody [2], duration},
{melody [2], duration},
{370, duration},
{415, duration},
{melody [5], 1250},
{melody [5], 250},
{melody [6], 250},
{melody [7], 250},
{melody[8], 1250},
{melody [5], 250},
{melody [5], 250},
{melody [7], 250},
{melody [7], duration},
{melody [6], duration},
{melody [5], duration}, 
{melody [4], duration},

{melody [9], 1250}, 
{melody [10], 250}, 
{melody [9], 250},
{melody [8], 250},
{melody [7], 1000}, 
{melody[5], duration}, 
{melody [7], duration}, 
{melody [8], 1250},
{melody [9], 250},
{melody [8], 250},
{melody [7], 250},
{melody [7], 1000}, 
{melody [6], duration}, 
{melody [4], duration},

{melody [11], 1250}, 
{melody [9], 250},
{melody [10], 250}, 
{melody [11], 250},
{melody [12], 1000}, 
{melody [5], 250},
{melody [6], 250}, 
{melody[7], 250}, 
{melody [10], 1000}, 
{melody [9], 1000}, 
{melody [7], 1250}

};

TimedAction motorAction = TimedAction(10, motor_control);
TimedAction buzzerAction = TimedAction (10, buzzer_control); 
TimedAction sensorAction = TimedAction(1000, sensor_control);

void setup() { 
  pinMode(ENABLE, OUTPUT); 
  pinMode(DIRA, OUTPUT); 
  pinMode(DIRB, OUTPUT);
  pinMode(R_ENABLE, OUTPUT);
  pinMode(R_DIRA, OUTPUT);
  pinMode(R_DIRB, OUTPUT); 
  Serial.begin(9600);
}

void loop() {
  motorAction.check();
  sensorAction.check();
  buzzerAction.check();
}

void motor_control() {
  if(sensor_flag == false && kaihi = 0) {
    analogWrite(ENABLE, 140);
    analogWrite(R_ENABLE, 200);
    digitalWrite(DIRA, HIGH); //one way
    digitalWrite(DIRB, LOW);
    digitalWrite(R_DIRA, HIGH); //one way
    digitalWrite(R_DIRB, LOW);
  }else{
    if(motor_cnt < 100){
      analogWrite(ENABLE, 140);
      analogWrite(R_ENABLE, 200);
      digitalWrite(DIRA, LOW);
      digitalWrite(DIRB, HIGH);
      digitalWrite(R_DIRA, LOW);
      digitalWrite(R_DIRB, HIGH); 
      motor_cnt += 1;
      if(motor_cnt == 100){
        digitalWrite(ENABLE, LOW);
        digitalWrite(R_ENABLE, LOW);
      }
    }else if(motor_cnt < 150){
      motor_cnt + 1;
      if(motor_cnt 150) {
        digitalWrite(R_ENABLE, HIGH);
      }
    }else if(motor_cnt < 270) {
      digitalWrite(R_DIRA, HIGH);
      digitalWrite(R_DIRB, LOW); 
      motor_cnt += 1;
      if(motor_cnt == 270) {
        digitalWrite(R_ENABLE, LOW);
      }
    }else{
      kaihi = 0;
      motor_cnt = 0;
    }
  }

void sensor_control(){ 
  a=sr04. Distance(); 
  if(a<45){
    sensor_flag = true; 
    kaihi = 1;
  }else{
    sensor_flag = false;
  }
}

void buzzer_control(){
  if(buzz > 59){
    buzz = 0;
  }
  if(sensor_flag == false && kaihi == 0){
    alarm_cnt = 0;
    if(cnt < musicset [buzz] [1] / 10){ 
      tone(8, musicset[buzz][0]);
      cnt++;
    }else{
      noTone(8);
      buzz++;
      cnt = 0;
    }
  }else{
    if(alarm_cnt < 30){
      tone(8, melody[0]);
      alarm_cnt++;
    }else{
      noTone(8);
      alarm_cnt = 0;
    }
  }
}

