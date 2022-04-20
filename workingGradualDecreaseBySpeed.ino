#include <Stepper.h>
#include <ezButton.h>

// Initialize buttons
ezButton greenButton(12);
ezButton redButton(13);

int stepsPerRevolution = 200;

int currentSpeed = 120;

unsigned long myTime;
unsigned long startTime = millis();
boolean decreaseState = false;
boolean increaseState = false;

Stepper myStepper(stepsPerRevolution, 2, 3, 4, 5);

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(currentSpeed);
}

void loop() {
  greenButton.loop();
  redButton.loop();
  myStepper.step(-stepsPerRevolution);
  myStepper.setSpeed(currentSpeed);
  // Serial.println(currentSpeed);
  if(greenButton.isReleased()){
    Serial.println("Turning on motor");
    // currentSpeed = 120;
    // stepsPerRevolution = 200;
    increaseState = true;
  }
  else if (redButton.isReleased()){
    Serial.println("Turning off motor");
    decreaseState = true;
    // stepsPerRevolution = 0;
  }
  if(decreaseState == true){
    decreaseSpeed();
    Serial.println("Let's decrease now.");
  }
  if(increaseState == true){
    increaseSpeed();
    Serial.println("Let's increase now.");
  }
}

void decreaseSpeed(){
      stepsPerRevolution -= 20;
      currentSpeed -= 9;
      if(stepsPerRevolution <= 0){
        stepsPerRevolution = 0;
        decreaseState = false;
      }
}

void increaseSpeed(){
  currentSpeed += 9;
  stepsPerRevolution += 20;
  if(stepsPerRevolution >= 200){
    stepsPerRevolution = 200;
    increaseState = false;
  }
}
