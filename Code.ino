void setup()
{
  int a,b,c,d,e,f,g,x,y;
  pinMode(5,INPUT)//Enable
  pinMode(6,INPUT)//Enable
  pinMode(7,INPUT)//Sensors 1-7
  pinMode(8,INPUT)
  pinMode(9,INPUT)
  pinMode(10,INPUT)
  pinMode(11,INPUT)
  pinMode(12,INPUT)
  pinMode(13,INPUT)
}

void loop()
{
  /*x=digitalRead(5);
  y=digitalRead(6);*/
  a=digitalRead(7);
  b=digitalRead(8);
  c=digitalRead(9);
  d=digitalRead(10);
  e=digitalRead(11);
  f=digitalRead(12);
  g=digitalRead(13);

  if(b==1&&c==1&&d==1&&f==1&&a==0&&e==0&&g==0)
  {
    forward();
  }
  if(b==1&&c==1&&d==1&&f==0&&a==0&&e==0&&g==0)
  {
    backward();
  }
  if(b==1&&c==1&&d==1&&f==1&&a==1&&e==0&&g==0)
  {
    left();
  }
  if(b==1&&c==1&&d==1&&f==1&&a==1&&e==1&&g==0)
  {
    left();
  }
  if(b==1&&c==1&&d==1&&f==1&&a==0&&e==1&&g==0)
  {
    forward();
  }
  }
}

