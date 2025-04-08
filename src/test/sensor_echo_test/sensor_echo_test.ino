const int trigPin = 11;  
const int echoPin = 10; 

void setup() {  
	pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
  Serial.begin(9600);
}

void loop() {
  // 发送10μs触发信号
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 测量回波时间（带30000μs超时）
  long duration = pulseIn(echoPin, HIGH, 30000);
  
  if(duration == 0) {
    Serial.println("Error: No echo detected!");
  } else {
    Serial.print("Duration: ");
    Serial.print(duration);
    Serial.println(" us");
  }
  delay(500);
}