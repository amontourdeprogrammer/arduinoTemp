#include <Adafruit_NeoPixel.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
const int inPin = 0;
#define PIN 10
#define NUMPIXELS 3
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  analogReference(INTERNAL);
  lcd.begin(16,2);
  Serial.begin(9600);
  pixels.begin();
  
}
void loop()
{
  int value = analogRead(inPin);
  lcd.setCursor(0,1);
  float millivolts = (value / 1024.0) * 2560; //5000;
  float temp = (millivolts / 10) - 50;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(temp);
  lcd.print("C");
  Serial.println(temp);
  lcd.setCursor(0,1);
  delay(1000);

  for(int i=0;i<NUMPIXELS;i++){

    if(temp >= 26 && temp <27) {
      pixels.setPixelColor(i, pixels.Color(255,0,255));
      pixels.show();
      delay(200);
    }else if(temp >= 27 && temp <28){
      pixels.setPixelColor(i, pixels.Color(255,255,0));
      pixels.show();
      delay(200);
    }else if(temp >= 28 && temp <29){
      pixels.setPixelColor(i, pixels.Color(0,255,0));
      pixels.show();
      delay(200);
    }else if(temp >= 29 && temp <30){
      pixels.setPixelColor(i, pixels.Color(0,255,255));
      pixels.show();
      delay(200);
    }else if(temp >= 30 && temp <31){
      pixels.setPixelColor(i, pixels.Color(0,0,255));
      pixels.show();
      delay(200);
    }else if(temp >= 31 && temp <32){
      pixels.setPixelColor(i, pixels.Color(255,0,255));
      pixels.show();
      delay(200);
    }else if(temp >= 32 && temp <33){
      pixels.setPixelColor(i, pixels.Color(255,0,0));
      pixels.show();
      delay(200);
    }else{
      pixels.setPixelColor(i, pixels.Color(255,255,255));
      pixels.show();
      delay(200);
    }
  }
}
