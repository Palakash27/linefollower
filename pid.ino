int s1,s2,s3,s4,s5;
int pos=0;

int kp,ki,kd;
int powerdif;
int der=0;
int enl=5;
int enr=6;
int l1=10;
int l2=11;
int r1=12;
int r2=13;



void setup() {

  
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);

  pinMode(enl,OUTPUT);
  pinMode(enr,OUTPUT);
  Serial.begin(9600);

}

void loop(){

kp=analogRead(A0)/16;      
 
ki=analogRead(A1)/16;

kd=analogRead(A2)/1600000;

  pid();
 Serial.print(kp);
 Serial.print("\t"); 
Serial.print(ki);
 Serial.print("\t");
 Serial.println(kd);
 
}
void pid()
{while(1)
{s1=digitalRead(8);
s2=digitalRead(7);
s3=digitalRead(A5);
s4=digitalRead(3);
s5=digitalRead(2);
int lasterror=0;
int integral=0;
int error;
  readline();
  error=0-pos;
 /*Serial.print("E = ");
 Serial.print(error);*/
  der=error-lasterror;
  integral=integral+error;
  lasterror= error;
  powerdif=(kp*error)+(ki*integral)+(kd*der);
  if(powerdif>255)
  powerdif=255;
Serial.print("\tdef = ");
Serial.println(powerdif);

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
if(s1==0&&s2==0&&s3==0&&s4==0&&s5==1)
return;
if(s1==1&&s2==0&&s3==0&&s4==0&&s5==0)
 return;
/*else
{
 analogWrite(enl,255);
 analogWrite(enr,255);
  digitalWrite(l1,HIGH);
 digitalWrite(r1,HIGH);
 digitalWrite(l2,LOW);
 digitalWrite(r2,LOW);
 
}*/
  
}
 if(s1==0&&s2==0&&s3==0&&s4==0&&s5==1)
 {
  analogWrite(enl,255);
 analogWrite(enr,255);
   digitalWrite(l1,HIGH);
  digitalWrite(r1,LOW);
  digitalWrite(l2,LOW);
  digitalWrite(r2,HIGH);
 }
  if(s1==1&&s2==0&&s3==0&&s4==0&&s5==0)
 {
  analogWrite(enl,255);
 analogWrite(enr,255);
   digitalWrite(l1,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(l2,HIGH);
  digitalWrite(r2,LOW);
 }
}
void readline()
{

/*Serial.print("S1 = ");
Serial.print(s1);
Serial.print("\tS2 = ");
Serial.print(s2);
Serial.print("\tS3 = ");
Serial.print(s3);
Serial.print("\tS4 = ");
Serial.print(s4);
Serial.print("\tS5 = ");
Serial.print(s5);
Serial.print("\t");
delay(10);*/



if(s1==1&&s2==1&&s3==0&&s4==0&&s5==0)
 pos=3;
else if(s1==0&&s2==1&&s3==0&&s4==0&&s5==0)
 pos=2;
else if(s1==0&&s2==1&&s3==1&&s4==0&&s5==0)
 pos=1;
else if(s1==0&&s2==0&&s3==1&&s4==0&&s5==0)
pos=0;

else if(s1==0&&s2==0&&s3==1&&s4==1&&s5==0)
 pos=-1;
else if(s1==0&&s2==0&&s3==0&&s4==1&&s5==0)
 pos=-2;
else if(s1==0&&s2==0&&s3==0&&s4==1&&s5==1)
 pos=-3;

//Serial.print("\t POS = ");
//Serial.println(pos);
//delay(100);

 
}


