/* 
스텝모터와 버튼을 활용한 비행기 상승 하강 예제

좌측 버튼 : 상승
우측 버튼 : 하강
 */

#include <Stepper.h> // 스텝모터 라이브러리

// 변수 정의
int up;
int down;

const int stepsPerRevolution = 1024; // 회전 각도 180도 
Stepper myStepper(stepsPerRevolution,11,9,10,8); // 스텝모터 핀세팅
 
void setup() {
  pinMode(4,INPUT);
  pinMode(5,INPUT);

  myStepper.setSpeed(30); // 스텝모터 회전속도 30
}

void loop() {
  up = digitalRead(4);
  down = digitalRead(5);

  // 좌측 버튼 누를시 시계방향 회전
  if (up == HIGH) {
    for (int a=0; a <= 2; a++) {
      myStepper.step(stepsPerRevolution); 
    }
  }

  // 우측 버튼 누를시 반시계방향 회전
  else if (down == HIGH) {
    for (int b=0; b <= 2; b++) {
      myStepper.step(-stepsPerRevolution); 
    }
  }
}