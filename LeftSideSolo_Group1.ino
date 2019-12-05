
//Pin connected to ST_CP of 74HC595
int latchPinL = 8;
//Pin connected to SH_CP of 74HC595
int clockPinL = 12;
////Pin connected to DS of 74HC595
int dataPinL = 11;

const int tb1 = 4;//triangle left button
const int tb2 = 5;//triangle right button
const int cb1 = 6;//circle left button
const int cb2 = 7
;//circle right button
const int green4 = 3;

byte data1;
byte data2;
byte data3;

byte lightSet1[20];
byte lightSet2[20];
byte lightSet3[20];


int ts1 = 0;
int ts2 = 0;
int cs1 = 0;
int cs2 = 0;

int cost1 = 0;
int cost2 = 0;
int sus1 = 0;
int sus2 = 0;
int eff1 = 0; 
int eff2 = 0;
int hap1 = 0;
int hap2 = 0;

void setup() {
  // put your setup code here, to run once:
 //set pins to output because they are addressed in the main loop
 pinMode(green4, OUTPUT);
  pinMode(latchPinL, OUTPUT);
 //  pinMode(latchPinR, OUTPUT);
  Serial.begin(9600);


pinMode(tb1, INPUT_PULLUP);   //set this as a pullup to sense whether the left triangle(power) switch is flipped
 pinMode(tb2, INPUT_PULLUP);   //set this as a pullup to sense whether the right triangle(power) switch is flipped
 pinMode(cb1, INPUT_PULLUP);   //set this as a pullup to sense whether the left circle(waste) switch is flipped
 pinMode(cb2, INPUT_PULLUP);   //set this as a pullup to sense whether the right circle(waste) switch is flipped

   //Binary notation as comment


//set1 is top 8 for waste
//set1 landfill    1100 1111 0xCF  207 //
//set1 incinerator 1101 1011 0xDB  219 //
//set1 recylcing   0111 1001 0x79  121
//set1 null        0000 0000 0x00    0

  lightSet1[0] = 0x00;
  lightSet1[1] = 0xCF;
  lightSet1[2] = 0xDB;
  lightSet1[3] = 0x79;
  lightSet1[4] = 0x00; //0b00000000
  lightSet1[5] = 0xFF; //0b11111111

//set 2 is last 4 waste and first 4 power
//set2 fossil-null         1111 0000 0xF0  240
//set2 fossil-landfill     1111 0011 0xF3  243
//set2 fossil-incinerator  1111 0110 0xF6  246
//set2 fossil-recycling    1111 1110 0xFE  254
//set2 nuclear-null        1011 0000 0xB0  176
//set2 nuclear-landfill    1011 0011 0xB3  179
//set2 nuclear-incinerator 1011 0110 0xB6  182
//set2 nuclear-recycling   1011 1110 0xBE  190
//set2 renew-null          1001 0000 0x90  144
//set2 renew-landfill      1001 0011 0x93  147
//set2 renew-incinerator   1001 0110 0x96  150
//set2 renew-recycling     1001 1110 0x9E  158
//set2 null-null           0000 0000 0x00    0
//set2 null-landfull       0000 0011 0x03    3
//set2 null-incinerator    0000 0110 0x06    6
//set2 null-recycling      0000 1110 0x0E   14

lightSet2[0] = 0x00;
lightSet2[1] = 0xF0; 
lightSet2[2] = 0xF3; 
lightSet2[3] = 0xF6; 
lightSet2[4] = 0xFE; 
lightSet2[5] = 0xB0; 
lightSet2[6] = 0xB3; 
lightSet2[7] = 0xB6; 
lightSet2[8] = 0xBE; 
lightSet2[9] = 0x90; 
lightSet2[10] = 0x93; 
lightSet2[11] = 0x96; 
lightSet2[12] = 0x9E; 
lightSet2[13] = 0x00; 
lightSet2[14] = 0x03; 
lightSet2[15] = 0x06; 
lightSet2[16] = 0x0E; 

//set 3 is last 8 power
//set3 fossil  0010 0100 0x24   36  - - - - -00101100 1111 2C
//set3 nuclear 0111 1101 0x7D  125  - - - - -01111101 1011 7D
//set3 renew   1110 1111 0xEF  239  - - - - -11100111 1001 E7
//set3 null    0000 0000 0x00    0

  lightSet3[0] = 0x00;
  lightSet3[1] = 0x2C; 
  lightSet3[2] = 0x7C; 
  lightSet3[3] = 0xE7;
  lightSet3[4] = 0x00; //0b00000000
  lightSet3[5] = 0xFF; //0b11111111

}

void loop() {
  // put your main code here, to run repeatedly:
 ts1 = digitalRead(tb1); //sets the button state variable to the value of the left triangle switch
   ts2 = digitalRead(tb2); //sets the button state variable to the value of the right triangle switch
   cs1 = digitalRead(cb1); //sets the button state variable to the value of the left circle switch
   cs2 = digitalRead(cb2); //sets the button state variable to the value of the right circle switch

delay(10);
//***************FIRST SET LEFT SIDE START*******************************
 //if landfill waste
 if ((cs1 == LOW && cs2 == HIGH)) {
    //load the light sequence you want from array
    data1 = lightSet1[1];
    cost1 = 5;
    sus1 = 1;
    eff1 = 5;
    hap1 = 1;
 }
 //if incinerating waste
 else if ((cs1 == HIGH && cs2 == LOW)) {
    //load the light sequence you want from array
    data1 = lightSet1[2];
     cost1 = 3;
    sus1 = 3;
    eff1 = 3;
    hap1 = 3;

 }
 //if recylcing waste
  else if ((cs1 == LOW && cs2 == LOW)) {
    //load the light sequence you want from array
    data1 = lightSet1[3];
     cost1 = 1;
    sus1 = 5;
    eff1 = 5;
    hap1 = 5;
 }
 //if null
  else {
    //load the light sequence you want from array
    data1 = lightSet1[4];
     cost1 = 0;
    sus1 = 0;
    eff1 = 0;
    hap1 = 0;
 
 }
 delay(10);
//***************FIRST SET LEFT SIDE END*******************************



//***************THIRD SET LEFT SIDE START*******************************
//if fossil fuel energy
 if ((ts1 == LOW && ts2 == HIGH)) {
    //load the light sequence you want from array
    data3 = lightSet3[1];
     cost2 = 5;
    sus2 = 1;
    eff2 = 3;
    hap2 = 1;
      digitalWrite(green4, LOW);
 }
 //if nuclear energy
 else if ((ts1 == HIGH && ts2 == LOW)) {
    //load the light sequence you want from array
    data3 = lightSet3[2];
   cost2 = 3;
    sus2 = 1;
    eff2 = 5;
    hap2 = 3;
      digitalWrite(green4, LOW);
 }
 //if renewable energy
  else if ((ts1 == LOW && ts2 == LOW)) {
    //load the light sequence you want from array
    data3 = lightSet3[3];
     cost2 = 1;
    sus2 = 5;
    eff2 = 1;
    hap2 = 5;
    digitalWrite(green4, HIGH);

 }
 //if null
  else {
    //load the light sequence you want from array
    data3 = lightSet3[4];
     cost2 = 0;
    sus2 = 0;
    eff2 = 0;
    hap2 = 0;
  digitalWrite(green4, LOW);
 }
 delay(10);
//***************THIRD SET LEFT SIDE END*******************************


//***************SECOND SET LEFT SIDE START*******************************

//****for if fossil fuel energy*****
if (ts1 == LOW && ts2 == HIGH){
  //if null waste
  if (cs1 == HIGH && cs2 == HIGH){
     data2 = lightSet2[1];

  }
  //if landfill waste
  else if (cs1 == LOW && cs2 == HIGH){
     data2 = lightSet2[2];

  }
  //if incinerating waste
  else if (cs1 == HIGH && cs2 == LOW){
     data2 = lightSet2[3];

  }
  //if recycling waste
  else if (cs1 == LOW && cs2 == LOW){
     data2 = lightSet2[4];
  }
}
//****End of fossil fuel
//****If nuclear energy
if (ts1 == HIGH && ts2 == LOW){
  //if null waste
  if (cs1 == HIGH && cs2 == HIGH){
     data2 = lightSet2[5];
  }
  //if landfill waste
  else if (cs1 == LOW && cs2 == HIGH){
     data2 = lightSet2[6];
  }
  //if incinerating waste
  else if (cs1 == HIGH && cs2 == LOW){
     data2 = lightSet2[7];
  }
  //if recycling waste
  else if (cs1 == LOW && cs2 == LOW){
     data2 = lightSet2[8];
  }
}
//****If renewable energy
if (ts1 == LOW && ts2 == LOW){
  //if null waste
  if (cs1 == HIGH && cs2 == HIGH){
     data2 = lightSet2[9];
  }
  //if landfill waste
  else if (cs1 == LOW && cs2 == HIGH){
     data2 = lightSet2[10];
  }
  //if incinerating waste
  else if (cs1 == HIGH && cs2 == LOW){
     data2 = lightSet2[11];
  }
  //if recycling waste
  else if (cs1 == LOW && cs2 == LOW){
     data2 = lightSet2[12];
  }
}
//****If null energy
if (ts1 == HIGH && ts2 == HIGH){
  //if null waste
  if (cs1 == HIGH && cs2 == HIGH){
     data2 = lightSet2[13];
  }
  //if landfill waste
  else if (cs1 == LOW && cs2 == HIGH){
     data2 = lightSet2[14];
  }
  //if incinerating waste
  else if (cs1 == HIGH && cs2 == LOW){
     data2 = lightSet2[15];
  }
  //if recycling waste
  else if (cs1 == LOW && cs2 == LOW){
     data2 = lightSet2[16];
  }
}

delay(10);
  digitalWrite(latchPinL, 0);
    //move 'em out
    //move 'em out
    shiftOut(dataPinL, clockPinL, data3);
    shiftOut(dataPinL, clockPinL, data2);
    shiftOut(dataPinL, clockPinL, data1);


Serial.print("Left Side");
       Serial.print(data1);
      Serial.print(data2);
      Serial.println(data3);
       digitalWrite(latchPinL, 1);    

delay(500);
//end of loop
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
