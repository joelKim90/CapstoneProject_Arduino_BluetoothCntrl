#include <SoftwareSerial.h>   //Software Serial Port
#include <Stepper.h>
#include "DualVNH5019MotorShield.h" //custom library for the motor shield

DualVNH5019MotorShield md;

#define RxD 7
#define TxD 6

#define DEBUG_ENABLED  1



SoftwareSerial blueToothSerial(RxD,TxD);

//assigning the pins
int stepIN1Pin = 16;
int stepIN2Pin = 17;
int stepIN3Pin = 11;
int stepIN4Pin = 13;

//long startTime;
//long elapsedTime;

int stepsPerRevolution = 2048;

Stepper myStepper(stepsPerRevolution,
                  stepIN1Pin, stepIN3Pin,
                  stepIN2Pin, stepIN4Pin);


void setup()
{
    Serial.begin(9600);
    pinMode(RxD, INPUT);
    pinMode(TxD, OUTPUT);
    setupBlueToothConnection();
    md.init();

        // set the RPM
    myStepper.setSpeed(15);

}

void loop()
{

    char recvChar;

    
    
        if(blueToothSerial.available())
        {//check if there's any data sent from the remote bluetooth shield
            //startTime = millis();
            recvChar = blueToothSerial.read();
            Serial.print(recvChar);
            
            if(recvChar == '1') // this is low speed
            {
                
                blueToothSerial.print("Shoot!");
                
                // step one revolution in one direction
                //elapsedTime = millis() - startTime;
                //blueToothSerial.print(elapsedTime);

                blueToothSerial.print("speed: ");
                md.setM1Speed(200);
                md.setM2Speed(200);
                stopIfFault();
                blueToothSerial.println(md.getM1CurrentMilliamps());
                blueToothSerial.println(md.getM2CurrentMilliamps());
                Serial.println(md.getM1CurrentMilliamps());
                Serial.println(md.getM2CurrentMilliamps());

                delay(2000);
                myStepper.step(stepsPerRevolution);
                // wait a second
                delay(1000);

                // step one revolution in the other direction
                myStepper.step(-stepsPerRevolution);
                // wait a second
                delay(1000);
                //blueToothSerial.println(getTemp());
                //delay(2000);
            }
        
            
            if(recvChar == '2') //medium speed
            {
                blueToothSerial.print("Shoot!");

                blueToothSerial.print("speed: ");
                md.setM1Speed(400);
                md.setM2Speed(400);
                stopIfFault();
                blueToothSerial.println(md.getM1CurrentMilliamps());
                blueToothSerial.println(md.getM2CurrentMilliamps());
                Serial.println(md.getM1CurrentMilliamps());
                Serial.println(md.getM2CurrentMilliamps());

                delay(2000);
                myStepper.step(stepsPerRevolution);
                // wait a second
                delay(1000);

                // step one revolution in the other direction
                myStepper.step(-stepsPerRevolution);
                // wait a second
                delay(1000);
            }

            if(recvChar == '3') //high speed
            {
                blueToothSerial.print("Shoot!");

                blueToothSerial.print("speed: ");
                md.setM1Speed(1000);
                md.setM2Speed(1000);
                stopIfFault();
                blueToothSerial.println(md.getM1CurrentMilliamps());
                blueToothSerial.println(md.getM2CurrentMilliamps());
                Serial.println(md.getM1CurrentMilliamps());
                Serial.println(md.getM2CurrentMilliamps());

                delay(2000);
                myStepper.step(stepsPerRevolution);
                // wait a second
                delay(1000);

                // step one revolution in the other direction
                myStepper.step(-stepsPerRevolution);
                // wait a second
                delay(1000);  
            }


}


void setupBlueToothConnection()
{          
	blueToothSerial.begin(9600);  
	
	blueToothSerial.print("AT");
	delay(400); 

	blueToothSerial.print("AT+DEFAULT");             // Restore all setup value to factory setup
	delay(2000); 
	
	blueToothSerial.print("AT+NAMESeeedBTSlave");    // set the bluetooth name as "SeeedBTSlave" ,the length of bluetooth name must less than 12 characters.
	delay(400);
	
    blueToothSerial.print("AT+PIN0000");             // set the pair code to connect 
	delay(400);
	
	blueToothSerial.print("AT+AUTH1");             //
    delay(400);    

    blueToothSerial.flush();
}
