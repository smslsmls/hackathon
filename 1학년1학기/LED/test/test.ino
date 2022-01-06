int soundSensor = A0;     // 사운드 센서 핀
int led = 8;  // LED핀 8~13
int threshold = 60; // 소리 크기 기준
int count = 0;      // 박수를 몇 번 쳤는지 카운트
int analog;

void setup() {
  Serial.begin(9600); // 시리얼모니터 출력
  pinMode(soundSensor, INPUT);  // 사운드 센서 입력으로 설정     // LED 핀 출력으로 설정
  pinMode(led, OUTPUT);
}

void loop() {
  analog=analogRead(soundSensor);
  if( analog >= threshold){    // 감지된 소리의 크기가 500 이상일 때
    Serial.println(analog);
      if(count==1)        // 카운트 된 박수 개수로 led 제어 
        digitalWrite(led, HIGH);
      else 
        digitalWrite(led, LOW);
    count = (count < 1) ? count+1 : 0;  // count<6가 참일 때 count + 1, 거짓일때 0 반환
    delay(200);     // 박수 중복 입력이 안되게 200ms 딜레이
  } 
  else       // 감지된 소리의 크기가 500 이하일 때 
    delay(1);
}
