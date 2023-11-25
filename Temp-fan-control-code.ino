#include <LiquidCrystal.h>
#define ENABLE 5
#define DIRA 3
#define DIRB 4

int tempPin = 0;
int i;


LiquidCrystal lcd(7,8,9,10,11,12);


void setup() {

  lcd.begin(16,2);
  lcd.print("Device On");


  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
}

void loop() {


  int tempReading = analogRead(tempPin);
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
  float tempC = tempK - 273.15;           
  float tempF = (tempC * 9.0)/ 5.0 + 32.0;

  lcd.setCursor(0, 0);
  lcd.print("Temp         F  ");
  lcd.setCursor(6, 0);
  lcd.print(tempF);

  delay(500);


  int tempF2 = (int) tempF ; //Convert tempF to an integer from Float

  if (tempF2 > 80) {
    lcd.setCursor(0, 1);
    lcd.print("Fan On ");
    digitalWrite(ENABLE, HIGH);
    digitalWrite(DIRA, HIGH);
    digitalWrite(DIRB, LOW);
    delay(4000);
    digitalWrite(ENABLE,LOW);
  }
  else{
    lcd.setCursor(0, 1);
    lcd.print("Fan Off");
    }




}
