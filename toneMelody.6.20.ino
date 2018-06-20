#include "pitches.h"
const int buttonPin1 = 7; 
const int buttonPin2 = 4; 

int buttonState1 = 0; 
int buttonState2 = 0; 

long currentTime ,previousTime;
bool check;


const int buzzer = 8;

const int toneTable[7][5]={

    { 66, 131, 262, 523, 1046},  // C Do

    { 74, 147, 294, 587, 1175},  // D Re

    { 83, 165, 330, 659, 1318},  // E Mi

    { 88, 175, 349, 698, 1397},  // F Fa

    { 98, 196, 392, 784, 1568},  // G So

    {110, 220, 440, 880, 1760},  // A La

    {124, 247, 494, 988, 1976}   // B Si

};

char toneName[]="CDEFGAB";

char beeTone[]="GEEFDDCDEFGGGGEEFDDCEGGEDDDDDEFEEEEEFGGEEFDDCEGGC";

char starTone[]="CCGGAAGFFEEDDCGGFFEEDGGFFEEDCCGGAAGFFEEDDC";

int beeBeat[]={

    1,1,2, 1,1,2, 1,1,1,1,1,1,2,

    1,1,2, 1,1,2, 1,1,1,1,4,

    1,1,1,1,1,1,2, 1,1,1,1,1,1,2,

    1,1,2, 1,1,2, 1,1,1,1,4

};

int starBeat[]={

    1,1,1,1,1,1,2, 1,1,1,1,1,1,2,

    1,1,1,1,1,1,2, 1,1,1,1,1,1,2,

    1,1,1,1,1,1,2, 1,1,1,1,1,1,2

};

 

int getTone(char symbol) {

    int toneNo = 0;

    for ( int ii=0; ii<7; ii++ ) {

        if ( toneName[ii]==symbol ) {

            toneNo = ii;

            break;

        }

    }

    return toneNo;

}
static bool st=false;
 const int bP=2;
 const int lP=13;
 int bS=0;

void setup() {
pinMode(lP,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(bP,INPUT);
pinMode(buttonPin1, INPUT);
pinMode(buttonPin2, INPUT);
digitalWrite(bP,HIGH);
    noTone(buzzer);

}

 

void loop() {
    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
  int ii,length , toneNo;
   if (buttonState1 == HIGH) {
    bS=digitalRead(bP);
    int duration;
    // bee
    length = sizeof(beeTone)-1;
    for ( ii=0; ii<length; ii++ ) {
        toneNo = getTone(beeTone[ii]);
        duration = beeBeat[ii]*333;
        tone(buzzer,toneTable[toneNo][3]);
       previousTime=millis();
check=false;
digitalWrite(13,HIGH);
while(!check){
currentTime=millis();
  if(currentTime-previousTime>400){check=true;}
  if(currentTime-previousTime>300){digitalWrite(13,LOW);}
             }
     if(bS==HIGH){st=true;}
        noTone(buzzer);
                                  }
}
   else if(buttonState2 == HIGH) {
    bS=digitalRead(bP);
    int duration;
    // star
    length = sizeof(starTone)-1;
    for ( ii=0; ii<length; ii++ ) {
        toneNo = getTone(starTone[ii]);
        duration = starBeat[ii]*333;
        tone(buzzer,toneTable[toneNo][3]);
       previousTime=millis();
check=false;
digitalWrite(13,HIGH);
while(!check){
  currentTime=millis();
  if(currentTime-previousTime>400){
check=true;}
if(currentTime-previousTime>300){
digitalWrite(13,LOW);
  }
  }  
  if(bS==HIGH){  
    st=true;
    }
        noTone(buzzer);
    }
   }
}  


