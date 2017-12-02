#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
char msg[3];
RF24 radio(9,10);
const uint64_t pipe = 0xF0F0F0F0E1LL;
int SW1 = 7;

void setup(void){
Serial.begin(9600);
radio.begin();
radio.openWritingPipe(pipe);}

void loop(void){
  //bool val  = true;
  //while (Serial.read() == 'a' && val == true){
    msg[0] = 'N'; 
    msg[1] = 'C';
    msg[2] = 'D';    
    radio.write(msg, sizeof(msg));
    Serial.println(msg[0]);    
    Serial.println(msg[1]);    
    Serial.println(msg[2]);
    delay(1000);
    //val = false;
  //}
}
