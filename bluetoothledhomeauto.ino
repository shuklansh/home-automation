#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
double __var__108_105_118_105_110_103_32_114_111_111_109;
double bedroom;
double __var__100_105_110_105_110_103_32_114_111_111_109;
SoftwareSerial Bluetooth(1, 0);
char Data;
void sendData(String transmitData){
Bluetooth.println(transmitData);}

void setup(){
    Bluetooth.begin(9600);
    __var__108_105_118_105_110_103_32_114_111_111_109 = 5;
    bedroom = 6;
    __var__100_105_110_105_110_103_32_114_111_111_109 = 7;
    pinMode(__var__108_105_118_105_110_103_32_114_111_111_109,OUTPUT);
    pinMode(__var__100_105_110_105_110_103_32_114_111_111_109,OUTPUT);
    pinMode(bedroom,OUTPUT);
}

void loop(){
    Data=Bluetooth.read();
    if(Data==('4')){
        digitalWrite(__var__108_105_118_105_110_103_32_114_111_111_109,1);
        sendData("living room on");
    }
    if(Data==('1')){
        digitalWrite(__var__108_105_118_105_110_103_32_114_111_111_109,0);
        sendData("living room off");
    }
    if(Data==('5')){
        digitalWrite(__var__100_105_110_105_110_103_32_114_111_111_109,1);
        sendData("dining room on");
    }
    if(Data==('2')){
        digitalWrite(__var__100_105_110_105_110_103_32_114_111_111_109,0);
        sendData("dining room off");
    }
    if(Data==('6')){
        digitalWrite(bedroom,1);
        sendData("bedroom on");
    }
    if(Data==('3')){
        digitalWrite(bedroom,0);
        sendData("bedroom off");
    }
    if(Data==('9')){
        digitalWrite(bedroom,1);
        digitalWrite(__var__100_105_110_105_110_103_32_114_111_111_109,1);
        digitalWrite(__var__108_105_118_105_110_103_32_114_111_111_109,1);
        sendData("all on");
    }
    if(Data==('0')){
        digitalWrite(bedroom,0);
        digitalWrite(__var__100_105_110_105_110_103_32_114_111_111_109,0);
        digitalWrite(__var__108_105_118_105_110_103_32_114_111_111_109,0);
        sendData("all off");
    }
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
}
