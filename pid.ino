#include <SoftwareSerial.h>
SoftwareSerial bt(A0,A1);



int s1,s2,s3,s4,s5;
int pos;
int error;
int kp;
int powerdif;
int der;
int enl=5;
int enr=6;
int l1=10;
int l2=11;
int r1=12;
int r2=13;
int x;

int lasterror=0;
int integral=0;

void setup() {

  
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);

  pinMode(enl,OUTPUT);
  pinMode(enr,OUTPUT);
  Serial.begin(9600);
bt.begin(9600);
}

void loop(){
  if(bt.available())
  {
    x=bt.read();
    kp+=x;
  }
 
kp=1;

  pid();
  

}
void pid()
{
  readline();
  error=0-pos;
  der=error-lasterror;
  integral=integral+error;
  lasterror= error;
  powerdif=kp*error;
  if(powerdif>255)
  powerdif=255;

if(powerdif<-255)
 powerdif=-255;
 
 if(powerdif<0)
 {

  analogWrite(enl,255+powerdif);
  analogWrite(enr,255);
  digitalWrite(l1,HIGH);
  digitalWrite(r1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r2,LOW);
}

 if(powerdif>0)
 {

 analogWrite(enl,255);
 analogWrite(enr,255-powerdif);
 digitalWrite(l1,HIGH);
 digitalWrite(r1,HIGH);
 digitalWrite(l2,LOW);
 digitalWrite(r2,LOW);
 
}
else
{
 analogWrite(enl,255);
 analogWrite(enr,255);
  digitalWrite(l1,HIGH);
 digitalWrite(r1,HIGH);
 digitalWrite(l2,LOW);
 digitalWrite(r2,LOW);
 
}
  
 
  
}
void readline()
{
s1=digitalRead(8);
s2=digitalRead(7);
s3=digitalRead(A5);
s4=digitalRead(3);
s5=digitalRead(2);
 if(s1==1&&s2==0&&A5==0&&s4==0&&s5==0)
 pos=4;
 if(s1==1&&s2==1&&A5==0&&s4==0&&s5==0)
 pos=3;
 if(s1==0&&s2==1&&A5==0&&s4==0&&s5==0)
 pos=2;
 if(s1==0&&s2==1&&A5==1&&s4==0&&s5==0)
 pos=1;
 if(s1==0&&s2==0&&A5==1&&s4==0&&s5==0)
 pos=0;

 if(s1==0&&s2==0&&A5==1&&s4==1&&s5==0)
 pos=-1;
 if(s1==0&&s2==0&&A5==0&&s4==1&&s5==0)
 pos=-2;
 if(s1==0&&s2==0&&A5==0&&s4==1&&s5==1)
 pos=-3;
 if(s1==0&&s2==0&&A5==0&&s4==0&&s5==1)
 pos=-4;

 
}


