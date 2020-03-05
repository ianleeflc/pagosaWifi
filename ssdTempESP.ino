// Code V7, Master get data from ds18b20 (connect to atmega pin 4) and send to slave for display in serial monitor
//Master
//#include<Wire.h>//This library is used for I2C communication
//#include <OneWire.h> 
//#include <DallasTemperature.h>
//#define ONE_WIRE_BUS 2 
//OneWire oneWire(ONE_WIRE_BUS); 
//DallasTemperature sensors(&oneWire);
//int allDigits[3];
//int x;
//void setup() {
//  Wire.begin(); 
//  Serial.begin(9600);
//}
//void loop() {
// sensors.requestTemperatures(); // Send the command to get temperature readings 
// float tempF=sensors.getTempCByIndex(0)*1.8+32;
// int sensorInt=tempF/1;
//
//  Wire.beginTransmission(9);//9 here is the address of the slave board 
//  Wire.write(sensorInt);//Transfers the value of potentiometer to the slave board            
//  Wire.endTransmission(); 
//  Serial.println(sensorInt);
//  delay(1000);
//}
// Slave
//#include<Wire.h>
//int x;
//void setup() {
////  pinMode (13, OUTPUT);//Connect LED to pin 13
//  Wire.begin(9);//9 here is the address(Mentioned even in the master board code) 
//  Wire.onReceive(receiveEvent);//handler: the function to be called when the slave receives data; this should take a single int parameter (the number of bytes read from the master) and return nothing
//  Serial.begin(9600);
//}
//void receiveEvent(int bytes) {
//  x = Wire.read();//Receive value from master board
//  Serial.println(x);
//}
//void loop() {
//}




// Code V6, arduino talk to arduino, I2C. Works by just simply connect two atmega328p's Pin27/28 pins together. 
// Master
//#include<Wire.h>//This library is used for I2C communication
//int x;
//void setup() {
//  Wire.begin(); 
//  Serial.begin(9600);
//}
//void loop() {
////  x = analogRead(A0);//Reading value from Potentiometer
////  x/=4;
//x=100;
//  Wire.beginTransmission(9);//9 here is the address of the slave board 
//  Wire.write(x);//Transfers the value of potentiometer to the slave board            
//  Wire.endTransmission(); 
////  Serial.print(x);
//  delay(1000);
//}
// Slave
//#include<Wire.h>
//int x;
//void setup() {
////  pinMode (13, OUTPUT);//Connect LED to pin 13
//  Wire.begin(9);//9 here is the address(Mentioned even in the master board code) 
//  Wire.onReceive(receiveEvent);//handler: the function to be called when the slave receives data; this should take a single int parameter (the number of bytes read from the master) and return nothing
//  Serial.begin(9600);
//}
//void receiveEvent(int bytes) {
//  x = Wire.read();//Receive value from master board
//  Serial.println(x);
//}
//void loop() {
//}





//// Code v5, The program with timer/interrupt to fix the problem, problem fixed but it blinks when it updates the temp. For the lunch box version, use the common anode, LDS-AD12RI 48mmx70mm modules. 
//#include <OneWire.h> 
//#include <DallasTemperature.h>
//#define ONE_WIRE_BUS 2 
//OneWire oneWire(ONE_WIRE_BUS); 
//DallasTemperature sensors(&oneWire);
//
//int latchPin=11;
//int clockPin=9;
//int dataPin=12;
//int ssd_6_DIG4=7;
//int ssd_8_DIG3=6;
//int ssd_9_DIG2=5;
//int ssd_12_DIG1=4;
// int sensorInt;
// int sensorIntR3;
// int sensorIntR2;
// int sensorIntR1;
//int SSDs, SSDs_re;
//int allDigits[3];
//int allDigits_global[3];
//
//void setup() 
//{ 
// pinMode(latchPin,OUTPUT);
// pinMode(dataPin,OUTPUT);
// pinMode(clockPin,OUTPUT); 
// pinMode(ssd_6_DIG4, OUTPUT);
// pinMode(ssd_8_DIG3, OUTPUT);
// pinMode(ssd_9_DIG2, OUTPUT);
// pinMode(ssd_12_DIG1, OUTPUT);
// Serial.begin(9600);
//noInterrupts();
//TCCR1A=0;
//TCCR1B=0;
//TCNT1=0;
//OCR1A=62500;
//TCCR1B|=(1<<WGM12);
//TCCR1B|=(1<<CS12);
//TCCR1B|=(1<<CS10);
//TIMSK1|=(1<<OCIE1A);
//interrupts();
//} 
//
//ISR(TIMER1_COMPA_vect){  // timer compare interrupt service routine
// binToDec(); 
//// Serial.println(1); 
//// delay(1000);
//}
//
//void loop() 
//{ 
//  rightOne();
//  SSDs=0x71; //0111 0001, LSB first, common cathode, display 'F'
//  updateShifReg(0x71);
//  delay(4);
//  
//// Serial.println(sensorIntR2);
//  SSDs_re=checkNum(allDigits[0]);
//  rightTwo();
//   updateShifReg(SSDs_re);   
//  delay(4);
//  
//  SSDs_re=checkNum(allDigits[1]);
//  rightThree();
//   updateShifReg(SSDs_re);   
//  delay(4);
//  
//  SSDs_re=checkNum(allDigits[2]);
//  rightFour();
//   updateShifReg(SSDs_re);   
//  delay(4); 
//} 
//
//int binToDec(){
// sensors.requestTemperatures(); // Send the command to get temperature readings 
// float tempF=sensors.getTempCByIndex(0)*1.8+32;
// int sensorInt=tempF/1;
// allDigits[2]=sensorInt/100;
// allDigits[1]=(sensorInt/10)%10;
// allDigits[0]=sensorInt%10;
// return allDigits;
//// Serial.println(sensorIntR1);
//}
//
//void updateShifReg(int x)
//{
//  digitalWrite(latchPin,LOW); // disable latch/pass
//  shiftOut(dataPin,clockPin,LSBFIRST,x);
//  digitalWrite(latchPin,HIGH); // rising edge latches/passes data through
//}
//
//void rightOne(){
//  digitalWrite(ssd_6_DIG4,LOW);
//  digitalWrite(ssd_8_DIG3,HIGH);
//  digitalWrite(ssd_9_DIG2,HIGH);
//  digitalWrite(ssd_12_DIG1,HIGH);
//}
//void rightTwo(){
//  digitalWrite(ssd_6_DIG4,HIGH);
//  digitalWrite(ssd_8_DIG3,LOW);
//  digitalWrite(ssd_9_DIG2,HIGH);
//  digitalWrite(ssd_12_DIG1,HIGH);
//}
//void rightThree(){
//  digitalWrite(ssd_6_DIG4,HIGH);
//  digitalWrite(ssd_8_DIG3,HIGH);
//  digitalWrite(ssd_9_DIG2,LOW);
//  digitalWrite(ssd_12_DIG1,HIGH);
//}
//void rightFour(){
//  digitalWrite(ssd_6_DIG4,HIGH);
//  digitalWrite(ssd_8_DIG3,HIGH);
//  digitalWrite(ssd_9_DIG2,HIGH);
//  digitalWrite(ssd_12_DIG1,LOW);
//}
//
//int checkNum(int arg){
//  switch(arg){
//    case 0: 
//    SSDs=0x03;// 0000 0011, display '0', only turn off G and H
//    break;
//    case 1:
//    SSDs=0x9F;// 
//    break;
//    case 2:
//    SSDs=0x25;
//    break;
//    case 3:
//    SSDs=0x0D;
//    break;
//    case 4:
//    SSDs=0x99;
//    break;
//    case 5:
//    SSDs=0x49;
//    break;
//    case 6:
//    SSDs=0x41;
//    break;
//    case 7:
//    SSDs=0x1F;
//    break;
//    case 8:
//    SSDs=0x01;
//    break;
//    case 9:
//    SSDs=0x09;
//    break;
//  }
//  return SSDs;
//}


//// Code v4, The program with timer/interrupt to fix the problem, problem fixed but it blinks when it updates the temp. For the lunch box version, use the 4-digit elegoo ssd module. 
//#include <OneWire.h> 
//#include <DallasTemperature.h>
//#define ONE_WIRE_BUS 2 
//OneWire oneWire(ONE_WIRE_BUS); 
//DallasTemperature sensors(&oneWire);
//
//int latchPin=11;
//int clockPin=9;
//int dataPin=12;
//int ssd_6_DIG4=7;
//int ssd_8_DIG3=6;
//int ssd_9_DIG2=5;
//int ssd_12_DIG1=4;
// int sensorInt;
// int sensorIntR3;
// int sensorIntR2;
// int sensorIntR1;
//int SSDs, SSDs_re;
//int allDigits[3];
//int allDigits_global[3];
//
//void setup() 
//{ 
// pinMode(latchPin,OUTPUT);
// pinMode(dataPin,OUTPUT);
// pinMode(clockPin,OUTPUT); 
// pinMode(ssd_6_DIG4, OUTPUT);
// pinMode(ssd_8_DIG3, OUTPUT);
// pinMode(ssd_9_DIG2, OUTPUT);
// pinMode(ssd_12_DIG1, OUTPUT);
// Serial.begin(9600);
//noInterrupts();
//TCCR1A=0;
//TCCR1B=0;
//TCNT1=0;
//OCR1A=62500;
//TCCR1B|=(1<<WGM12);
//TCCR1B|=(1<<CS12);
//TCCR1B|=(1<<CS10);
//TIMSK1|=(1<<OCIE1A);
//interrupts();
//} 
//
//ISR(TIMER1_COMPA_vect){  // timer compare interrupt service routine
// binToDec(); 
//// Serial.println(1); 
//// delay(1000);
//}
//
//void loop() 
//{ 
//  rightOne();
//  SSDs=0x8E;
//  updateShifReg(0x8E);
//  delay(5);
//  
//// Serial.println(sensorIntR2);
//  SSDs_re=checkNum(allDigits[0]);
//  rightTwo();
//   updateShifReg(SSDs_re);   
//  delay(5);
//  
//  SSDs_re=checkNum(allDigits[1]);
//  rightThree();
//   updateShifReg(SSDs_re);   
//  delay(5);
//  
//  SSDs_re=checkNum(allDigits[2]);
//  rightFour();
//   updateShifReg(SSDs_re);   
//  delay(5); 
//} 
//
//int binToDec(){
// sensors.requestTemperatures(); // Send the command to get temperature readings 
// float tempF=sensors.getTempCByIndex(0)*1.8+32;
// int sensorInt=tempF/1;
// allDigits[2]=sensorInt/100;
// allDigits[1]=(sensorInt/10)%10;
// allDigits[0]=sensorInt%10;
// return allDigits;
//// Serial.println(sensorIntR1);
//}
//
//void updateShifReg(int x)
//{
//  digitalWrite(latchPin,LOW); // disable latch/pass
//  shiftOut(dataPin,clockPin,LSBFIRST,x);
//  digitalWrite(latchPin,HIGH); // rising edge latches/passes data through
//}
//
//void rightOne(){
//  digitalWrite(ssd_6_DIG4,LOW);
//  digitalWrite(ssd_8_DIG3,HIGH);
//  digitalWrite(ssd_9_DIG2,HIGH);
//  digitalWrite(ssd_12_DIG1,HIGH);
//}
//void rightTwo(){
//  digitalWrite(ssd_6_DIG4,HIGH);
//  digitalWrite(ssd_8_DIG3,LOW);
//  digitalWrite(ssd_9_DIG2,HIGH);
//  digitalWrite(ssd_12_DIG1,HIGH);
//}
//void rightThree(){
//  digitalWrite(ssd_6_DIG4,HIGH);
//  digitalWrite(ssd_8_DIG3,HIGH);
//  digitalWrite(ssd_9_DIG2,LOW);
//  digitalWrite(ssd_12_DIG1,HIGH);
//}
//void rightFour(){
//  digitalWrite(ssd_6_DIG4,HIGH);
//  digitalWrite(ssd_8_DIG3,HIGH);
//  digitalWrite(ssd_9_DIG2,HIGH);
//  digitalWrite(ssd_12_DIG1,LOW);
//}
//
//int checkNum(int arg){
//  switch(arg){
//    case 0: 
//    SSDs=0xFC;// 
//    break;
//    case 1:
//    SSDs=0x60;
//    break;
//    case 2:
//    SSDs=0xDA;
//    break;
//    case 3:
//    SSDs=0xF2;
//    break;
//    case 4:
//    SSDs=0x66;
//    break;
//    case 5:
//    SSDs=0xB6;
//    break;
//    case 6:
//    SSDs=0xBE;
//    break;
//    case 7:
//    SSDs=0xE0;
//    break;
//    case 8:
//    SSDs=0xFE;
//    break;
//    case 9:
//    SSDs=0xF6;
//    break;
//  }
//  return SSDs;
//}


// Code v3, Temperature to 4-digit small 7-segment, this one can only read the temperature onece. It won't work if I put the temperature reading
// into the main loop since the temperature reading takes a lot of time to complete which interfere with the display scanning. 
// we need a timer and interrupt rutine to solve this problem. 
//#include <OneWire.h> 
//#include <DallasTemperature.h>
//#define ONE_WIRE_BUS 2 
//OneWire oneWire(ONE_WIRE_BUS); 
//DallasTemperature sensors(&oneWire);
//
//int latchPin=11;
//int clockPin=9;
//int dataPin=12;
//int ssd_6_DIG4=7;
//int ssd_8_DIG3=6;
//int ssd_9_DIG2=5;
//int ssd_12_DIG1=4;
// int sensorInt;
// int sensorIntR3;
// int sensorIntR2;
// int sensorIntR1;
//int SSDs, SSDs_re;
//int allDigits[3];
//
//void setup() 
//{ 
// pinMode(latchPin,OUTPUT);
// pinMode(dataPin,OUTPUT);
// pinMode(clockPin,OUTPUT); 
// pinMode(ssd_6_DIG4, OUTPUT);
// pinMode(ssd_8_DIG3, OUTPUT);
// pinMode(ssd_9_DIG2, OUTPUT);
// pinMode(ssd_12_DIG1, OUTPUT);
// Serial.begin(9600);
//  binToDec();
//} 
//void loop() 
//{ 
//  rightOne();
//  SSDs=0x8E;
//  updateShifReg(0x8E);
//  delay(5);
//  
// Serial.println(sensorIntR2);
//  SSDs_re=checkNum(allDigits[0]);
//  rightTwo();
//   updateShifReg(SSDs_re);   
//  delay(5);
//  
//  SSDs_re=checkNum(allDigits[1]);
//  rightThree();
//   updateShifReg(SSDs_re);   
//  delay(5);
//  
//  SSDs_re=checkNum(allDigits[2]);
//  rightFour();
//   updateShifReg(SSDs_re);   
//  delay(5); 
//} 
//
//int binToDec(){
// sensors.requestTemperatures(); // Send the command to get temperature readings 
// float tempF=sensors.getTempCByIndex(0)*1.8+32;
// int sensorInt=tempF/1;
// allDigits[2]=sensorInt/100;
// allDigits[1]=(sensorInt/10)%10;
// allDigits[0]=sensorInt%10;
// return allDigits;
//// Serial.println(sensorIntR1);
//}
//
//void updateShifReg(int x)
//{
//  digitalWrite(latchPin,LOW); // disable latch/pass
//  shiftOut(dataPin,clockPin,LSBFIRST,x);
//  digitalWrite(latchPin,HIGH); // rising edge latches/passes data through
//}
//
//void rightOne(){
//  digitalWrite(ssd_6_DIG4,LOW);
//  digitalWrite(ssd_8_DIG3,HIGH);
//  digitalWrite(ssd_9_DIG2,HIGH);
//  digitalWrite(ssd_12_DIG1,HIGH);
//}
//void rightTwo(){
//  digitalWrite(ssd_6_DIG4,HIGH);
//  digitalWrite(ssd_8_DIG3,LOW);
//  digitalWrite(ssd_9_DIG2,HIGH);
//  digitalWrite(ssd_12_DIG1,HIGH);
//}
//void rightThree(){
//  digitalWrite(ssd_6_DIG4,HIGH);
//  digitalWrite(ssd_8_DIG3,HIGH);
//  digitalWrite(ssd_9_DIG2,LOW);
//  digitalWrite(ssd_12_DIG1,HIGH);
//}
//void rightFour(){
//  digitalWrite(ssd_6_DIG4,HIGH);
//  digitalWrite(ssd_8_DIG3,HIGH);
//  digitalWrite(ssd_9_DIG2,HIGH);
//  digitalWrite(ssd_12_DIG1,LOW);
//}
//
//int checkNum(int arg){
//  switch(arg){
//    case 0: 
//    SSDs=0xFC;// 
//    break;
//    case 1:
//    SSDs=0x60;
//    break;
//    case 2:
//    SSDs=0xDA;
//    break;
//    case 3:
//    SSDs=0xF2;
//    break;
//    case 4:
//    SSDs=0x66;
//    break;
//    case 5:
//    SSDs=0xB6;
//    break;
//    case 6:
//    SSDs=0xBE;
//    break;
//    case 7:
//    SSDs=0xE0;
//    break;
//    case 8:
//    SSDs=0xFE;
//    break;
//    case 9:
//    SSDs=0xF6;
//    break;
//  }
//  return SSDs;
//}


//// Code v2, Test, Temperature to serial plotter, test, to split and convert the original float to integers
//#include <OneWire.h> 
//#include <DallasTemperature.h>
//#define ONE_WIRE_BUS 2 
//OneWire oneWire(ONE_WIRE_BUS); 
//DallasTemperature sensors(&oneWire);
//
//void setup() 
//{ 
// Serial.begin(9600); 
// sensors.begin(); 
//} 
//void loop() 
//{ 
// sensors.requestTemperatures(); // Send the command to get temperature readings 
// float tempF=sensors.getTempCByIndex(0)*1.8+32;
// int sensorInt=tempF/1;
// int sensorIntR3=sensorInt/100;
// int sensorIntR2=(sensorInt/10)%10;
// int sensorIntR1=sensorInt%10;
// Serial.println(sensorIntR1); 
// delay(500);
// Serial.println(sensorIntR2); 
// delay(500); 
// Serial.println(sensorIntR3); 
// delay(500);  
//} 



//// Code v1, Temperature to serial plotter
//#include <OneWire.h> 
//#include <DallasTemperature.h>
//#define ONE_WIRE_BUS 2 
//OneWire oneWire(ONE_WIRE_BUS); 
//DallasTemperature sensors(&oneWire);
//
//void setup() 
//{ 
// Serial.begin(9600); 
// sensors.begin(); 
//} 
//void loop() 
//{ 
// sensors.requestTemperatures(); // Send the command to get temperature readings 
// Serial.println(sensors.getTempCByIndex(0)); 
// delay(10); 
//} 
