

// NO OF 12V 
// WATER PUMP
// SOLENOID LOCK / RICE_BIN
// SOLENOID WATER VALVE
// 
 

// RECEIVE SMS
// CHECK SETTINGS 
// DROP RICE
// POUR WATER
// TURN ON / AIR PUMP
// DRAIN WATER
// SERVO / OPEN RICE COOKER LID
// STEPPER / POUR RICE
// SERVO / TURN ON RICE COOKER
// SMS / TEXT RICE IS COOKING 

#define BAUD       9600
#define GSM_BAUD   2400
#define SOLENOID_RICE_BIN 

#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <Utility.h>
#include "SIM900.h"
#include "sms.h"
#include <AccelStepper.h>
#include <Servo.h>


LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int lcd_key     = 0;
int adc_key_in  = 0;
 
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

#define SOLENOID_RICE_BIN A2
#define WATER_PUMP A3
#define AIR_PUMP 9
#define SOLENOID_WATER_DRAIN A1

AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

int state = 0;
int cup = 1;
char water = 'A';

boolean isCooking = false;

unsigned long previousMillis = 0;
unsigned long previousMillis_rest = 0;

SMSGSM sms;
boolean started=false;
char smsbuffer[160];
char n[20];
char pos;
char terminate = '\0';
int numdata;
int prevPos = 9;

const long interval = 5000;
const byte MIN = 0;
const byte MAX = 20;

char message[180];

Servo arm;
Servo base;
Servo switch_cooker;

void setup()
{ 
  Serial.begin(9600);
  stepper.setMaxSpeed(100);
  stepper.setAcceleration(20);
  stepper.moveTo(200);
  
  arm.attach(10);
  base.attach(11);
  switch_cooker.attach(9);
  
  pinMode(SOLENOID_RICE_BIN,OUTPUT);
  pinMode(WATER_PUMP,OUTPUT);
  pinMode(AIR_PUMP,OUTPUT);
  
  //stepper.runToNewPosition(0);
  //callMe();
  
  lcd.begin(16, 2);              // star
  lcd.setCursor(0,0);
  lcd.print("CUP: "); // display“Push the buttons”
  lcd.setCursor(1,0);
  lcd.print("WATER: ");

  SMS_CHECK();
}

void loop()
{
  
  /*  
  if (Serial.available()){
    int steps = Serial.parseInt();
    stepper.runToNewPosition(steps);
    //Serial.println(stepper.distanceToGo());
    //stepper.moveTo(-stepper.currentPosition());
  }
  
  // Serial.println(stepper.currentPosition());
  delay(100);
  */
 
  // Controls MANUAL VS SMS  
  PRESS_BUTTON();
  RECEIVE_SMS();
  
  if (isCooking == true){
    DROP_RICE();
    POUR_WATER();
    TURN_ON_AIR_PUMP();
    DRAIN_WATER();
    
    OPEN_LID();
    SPILL_PAN();
    RECOVER_PAN();
    CLOSE_LID();
    SWITCH_ON_COOKER();
    
    
  isCooking = false;
  }
}


