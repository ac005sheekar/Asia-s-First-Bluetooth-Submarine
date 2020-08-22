//The entire code is created by SHEEKAR BANERJEE
//Dept. of CSE, IUBAT UNIVERSITY

#include<SoftwareSerial.h> //This Calls the header of the repository containing the library files of the Bluetooth Communication System
#include<Servo.h>          ////This calls the Header of the repository containing the library files of Servo Motor Driver Modules

Servo sm1, sm2, sm3; //Servo is a Class which is providing an independent data type // sm1, sm2 and sm3 are the variables which are representing the servo motors on left wing, right wing and the tail of the Bluetooth Submarine



int bluetoothTx=10; //This is initializing the TX pin of HC-05 Bluetooth Module to the pin no 10 of Arduino Microcontroller
int bluetoothRx=11; //This is initializing the RX pin of HC-05 Bluetooth Module to the pin no 11 of Arduino Microcontroller

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx); //Declaration of 'bluetooth' function with the parameters named bluetoothTx and bluetoothRx. The function type is derived of the header named SoftwareSerial
void setup() {
  sm1.attach(3);  //The Coding Yellow Wire of the Left Wing Servo motor(sm1) is attached to the pin no. 3 of Arduino Microcontroller
  sm2.attach(5);  //The Coding Yellow Wire of the Right Wing Servo motor(sm2) is attached to the pin no. 5 of Arduino Microcontroller
  sm3.attach(7);  //The Coding Yellow Wire of the Tail Servo motor(sm3) is attached to the pin no. 7 of Arduino Microcontroller
  Serial.begin(9600);     //This opens serial port, sets data rate to 9600 bps
  
  
  bluetooth.begin(9600);   //This opens SoftwareSerial port which enables Bluetooth Communication and sets data rate to 9600 bps
}

void loop() {
  if(bluetooth.available()>=2)  
  {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1*256)+servopos;
    
    
   

   
    if(realservo>=1000 && realservo<1180)
    {
      int servo1=realservo;
      servo1 = map(servo1,1000,1180,0,180);

      sm1.write(servo1);
      Serial.println("Servo1 ON");
      delay(10);
    }
    if(realservo>=2000 && realservo<2180)
    {
      int servo2=realservo;
      servo2 = map(servo2,2000,2180,0,180);

      sm3.write(servo2);
      Serial.println("Servo2 ON");
      delay(10);
    }

    if(realservo>=3000 && realservo<3180)
    {
      int servo3=realservo;
      servo3 = map(servo3,3000,3180,0,180);

      sm3.write(servo3);
      Serial.println("Servo3 ON");
      delay(10);
    }
    
    
    
  }

}
