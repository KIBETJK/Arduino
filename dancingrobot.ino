#include <Servo.h>

// Define the servo pin numbers
#define SERVO_PIN_1 2
#define SERVO_PIN_2 3
#define SERVO_PIN_3 4
#define SERVO_PIN_4 5

// Define the ultrasonic sensor pin numbers
#define TRIGGER_PIN 6
#define ECHO_PIN 7

// Define the initial angles for each servo
int servoAngle1 = 90;
int servoAngle2 = 90;
int servoAngle3 = 90;
int servoAngle4 = 90;

// Create servo objects
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Variables for obstacle avoidance
long duration;
int distance;

void setup() {
  // Attach the servo objects to the corresponding pins
  servo1.attach(SERVO_PIN_1);
  servo2.attach(SERVO_PIN_2);
  servo3.attach(SERVO_PIN_3);
  servo4.attach(SERVO_PIN_4);
  
  // Initialize the servos to their initial positions
  servo1.write(servoAngle1);
  servo2.write(servoAngle2);
  servo3.write(servoAngle3);
  servo4.write(servoAngle4);
  
  // Initialize the ultrasonic sensor pins
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Check for obstacles
  if (detectObstacle()) {
    // If an obstacle is detected, stop and turn away
    stopRobot();
    delay(500);
    turnAway();
    delay(1000);
  } else {
    // If no obstacle is detected, perform a dance routine
    danceRoutine();
  }
}

bool detectObstacle() {
  // Send ultrasonic pulse
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  // Measure the pulse duration
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate the distance based on the speed of sound
  distance = duration * 0.034 / 2;
  
  // Check if an obstacle is within a certain range
  if (distance <= 10) {
    return true;  // Obstacle detected
  } else {
    return false; // No obstacle detected
  }
}

void stopRobot() {
  // Stop the robot by setting all servos to the initial position
  servo1.write(servoAngle1);
  servo2.write(servoAngle2);
  servo3.write(servoAngle3);
  servo4.write(servoAngle4);
}

void turnAway() {
  // Turn the robot away from the obstacle
  servoAngle1 = 60;
  servoAngle2 = 120;
  servoAngle3 = 120;
  servoAngle4 = 60;
  
  // Apply the new servo angles
  servo1.write(servoAngle1);
  servo2.write(servoAngle2);
  servo3.write(servoAngle3);
  servo4.write(servoAngle4);
}

void danceRoutine() {
  // Perform a dance routine by sequentially changing the angles of each servo
  
  // Dance move 1
  servoAngle1 = 120;
  servoAngle2 = 60;
  servoAngle3 = 120;
  servoAngle4 = 60;
  applyServoAngles();
  delay(1000);
  
  // Dance move 2
  servoAngle1 = 60;
  servoAngle2 = 120;
  servoAngle3 = 60;
  servoAngle4 = 120;
  applyServoAngles();
  delay(1000);
  
  // Dance move 3
  servoAngle1 = 120;
  servoAngle2 = 60;
  servoAngle3 = 60;
  servoAngle4 = 120;
  applyServoAngles();
  delay(1000);
  
  // Dance move 4
  servoAngle1 = 60;
  servoAngle2 = 120;
  servoAngle3 = 120;
  servoAngle4 = 60;
  applyServoAngles();
  delay(1000);
}

void applyServoAngles() {
  // Apply the new servo angles
  servo1.write(servoAngle1);
  servo2.write(servoAngle2);
  servo3.write(servoAngle3);
  servo4.write(servoAngle4);
}
