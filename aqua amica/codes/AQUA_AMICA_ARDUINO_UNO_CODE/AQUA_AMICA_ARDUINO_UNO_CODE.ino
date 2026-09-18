#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

Servo sorter;

// Motor Driver Pins
#define ENA 5
#define IN1 6
#define IN2 7

#define ENB 9
#define IN3 10
#define IN4 11

// Conveyor
#define CONVEYOR 4

// Sensors
#define IR_TOP 2
#define INDUCTIVE 3

#define TDS_PIN A0
#define TURBIDITY_PIN A1

char command='S';

void setup()
{
  Serial.begin(9600);

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);

  pinMode(CONVEYOR,OUTPUT);

  pinMode(IR_TOP,INPUT);
  pinMode(INDUCTIVE,INPUT);

  sorter.attach(8);
  sorter.write(90);

  lcd.init();
  lcd.backlight();

  stopRobot();
}

void loop()
{
  waterQualityMonitor();

  if(Serial.available())
  {
    command=Serial.read();
  }

  switch(command)
  {
    case 'F':
      moveForward();
      break;

    case 'L':
      turnLeft();
      break;

    case 'R':
      turnRight();
      break;

    case 'S':
      stopRobot();
      break;

    case 'C':
      captureWaste();
      command='S';
      break;
  }
}

void moveForward()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  analogWrite(ENA,180);
  analogWrite(ENB,180);
}

void turnLeft()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);

  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  analogWrite(ENA,150);
  analogWrite(ENB,150);
}

void turnRight()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);

  analogWrite(ENA,150);
  analogWrite(ENB,150);
}

void stopRobot()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

void captureWaste()
{
  stopRobot();

  digitalWrite(CONVEYOR,HIGH);

  while(digitalRead(IR_TOP)==LOW)
  {
  }

  delay(1000);

  digitalWrite(CONVEYOR,LOW);

  segregateWaste();
}

void segregateWaste()
{
  bool metal=digitalRead(INDUCTIVE);

  if(metal)
  {
    sorter.write(30);
    delay(2000);
  }
  else
  {
    sorter.write(150);
    delay(2000);
  }

  sorter.write(90);
}

void waterQualityMonitor()
{
  int turbidity=analogRead(TURBIDITY_PIN);
  int tdsRaw=analogRead(TDS_PIN);

  float voltage=tdsRaw*(5.0/1023.0);

  float tds=
  (133.42*voltage*voltage*voltage
  -255.86*voltage*voltage
  +857.39*voltage)*0.5;

  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print((int)tds);

  lcd.print(" Tb:");
  lcd.print(turbidity);

  lcd.setCursor(0,1);

  if(tds<300 && turbidity>700)
  {
    lcd.print("WATER GOOD    ");
  }
  else if(tds<600)
  {
    lcd.print("WATER MODERATE");
  }
  else
  {
    lcd.print("WATER POLLUTED");
  }
}