/*
  this code receives a chunk of text once a connection has been initialized and constantly prints out text
  even if the transmitter does not send any data (since the connection still exists)
  
  you can set any address you want, but keep in mind that an address' length can be at a maximum of 5 bytes 
  and both the receiver and transmitter have to listen to the same address
  https://arduino.stackexchange.com/questions/70441/why-nrf24l01-pipe-has-5-byte-address

  by @im-bacho

  more (including pinout) is here: 
  https://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/
*/

#include <SPI.h>
#include <RF24.h>

RF24 radio(9, 10); 
const byte address[6] = "git00";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}
