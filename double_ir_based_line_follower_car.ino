// Here pin 8 and pin 9 of the Arduino Uno are used for left motor and pin 10 and pin 11 are for the right motor
// EN-A and EN-B of the motor driver are connected to  the pin 12 and pin 13 of th arduino and these pins must keep in "HIGH" state to drive the motors 
// Analog pin A0 is connected with left ir sensor and Analog pin A1 is connected with right ir sensor 

int a1=8;
int a2=9;
int b1=10;
int b2=11;
int ENA=12;
int ENB=13;
void setup() 
{

  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(a1,OUTPUT);
pinMode(a2,OUTPUT);
pinMode(b1,OUTPUT);
pinMode(b2,OUTPUT);
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
analogWrite(ENA,255);
analogWrite(ENB,255);

}

void loop() 
{
  
  // put your main code here, to run repeatedly:
  
int Leftval=analogRead(A0);
Serial.print("Left_IR_val = ");
Serial.println(Leftval);

int Rightval=analogRead(A1);
Serial.print("Right_IR_val = ");
Serial.println(Rightval);

if(Leftval<500&&Rightval<500)
forward();
else if(Leftval>500&&Rightval<500)
left();
else if(Leftval<500&&Rightval>500)
right();

}

void forward()
{
  
  
  digitalWrite(a1,LOW);
  digitalWrite(a2,HIGH);
  digitalWrite(b1,LOW);
  digitalWrite(b2,HIGH);

  
}

void right()
{
  
  
  digitalWrite(a1,LOW);
  digitalWrite(a2,HIGH);
  digitalWrite(b1,HIGH);
  digitalWrite(b2,LOW);

  
  
  }

void left()
{
  
  
   digitalWrite(a1,HIGH);
  digitalWrite(a2,LOW);
  digitalWrite(b1,LOW);
  digitalWrite(b2,HIGH);
  
  
  
  }
