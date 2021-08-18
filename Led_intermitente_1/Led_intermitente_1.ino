int Led1 = 13;
int x;
int v= 100;
void setup() {
  // put your setup code here, to run once:
  //pinMode(Led1, OUTPUT);
  for (int x1=2; x1<8;x1++) {
    pinMode(x1,OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  
  for (int x1 = 2; x1 < 8; x1++) {
    digitalWrite(x1,HIGH);
    delay(v);
    digitalWrite(x1,LOW);
    //delay(v);
  };
  for (int x1 = 8; x1 >= 2; x1--) {
    digitalWrite(x1,HIGH);
    delay(v);
    digitalWrite(x1,LOW);
    //delay(v);
  }
}
