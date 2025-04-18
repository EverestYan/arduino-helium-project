const int trigPin = 11;  
const int echoPin = 10; 

float duration, distance;  

void setup() {  
	pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
	Serial.begin(9600);  
  Serial.println("Ultrasonic Test Begin");
}  

void loop() {  
	digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);  
  
  duration = pulseIn(echoPin, HIGH, 30000);  
  distance = (duration*.0343)/2; 
  
  Serial.print("Raw duration: ");
  Serial.println(duration); 
	Serial.print("Distance: ");  
	Serial.println(distance);  
	delay(100);  
}  
