
int cost1 = 0;
int cost2 = 0;
int cost3 = 0;
int cost4 = 0;
int sus1 = 0;
int sus2 = 0;
int sus3 = 0;
int sus4 = 0;
int eff1 = 0; 
int eff2 = 0;
int eff3 = 0;
int eff4 = 0;
int hap1 = 0;
int hap2 = 0;
int hap3 = 0;
int hap4 = 0;
int costT = 0;
int susT = 0;
int effT = 0;
int hapT = 0;
int costG = 0;
int susG = 0;
int effG = 0;
int hapG = 0;
int total = 0;

const int tb1 = 5;//triangle left button
const int tb2 = 2;//triangle right button
const int cb1 = 3;//circle left button
const int cb2 = 4;//circle right button
const int sb1 = 8;//square left button
const int sb2 = 9;//square right button
const int pb1 = 6;//pentagon left button
const int pb2 = 7;//pentagon right button

int ts1 = 0;
int ts2 = 0;
int cs1 = 0;
int cs2 = 0;
int ss1 = 0;
int ss2 = 0;
int ps1 = 0;
int ps2 = 0;

int i = 0;

#include <FastLED.h>

#define LED_PIN     12
#define NUM_LEDS    48
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB

#define UPDATES_PER_SECOND 100

CRGB leds[NUM_LEDS];


#include <SoftwareSerial.h>
SoftwareSerial LCD(10, 11); // Arduino SS_RX = pin 10 (unused), Arduino SS_TX = pin 11 


void setup() {


   Serial.begin(9600);
   
 pinMode(tb1, INPUT_PULLUP);   //set this as a pullup to sense whether the left triangle(power) switch is flipped
 pinMode(tb2, INPUT_PULLUP);   //set this as a pullup to sense whether the right triangle(power) switch is flipped
 pinMode(cb1, INPUT_PULLUP);   //set this as a pullup to sense whether the left circle(waste) switch is flipped
 pinMode(cb2, INPUT_PULLUP);   //set this as a pullup to sense whether the right circle(waste) switch is flipped
 pinMode(sb1, INPUT_PULLUP);
 pinMode(sb2, INPUT_PULLUP);
 pinMode(pb1, INPUT_PULLUP);
 pinMode(pb2, INPUT_PULLUP);


  LCD.begin(9600); // set up serial port for 9600 baud
  delay(500); // wait for display to boot up


  // put your setup code here, to run once:
 FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );

}

void loop() {
/*
/*************LCD EXAMPLE *********************
 
// move cursor to beginning of first line
LCD.write(254);
LCD.write(192);
  // clear display by sending spaces
  LCD.write("                ");
  LCD.write("                ");
  // move cursor to beginning of first line
  LCD.write(254);
  LCD.write(128);
  LCD.write("Hello, world!");
  // move cursor to beginning of second line
  LCD.write(254);
  LCD.write(192);
  LCD.write("Less is more!");
  while (1); // wait forever*/
  
  // put your setup code here, to run once:

Serial.print("buttons before");//prints out button states
Serial.print(ts1);
Serial.print(ts2);
Serial.print(cs1);
Serial.print(cs2);
Serial.print(ss1);
Serial.print(ss2);
Serial.print(ps1);
Serial.println(ps2);
   ts1 = digitalRead(tb1); //sets the button state variable to the value of the left triangle switch
   ts2 = digitalRead(tb2); //sets the button state variable to the value of the right triangle switch
   cs1 = digitalRead(cb1); //sets the button state variable to the value of the left circle switch
   cs2 = digitalRead(cb2); //sets the button state variable to the value of the right circle switch
   ss1 = digitalRead(sb1); //sets the button state variable to the value of the left square switch
   ss2 = digitalRead(sb2); //sets the button state variable to the value of the right square switch
   ps1 = digitalRead(pb1); //sets the button state variable to the value of the left pentagon switch
   ps2 = digitalRead(pb2); //sets the button state variable to the value of the right pentagon switch
Serial.print("buttons after");//prints out button states
Serial.print(ts1);
Serial.print(ts2);
Serial.print(cs1);
Serial.print(cs2);
Serial.print(ss1);
Serial.print(ss2);
Serial.print(ps1);
Serial.println(ps2);

 //if landfill waste
 if ((cs1 == HIGH && cs2 == LOW)) {
  Serial.print("Landfill ");
    cost1 = 5;
    sus1 = 1;
    eff1 = 5;
    hap1 = 1;
 }
 //if incinerating waste
 else if ((cs1 == LOW && cs2 == HIGH)) {
  Serial.print("Incinerate ");
     cost1 = 3;
    sus1 = 3;
    eff1 = 3;
    hap1 = 3;

 }
 //if recylcing waste
  else if ((cs1 == HIGH && cs2 == HIGH)) {
    Serial.print("Recycle ");
     cost1 = 1;
    sus1 = 5;
    eff1 = 1;
    hap1 = 5;
 }
 //if null
  else {
    Serial.print("Null ");
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
  Serial.print("Fossil ");
     cost2 = 5;
    sus2 = 1;
    eff2 = 3;
    hap2 = 1;
 }
 //if nuclear energy
 else if ((ts1 == HIGH && ts2 == LOW)) {
  Serial.print("Nuclear ");
   cost2 = 3;
    sus2 = 1;
    eff2 = 5;
    hap2 = 3;
 }
 //if renewable energy
  else if ((ts1 == HIGH && ts2 == HIGH)) {
    Serial.print("Renewable ");
     cost2 = 1;
    sus2 = 5;
    eff2 = 1;
    hap2 = 5;

 }
 //if null
  else {
    Serial.print("Null ");
     cost2 = 0;
    sus2 = 0;
    eff2 = 0;
    hap2 = 0;

 }
 delay(10);
//***************THIRD SET LEFT SIDE END*******************************
//***************fourth SET RIGHT SIDE START*******************************
 //if freshwater
 if ((ps1 == HIGH && ps2 == LOW)) {
  Serial.print("Fresh ");
    //load the light sequence you want from array
    cost3 = 3;
    sus3 = 3;
    eff3 = 3;
    hap3 = 3;
 }
 //if purified water
 else if ((ps1 == LOW && ps2 == HIGH)) {
  Serial.print("Purified ");
    //load the light sequence you want from array
    cost3 = 1;
    sus3 = 5;
    eff3 = 1;
    hap3 = 5;

 }
 //if local water
  else if ((ps1 == HIGH && ps2 == HIGH)) {
    Serial.print("Local ");
    //load the light sequence you want from array
    cost3 = 5;
    sus3 = 1;
    eff3 = 5;
    hap3 = 1;
 }
 //if null
  else {
    Serial.print("Null ");
    //load the light sequence you want from array
    cost3 = 0;
    sus3 = 0;
    eff3 = 0;
    hap3 = 0;
 
 }
 delay(10);
//***************fourth SET RIGHT SIDE END*******************************
//***************sixth SET RIGHT SIDE START*******************************
//if roadways
 if ((ss1 == HIGH && ss2 == LOW)) {
  Serial.print("Road ");
    //load the light sequence you want from array
    cost4 = 3;
    sus4 = 1;
    eff4 = 3;
    hap4 = 5;
 }
 //if railways
 else if ((ss1 == LOW && ss2 == HIGH)) {
  Serial.print("Rail ");
    cost4 = 1;
    sus4 = 3;
    eff4 = 5;
    hap4 = 3;

 }
 //if bike
  else if ((ss1 == HIGH && ss2 == HIGH)) {
    Serial.print("Bike ");
    cost4 = 5;
    sus4 = 5;
    eff4 = 1;
    hap4 = 1;

 }
 //if null
  else {
    Serial.print("Null ");
    cost4 = 0;
    sus4 = 0;
    eff4 = 0;
    hap4 = 0;

 }
 delay(10);


costT = 0;
susT = 0;
effT = 0;
hapT = 0;

  // put your main code here, to run repeatedly:
costT = (cost1 + cost2 + cost3 + cost4);
susT = (sus1 + sus2 + sus3 + sus4);
effT = (eff1 + eff2 + eff3 + eff4);
hapT = (hap1 + hap2 + hap3 + hap4);
/*
Serial.print(" cost1 ");//ouputs calculated values
Serial.print(cost1);
Serial.print(" cost2 ");
Serial.print(cost2);
Serial.print(" cost3 ");
Serial.print(cost3);
Serial.print(" cost4 ");
Serial.print(cost4);
Serial.print(" costT ");
Serial.print(costT);
Serial.print(" susT ");
Serial.print(susT);
Serial.print(" effT ");
Serial.print(effT);
Serial.print(" hapT ");
Serial.print(hapT);
*/
total = 0;
if ((costT <= susT) && (costT <= effT) && (costT <= hapT)){
total = (costT + costT + susT + effT + hapT);//calculates total score to print
}
else if ((susT <= costT) && (susT <= effT) && (susT <= hapT)){
  total = (costT + susT + susT + effT + hapT);
}
else if ((effT <= costT) && (effT <=susT) && (effT <= hapT)) {
  total = (costT + susT + effT + effT + hapT);
}
else {
  total = (costT + susT + effT + hapT + hapT);
}

Serial.print(" Total ");
Serial.print(total);


costG = costT -4;//calculates relative attributes for LED strip
susG = susT -4;
effG = effT -4;
hapG = hapT -4;

 LCD.write(254);//sets to the first line of LCD
LCD.write(192);
  // clear display by sending spaces
  LCD.write("                ");//clears LCD
  LCD.write("                ");
    

  //move lcd to first line
  LCD.write(254);
  LCD.write(128);
  LCD.write(" OVERALL SCORE");
 
   // move cursor to beginning of second line
  LCD.write(254);
  LCD.write(192);


//depending on total score, prints it to LCD
  if (total >= 48 && total < 49){
      LCD.write("       50     ");
  }
   else if (total >= 49 && total < 50){
      LCD.write("       55     ");
  }
   else if (total >= 50 && total < 51){
      LCD.write("       60     ");
  }
   else if (total >= 52 && total < 53){
      LCD.write("       65     ");
  }
   else if (total >=53 && total < 54){
      LCD.write("       70     ");
  }
   else if (total >= 54 && total < 55){
      LCD.write("       75     ");
  }
   else if (total >= 55 && total < 56){
      LCD.write("       80     ");
  }
 else if (total >= 56 && total < 57){
      LCD.write("       85     ");
  }
   else if (total >= 57 && total < 58){
      LCD.write("       90     ");
  }
   else if (total >= 58 && total < 59){
      LCD.write("       95     ");}
  else if (total >= 59){
      LCD.write("      100     ");
  }
  else if (total < 48){
    
  //move lcd to first line
  LCD.write(254);
  LCD.write(128);
  LCD.write("Incomplete Build");
 
   // move cursor to beginning of second line
  LCD.write(254);
  LCD.write(192);

    LCD.write(" Finish Nation");
  }
  else {
    LCD.write("Unknown");
  }
  
     /*  i=0;   
       //****************************STRIP EXAMPLE
  // put your main code here, to run repeatedly:
 /* while ((( i<NUM_LEDS)) && (costT == 0) || (susT == 0) || (effT == 0) || (hapT == 0)) {
    i = i + 1;
leds[i] = CRGB::Green;
  FastLED.show();
  // Now turn the LED off, then pause
  leds[i-1] = CRGB::White;
  FastLED.show();
  delay(50);
  }*/

i=0;
  while (i<11) {
    i = i+1;
//  Serial.print("  i  ");
 //  Serial.print(i);

    //while counter is less than relative green value, sets that index to green, else sets it to white
    if (i < hapG){
      leds[i] = CRGB::Green;
    }
    else {
      leds[i] = CRGB::White;
    }
    
    if (i < effG){
      leds[i+12] = CRGB::Green;
    }
    else {
      leds[i+12] = CRGB::White;
    }
    
     if (i < susG){
      leds[i+24] = CRGB::Green;
    }
    else {
      leds[i+24] = CRGB::White;
    }
    
       if (i < costG){
      leds[i+36] = CRGB::Green;
    }
    else {
      leds[i+36] = CRGB::White;
    }
  delay(10);
  
  //prints leds to strip
  FastLED.show();
  } delay(1500);
}
