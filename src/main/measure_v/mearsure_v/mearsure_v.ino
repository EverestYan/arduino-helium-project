// helium_ultrasonic.ino
#define TRIG_PIN 11
#define ECHO_PIN 10
#define FIXED_DISTANCE_CM 50.0  // 固定距离需手动校准

void setup() { 
  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
	Serial.begin(9600);  
  Serial.println("Ultrasonic Test Begin");
}

float measureTime() {
  // 触发超声波并返回时间（微秒）
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  return pulseIn(ECHO_PIN, HIGH);
}

void loop() {
  // 多次采样取平均
  float avg_duration = 0;
  for(int i=0; i<10; i++) {
    avg_duration += measureTime();
    delay(50);
  }
  avg_duration /= 10.0;

  // 计算声速 v = 2x / t （单位：m/s）
  float speed = 2 * FIXED_DISTANCE_CM / (avg_duration * 1e-6) / 100.0;

  Serial.println(speed);
}