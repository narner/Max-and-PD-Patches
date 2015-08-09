
const int  switchPin = 2;    // digital in 2 (pin the switch is attached to)

int switchState = 0;         // current state of the switch
int lastSwitchState = 0;     // previous state of the switch


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
    
  // initialize the button pin as a input:
  pinMode(switchPin, INPUT);
}
  
  
void loop() {
    
  // read the switch input pin:
  switchState = digitalRead(switchPin);

  // compare the switchState to its previous state
  if (switchState != lastSwitchState) {
  // if the state has changed, increment the counter
    if (switchState == HIGH) {
    // if the current state is HIGH then the button
    // wend from off to on:
    Serial.println("Switch one is on");
  }
  else {
    // if the current state is LOW then the button
    // wend from on to off:
    Serial.println("Switch one is off");
  }
  // Delay a little bit to avoid bouncing
  delay(50);  
}
// save the current state as the last state,
//for next time through the loop
lastSwitchState = switchPin;

}
