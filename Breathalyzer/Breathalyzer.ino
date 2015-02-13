#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  
}

/*
adc_counts is a 10 bit value recorded from the ADC. 
1024 is the maximum 10 bit value.
5v is the maximum ADC value. 

This function generates a percentage 

       adc_counts
  5v * ---------- = Vout
          1024

*/
float adc_to_volts(int adc_counts) {
  float volts = 0;
  volts = ( (float) adc_counts / 1024.0 ) * 5.0 ;
  return(volts);
}

void loop() {
  
  int val = 0;
  float voltage = 0;
  while(1) {
    lcd.setCursor(0,0);
    lcd.clear();
    val = analogRead(0);
    voltage = adc_to_volts(val);
     
    lcd.print(val);
    lcd.setCursor(7,0);
    lcd.print(voltage);
     
     
  if(val>200) {
    lcd.setCursor(0,1);
    lcd.print("you're drunk");
     
  }
     
     delay(2000);
   }
  
}


