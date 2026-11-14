#include <Servo.h>

//VARIABLES--------------------------------
//SERVOS-------------------------------
Servo doorServo;
Servo omSpinServo; //om = other mother
Servo omFallServo;
Servo marbleServo;
Servo keyServo;
//SWITCHES AND LEDS-------------------
const int doorSwitch = A2;
const int buttonsPushSwitch = 2;
const int gardenPuzzle = 3;
const int ge1 = 4; //ge = ghost eye
const int basementPuzzle = 5;
const int ge2 = 6;
const int atticPuzzle = 7;
const int ge3 = 8;
const int wellSwitch = 9;
const int piezoBuzzer = 10;
//ENCLOSURE STATES-------------------
bool doorUnlocked = false;
bool eyesPushed = false;
bool gardenSolved = false;
bool basementSolved = false;
bool atticSolved = false;
bool keyDrop = false;


void setup() {
  doorServo.attach(11);
  omSpinServo.attach(12);
  omFallServo.attach(A0);
  marbleServo.attach(A1);
  keyServo.attach(A3);

  pinMode(doorSwitch, INPUT);
  pinMode(buttonsPushSwitch, INPUT);
  pinMode(gardenPuzzle, INPUT);
  pinMode(basementPuzzle, INPUT);
  pinMode(atticPuzzle, INPUT);
  pinMode(wellSwitch, INPUT);

  pinMode(ge1, OUTPUT);
  pinMode(ge2, OUTPUT);
  pinMode(ge3, OUTPUT);
  pinMode(piezoBuzzer, OUTPUT);
}

void loop() {

}
