// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>

#define DHTPIN   4       // The Paricle pin the DHT sensor is connected to
#define DHTTYPE  DHT22  // DHT type (DHT 22)

int led = D7;  // The on-board LED

DHT dht(DHTPIN, DHTTYPE);   // Initialise DH22 sensor

void setup() {
  pinMode(led, OUTPUT);
  dht.begin();
}

void loop() {
  digitalWrite(led, HIGH);   // Turn ON the LED

  double temp = dht.getTempCelcius(); // Read temperature as Celcius
  
  Particle.publish("temp", String(temp), PRIVATE);
  delay(30000);               // Wait for 30 seconds

  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(30000);               // Wait for 30 seconds
}