#include <Stepper.h>
#include <ezButton.h>

// Initialize buttons
ezButton buttonOne(12);
ezButton buttonTwo(13);
int stepsPerRevolution = 200;
int currentSpeed = 120;
unsigned long myTime;
unsigned long startTime = millis();

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

  
  if(buttonOne.isReleased()){
    Serial.println("Turning on motor");
    stepsPerRevolution = 200;
  }
  else if (buttonTwo.isReleased()){
    Serial.println("Turning off motor");
//    Serial.println("Time: ");
//    Serial.println(myTime);
//    for(int i = 200; i >= 0; i-=20){
//       stepsPerRevolution = i;
//       Serial.println(stepsPerRevolution);
//    }
    //if(
    stepsPerRevolution = 0;
  }
  //Serial.println(stepsPerRevolution);
}

