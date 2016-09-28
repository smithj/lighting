/**

Latest haloween light script from bailey

*/

#include <math.h>


int ledR = 11;
int ledG = 10;
int ledB = 9;

int flashDuration = 200;

/*

PINS:
  3 - side of garege
  5 - front of garage
  6 - side of living room/front door
  
  9 - red
  10 - blue
  11 - green
  



*/

int allPins[6] = {3,5,6,9,10,11};
int allPinValues[6] = {192,255,64,0,0,255};


void setup() {
  Serial.begin(115200);
 
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);  
  pinMode(3, OUTPUT);  
  
  
  pinMode(13, OUTPUT);
  digitalWrite(13,LOW);

  pinMode(2, OUTPUT);
  digitalWrite(2,HIGH);
  
  pinMode(4,OUTPUT);
  digitalWrite(4, LOW);



}

void flash(int pin, int duration){
   
 analogWrite(pin, 255);
 delay(duration);
 analogWrite(pin,0);
}

void flashAll(int duration){
 
   for (int i=0; i<6; i++){  
      analogWrite(allPins[i], 255);
   }
    digitalWrite(4, HIGH);

   delay(duration);
   
   refreshAllPins();
    digitalWrite(4, LOW);


}

void refreshAllPins(){
   for (int i=0; i<6; i++){  
      analogWrite(allPins[i],allPinValues[i]);
   } 
}


void fade(int pinIndex, int startB, int stopB, int stepDuration){
  
   if (startB > stopB){
      startB = 0 - startB;
      stopB = 0 - stopB;
   }   
   for (int i=startB; i<stopB; i++){
       analogWrite(allPins[pinIndex],abs(i));
       allPinValues[allPins[pinIndex]] = abs(i);
       delay(stepDuration);
   }
   
}


void lightening(){
  


   flashAll(flashDuration);
   delay(100);
   flashAll(flashDuration*2);
   delay(20);
   flashAll(flashDuration);
   delay(100);
   flashAll(flashDuration*2);
   
   
      digitalWrite(13,HIGH);
   delay(1000);
   digitalWrite(13,LOW);
   
}


void loop() {
 
   refreshAllPins();   
   
   int brightMin = random(0,64);
   int stepDuration = random(30,200);
   
   Serial.print("bright min: ");
   Serial.println(brightMin);
   Serial.print("step duration: ");
   Serial.println(stepDuration);

   fade(1, 255, brightMin, stepDuration);
   
   int lighteningStrike = random(0,4);
   
//   if (lighteningStrike != 0){
      
      Serial.println("boom");
      lightening();      
//   }
   
   fade(1, brightMin, 255, stepDuration);

   
}
