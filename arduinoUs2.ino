const unsigned int TRIG_PIN1=13;
const unsigned int ECHO_PIN1=12;
const unsigned int TRIG_PIN2=11;
const unsigned int ECHO_PIN2=10;
const unsigned int TRIG_PIN3=9;
const unsigned int ECHO_PIN3=8;

const unsigned int BAUD_RATE=9600;

void setup() {
  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
  pinMode(TRIG_PIN3, OUTPUT);
  pinMode(ECHO_PIN3, INPUT);
  Serial.begin(BAUD_RATE);
}

void loop() {
  digitalWrite(TRIG_PIN1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, LOW);
  
  const unsigned long duration1= pulseIn(ECHO_PIN1, HIGH);
  int distance1= duration1/29/2;
  
  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);
  
  const unsigned long duration2= pulseIn(ECHO_PIN2, HIGH);
  int distance2= duration2/29/2;

  digitalWrite(TRIG_PIN3, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN3, LOW);
  
  const unsigned long duration3= pulseIn(ECHO_PIN3, HIGH);
  int distance3= duration3/29/2;

  Serial.println( String(distance1) + " " + String(distance2) + " " +  String(distance3) );
 delay(300);
  
 }
 
  
 
 


