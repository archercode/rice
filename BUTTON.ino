int read_LCD_buttons()
{
 adc_key_in = analogRead(0);
 if (adc_key_in > 1000) return btnNONE; 
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 250)  return btnUP; 
 if (adc_key_in < 450)  return btnDOWN; 
 if (adc_key_in < 650)  return btnLEFT; 
 if (adc_key_in < 850)  return btnSELECT;  
 return btnNONE; 
}


void PRESS_BUTTON(){
lcd_key = read_LCD_buttons();  // read key
switch (lcd_key)               // display key
 {
   case btnRIGHT:
     {
     //lcd.print("RIGHT ");
       if (water  == 'A'){
         water = 'B';
       }else if (water == 'B'){
         water = 'C';
       }else if (water == 'C'){
         water = 'A';
       }
     break;
     }
   case btnLEFT:
     {
     //lcd.print("LEFT   ");
       if (cup == 1){
         cup = 2;
       }else if(cup == 2){
         cup = 1;
       }
     
     break;
     }
   case btnUP:
     {
     //lcd.print("UP    ");
     break;
     }
   case btnDOWN:{ break;}
   case btnSELECT:{
     isCooking = true;
   break;}
   case btnNONE:{ break;}
 }
}
