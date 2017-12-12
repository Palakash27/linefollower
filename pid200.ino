#define L1 A3
#define L2 A2
#define enl 5
#define R1 A1
#define R2 A0
#define enr 6
#define s1 8
#define s2 9
#define s3 10
#define s4 11
#define s5 12


int s[5] = { 0 };
int error=0;
int pos=0;
int previousError=0;
int totalError=0;
int power=0;
int Kp=40;
int Kd=5;
int Ki=0;
int PWM_Right=0;
int PWM_Left=0;
int x=0;


/*float activeSensor = 0; // Count active sensors
  float totalSensor = 0; // Total sensor readings
  float avgSensor = 3;*/ // Average sensor reading

//int s1,s2,s3,s4,s5;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(enl, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(enr, OUTPUT);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);


}

void loop() {
  pid();
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 5; i++)
  {
    s[i] = digitalRead(8 + i);
  }

if(s[0]==0&&s[1]==0&&s[2]==1&&s[3]==0&&s[4]==0||s[0]==0&&s[1]==0&&s[2]==1&&s[3]==1&&s[4]==0||s[0]==0&&s[1]==1&&s[2]==1&&s[3]==0&&s[4]==0)
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
}

void left()
{
  analogWrite(enl, 180);
  analogWrite(enr, 180);
  digitalWrite(L2, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
}


void slowleft()
{
  analogWrite(enl, 60);
  analogWrite(enr, 60);
  digitalWrite(L2, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
}

void right()
{
  analogWrite(enl, 180);
  analogWrite(enr, 180);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R2, HIGH);
  digitalWrite(R1, LOW);
}


void slowright()
{
  analogWrite(enl, 60);
  analogWrite(enr, 60);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R2, HIGH);
  digitalWrite(R1, LOW);
}
void pid()
{
  readSensor();
  error = 0 - pos;
  totalError += error;

   // save previous error for differential
   // Count how much robot deviate from center
     // Accumulate error for integral
    power = (Kp*error) + (Kd*(error-previousError)) + (Ki*totalError);
previousError = error;


    if( power>255 ) { power = 255; }
    if( power<-255 ) { power = -255; }
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
if(s[0]==1&&s[1]==1&&s[2]==1&&s[3]==0&&s[4]==0||s[0]==1&&s[1]==1&&s[2]==0&&s[3]==0&&s[4]==0)
{stop();
x=1;
return;
}

if(s[0]==0&&s[1]==0&&s[2]==1&&s[3]==1&&s[4]==1||s[0]==0&&s[1]==0&&s[2]==0&&s[3]==1&&s[4]==1)
{stop();
x=3;
return;
}

if(s[0]==1&&s[1]==1&&s[2]==1&&s[3]==1&&s[4]==1||s[0]==1&&s[1]==1&&s[2]==1&&s[3]==1&&s[4]==0||s[0]==0&&s[1]==1&&s[2]==1&&s[3]==1&&s[4]==1)
{stop();
x=2;
return;
}

}

void readSensor() {
  s[0] = digitalRead(s1);
  s[1] = digitalRead(s2);
  s[2] = digitalRead(s3);
  s[3] = digitalRead(s4);
  s[4] = digitalRead(s5);


  /*if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 0)
    pos = 4;*/
  if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 0)
    pos = 3;
  if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 0)
    pos = 2;
  if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0)
    pos = 1;
  if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 0 && s[4] == 0)
    pos = 0;

  if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0)
    pos = -1;
  if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 0)
    pos = -2;
  if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1)
    pos = -3;
/* if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 1)
    pos = -4;*/

}
void stop()
{
  analogWrite(enl, 0);
  analogWrite(enr, 0);
  digitalWrite(L2, HIGH);
  digitalWrite(L1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R1, HIGH);
}

