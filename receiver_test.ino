#include <VirtualWire.h>
#define ledPin LED_BUILTIN
const int datain = 12;
void setup()
{ Serial.begin(9600);
    vw_set_ptt_inverted(true);
    vw_set_rx_pin(datain);
    vw_setup(2000);
    pinMode(ledPin, OUTPUT);
    vw_rx_start();
}
    void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN; 
 
    if (vw_get_message(buf, &buflen))
    { //Serial.println("inside if");
      if(buf[0]==115)
      {  Serial.println("s");
       digitalWrite(ledPin,HIGH);
      }  
      if(buf[0]==102)
      { Serial.println("f");
       digitalWrite(ledPin,LOW);
      }
      if(buf[0]==97)
      { Serial.println("b");
       digitalWrite(ledPin,LOW);
      }
      if(buf[0]==114)
      { Serial.println("r");
       digitalWrite(ledPin,LOW);
      }
      if(buf[0]==108)
      { Serial.println("l");
       digitalWrite(ledPin,LOW);
      }
    }
}

