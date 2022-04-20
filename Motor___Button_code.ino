#include <Stepper.h>
#include <ezButton.h>

ezButton button(12);
int stepsPerRevolution = 200;
int currentSpeed = 120;
boolean buttonState = false;

Stepper myStepper(stepsPerRevolution, 2, 3, 4, 5);

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(currentSpeed);

}

void loop() {
  button.loop();
  myStepper.step(stepsPerRevolution);
  if(button.isReleased() && buttonState == false){
    Serial.println("Turning off motor");
    currentSpeed = 0;
    buttonState = true;
//    Serial.println(buttonState);
//    myStepper.setSpeed(0);
  }
  else if (button.isReleased() && buttonState == true){
    Serial.println("Turning on motor");
    currentSpeed = 120;
    buttonState = false;
  }
  myStepper.setSpeed(currentSpeed);
}
