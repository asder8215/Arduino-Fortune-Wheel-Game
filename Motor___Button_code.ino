#include <Stepper.h>
#include <ezButton.h>

// Initialize buttons
ezButton buttonOne(12);
ezButton buttonTwo(13);
int stepsPerRevolution = 200;
int currentSpeed = 120;
unsigned long myTime;
unsigned long startTime = millis();
boolean decreaseState = false;

Stepper myStepper(stepsPerRevolution, 2, 3, 4, 5);

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(currentSpeed);
}

void loop() {
  
  buttonOne.loop();
  buttonTwo.loop();
  myTime = millis();
  myStepper.step(-stepsPerRevolution);
  //Serial.println(-stepsPerRevolution);
  Serial.println(stepsPerRevolution);

  
  if(buttonOne.isReleased()){
    Serial.println("Turning on motor");
    stepsPerRevolution = 200;
  }
  else if (buttonTwo.isReleased()){
    Serial.println("Turning off motor");
    decreaseState = true;
    //stepsPerRevolution = 0;
  }
  if(decreaseState == true){
    decreaseSpeed();
  }
  //Serial.println(stepsPerRevolution);
}7

void decreaseSpeed(){
      stepsPerRevolution -= 10;
      if(stepsPerRevolution <= 0){
        stepsPerRevolution = 0;
        decreaseState = false;
        delay(10000);
      }
}
