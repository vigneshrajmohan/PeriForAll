#include "Arduino.h"

static unsigned long time;
static unsigned int state;

void setup() {
  Serial.begin(9800);
  pinMode(13, OUTPUT);
  
  time = seconds();
  state = 0;
  digitalWrite(13, LOW);
}

void loop() {
  Serial.println("state: " + String(state));
  switch (state)
  {
    case 1:
      n_blinks(1);
      break;
    case 2:
      n_blinks(2);
      break;
    case 3:
      n_blinks(3);
      break;
    default:
      break;
  }

//  
//  switch ((time % 60) / 10)
//  {
//    case 0:
//      state = 1;
//      break;
//    case 1:
//      state = 2;
//      break;
//    case 2:
//      state = 3;
//      break;
//    case 3:
//      state = 1;
//      break;
//    case 4:
//      state = 2;
//      break;
//    case 5:
//      state = 3;
//      break;
//    default:
//      state = 1;
//  }
//
//  time = seconds();

  if(Serial.available()){
      String command = Serial.readStringUntil('\n');
       
      if(command.equals("1")){
          state = 1;
      }
      else if(command.equals("2")){
          state = 2;
      }
      else if(command.equals("3")){
          state = 3;
      }
      else {
          state = 0;
      }
  }
  else {
    state = 0;
  }
}

void n_blinks(int n)
{
  for (int i = 0; i < n; i++) {
    digitalWrite(13, HIGH);
    delay(250);
    digitalWrite(13, LOW);
    if (i < n - 1) delay(100);
  }
}

unsigned long seconds()
{
  unsigned long result = ((millis() + 500) / 1000);
  Serial.println(result);
  return result;
}
