#include <DHT11.h>
#include <LiquidCrystal_I2C.h>     //LiquidCrystal 라이브러리 추가 
LiquidCrystal_I2C lcd(0x27, 16, 2);  //lcd 객체 선언
int pin=3;    // 연결한 아두이노 디지털 핀 번호

DHT11 dht11(pin);

void setup()

{
   lcd.begin(); //LCD 사용 시작
   Serial.begin(9600);

}

void loop()

{

  int err;

  float temp, humi;

  if((err=dht11.read(humi, temp))==0)

  {

      lcd.setCursor(0, 0);
      lcd.print("temperature:");
      lcd.print(temp);
      lcd.setCursor(0, 1);
      lcd.print("humidity:");
      lcd.print(humi);
  }

  else

  {

    Serial.println();

    Serial.print("Error No :");

    Serial.print(err);

    Serial.println();    

  }

  delay(5000); //delay for reread

}
