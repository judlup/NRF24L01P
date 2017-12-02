#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
char msg[3];
RF24 radio(9,10);
const uint64_t pipe = 0xF0F0F0F0E1LL;
int LED1 = 3;

void setup(void){
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(1,pipe);
radio.startListening();
pinMode(LED1, OUTPUT);}

void loop(void){
//if (radio.available())
Serial.println(radio.available());
if(radio.available())
{  
  radio.read(msg, sizeof(msg));
  Serial.println(msg[0]);
  Serial.println(msg[1]);  
  Serial.println(msg[2]);  
  if (msg[2] == 'D')
  {
    Serial.println("ON");    
    digitalWrite(LED1, HIGH);
  }
  else 
  {
    Serial.println("OFF");
    digitalWrite(LED1, LOW);
  }
  delay(1000);
}

}
