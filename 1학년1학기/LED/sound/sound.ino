int const SOUND = A0;     // 사운드 센서 핀
int const LED = 8;  // LED핀 8
int const THRES = 60; // 소리 크기 기준
int count = 0;      // 박수를 몇 번 쳤는지 카운트
int analog;

void setup() {
  Serial.begin(9600); // 시리얼모니터 출력
  pinMode(SOUND, INPUT);  // 사운드 센서 입력으로 설정     // LED 핀 출력으로 설정
  pinMode(LED, OUTPUT);
}

void loop() {
  analog=analogRead(SOUND);
  if( analog >= THRES){    // 감지된 소리의 크기가 THRES 이상일 때
    Serial.println(analog);
      if(count==1)        // 카운트 된 박수 개수로 LED 제어 
        digitalWrite(LED, HIGH);
      else 
        digitalWrite(LED, LOW);
    count = (count < 1) ? count+1 : 0;
    delay(200);     // 박수 중복 입력이 안되게 200ms 딜레이
  } 
  else       // 감지된 소리의 크기가 THRES 이하일 때 
    delay(1);
}
