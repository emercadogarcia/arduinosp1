int ledRosa = 13;
int potPin = A0;
int potValue = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(ledRosa,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Requiere potenciometro para poder hacer la prueba
  potValue = analogRead(potPin);
  Serial.println(potValue);
  digitalWrite(ledRosa,HIGH);
  delay(potValue);
  digitalWrite(ledRosa,LOW);
  delay(potValue);

}
