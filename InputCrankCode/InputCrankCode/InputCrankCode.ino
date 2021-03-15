void setup() {
  // put your setup code here, to run once:
  
#define EN        8  

//Direction pin
#define In_DIR     5 
#define Crank_DIR     6

//Step pin
#define In_STP     2
#define Crank_STP     3 
 

}

void step(boolean dir, byte dirPin, byte stepperPin, int stps, int delayTime)

{


  digitalWrite(dirPin, dir);

  delay(10);

  for (int i = 0; i < stps; i++) {

    digitalWrite(stepperPin, HIGH);

    delayMicroseconds(delayTime); 

    digitalWrite(stepperPin, LOW);

    delayMicroseconds(delayTime); 

 

  pinMode(In_DIR, OUTPUT); pinMode(In_STP, OUTPUT);

  pinMode(Crank_DIR, OUTPUT); pinMode(Crank_STP, OUTPUT);


  pinMode(EN, OUTPUT);

  digitalWrite(EN, LOW);

}
}
void loop(){
  //DRV8825
int delayTimeIn=100; //Delay between each pause (uS)
int delayTimeCrank=100; //Delay between each pause (uS)
int stpsIn=250;// Steps to move
int stpsCrank=350;// Steps to move

  step(false, In_DIR, In_STP, stpsIn, delayTimeIn); //X, Clockwise
  step(false, Crank_DIR, Crank_STP, stpsCrank, delayTimeCrank); //Y, Clockwise
  // step(false, Z_DIR, Z_STP, stps); //Z, Clockwise

  delay(100);

  

}
