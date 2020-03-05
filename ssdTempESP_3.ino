// Code V11, based on V10, but try to fix the WiFi password issue, works
//Master
#include <SoftwareSerial.h>
#define RX 7
#define TX 8
String AP = "PHSR2";       // AP NAME
String PASS = "Pr3sidi@n"; // AP PASSWORD
String API = "YBFFEGYDGI54K3WN";   // Write API KEY
String HOST = "api.thingspeak.com";
String PORT = "80";
int countTrueCommand;
int countTimeCommand; 
boolean found = false; 
int valSensor = 1;
SoftwareSerial esp8266(RX,TX); 

#include<Wire.h>//This library is used for I2C communication
#include <OneWire.h> 
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2 
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
int allDigits[3];
int x, sensorInt;

void setup() {
  Serial.begin(9600);
  Wire.begin(); //activate I2C protocol
//  delay(500);  
  esp8266.begin(115200); // ESP setup
//  delay(500);  
  sendCommand("AT+RST",5,"OK");
  sendCommand("AT",5,"OK");
  sendCommand("AT+CWMODE=1",5,"OK");
  String cmd = F("AT+CWJAP=\"");
  cmd += AP;
  cmd += F("\",\"");
  cmd += PASS;
  cmd += F("\"");
  sendCommand(cmd,20,"OK");
}

void loop() {
  sensors.requestTemperatures(); // Send the command to get temperature readings 
  float tempF=sensors.getTempCByIndex(0)*1.8+32;
  int sensorInt=tempF/1;//integer data in F is ready
  if (sensorInt!=185 && sensorInt!=-196){
    String sensorIntStr = String(sensorInt);  
    Wire.beginTransmission(9);// send through I2C to slave, 9 here is the address of the slave board 
    Wire.write(sensorInt);//Transfers the value of potentiometer to the slave board            
    Wire.endTransmission(); 
//  Serial.println(sensorIntStr);
//  delay(1000);
    String getData = "GET /update?api_key="+ API +"&field1="+sensorIntStr; // send to ThingSpeak, needs to be a string
    sendCommand("AT+CIPMUX=1",5,"OK");
    sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
    sendCommand("AT+CIPSEND=0," +String(getData.length()+4),4,">");
    esp8266.println(getData);delay(1500);countTrueCommand++;
    sendCommand("AT+CIPCLOSE=0",5,"OK");  
  } 
  else {}
}
//
void sendCommand(String command, int maxTime, char readReplay[]) {
//  Serial.print(countTrueCommand);
//  Serial.print(". at command => ");
//  Serial.print(command);
//  Serial.print(" ");
  while(countTimeCommand < (maxTime*1))
  {
    esp8266.println(command);//at+cipsend
    if(esp8266.find(readReplay))//ok
    {
      found = true;
      break;
    }  
    countTimeCommand++;
  }  
  if(found == true)
  {
    Serial.println("OYI");
    countTrueCommand++;
    countTimeCommand = 0;
  }  
  if(found == false)
  {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }  
  found = false;
 }

//// Slave
//#include<Wire.h>
//int latchPin=11;
//int clockPin=9;
//int dataPin=12;
//int ssd_6_DIG4=7;
//int ssd_8_DIG3=6;
//int ssd_9_DIG2=5;
//int ssd_12_DIG1=4;
//int SSDs, SSDs_re;
//int allDigits[3];
//int allDigits_global[3];
//int x;
//void setup() {
// pinMode(latchPin,OUTPUT);
// pinMode(dataPin,OUTPUT);
// pinMode(clockPin,OUTPUT); 
// pinMode(ssd_6_DIG4, OUTPUT);
// pinMode(ssd_8_DIG3, OUTPUT);
// pinMode(ssd_9_DIG2, OUTPUT);
// pinMode(ssd_12_DIG1, OUTPUT);
//  Wire.begin(9);//9 here is the address(Mentioned even in the master board code) 
//  Wire.onReceive(receiveEvent);//handler: the function to be called when the slave receives data; this should take a single int parameter (the number of bytes read from the master) and return nothing
//  Serial.begin(9600);
//}
//void receiveEvent(int bytes) {
//  x = Wire.read();//Receive value from master board
////  Serial.println(x);
//}
//void loop() {
//  binToDec();
//  
//    rightOne();
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
// allDigits[2]=x/100;
// allDigits[1]=(x/10)%10;
// allDigits[0]=x%10;
//// return allDigits;
//// Serial.println(sensorIntR1);
//}
//
//void updateShifReg(int y)
//{
//  digitalWrite(latchPin,LOW); // disable latch/pass
//  shiftOut(dataPin,clockPin,LSBFIRST,y);
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
