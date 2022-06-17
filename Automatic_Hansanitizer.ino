int trigPin1 = 11; //Trig Sensor Kiri
int echoPin1 = 13; //Echo Sensor Kiri

int trigPin2 = 10; //Trig Sensor Kanan
int echoPin2 = 8; //Echo Sensor Kanan

int ledPin1 = 4; //LED Kiri
int ledPin2 = 7; //LED Kanan


long duration1, distance1;
long duration2, distance2;

void setup() {
 //Serial Port begin
 Serial.begin (9600);
 //Define inputs and outputs
 pinMode(trigPin1, OUTPUT);
 pinMode(echoPin1, INPUT);
 
 pinMode(trigPin2, OUTPUT);
 pinMode(echoPin2, INPUT);
 
 pinMode(ledPin1, OUTPUT);
 pinMode(ledPin2, OUTPUT); 
}

void loop()
{ 
 // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
 // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
 digitalWrite(trigPin1, LOW);
 delayMicroseconds(5);
 digitalWrite(trigPin1, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin1, LOW);
 pinMode(echoPin1, INPUT);
 
 duration1 = pulseIn(echoPin1, HIGH);
 distance1 = 0.017*duration1;
 
 digitalWrite(trigPin2, LOW);
 delayMicroseconds(5);
 digitalWrite(trigPin2, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin2, LOW);
 pinMode(echoPin2, INPUT);
 
 duration2 = pulseIn(echoPin2, HIGH);
 distance2 = 0.017*duration2;

 if (distance1 <= 30) {
  digitalWrite(ledPin1, HIGH);
 } else {
  digitalWrite(ledPin1, LOW);
 }

 if (distance2 <= 30) {
  digitalWrite(ledPin2, HIGH);
 } else {
  digitalWrite(ledPin2, LOW);
 }
 
 Serial.print("Tangan kiri: ");
 Serial.print(distance1);
 Serial.print("cm; ");
 Serial.print("Tangan kanan: ");
 Serial.print(distance2);
 Serial.println("cm");
 delay(250);
}
