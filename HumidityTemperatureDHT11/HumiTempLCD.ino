#include <LiquidCrystal.h>
#include <dhtnew.h>

LiquidCrystal lcd(12, 11, 5, 6, 7, 8);

#define DHT11_PIN 9
DHTNEW mySensor(DHT11_PIN);
// https://www.youtube.com/watch?v=ECsGjMsnGRs

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println("DHT TEST PROGRAM");
  Serial.print("Sensor type: DHT");
  Serial.println(mySensor.getType());
  Serial.println("Humidity (%), \tTemperature (C)");
}


void loop()
{
  /*mySensor.read();
  Serial.print(mySensor.getHumidity(), 1);
  Serial.print("\t");
  Serial.println(mySensor.getTemperature(), 1);
  delay(500);*/
  int chk = mySensor.read();
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(mySensor.getTemperature());
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(mySensor.getHumidity());
  lcd.print("%");
  delay(1000);
}
