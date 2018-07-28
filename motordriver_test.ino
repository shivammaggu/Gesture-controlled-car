//L293D
//Motor A
const int motorPin1  = 7;  // Pin 15 of L293
const int motorPin2  = 10;  // Pin 10 of L293
//Motor B
const int motorPin3  = 9; // Pin  7 of L293
const int motorPin4  = 8;  // Pin  2 of L293
//ultrasonic
const int trigPin = 6;
const int echoPin = 5;
long duration;
int distance;
void ultra()
{
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
Serial.println(duration);
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);
if( distance <= 10)
{
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
}
}

void setup(){
 
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);

    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT);
    Serial.begin(9600);

   
  
}


void loop(){
   //This code  will turn Motor A clockwise for 2 sec.
    ultra();
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
   // digitalWrite(motorPin3, LOW);
   // digitalWrite(motorPin4, LOW);

     //This code will turn Motor B counter-clockwise for 2 sec.
    //digitalWrite(motorPin1, LOW);
    //digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    ultra();
    delay(5000); 
    //This code will turn Motor A counter-clockwise for 2 sec.
  // ultra();
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    //digitalWrite(motorPin3, LOW);
    //digitalWrite(motorPin4, LOW);
   // delay(2000);
    
    //This code will turn Motor B clockwise for 2 sec.
   // digitalWrite(motorPin1, LOW);
   // digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
   // ultra();
    delay(5000); 
    
    //And this code will stop motors
    

}


