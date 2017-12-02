#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

char msg[3];

RF24 radio(9,10);

const uint64_t pipe[2] = {0xF0F0F0F0E1LL,0xF0F0F0F0E2LL};

void setup(void){
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe[0]);
  radio.openReadingPipe(1,pipe[1]);
}
void loop(void){  
  radio.stopListening();
  msg[0] = 'N'; 
  msg[1] = 'C';
  msg[2] = 'D';    
  Serial.println("Writing");
  radio.write(msg, sizeof(msg));
  /*Serial.println(msg[0]);    
  Serial.println(msg[1]);    
  Serial.println(msg[2]);*/  
  radio.startListening(); 
  if(radio.available())
  {
    Serial.println("Reading");
    char resp[3];
    radio.read(resp, sizeof(resp));
    Serial.println(resp[0]);
    Serial.println(resp[1]);
    Serial.println(resp[2]);
  }
  radio.stopListening();
  Serial.println("waiting");
  radio.startListening();
  delay(800);
}
