 /*This Arduino sketch will read the values of two potentiometers and a 
   toggle switch, which will be used to two inputs of a video mixer*/
   
   //Only slightly modified from Daniel Jolliffe's example from the URL below:
   //http://playground.arduino.cc/Interfacing/MaxMSP

int x = 0;                              // a place to hold pin values
int ledpin = 13;

void setup()
{
  Serial.begin(115200);               // 115200 is the default Arduino Bluetooth speed
  digitalWrite(13,HIGH);              ///startup blink
  delay(600);
  digitalWrite(13,LOW);
  pinMode(13,INPUT);
}


void loop() { 

if (Serial.available() > 0){         // Check serial buffer for characters
        
    if (Serial.read() == 'r') {       // If an 'r' is received then read the pins
 
    
for (int pin= 0; pin <= 1; pin++) {      // Read and send analog pin 0 and 1 (Pin 0 will serve as a value to 
    x = analogRead(pin);                 //  mix between two video sources)
    sendValue (x);
    }

    Serial.println();                 // Send a carriage returnt to mark end of pin data. 
    delay (5);                        // add a delay to prevent crashing/overloading of the serial port
  
  }
 }
}

void sendValue (int x) {              // function to send the pin value followed by a "space". 
 Serial.print(x);
 Serial.write(32); 
}



