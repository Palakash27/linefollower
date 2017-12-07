#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);


void setup() {
 Serial.begin(9600);
 lcd.begin(16, 2);
 pinMode(8,INPUT);
 pinMode(9,INPUT);
 pinMode(10,INPUT);
 pinMode(11,INPUT);
 pinMode(12,INPUT);
 }

void loop() {
  lcd.setCursor(0, 1);
  int s1=digitalRead(8);
  int s2=digitalRead(9);
  int s3=digitalRead(10);
  int s4=digitalRead(11);
  int s5=digitalRead(12);

  if(s3==1&&s1==0&&s2==0&&s4==0&&s5==0)
    { Serial.println("forward");
    lcd.print("forward");
    }


 else if(s3==0)
    { Serial.println("stop");
    lcd.print("stop");
    Serial.println("5 cm fwd");
    delay(1000);
    Serial.println("5 cm bwd");
    delay(1000);

     if(s4==1&&s5==1&&s1==0&&s2==0)  
      { Serial.println("right");
        lcd.print("right");}

     else if(s1==1&&s2==1&&s4==0&&s5==0)
      { Serial.println("left");
      lcd.print("left");}
     else if(s4==1&&s5==1&&s1==1&&s2==1)  
      { Serial.println("left");
        lcd.print("left");}

  }
  else if(s1==1&&s2==1&&s3==1&&s4==0&&s5==0)
    {Serial.println("stop");
     Serial.println("5 cm fwd");
     delay(1000);
     Serial.println("5 cm bwd");
     delay(1000);
     Serial.println("left");   
      }
  else if(s1==0&&s2==0&&s3==1&&s4==1&&s5==1)
    {Serial.println("stop");
     Serial.println("5 cm fwd");
     delay(1000);
     if(s3==1)
     {Serial.println("forward");}
          
      }

  else if(s1==1&&s2==1&&s3==1&&s4==1&&s5==1)
  {Serial.println("stop");
     Serial.println("5 cm fwd");
     delay(1000);
     Serial.println("5 cm bwd");
     delay(1000);
     Serial.println("left");   
          
      }

  else if(s1==0&&s2==0&&s3==0&&s4==0&&s5==0)
  {Serial.println("stop");
     Serial.println("left");
   Serial.println("left");
   
    
    
    }








}
