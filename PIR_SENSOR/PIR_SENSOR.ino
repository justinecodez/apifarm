

#include <DHT.h>



//Constants
#define DHTPIN 3    // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino


//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value
int pin = 2;
int gasPin = A0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(pin,INPUT);
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
    dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
int val = digitalRead(pin);
if (val==1){
  Serial.println("motion detector");
    Serial.println(analogRead(gasPin));
hum = dht.readHumidity();
    temp= dht.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
  delay(1000);
}
}
