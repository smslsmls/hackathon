#define X A0
#define Y A1
#define X1 A2
#define Y1 A3
#define M_PIN 2
#define M_PIN1 8
#define J 9
#define SW1 3
#define SW2 4
#define SW3 5
#define SW4 6
#define RX 14
#define TX 16
#define ATACK 15

#include <Keyboard.h>
#include <Mouse.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(RX, TX);

void setup()
{
  Serial.begin(9600);
  BT.begin(9600);
  Keyboard.begin();
  pinMode(J, INPUT_PULLUP);
  pinMode(ATACK, INPUT_PULLUP);
}

void loop()
{
  unsigned long curr_millis = millis();
  unsigned long prev_millis = 0;
  if (curr_millis - prev_millis > 2)
  {
    prev_millis = curr_millis;
    JoyStick();
    JoyStick1();
    button();
  }
}

void JoyStick()
{
  int Y_read = analogRead(Y);
  int X_read = analogRead(X);
  int jump_read = digitalRead(J);
  if (digitalRead(M_PIN1))
  {
    if (Y_read < 200) //UP
    {
      //Serial.println("UP");
      //Keyboard.press(KEY_UP_ARROW);
      Mouse.move(0, -5, 0);
    }
    else
    {
      //Keyboard.release(KEY_UP_ARROW);
    }
    if (Y_read > 700) //DOWN
    {
      //Serial.println("DOWN");
      //Keyboard.press(KEY_DOWN_ARROW);   
      Mouse.move(0, 5, 0);
    }
    else
    {
      //Keyboard.release(KEY_DOWN_ARROW);
    }
    if (X_read < 200) //LEFT
    {
      //Keyboard.press(KEY_LEFT_ARROW);
      Mouse.move(-6, 0, 0);
    }
    else
    {
      //Keyboard.release(KEY_LEFT_ARROW);
    }
    if (X_read > 700) //RIGHT
    {
      //Keyboard.press(KEY_RIGHT_ARROW);
      Mouse.move(6, 0, 0);
    }
    else
    {
      //Keyboard.release(KEY_RIGHT_ARROW);
    }
    if (!jump_read)
    {
      Keyboard.press(' ');
    }
    else
    {
      Keyboard.release(' ');
    }
  }
}

void JoyStick1()
{
  int Y_read = analogRead(Y1);
  int X_read = analogRead(X1);
  //Serial.print(X_read);Serial.println(Y_read);

  if (digitalRead(M_PIN))
  {
    if (Y_read < 200) //UP
    {
      //Serial.println("UP");
      Keyboard.press('w');
    }
    else
    {
      Keyboard.release('w');
    }
    if (Y_read > 700) //DOWN
    {
      //Serial.println("DOWN");
      Keyboard.press('s');
    }
    else
    {
      Keyboard.release('s');
    }
    if (X_read < 200) //LEFT
    {
      Keyboard.press('a');
    }
    else
    {
      Keyboard.release('a');
    }
    if (X_read > 700) //RIGHT
    {
      Keyboard.press('d');
    }
    else
    {
      Keyboard.release('d');
    }
  }
}

void button()
{
  int bt1 = digitalRead(SW1);
  int bt2 = digitalRead(SW2);
  int bt3 = digitalRead(SW3);
  int bt4 = digitalRead(SW4);
  int atk_read = digitalRead(ATACK);
  if (bt1)
  {
    Keyboard.press('z');
  }
  else
  {
    Keyboard.release('z');
  }
  if (bt2)
  {
    Keyboard.press('x');
  }
  else
  {
    Keyboard.release('x');
  }
  if (bt3)
  {
    Keyboard.press('c');
  }
  else
  {
    Keyboard.release('c');
  }
  if (bt4)
  {
    Keyboard.press('v');
  }
  else
  {
    Keyboard.release('v');
  }
  if(!atk_read)
  {
    Mouse.press();
  }
  else
  {
    Mouse.release();
  }
}
