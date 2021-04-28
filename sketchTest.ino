#include <Adafruit_CircuitPlayground.h>
#include <Servo.h>

Servo lowerFinger1, lowerFinger2;
Servo middleFinger1, middleFinger2;
Servo upperFinger1, upperFinger2;

int lowerFinger1Default = 90, middleFinger1Default = 90, upperFinger1Default = 105;
int lowerFinger2Default = 0, middleFinger2Default = 0, upperFinger2Default = 20;

boolean play = false;

void setup() {
  Serial.begin(9600);
  delay(1000);
  CircuitPlayground.begin();
  lowerFinger1.attach(10);
  lowerFinger2.attach(9);
  middleFinger1.attach(6);
  middleFinger2.attach(1);
  upperFinger1.attach(0);
  upperFinger2.attach(2);
  
  lowerFinger1.write(lowerFinger1Default);
  lowerFinger2.write(lowerFinger2Default);

  //higher lower it goes
  middleFinger1.write(middleFinger1Default);
  middleFinger2.write(middleFinger2Default);

  //higher 
  upperFinger1.write(upperFinger1Default);
  upperFinger2.write(upperFinger2Default);
  
}

void paper()
{
  upperFinger1.write(45);
  lowerFinger1.write(110);
  middleFinger1.write(middleFinger1Default);
  
  lowerFinger2.write(lowerFinger2Default);
  middleFinger2.write(middleFinger2Default);
  upperFinger2.write(upperFinger2Default);
}

void rock()
{
  lowerFinger1.write(lowerFinger1Default);
  lowerFinger2.write(90);
  
  middleFinger1.write(lowerFinger1Default);
  middleFinger2.write(90);

  upperFinger1.write(lowerFinger1Default);
  upperFinger2.write(110);
}

void scissor()
{
  lowerFinger1.write(110);
  lowerFinger2.write(90);
  
  upperFinger1.write(45);
  upperFinger2.write(20);
  
  middleFinger1.write(110);
  middleFinger2.write(0);
  
}

void shaking()
{
  lowerFinger2.write(90);
  middleFinger2.write(90);
  upperFinger2.write(110);
  
  lowerFinger1.write(lowerFinger1Default);
  middleFinger1.write(middleFinger1Default);
  upperFinger1.write(upperFinger1Default);
  
  for(int i=0;i<3;i++)
  {
    upperFinger1.write(75);
    middleFinger1.write(60);
    lowerFinger1.write(60);
    
    delay(1000);
    lowerFinger1.write(lowerFinger1Default);
    middleFinger1.write(middleFinger1Default);
    upperFinger1.write(upperFinger1Default);
    delay(1000);
  }

}

void loop() 
{
  if(CircuitPlayground.leftButton()== 1)
  {
    shaking();
    int randNumber = random(3);
    if(randNumber == 0)
      scissor();
    else if(randNumber == 1)
      paper();
    else
      rock();
    delay(5000);
  }
  else
  {
    lowerFinger1.write(lowerFinger1Default);
    lowerFinger2.write(lowerFinger2Default);

    //higher lower it goes
    middleFinger1.write(middleFinger1Default);
    middleFinger2.write(middleFinger2Default);

    //higher 
    upperFinger1.write(upperFinger1Default);
    upperFinger2.write(upperFinger2Default);
  }
}




 
