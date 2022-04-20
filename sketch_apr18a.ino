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
  Serial.println(currentSpeed);

  Serial.println("Hey");

  if(greenButton.isReleased()){
    Serial.println("Turning on motor");
    currentSpeed = 120;

  }
  else if (redButton.isReleased()){
    Serial.println("Turning off motor");
    decreaseState = true;
  }

  Serial.println("Hey2");
  if(decreaseState == true){
    decreaseSpeed();
    Serial.println("Let's decrease now.");
  }
  //Serial.println(stepsPerRevolution);

  Serial.println("Hey3");
  delay(100);
}

void decreaseSpeed(){
      currentSpeed -= 20;
      if(currentSpeed <= 0){
        currentSpeed = 0;
        decreaseState = false;
      }
}