#include <VirtualWire.h>
#define ledPin LED_BUILTIN
char *data;
void setup() 
{
  pinMode(ledPin,OUTPUT);
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(12);
  vw_setup(4000);
}

void loop()
{
  data="1";
  digitalWrite(ledPin,HIGH);
  vw_send((uint8_t *)data, strlen(data));
  vw_wait_tx();
  delay(500);
  data="0";
  digitalWrite(ledPin,LOW);
  vw_send((uint8_t *)data, strlen(data));
  vw_wait_tx();
  delay(500);
}

