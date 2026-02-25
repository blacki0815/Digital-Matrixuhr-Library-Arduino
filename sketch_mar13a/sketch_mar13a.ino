// C++ code
//
int GELB=7;
int GRUN=6;
int Taster=5;
int Tasterstatus=0;
int Start=0;

void setup ()
{
  pinMode(GELB, OUTPUT);
  pinMode(GRUN, OUTPUT);
  //pinMode(Taster, INPUT);
  pinMode(Taster, INPUT_PULLUP);
} 

void loop ()
{
  digitalWrite(GRUN, LOW);
  digitalWrite(GELB, LOW);
  
  if(Start==0)
  {
    Tasterstatus=digitalRead(Taster);
    if(Tasterstatus==LOW)
    {
      Start=1;
      Tasterstatus=HIGH;
    }
  }
  
  if(Start==1)
  {
  digitalWrite(GELB, HIGH);
  delay(500);
  digitalWrite(GELB,HIGH);
  delay(500);
  digitalWrite(GELB,LOW);
  digitalWrite(GRUN, HIGH);
  delay(500);
  digitalWrite(GRUN,HIGH);
  delay(500);
  digitalWrite(GRUN,LOW);
  }
  
  
  if(Tasterstatus==1)
  {
    Tasterstatus=digitalRead(Taster);
    if(Tasterstatus==LOW)
    {
      Start=0;
    }
  }
}
