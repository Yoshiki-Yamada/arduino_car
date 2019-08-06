double x = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(6,INPUT);
  
  pinMode(7,OUTPUT);

  //左タイヤ
  pinMode(2,OUTPUT);
  //右タイヤ
  pinMode(3,OUTPUT);

  //12,13は前進
  //左タイヤ
  pinMode(12,OUTPUT);
  //右タイヤ
  pinMode(13,OUTPUT);

  pinMode(A0,INPUT);
  pinMode(A0,OUTPUT);
  
  Serial.begin(9600);

  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);

}

void loop() {
  //超音波センサーによる障害物までの距離を測定（cm）
  digitalWrite(7,LOW);
  delayMicroseconds(2);
  digitalWrite(7,HIGH);
  delayMicroseconds(10);
  digitalWrite(7,LOW);
  x = pulseIn(6,HIGH);
  x = x*340*100/1000000/2;
  Serial.println(x);

  //もし、障害物tの距離が10cm以下になったら一旦止まって右に回る
  if(x <= 30 && x > 20){
  //一旦止まる動作
  digitalWrite(12,LOW);
  digitalWrite(2,LOW);
  digitalWrite(13,LOW);
  digitalWrite(3,LOW);
  delay(100);

  //バックする
  digitalWrite(12,LOW);
  digitalWrite(2,HIGH);
  delay(500);
  digitalWrite(13,LOW);
  digitalWrite(3,HIGH);
  delay(500);

  //止まる動作
  digitalWrite(2,LOW);
  digitalWrite(12,LOW);
  digitalWrite(3,LOW);
  digitalWrite(13,LOW);
  delay(100);

  //曲がる動作
  digitalWrite(2,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(13,LOW);
  delay(2000);

   //止まる動作
  digitalWrite(2,LOW);
  digitalWrite(12,LOW);
  digitalWrite(3,LOW);
  digitalWrite(13,LOW);
  delay(100);
  
  }else{
  //タイヤを回す（前進）
  digitalWrite(12,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(13,HIGH);
  digitalWrite(3,LOW);
  }

}
