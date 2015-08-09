const int  switchOnePin = 2;    // digital in 2 (pin the switch one is attached to)
const int  switchTwoPin = 3;    // digital in 3 (pin the switch two is attached to)
const int  switchThreePin = 4;  // digital in 4 (pin the switch three is attached to)

const int  ledOne = 5;     
const int  ledTwo = 6;     
const int  ledThree = 7;     


int switchOneState = 0;         // current state of the switch
int lastSwitchOneState = 0;     // previous state of the switch

int switchTwoState = 0;
int lastSwitchTwoState = 0;

int switchThreeState = 0;
int lastSwitchThreeState = 0;


void setup() {
    //initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
            
    int switchOneState = 0;         // current state of the switch
    int lastSwitchOneState = 0;     // previous state of the switch switch pins as an input
    pinMode(switchOnePin, INPUT);
    pinMode(switchTwoPin, INPUT);
    pinMode(switchThreePin, INPUT);
    
    pinMode(ledOne, OUTPUT);
    pinMode(ledTwo, OUTPUT);     
    pinMode(ledThree, OUTPUT);         
}

void loop() {
    // read the switch input pins:
    switchOneState   = digitalRead(switchOnePin);
    switchTwoState   = digitalRead(switchTwoPin);
    switchThreeState = digitalRead(switchThreePin);
                    
    // compare the switchState to its previous state
    if (switchOneState != lastSwitchOneState) {
        // if the state has changed, increment the counter
        if (switchOneState == HIGH) {
        // if the current state is HIGH then the button
        // went from off to on:
            Serial.println("Switch one is on");
            digitalWrite(ledOne, HIGH);   
        } else {
            // if the current state is LOW then the button
            // went from on to off:
            Serial.println("Switch one is off");
            digitalWrite(ledOne, LOW);   
        }
    }
        
    if (switchTwoState != lastSwitchTwoState) {
        if (switchTwoState == HIGH) {
            Serial.println("Switch two is on");
            digitalWrite(ledTwo, HIGH);
        } else {
            Serial.println("Switch two is off");
            digitalWrite(ledTwo, LOW);   
        }
    }
                                                                                                    
    if (switchThreeState != lastSwitchThreeState) {
        if (switchThreeState == HIGH) {
            Serial.println("Switch three is on");
            digitalWrite(ledThree, HIGH);   
        } else {
            Serial.println("Switch thre is off");
            digitalWrite(ledThree, LOW);   
        }
    }

    // Delay a little bit to avoid bouncing
    delay(50);

    // save the current state as the last state,
    //for next time through the loop
    lastSwitchOneState   = switchOneState;
    lastSwitchTwoState   = switchTwoState;
    lastSwitchThreeState = switchThreeState;
}
