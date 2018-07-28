#include <VirtualWire.h>

#define ledPin LED_BUILTIN

const int datain = 12;
int lm=9;
int lmr=8;
int rm=10;
int rmr=7;
int i;
const int trigPin = 5;
const int echoPin = 6;
long duration;
int distance;


int ultrasonic()
{
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
return distance;
}
void setup()
{
 Serial.begin(9600);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); 
 pinMode(ledPin,OUTPUT);
 pinMode(lm,OUTPUT);
 pinMode(lmr,OUTPUT);
 pinMode(rm,OUTPUT);
 pinMode(rmr,OUTPUT);
 vw_set_ptt_inverted(true);
 vw_set_rx_pin(datain);
 vw_setup(2000); 
 vw_rx_start(); 
}
void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    if(vw_get_message(buf, &buflen)); // Non-blocking
    {
     int i;
      digitalWrite(ledPin,HIGH);

      Serial.print("Got: ");
      Serial.println(buf[0]);//debugging
 
   
         if (buf[0]==115)//Stationary
          { 
            Serial.print("s");
            digitalWrite(lm,LOW);  
            digitalWrite(lmr,LOW);
            digitalWrite(rm,LOW);
            digitalWrite(rmr,LOW);
          
            digitalWrite(ledPin,LOW);
          }
          else
          {
            if(buf[0]==102 && ultrasonic()>15)//Forward
            { 
              Serial.print("f");
              digitalWrite(lm,LOW);  
              digitalWrite(lmr,HIGH);
              digitalWrite(rm,HIGH);
              digitalWrite(rmr,LOW);
              
              digitalWrite(ledPin,HIGH);
            }
          if(buf[0]==102 && ultrasonic()<15)   
         { 
          Serial.println("stop");    
          digitalWrite(lm,LOW);  
            digitalWrite(lmr,LOW);
            digitalWrite(rm,LOW);
            digitalWrite(rmr,LOW);
         }
             
          
            if (buf[0]==97)//Backward
            {Serial.print("b");
              digitalWrite(lm,HIGH);  
              digitalWrite(lmr,LOW);
              digitalWrite(rm,LOW);
              digitalWrite(rmr,HIGH);
              
              digitalWrite(ledPin,HIGH);
          }
          
            if (buf[i]==114)//right
            {Serial.print("r");
              digitalWrite(lm,LOW);  
              digitalWrite(lmr,LOW);
              digitalWrite(rm,HIGH);
              digitalWrite(rmr,LOW);
              
              digitalWrite(ledPin,HIGH);
            }
          
            if (buf[i]==108)//left 
            {Serial.print("l");
              digitalWrite(lm,LOW);  
              digitalWrite(lmr,HIGH);
              digitalWrite(rm,LOW);
              digitalWrite(rmr,LOW);
              
              digitalWrite(ledPin,HIGH);
            }
          }
         }
        
    
    Serial.print("\n");// debugging
  }


