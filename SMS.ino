void SMS_CHECK(){
  if (gsm.begin(GSM_BAUD)) {
      Serial.println("\nstatus=READY");
      started=true;
  } else Serial.println("\nstatus=IDLE");
  if(started) delsms(); 
}

void RECEIVE_SMS(){
   unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        pos=sms.IsSMSPresent(SMS_UNREAD);
        message[0] = '\0';
        if((int)pos>MIN && (int)pos<=MAX){
          sms.GetSMS((int)pos,n,20,message,180);          
          String parse(message);
          String measurement;
          
          measurement = parse.substring(0);
          
          if (measurement == "1"){
            cup = 1;
          }
          else if(measurement == "2"){
            cup = 2;
          }else{}
          
          measurement = parse.substring(1);
          
          if (measurement == "A"){
            water = 'A';
          }
          else if(measurement == "B"){
            water = 'B';
          }
          else if (measurement == "C"){
            water = 'C';
          }else{}
         
          if (parse == "COOK"){
            isCooking = true;          
          } 
          
          sms.DeleteSMS((int)pos);
        }
    } 
}

void delsms(){
  for (int i=0; i<10; i++){
      int pos=sms.IsSMSPresent(SMS_ALL);
      if (pos!=0){ 
        if (sms.DeleteSMS(pos)==1){}
      }
  } 
}
