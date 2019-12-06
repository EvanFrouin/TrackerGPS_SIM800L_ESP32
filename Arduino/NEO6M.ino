#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = GPS RXPIN, TXPin = GPS TXPIN;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);


void initGPS() {
  Serial.println("Init GPS");
  ss.begin(GPSBaud);
}

void getPosition() {
  Serial.println("Try to get position");
  bool dataReceived = false;
  while (!dataReceived) {
    if(ss.available() > 0)gps.encode(ss.read());
    if (gps.location.isValid()) {
      Serial.println("Serial GPS recu");
      dataReceived = true;
      
      Serial.print("Latitude= ");
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= ");
      Serial.println(gps.location.lng(), 6);
      delay(1000);
      sendThingSpeak(gps.location.lat(),gps.location.lng());
    }
  }
}
