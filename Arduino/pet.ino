/*
 *   日期：2017-03-30
 *   功能：逗宠萌物程序
 */

#define IN1 4 // 4 5 右轮
#define IN2 5 
#define IN3 6 // 6 7 左轮
#define IN4 7 

#define LEFT '3' //左转编码
#define RIGHT '4'//右转编码
#define GO '1'//前进编码
#define BACK '2'//后退编码
#define STOP '0'//停止编码

void setup() {
  Serial.begin(9600);//设置蓝牙波特率
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  initCar();
}

void loop() {
  if(Serial.available()>0){
      char ch = Serial.read();
      if(ch == GO){
         //前进
         go();
         //Serial.print("GO\n");
      }else if(ch == BACK){
         //后退
         back();
         //Serial.print("BACK\n");
      }else if(ch == LEFT){
         //左转
         turnLeft();
         //Serial.print("turnLeft\n");
      }else if(ch == RIGHT){
        //右转
        turnRight();
        //Serial.print("turnRight\n");
      }else if(ch=='0'){
        //停车
        stopCar();
        //Serial.print("stop\n");
      }
    }
}

void initCar(){
  //默认全是低电平,停止状态
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

/**
* 左转
*/
void turnLeft(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);         //右轮前进
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);        //左轮后退
}

/**
* 右转
*/
void turnRight(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);        //右轮后退
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);         //左轮前进
}

/**
* 前进
*/
void go(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);         //右轮前进
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);         //左轮前进
}

/**
* 倒车
*/
void back(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);        //右轮后退
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);        //左轮后退
}

/**
* 停车
*/
void stopCar(){
  initCar();
}