int ball = 2;         //dectection pin for ball
int coin = 3;         //dectection pin for coin
int key = 4;          //dectection pin for key
int ballLed = 8;      //led pin for ball
int coinLed = 9;      //led pin for coin
int keyLed = 10;      //led pin for key
int b = LOW;          //state of ball
int c = LOW;          //state of coin
int k = LOW;          //state of key
int lock = 11;        //control pin for lock
int lockLed = 12;     //indicator for lock open


void setup() {
  pinMode(ball,INPUT);
  pinMode(coin,INPUT);
  pinMode(key,INPUT);
  pinMode(ballLed,OUTPUT);
  pinMode(coinLed,OUTPUT);
  pinMode(keyLed,OUTPUT);
  pinMode(lock,OUTPUT);  
  Serial.begin(9600);
}

void loop() {
  b,c,k = LOW;
  b = digitalRead(ball);  //read state of ball
  delay(50);
  c = digitalRead(coin);  //read state of coin
  delay(50);
  k = digitalRead(key);   //read state of key
  delay(50);
  Serial.print("ball = ");
  Serial.println(b);
  Serial.print("coin = ");
  Serial.println(c);
  Serial.print("key = ");
  Serial.println(k);
  digitalWrite(ballLed,b);
  digitalWrite(coinLed,c);
  digitalWrite(keyLed,k);
  if(b == HIGH && c == HIGH && k == HIGH){
    open_lock();
  }
  delay(500);
}

void open_lock(){
  Serial.println("Lock Open");
  digitalWrite(lock,HIGH);
  digitalWrite(lockLed,HIGH);
  delay(10000);
  digitalWrite(lock,LOW);
  digitalWrite(lockLed,LOW);
}
