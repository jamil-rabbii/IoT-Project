#include <string.h>
char user_num[15]="+8801771880355";

int sensor = A0;
int speaker = 10;
int gas_value;


void setup()
{

  pinMode(sensor, INPUT);
  pinMode(speaker, OUTPUT);
  digitalWrite(speaker,HIGH);
  Serial.begin(9600);
  delay(1000);
}

void loop()
{
digitalWrite(speaker,HIGH);

gas_value=analogRead(sensor);
  if(gas_value<255)
    {
      digitalWrite(speaker,LOW);
      makeCall(); //calling function
      delay(10000);
      digitalWrite(speaker,HIGH);
      delay(20000);
      //sendSMS("Gas Leakage Detected");
    }
  
}

/* 
void sendSMS(char text[])
{
  delay(500);
  Serial.println("AT+CMGF=1");
  delay(500);
  Serial.println("AT+CSCS=\"GSM\"");
  delay(1000);         //Sets the Serial Module in Text Mode
  Serial.print("AT+CMGS=\"");
  delay(500);
  Serial.print(user_num);
  delay(500);
  Serial.println("\""); //'user_num' is the string of the mobile number
  delay(500);
  Serial.print(text); // The SMS text you want to send
  delay(500);
  Serial.write(0x1A); // ASCII code of CTRL+Z. command to send SMS.
  delay(500);
  digitalWrite(speaker,HIGH);
} */


void makeCall()
{
  delay(500);
  Serial.print("ATD");
  Serial.print(user_num); //'user_num' is the string of the mobile number
  Serial.println(";");
  delay(10000);
  digitalWrite(speaker,HIGH);
  delay(15000);
  Serial.println("ATH"); //end the call
  delay(500);
}
