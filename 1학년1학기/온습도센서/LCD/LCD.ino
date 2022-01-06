#include <LiquidCrystal_I2C.h>     //LiquidCrystal 라이브러리 추가 
LiquidCrystal_I2C lcd(0x27, 16, 2);  //lcd 객체 선언

void setup()
{
  lcd.begin(); //LCD 사용 시작
}

void loop()
{
  lcd.setCursor(5, 0);    // 커서를 5, 0에 가져다 놓아라. (열, 행)
  lcd.print("Hi ^^");     // 5, 0에 Hi ^^를 출력해라.
  delay(1000);            // 1초 대기
  lcd.setCursor(3, 1);    // 커서를 3, 1로 가져다 놓아라. (열, 행)
  lcd.print("Codingrun"); // Codingrun을 입력해라.
  delay(1000);            // 1초 대기 
  lcd.clear();            // 글자를 모두 지워라.
  delay(1000);            // 1초 대기
}
