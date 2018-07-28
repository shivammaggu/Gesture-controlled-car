#include <VirtualWire.h>
#define ledPin LED_BUILTIN

int xPin=0;
int yPin=1;

void send(char *message)
{
  vw_send((uint8_t *)message, (uint8_t)strlen(message));
  vw_wait_tx();
}

void setup() 
{
  pinMode(ledPin,OUTPUT);
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(12);
  vw_setup(2000);
  Serial.begin(9600);
}

void loop() 
{
  int xval=analogRead(xPin);
  int yval=analogRead(yPin);
  
  Serial.print("xval=");
  Serial.println(xval);
  
  Serial.print("yval=");
  Serial.println(yval); 
  
  Serial.print("\n");
  
  if ((xval>330 && xval<345) && (yval>330 && yval<345)) //stationary or stop(transmitter parallel to ground)
  {
    digitalWrite(ledPin,LOW);
    send("s");
  } 
  else 
  { 
    if ((xval>280 && xval<320) && (yval>330 && yval<345)) //forward(transmitter tilted forward)
    {
      digitalWrite(ledPin,HIGH);
      send("f");
     
      delay(20);
      
    }
    if ((xval>355 && xval<390) && (yval>330 && yval<345)) //backward(transmitter tilted backward)
    {
      digitalWrite(ledPin,HIGH);
      send("a");
      
      delay(20);
     
    }
    if ((xval>330 && xval<340) && (yval>260 && yval<320)) //left(transmitter tilted to left)
    {
      digitalWrite(ledPin,HIGH);
      send("l");
      
      delay(20);
     }
     if ((xval>330 && xval<345) && (yval>350 && yval<395))//right(transmitter tilted to right)
    {
      digitalWrite(ledPin,HIGH);
      send("r");
      
      delay(20);
      
    }
  }  
}




