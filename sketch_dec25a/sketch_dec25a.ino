int potPin = 0;
int ledPin = 2;
void setup() {
  pinMode(ledPin,OUTPUT);  // put your setup code here, to run once:

}

void loop() {
  int delayTimer = analogRead(potPin);
  
  digitalWrite(ledPin, HIGH);
  delay(delayTimer);
  
  digitalWrite(ledPin, LOW);
  delay(delayTimer);
  // put your main code here, to run repeatedly:

}
