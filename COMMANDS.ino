void DROP_RICE(){
  switch(cup){
    case 1:
      digitalWrite(SOLENOID_RICE_BIN, HIGH);
      delay(1000);
      digitalWrite(SOLENOID_RICE_BIN, LOW);
      
      break;
    case 2:
      digitalWrite(SOLENOID_RICE_BIN, HIGH);
      delay(2000);
      digitalWrite(SOLENOID_RICE_BIN, LOW);
      break;
  }
}

void POUR_WATER(){
  switch(water){
    case 'A':
        digitalWrite(WATER_PUMP, HIGH);
        delay(1000);
        digitalWrite(WATER_PUMP, LOW);    
      break;
    case 'B':
        digitalWrite(WATER_PUMP, HIGH);
        delay(2000);
        digitalWrite(WATER_PUMP, LOW);
      break;
    case 'C': 
        digitalWrite(WATER_PUMP, HIGH);
        delay(3000);
        digitalWrite(WATER_PUMP, LOW);
      break;
  }
}

void TURN_ON_AIR_PUMP(){
  digitalWrite(AIR_PUMP, HIGH);
  delay(10000);
  digitalWrite(AIR_PUMP,LOW);
}

void DRAIN_WATER(){
  digitalWrite(SOLENOID_WATER_DRAIN, HIGH);
  delay(5000);
  digitalWrite(SOLENOID_WATER_DRAIN,LOW);
}


void OPEN_LID(){
  arm.write(100);
  base.write(100);
}

void SPILL_PAN(){
  stepper.runToNewPosition(-100);
  delay(5000);
//  stepper.runToNewPosition(400);  
}  

void RECOVER_PAN(){
  stepper.runToNewPosition(400);  
}


void CLOSE_LID(){
  arm.write(100);
  base.write(100);
}

void SWITCH_ON_COOKER(){
  switch_cooker.write(100);
  delay(1000);
  switch_cooker.write(0);
}




