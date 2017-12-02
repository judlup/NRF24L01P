#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
char msg[3];
RF24 radio(9,10);
const uint64_t pipe[2] = {0xF0F0F0F0E1LL,0xF0F0F0F0E2LL};
int LED1 = 3;

void setup(void){
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(1,pipe[0]);
radio.openWritingPipe(pipe[1]);
radio.startListening();
pinMode(LED1, OUTPUT);}

void loop(void){
while(radio.available())
{  
  radio.read(msg, sizeof(msg));
  Serial.println(msg[0]);
  Serial.println(msg[1]);  
  Serial.println(msg[2]);  
  //if (msg[0] == 'N')*/
  if(1)
  {
    Serial.println("ON");    
    digitalWrite(LED1, HIGH);
    radio.stopListening();
    char resp[3];
    resp[0] = 'N';
    resp[1] = 'D';
    resp[2] = 'S';
    radio.write(resp, sizeof(resp));
    delay(50);
    radio.startListening();
  }
  else 
  {
    Serial.println("OFF");
    digitalWrite(LED1, LOW);
  }
  delay(1000);
}

}
