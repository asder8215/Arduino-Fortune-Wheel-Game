// Libraries
#include <Stepper.h>
#include <ezButton.h>

// Initialize buttons with pin number on arduino (#)
ezButton greenButton(12);
ezButton redButton(13);

// Number of steps to take per revolution
int stepsPerRevolution = 200;

// The initial speed of the motor
int currentSpeed = 120;
// holds boolean telling us if we begin decreasing or not
boolean decreaseState = false;
boolean increaseState = false;

// instantiate stepper with steps per rev, and pin #s (2-13)
Stepper myStepper(stepsPerRevolution, 2, 3, 4, 5);

// Initial setup of motor
void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(currentSpeed);
}

// Program that loops while current goes through arduino
void loop() {
  // needed - dont remove if using buttons
  greenButton.loop();
  redButton.loop();

  // step motor in clockwise direction with given #
  myStepper.step(-stepsPerRevolution);
  // indicates delay in responses to motor (lower the greater the delay)
  myStepper.setSpeed(currentSpeed);


  if(greenButton.isReleased()){
    //Serial.println("Turning on motor");
    increaseState = true;
  }
  else if (redButton.isReleased()){
    //Serial.println("Turning off motor");
    decreaseState = true;
  }
  if(decreaseState == true){
    decreaseSpeed();
    //Serial.println("Let's decrease now.");
  }
  if(increaseState == true){
    increaseSpeed();
    //Serial.println("Let's increase now.");
  }
}

void decreaseSpeed(){
  // decrease rev by 20
  stepsPerRevolution -= 20;
  // decrease speed by 9
  currentSpeed -= 9;
  // if we reach zero, 
  if(stepsPerRevolution <= 0){
    stepsPerRevolution = 0;
    currentSpeed = 30;
    decreaseState = false;
  }
}

void increaseSpeed(){
  currentSpeed += 9;
  stepsPerRevolution += 20;
  if(stepsPerRevolution >= 200){
    stepsPerRevolution = 200;
    currentSpeed = 120;
    increaseState = false;
  }
}
