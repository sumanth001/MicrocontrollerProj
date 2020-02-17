#include <Servo.h>  //include servo library
int waterPin = A0;  // join water sensor pin to analog pin
int waterSensorVal = 0; 
int buzzerPin = 11; // join digital pin 
int ledPin = 10; // join led to digital pin


int servoPos = 0;
int servoPin = 9; // join servo motor to digital pin
int servoDelay = 25;

Servo servo;

void setup() {
  pinMode(waterPin, INPUT);  //input from water sensor.
  pinMode(buzzerPin, OUTPUT); //output for buzzer
  servo.attach(servoPin);  // output for servo.
  Serial.begin(9600);  //initialize serial port
}

void loop() {
  waterSensorVal = analogRead(waterPin);  //read analog value of water sensor
  Serial.println(waterSensorVal); 
  if (waterSensorVal > 80) {    // condition for water level.
      tone(buzzerPin, 450);  //buzzer on with 450 hz
      digitalWrite(ledPin, HIGH);
    
  //changing the servo position 
      for(servoPos=15; servoPos<=170; servoPos=servoPos+1){
        servo.write(servoPos);
        delay(servoDelay);
      }
  // bringing back to same positon
      for(servoPos=170; servoPos>=15; servoPos=servoPos-1){
        servo.write(servoPos);
        delay(servoDelay);
      }
   }
   
   delay(5000);  
   noTone(buzzerPin); //turn off the buzzer
   digitalWrite(ledPin, LOW); //turn off the led

  // while(true){} // running the loop just once. cause buzzer makes annoying sound.
}
