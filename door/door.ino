#include <LiquidCrystal.h>
#include <Servo.h>
Servo myservo;

const int rs = 12, en = 11, d4 = 5, d5 = 5, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int trigPin = 13;
int echoPin = 10;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16, 2);
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() 
{
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.412;

  if (distance > 41) {
    lcd.setCursor(0, 0);
    lcd.print("WELCOME");
    lcd.setCursor(0, 2);
    lcd.print("DISTANCE:");
    lcd.print(">40cm");
  }

  else if(distance<=40 || distance>10)
  {
    lcd.setCursor(0, 0);
    lcd.print("Please Enter");
    lcd.setCursor(0, 2);
    lcd.print("DISTANCE:");
    lcd.print(distance);
    lcd.print("cm");
    delay(1000);
    lcd.clear();

  }

  if(distance>=20)
  {
    myservo.write(120);
    delay(1000);
  }

  else 
  {
    myservo.write(0);

  }

  Serial.print("distance");
  Serial.println(distance);

  delay(100);

}
