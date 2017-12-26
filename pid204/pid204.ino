#define L1 17
#define L2 16
#define enl 5
#define R1 15
#define R2 14
#define enr 6
#define s0 4
#define s1 7
#define s2 8
#define s3 9
#define s4 10
#define s5 11
#define s6 12


int s[7] = { 0 };
int error=0;
int pos=0;
int previousError=0;
int totalError=0;
int power=0;
int Kp=50;
int Kd=5;
int Ki=0.6;
int PWM_Right=0;
int PWM_Left=0;
int x=0;
int y=0;
int z=0;
int p=180;
int but=0;
int b=0;


void setup() {

  Serial.begin(9600);

  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(enl, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(enr, OUTPUT);
  pinMode(s0, INPUT);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);
  pinMode(s6, INPUT);
  pinMode(2, OUTPUT);
 

}

void loop()
{
  //Serial.println("main");
  
  
          pid();
  
          readSensor();
         if(s[0]==0&&s[1]==0&&s[2]==0&&s[3]==0&&s[4]==0&&s[5]==0&&s[6]==0&&x==0)
         {left();
         left();
         }
          if(x)
          {
if(s[0]==1&&s[1]==1&&s[2]==1&&s[3]==1&&s[4]==1&&s[5]==1&&s[6]==1)
          {
            stop();
            digitalWrite(2,HIGH);
            delay(500);
            digitalWrite(2,LOW);
            delay(500);

            digitalWrite(2,HIGH);
            delay(500);
            digitalWrite(2,LOW);
            delay(500);


            delay(2000);
          }

            
         else if(s[2]==1||s[3]==1||s[4]==1)
          {
          
            //Serial.println("forward line");
          
            if(x==1)
            {digitalWrite(2,HIGH);
            
              left();
              digitalWrite(2,LOW);
              x=0;
              
  
            }

            else if(x==3)
            {digitalWrite(2,HIGH);
              forward();
              digitalWrite(2,LOW);
               x=0;

  
            }

            else if(x==2)
            {digitalWrite(2,HIGH);
              left();
              digitalWrite(2,LOW);
                x=0;

             }
           }

            else if(s[1]==0&&s[2]==0&&s[3]==0)
           
          {
            //Serial.println("noForward line");
            
            if(x==1)
            {
               left();
              x=0;
  
            }

            else if(x==3)
            {
                right();
  
              x=0;
            }

            else if(x==2)
            {digitalWrite(2,HIGH);
                left();
                digitalWrite(2,LOW);
              x=0;
  
            }
          }

          
          }

          
          
//if(s[0]==0&&s[1]==0&&s[2]==0&&s[3]==0&&s[4]==0&&s[5]==0&&s[6]==0)
//{
//Serial.println("noLine");
//stop();
//}            
stop();          

          
/*
          if(s[0]==0&&s[1]==0&&s[2]==0&&s[3]==0&&s[4]==0&&s[5]==0&&s[6]==0)
          {
            left();
            delay(400);
            
          }*/
/*if(s[0]==0&&s[1]==0&&s[2]==1&&s[3]==0&&s[4]==0||s[0]==0&&s[1]==0&&s[2]==1&&s[3]==1&&s[4]==0||s[0]==0&&s[1]==1&&s[2]==1&&s[3]==0&&s[4]==0)
{
if(x==1||x==2)
{
  left();
  //enter char=L
}

if(x==3)
{
  forward();
  //enter char =S
}
}

if(s[0]==0&&s[1]==0&&s[2]==0&&s[3]==0&&s[4]==0)
{
if(x==1)
{
  left();
  
}
if(x==3)
{
  right();
  
}

if(x==2)
{
  left();
  //enter char='l'
}

if(x==3)
{
  forward();
  //enter char =S
}
}


/*
if(s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] ==0 )
forward();

if(s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] ==0 )
forward();

*/
 /* for (int i = 0; i < 4; i++)
  {
    Serial.print(s[i]);
    Serial.print("-");
  }
  Serial.println(s[4]);*/

}
void forward()
{
  analogWrite(enl, 180);
  analogWrite(enr, 180);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
  Serial.println("forward");
  
}

void left()
{Serial.println("left");
  analogWrite(enl, 180);
  analogWrite(enr, 180);
  digitalWrite(L2, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
  delay(500);
  


}




void right()
{ Serial.println("right");
  analogWrite(enl, 180);
  analogWrite(enr, 180);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R2, HIGH);
  digitalWrite(R1, LOW);
  delay(500);


  

}

void pid()
{Serial.println("PID");
  readSensor();
  error = 0 - pos;
  totalError += error;

   // save previous error for differential
   // Count how much robot deviate from center
     // Accumulate error for integral
    power = (Kp*error) + (Kd*(error-previousError)) + (Ki*totalError);
previousError = error;


    if( power>180 ) { power = 180; }
    if( power<-180 ) { power = -180; }
    //Serial.println(power);
    if(power<0) // Turn left
    {
    PWM_Right = 180;
    PWM_Left = 180 - abs(int(power));
    
    }

    else // Turn right
    {
    PWM_Right = 180 - abs(int(power));
    PWM_Left = 180;
    
    }


  //Serial.println(power);
      analogWrite(enl, PWM_Left);
     analogWrite(enr, PWM_Right);
     digitalWrite(L1,HIGH);
      digitalWrite(L2,LOW);
      digitalWrite(R1,HIGH);
      digitalWrite(R2,LOW);
      /*Serial.print(power);
      Serial.print("   left");
      Serial.print(PWM_Left);
      Serial.print("  right");
      Serial.println(PWM_Right);*/
      readSensor();
 if(s[0]==1)
 {
  y=1;
  for(int i=0;i<7;i++)
  {forward();
    delay(3);
readSensor();
if(s[6]==1)
 {
  z=1;
  
 }
 
stop();
  }
  
 }
 if(s[6]==1)
 {
  z=1;
  
  for(int i=0;i<7;i++)
  {forward();
    delay(3);
readSensor();
if(s[0]==1)
 {
  y=1;
  
 }
stop();
  }

  
 }
 
 if(y==1&&z==1)
 {
//stop();
/*Serial.print("x=");
Serial.println(x);*/

x=2;

//left();
y=0;
z=0;
return;
  
 }

 else if(y==1&&z==0)
 {
  //stop();

x=1;

//left();
y=0;
return;
 }

 else if(y==0&&z==1)
 {
//stop();

/*Serial.print("x=");
Serial.println(x);*/

x=3;

//right();
z=0;
return;

 }
 

 
 
 

 
/*if(s[0]==1&&s[6]==1)
{stop();
Serial.print("x=");
Serial.println(x);
delay(500);
x=2;

//left();
return;
}
    
else if(s[0]==1)
{stop();
Serial.print("x=");
Serial.println(x);
delay(500);
x=1;

//left();
return;
}

else if(s[6]==1)
{stop();
Serial.print("x=");
Serial.println(x);
delay(500);
x=3;
//right();
return;
}*/

}
   

void readSensor() {
  Serial.println("readSensor");
  s[0] = digitalRead(s0);
  s[1] = digitalRead(s1);
  s[2] = digitalRead(s2);
  s[3] = digitalRead(s3);
  s[4] = digitalRead(s4);
  s[5] = digitalRead(s5);
  s[6] = digitalRead(s6);
for (int i = 0; i < 6; i++)
  {
    Serial.print(s[i]);
    Serial.print("-");
  }
Serial.println(s[6]);
  
  /*Serial.print(s[5]);
  Serial.print("-");
  for (int i = 0; i < 5; i++)
  {
    Serial.print(s[i]);
    Serial.print("-");
  }
Serial.println(s[6]);
 */ 

  if (s[0]==0&&s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 0&&s[6] == 0)
    pos = 4;
  if (s[0]==0&&s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 0&&s[6] == 0)
    pos = 3;
  if (s[0]==0&&s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 0 && s[5] == 0&&s[6] == 0)
    pos = 2;
  if (s[0]==0&&s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0 && s[5] == 0&&s[6] == 0)
    pos = 1;
  if (s[0]==0&&s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 0 && s[5] == 0&&s[6] == 0)
    pos = 0;

  if (s[0]==0&&s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1 && s[5] == 0&&s[6] == 0)
    pos = -1;
  if (s[0]==0&&s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 0&&s[6] == 0)
    pos = -2;
  if (s[0]==0&&s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 1 && s[5] == 1&&s[6] == 0)
    pos = -3;
if (s[0]==0&&s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 0 && s[5] == 1&&s[6] == 0)
    pos = -4;
//Serial.print("positioN==");
    //Serial.println(pos);
}
void stop()
{
   //Serial.println("stop");
   for(int i=200;i>=0;i--)
  {
   analogWrite(enl, i);
  analogWrite(enr, i);
      digitalWrite(L1,HIGH);
      digitalWrite(L2,LOW);
      digitalWrite(R1,HIGH);
      digitalWrite(R2,LOW);
     
      
  analogWrite(enl, i);
  analogWrite(enr, i);
      digitalWrite(L2,HIGH);
      digitalWrite(L1,LOW);
      digitalWrite(R2,HIGH);
      digitalWrite(R1,LOW);
      
  }
  /*analogWrite(enl, 0);
  analogWrite(enr, 0);
  digitalWrite(L2, HIGH);
  digitalWrite(L1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R1, HIGH);*/
}
void move()
{
 analogWrite(enl, 180);
  analogWrite(enr, 180);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
  delay(50);
  analogWrite(enl, 0);
  analogWrite(enr, 0);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW); 
}

