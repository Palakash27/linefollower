int m1=10;
int m2=11;
int n1=12;
int n2=13;
int ir=A3;
int e1=5;
int e2=6;
int a;
int b;
int c;
int d;
int e;
int n=0;
int i;
int kp;
int ki;
int kd;

void setup() {
  // put your setup code here, to run once:
digitalWrite(e1,1);
digitalWrite(e2,1);

}

void loop() {i=digitalRead(ir);
  // put your main code here, to run repeatedly:
  if(i==0)
 {
while(i!=1)
{i=digitalRead(ir);
  forward();
}
while(i)
{
i=digitalRead(ir);
  forward();
}
stop();
delay(1000);
}


         if(i)
        {
        while(i!=0)
        {i=digitalRead(ir);
        forward();
        }
        while(i==0)
        {
        i=digitalRead(ir);
        forward();
        }
        stop();
    delay(1000);
}

}

void forward()
{
  digitalWrite(m1,1);
  digitalWrite(m2,0);
  digitalWrite(n1,HIGH);
  digitalWrite(n2,0);
 /* while(n!=2)
  {
  while(i==0)
  {
  digitalWrite(m1,1);
  digitalWrite(m2,0);
  digitalWrite(n1,HIGH);
  digitalWrite(n2,0);
  n++;
  }
  while(i)
  {
  digitalWrite(m1,1);
  digitalWrite(m2,0);
  digitalWrite(n1,1);
  digitalWrite(n2,0);
  n++;
  }
  
  }
  delay(1000);
  */

 
 }
 void stop()
{
   digitalWrite(m1,0);
  digitalWrite(m2,0);
  digitalWrite(n1,0);
  digitalWrite(n2,0);
}

