/* 
스텝모터와 버튼을 활용한 비행기 상승 하강 예제

좌측 버튼 : 상승
우측 버튼 : 하강
 */


#include <Stepper.h> // 스텝모터 라이브러리

// 변수 정의
int up;
int down;

const int stepsPerRevolution = 64; // 회전 각도 180도 
Stepper myStepper(stepsPerRevolution,11,9,10,8); // 스텝모터 핀세팅
 
void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  myStepper.setSpeed(300); // 스텝모터 회전속도 30

  Serial.begin(115200);
}

void loop() {
  if (Serial.available()) {
    char in = Serial.parseInt();
    // 좌측 버튼 누를시 시계방향 회전
    if(in == 1) {
  for(int i=0; i<32; i++) {  // 64 * 32 = 2048 한바퀴
    myStepper.step(stepsPerRevolution);
  }
    }
    if(in == 2) {
  for(int i=0; i<32; i++) {  // 64 * 32 = 2048 한바퀴
    myStepper.step(-stepsPerRevolution);
    }
  }
}
}
