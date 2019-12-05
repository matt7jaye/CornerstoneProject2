
//Pin connected to ST_CP of 74HC595
int latchPinL = 8;
//Pin connected to SH_CP of 74HC595
int clockPinL = 12;
////Pin connected to DS of 74HC595
int dataPinL = 11;


const int sb1 =6;//square left button
const int sb2 = 7;//square right button
const int pb1 = 4;//pentagon left button
const int pb2 = 5;//pentagon right button

byte data4;
byte data5;
byte data6;

byte lightSet4[20];
byte lightSet5[20];
byte lightSet6[20];

int ss1 = 0;
int ss2 = 0;
int ps1 = 0;
int ps2 = 0;


int cost3 = 0;
int cost4 = 0;

int sus3 = 0;
int sus4 = 0;

int eff3 = 0;
int eff4 = 0;

int hap3 = 0;
int hap4 = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(latchPinL, OUTPUT);
    Serial.begin(9600);
     pinMode(sb1, INPUT_PULLUP);
 pinMode(sb2, INPUT_PULLUP);
 pinMode(pb1, INPUT_PULLUP);
 pinMode(pb2, INPUT_PULLUP);
 
//Set 4 is for water purification
//set4 Fresh Water 1101 1011 0xDB  219 //
//set4 Purified    0111 1001 0x79  121
//set4 Local       1100 1111 0xCF  207 //
//set4 null        0000 0000 0x00    0

  lightSet4[0] = 0x00;
  lightSet4[1] = 0xDB;
  lightSet4[3] = 0x79;
  lightSet4[2] = 0xCF;
  lightSet4[4] = 0x00; //0b00000000
  lightSet4[5] = 0xFF; //0b11111111

//Set 5 is for the last 4 water and first 4 transport
//Set 5 road - null    B0
//Set 5 road - fresh   B6
//Set 5 road - pure    BE
//Set 5 road - local   B3
//Set 5 rail - null    90
//Set 5 rail - fresh   96
//Set 5 rail - pure    9E
//Set 5 rail - local   93
//Set 5 bike - null    F0
//Set 5 bike - fresh   F6
//Set 5 bike - pure    FE
//Set 5 bike - local   F3
//Set 5 null - null    00
//Set 5 null - fresh   06
//Set 5 null - pure    0E
//Set 5 null - local   03

lightSet5[0] = 0x00;
lightSet5[1] = 0xB0; 
lightSet5[2] = 0xB6; 
lightSet5[3] = 0xB3; 
lightSet5[4] = 0xBE; 
lightSet5[5] = 0xF0; 
lightSet5[6] = 0xF6; 
lightSet5[7] = 0xF3; 
lightSet5[8] = 0xFE; 
lightSet5[9] = 0x90; 
lightSet5[10] = 0x96; 
lightSet5[11] = 0x93; 
lightSet5[12] = 0x9E; 
lightSet5[13] = 0x00; 
lightSet5[14] = 0x06; 
lightSet5[15] = 0x03; 
lightSet5[16] = 0x0E; 


//Set 6 is for Transport Last 8
//Set 6 roadways 11101100 EC
//Set 6 railways 00111101 3D
//Set 6 bikes    01100111 67
  lightSet6[0] = 0x00;
  lightSet6[3] = 0xFC;
  lightSet6[1] = 0x2F;
  lightSet6[2] = 0x65;
  lightSet6[4] = 0x00; //0b00000000
  lightSet6[5] = 0xFF; //0b11111111   
}

void loop() {
  // put your main code here, to run repeatedly:
  
   ss1 = digitalRead(sb1); //sets the button state variable to the value of the left square switch
   ss2 = digitalRead(sb2); //sets the button state variable to the value of the right square switch
   ps1 = digitalRead(pb1); //sets the button state variable to the value of the left pentagon switch
   ps2 = digitalRead(pb2); //sets the button state variable to the value of the right pentagon switch
delay(10);
   

//***************fourth SET RIGHT SIDE START*******************************
 //if freshwater
 if ((ps1 == LOW && ps2 == HIGH)) {
    //load the light sequence you want from array
    data4 = lightSet4[1];
    cost3 = 3;
    sus3 = 3;
    eff3 = 3;
    hap3 = 3;
 }
 //if purified water
 else if ((ps1 == HIGH && ps2 == LOW)) {
    //load the light sequence you want from array
    data4 = lightSet4[2];
    cost3 = 1;
    sus3 = 5;
    eff3 = 1;
    hap3 = 5;

 }
 //if local water
  else if ((ps1 == LOW && ps2 == LOW)) {
    //load the light sequence you want from array
    data4 = lightSet4[3];
    cost3 = 5;
    sus3 = 1;
    eff3 = 5;
    hap3 = 1;
 }
 //if null
  else {
    //load the light sequence you want from array
    data4 = lightSet4[4];
    cost3 = 0;
    sus3 = 0;
    eff3 = 0;
    hap3 = 0;
 
 }
 delay(10);
//***************fourth SET RIGHT SIDE END*******************************



//***************sixth SET RIGHT SIDE START*******************************
//if roadways
 if ((ss1 == LOW && ss2 == HIGH)) {
    //load the light sequence you want from array
    data6 = lightSet6[1];
    cost4 = 3;
    sus4 = 1;
    eff4 = 3;
    hap4 = 5;
 }
 //if railways
 else if ((ss1 == HIGH && ss2 == LOW)) {
    //load the light sequence you want from array
    data6 = lightSet6[2];
    cost4 = 1;
    sus4 = 3;
    eff4 = 5;
    hap4 = 3;

 }
 //if bike
  else if ((ss1 == LOW && ss2 == LOW)) {
    //load the light sequence you want from array
    data6 = lightSet6[3];
    cost4 = 5;
    sus4 = 5;
    eff4 = 1;
    hap4 = 1;

 }
 //if null
  else {
    //load the light sequence you want from array
    data6 = lightSet6[4];
    cost4 = 0;
    sus4 = 0;
    eff4 = 0;
    hap4 = 0;

 }
 delay(10);
//***************sixth SET RIGHT SIDE END*******************************


//***************fifth SET RIGHT SIDE START*******************************

//****for if roadways*****
if (ss1 == LOW && ss2 == HIGH){
  //if null water
  if (ps1 == HIGH && ps2 == HIGH){
     data5 = lightSet5[1];

  }
  //if fresh water
  else if (ps1 == LOW && ps2 == HIGH){
     data5 = lightSet5[2];

  }
  //if purified water
  else if (ps1 == HIGH && ps2 == LOW){
     data5 = lightSet5[3];

  }
  //if local water
  else if (ps1 == LOW && ps2 == LOW){
     data5 = lightSet5[4];
  }
}
//****End of fossil fuel
//****If railways
if (ss1 == HIGH && ss2 == LOW){
  //if null water
  if (ps1 == HIGH && ps2 == HIGH){
     data5 = lightSet5[5];
  }
  //if fresh water
  else if (ps1 == LOW && ps2 == HIGH){
     data5 = lightSet5[6];
  }
  //if pure water
  else if (ps1 == HIGH && ps2 == LOW){
     data5 = lightSet5[7];
  }
  //if local water
  else if (ps1 == LOW && ps2 == LOW){
     data5 = lightSet5[8];
  }
}
//****If bikes
if (ss1 == LOW && ss2 == LOW){
  //if null water
  if (ps1 == HIGH && ps2 == HIGH){
     data5 = lightSet5[9];
  }
  //if fresh water
  else if (ps1 == LOW && ps2 == HIGH){
     data5 = lightSet5[10];
  }
  //if purified water
  else if (ps1 == HIGH && ps2 == LOW){
     data5 = lightSet5[11];
  }
  //if local water
  else if (ps1 == LOW && ps2 == LOW){
     data5 = lightSet5[12];
  }
}
//****If null roadway
if (ss1 == HIGH && ss2 == HIGH){
  //if null water
  if (ps1 == HIGH && ps2 == HIGH){
     data5 = lightSet5[13];
  }
  //if fresh water
  else if (ps1 == LOW && ps2 == HIGH){
     data5 = lightSet5[14];
  }
  //if purified water
  else if (ps1 == HIGH && ps2 == LOW){
     data5 = lightSet5[15];
  }
  //if local water
  else if (ps1 == LOW && ps2 == LOW){
     data5 = lightSet5[16];
  }
}

delay(10);
//  digitalWrite(latchPinR, 0);
  digitalWrite(latchPinL, 0);
    //move 'em out
    shiftOut(dataPinL, clockPinL, data6);
    shiftOut(dataPinL, clockPinL, data5);
    shiftOut(dataPinL, clockPinL, data4);
    //move 'em out
 Serial.print("Right Side");
         Serial.print(data4);
      Serial.print(data5);
      Serial.println(data6);

    digitalWrite(latchPinL, 1);    
delay(500);
 //END OF LOOP
   
}

// the heart of the program
void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {
  // This shifts 8 bits out MSB first,
  //on the rising edge of the clock,
  //clock idles low

  //internal function setup
  int i=0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);

  //clear everything out just in case to
  //prepare shift register for bit shifting
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);

  //for each bit in the byte myDataOut�
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights.
  for (i=7; i>=0; i--)  {
    digitalWrite(myClockPin, 0);

    //if the value passed to myDataOut and a bitmask result
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000
    // and proceeds to set pinState to 1.
    if ( myDataOut & (1<<i) ) {
      pinState= 1;
    }
    else { 
      pinState= 0;
    }

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(myDataPin, pinState);
    //register shifts bits on upstroke of clock pin  
    digitalWrite(myClockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(myDataPin, 0);
  }

  //stop shifting    
  digitalWrite(myClockPin, 0);
}
