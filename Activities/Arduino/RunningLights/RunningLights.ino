
const int ledPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
const int numLeds = 8;
const int delayTime = 200;
const int dimmingDelayTime = 10;
const int alternateDelayTime = 500;
void setup() {
  // initialize pins 
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
	rightToLeft();
  midtoEdging();
  digitalWrite(6, HIGH); // All HIGH outputs will turn of the LEDs due to the configuration of the circuit
 	digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
 	digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  delay(200);
  dimLights();
  alternateLights();
}

void rightToLeft(){
	for (int i = -1; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);  
    delay(delayTime);                
    digitalWrite(ledPins[i], LOW);   
  }
}

void midtoEdging(){
  	int mid1 = numLeds / 2 - 1;
  	int mid2 = mid1 + 1;
	for (int i = 0; i <= mid1; i++) {
    digitalWrite(ledPins[mid1 - i], HIGH);  
    digitalWrite(ledPins[mid2 + i], HIGH);
    delay(delayTime);                       
    digitalWrite(ledPins[mid1 - i], LOW);   
    digitalWrite(ledPins[mid2 + i], LOW);   
    }
}

void dimLights(){
  const int dimmedPins[] = {6, 9, 10, 11};
  const int numDimmedLeds = sizeof(dimmedPins) / sizeof(dimmedPins[0]);

  
  for (int brightness = 0; brightness <= 255; brightness++) {
    for (int i = 0; i < numDimmedLeds; i++) {
      analogWrite(dimmedPins[i], brightness);
    }
    delay(dimmingDelayTime);
  }

  for (int brightness = 255; brightness >= 0; brightness--) {
    for (int i = 0; i < numDimmedLeds; i++) {
      analogWrite(dimmedPins[i], brightness);
    }
    delay(dimmingDelayTime);
  }
}

void alternateLights() {

  for (int i = 0; i < numLeds; i += 2) {
    digitalWrite(ledPins[i], HIGH);
  }
  delay(alternateDelayTime);

  for (int i = 0; i < numLeds; i += 2) {
    digitalWrite(ledPins[i], LOW);
  }

  for (int i = 1; i < numLeds; i += 2) {
    digitalWrite(ledPins[i], HIGH);
  }
  delay(alternateDelayTime);

  for (int i = 1; i < numLeds; i += 2) {
    digitalWrite(ledPins[i], LOW);
  }
}
