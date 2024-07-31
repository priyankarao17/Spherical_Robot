#include<Servo.h>
Servo myservo;
char t;
int leftUSval;
int rightUSval;


#define IN_1 2
#define IN_2 3
#define IN_3 4
#define IN_4 5
 

int L;
int R;
 

void goForward(){ 
  Serial.println("FORWARD");
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
  }

void goBack(){ 
  Serial.println("BACKWORD");
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
  }

void goRight(){ 
  Serial.println("RIGHT");
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
  }

void goLeft(){
  Serial.println("LEFT");
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
  }

void hold(){  
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
 }
 
void BTcontrol() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
   myservo.write(90);
  //delay(2000);
  goForward();
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
 
  goBack();
  
}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  myservo.write(140);
  //delay(2000);
   goRight();
}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
    myservo.write(45);
  //delay(2000);
   goLeft();

}

else if(t == 'S'){      //STOP (all motors stop)
 
  hold();
}

}

void setup() {
  Serial.begin(9600);
  myservo.attach(6);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT); 

  
   }

void loop() {
     BTcontrol();
 
}