#define motor1 27
#define motor2 26
// #define enable1Pin = 14; 

// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 200;

void setup() {
  // sets the pins as outputs:
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  // pinMode(enable1Pin, OUTPUT);
  
  // configure LEDC PWM


  Serial.begin(115200);

  // testing
  Serial.print("Testing DC Motor...");
}

void loop() {
  // Move the DC motor forward at maximum speed
  Serial.println("Moving Forward");
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH); 
  delay(2000);

  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  delay(1000);

  // Move DC motor backwards at maximum speed
  Serial.println("Moving Backwards");
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW); 
  delay(2000);

  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  delay(1000);

  // Move DC motor forward with increasing speed
  ledcAttachChannel(motor1, freq, resolution, pwmChannel);
  while (dutyCycle <= 255){
    ledcWrite(motor1, dutyCycle);   
    Serial.print("Forward with duty cycle: ");
    Serial.println(dutyCycle);
    dutyCycle = dutyCycle + 5;
    delay(500);
  }
  dutyCycle = 255;
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  ledcAttachChannel(motor2, freq, resolution, pwmChannel);
  while ((dutyCycle>= 200)&(dutyCycle <= 255)){
    ledcWrite(motor2, dutyCycle);   
    Serial.print("Backward with duty cycle: ");
    Serial.println(dutyCycle);
    dutyCycle = dutyCycle - 5;
    delay(500);
  }
  dutyCycle=200;
}