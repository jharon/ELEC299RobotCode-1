// I am just testing this forking malarky
#include <QSerial.h>
QSerial myIRserial;
int c = 0;
void setup() 
{
 myIRserial.attach(-1, 4);
}

void loop() 
{
  if(c <= 5000)
  {
    myIRserial.transmit('0');
    delay(100);
  }
  else if(c > 5000 && c <= 10000)
  {
    myIRserial.transmit('1');
    delay(100);
  }
  else if(c > 10000 && c <= 15000)
  {
    myIRserial.transmit('2');
    delay(100);
  }
  c = c + 100;
  
  if(c > 15000)
  {
    c = 0;
  }
}
