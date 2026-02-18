// Project 26 - Digital Stopwatch


#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);        // select the pins used on the LCD panel
//unsigned 
long starting, finished, elapsed;

#define btnUP     1
#define btnDOWN   2
#define btnNONE   5
int adc_key_in = 0;
int lcd_key = 0;
int bright = 255;


void setup()
{
    lcd.begin(16, 2);                       // start the library
    starting = millis();
}


int readButtons()
{
  adc_key_in = analogRead(0);
  if (adc_key_in < 250 && adc_key_in > 144) return btnUP;
  else if (adc_key_in < 450 && adc_key_in > 251) return btnDOWN;
  else return btnNONE;
}


void loop()
{
 long over;
  finished = millis();
  elapsed = finished - starting;


    // display hours
    lcd.setCursor(0, 0);                   // set the LCD cursor position
    long h;
    h = int (elapsed / 3600000);
    over = elapsed % 3600000;
    lcd.print("HR");
    lcd.setCursor(0,1);
    lcd.print(h );


    // display minutes
    lcd.setCursor(4,0);
    long m;
    int m1, m2;
    m = int (over / 60000);
    over = over % 60000;
    m1 = m / 10;
    m2 = int (m) % 10;
    lcd.print("MIN");
    lcd.setCursor(4,1);
    lcd.print(m );


    // display seconds
    lcd.setCursor(8,0);
    long s;
    int s1, s2;
    s = int (over / 1000);
    lcd.print("SEC");
    lcd.setCursor(8,1);
    lcd.print(s );


    // display milliseconds
    lcd.setCursor(12,0);
    long ms;
    int ms1, ms2, ms3;
    ms = over % 1000;
    lcd.print("MS");
    lcd.setCursor(12,1);
    lcd.print(ms );

    lcd_key = readButtons();
    switch (lcd_key)
    {
      case btnDOWN:{
        delay(2000);
        break;
      }
      case btnUP:{
        break;
      }
      case btnNONE:{
        break;
      }
    }
    }


