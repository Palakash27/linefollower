char ent[40];
char proc[40];
int i = 0;
int z=0;
int v=0;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("enter the char");
  Serial.println();
  // put your setup code here, to run once:

}

void loop() {
  if (Serial.available() > 0) {
    char thisChar = Serial.read();
    if (thisChar != 'w')
    {
      ent[i] = thisChar;
      i++;
    }
    else
    {
      for (int j = 0; j <=i; j++)
      {
        Serial.print(ent[j]);
        Serial.println();
      }
      
      
      process();
      check();
      while(v!=0)
      {
        process();
        check();
      }
      
    }
    // put your main code here, to run repeatedly:

  }
}
void process()
{int j=0;

  for(int i=0;i<40;i++)
  {
 if(ent[i]=='l')
    {
                    if(ent[i+1]=='u')
                    {
                            if(ent[i+2]=='l')
                            { 
                            proc[j]='s';
                            i=i+2;
                            j++;
                            z++;
                            }

                            else if(ent[i+2]=='s')
                            {
                              proc[j]='r';
                              i=i+2;
                              j++;
                              z++;
                            }

                            else if(ent[i+2]=='r')
                            {
                              proc[j]='b';
                              i=i+2;
                              j++;
                              z++;
                            } 
                  }

                  /*else
                  {
                  proc[j]='l';
                  j++;
                  }*/
    }



    //back conditions
    if(ent[i]=='l'&&z==0)
    {
                    if(ent[i+1]=='b')
                    {
                            if(ent[i+2]=='l')
                            { 
                            proc[j]='s';
                            i=i+2;
                            j++;
                            z++;
                            }

                            else if(ent[i+2]=='s')
                            {
                              proc[j]='r';
                              i=i+2;
                              j++;
                              z++;
                            }

                            else if(ent[i+2]=='r')
                            {
                              proc[j]='b';
                              i=i+2;
                              j++;
                              z++;
                            } 
                  }

                  else
                  {
                  proc[j]='l';
                  j++;
                  }
    }
    

    if(ent[i]=='s'&&z==0)
    {
                  if(ent[i+1]=='u')
                  {
                          if(ent[i+2]=='l')
                          {
                          proc[j]='r';
                          i=i+2;
                          j++;
                          z++;
                          }

                          else if(ent[i+2]=='r')
                          {
                          proc[j]='l';
                          i=i+2;
                          j++;
                          z++;
                          }

                          else if(ent[i+2]=='s')
                          {
                          proc[j]='b';
                          i=i+2;
                          j++;
                          z++;
                          }
              }
              /*else
              {
              proc[j]='s';
              j++;
              }*/
    }



//Back condition

if(ent[i]=='s'&&z==0)
    {
                  if(ent[i+1]=='b')
                  {
                          if(ent[i+2]=='l')
                          {
                          proc[j]='r';
                          i=i+2;
                          j++;
                          z++;
                          }

                          else if(ent[i+2]=='r')
                          {
                          proc[j]='l';
                          i=i+2;
                          j++;
                          z++;
                          }

                          else if(ent[i+2]=='s')
                          {
                          proc[j]='b';
                          i=i+2;
                          j++;
                          z++;
                          }
              }
              else
              {
              proc[j]='s';
              j++;
              }
    }


    if(ent[i]=='r'&&z==0)
    {
              if(ent[i+1]=='u')
              {
                          if(ent[i+2]=='s')
                          {
                            proc[j]='l';
                            i=i+2;
                            j++;
                            z++;
                          }

                          else if(ent[i+2]=='r')
                          {
                          proc[j]='s';
                          i=i+2;
                          j++;
                          z++;
                          }

                          else if(ent[i+2]=='l')
                          {
                          proc[j]='b';
                          i=i+2;
                          j++;
                          z++;
                          }
              }
      
              /*else
              {
              proc[j]='r';
              j++;
              }*/
    }


    //back conditions
    

    if(ent[i]=='r'&&z==0)
    {
              if(ent[i+1]=='b')
              {
                          if(ent[i+2]=='s')
                          {
                            proc[j]='l';
                            i=i+2;
                            j++;
                            z++;
                          }

                          else if(ent[i+2]=='r')
                          {
                          proc[j]='s';
                          i=i+2;
                          j++;
                          z++;
                          }

                          else if(ent[i+2]=='l')
                          {
                          proc[j]='b';
                          i=i+2;
                          j++;
                          z++;
                          }
              }
      
              else
              {
              proc[j]='r';
              j++;
              }
    }




    if(ent[i]=='u'&&z==0)
    {
     proc[j]='u';
      j++; 
    }
 if(ent[i]=='w'&&z==0)
    {
     proc[j]='w';
      j++; 
    }

   z=0; 
  }
  for (int j = 0; j < 40; j++)
      {
        Serial.print(proc[j]);
      }
      
}

void check()
{v=0;
  for(int i=0;i<40;i++)
  {
if(proc[i]=='u'||proc[i]=='b')
{
  v++;
}
    
  }

  Serial.println(v);
  if(v!=0)
  {
    for(int i=0;i<40;i++)
    {
      ent[i]=proc[i];
    }
  }
}

