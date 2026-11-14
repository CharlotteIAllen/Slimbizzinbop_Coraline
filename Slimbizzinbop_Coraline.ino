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
//GAME STATES-------------------
int gameStage = 0;
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
  //UNLOCK FRONT DOOR-----------------------------------
  if gameStage == 0 && digitalRead(doorSwitch == HIGH){
    doorServo.write(90);
    delay(500);
    gameStage = 1;
  }
  
  //CORALINE PUSHES EYES AWAY-----------------------------------
  if gameStage == 1 && digitalRead(buttonsPushSwitch) == HIGH){
    omSprinServo.write(180); //other mother turns evil
    //ghost eye blink sequence
    digitalWrite(ge1, HIGH);
    delay(250);
    digitalWrite(ge1, LOW);
    
    digitalWrite(ge2, HIGH);
    delay(250);
    digitalWrite(ge2, LOW);

    digitalWrite(ge3, HIGH);
    delay(250);
    digitalWrite(ge3, LOW);

    gameStage = 2;
  }
  
  //GARDEN PUZZLE------------------------------------------
  if (gameStage == 2 && digitalRead(gardenPuzzle) == HIGH){
    digitalWrite(ge1, HIGH);
    marbleServo.write(90);

    gameStage = 3;
  }

  //BASEMENT PUZZLE------------------------------------------
  if (gameStage == 3 && digitalRead(basementPuzzle) == HIGH){
    digitalWrite (ge2, HIGH);

    gameStage = 3;
  }

  //ATTIC PUZZLE-------------------------------------------
  if (gameStage == 4 && digitalRead(atticPuzzle) == HIGH){
    digitalWrite(ge3, HIGH);
    delay(500);
    omFallServo.write(90);
    delay(500);
    keyServo.write(90);

    gameStage = 5;
  }

  //THROW KEY IN WELL-
  if (gameStage == 5 && digitalRead(wellSwitch) == HIGH){
    tone(piezoBuzzer, 523);

    gameStage = 6;
  }
}
