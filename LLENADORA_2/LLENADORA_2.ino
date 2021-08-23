int CNT1=0;
int S1= 0;
#define S2 2
#define S3 3
int AX1 =4;
int AX2 =5;
int AX3 =6;
int AX4 =7;
int AX5 =8;

void setup() {
  // put your setup code here, to run once:
  pinMode(S1,INPUT);
  pinMode(S2,INPUT_PULLUP);
  pinMode(S3,INPUT_PULLUP);
  pinMode(AX1,OUTPUT);
  pinMode(AX2,OUTPUT);
  pinMode(AX3,OUTPUT);
  pinMode(AX4,OUTPUT);
  pinMode(AX5,OUTPUT);
  Serial.begin(9600);
  Serial.println("Tiempo = ");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Loop_S1(1000);
  //LED2(4,200);
  //LED(7,150);
  //LED(6,100);
  MOD1(AX1,7500);
  MOD2(AX3,4500);
}

void MOD1(int SX1,long T) {
  static long hora_inicio = 0;
  int CONT;
  long hora = millis();
 if (digitalRead(S2) == LOW) {
   while (digitalRead(S2) == LOW) {
    Serial.println("Esperando Señal...");
   };
    CNT1++;   CONT++;
    Serial.print(CNT1);
    Serial.println(digitalRead(CONT));
    //Serial.println(digitalRead(S1));
 }
  if (CNT1==1) {
    digitalWrite(SX1,HIGH);
  }
  if (CNT1==4) {
    //digitalWrite(SX1,HIGH);
    hora_inicio = millis();
    Serial.print("Esperando Tiempo...:");
    Serial.println(hora_inicio);
    do {
      digitalWrite(AX2,HIGH);
      hora=millis();
      Serial.println(hora-hora_inicio);
    } while (hora-hora_inicio < T);
    Serial.print("Ciclo finalizado...:");
    Serial.println(hora-hora_inicio);
    digitalWrite(AX2,LOW);
    digitalWrite(SX1,LOW);
    //---
    CNT1=0;
  }
}
void MOD2(int SX1,long T) {
  static long hora_inicio = 0;
  int CONT;
  long hora = millis();
 if (digitalRead(S3) == LOW) {
    CONT++;
 }
  if (CONT==1) {
    digitalWrite(SX1,HIGH);
    digitalWrite(AX4,HIGH);
    hora_inicio = millis();
    do {
      hora=millis();
    } while (hora-hora_inicio>T);
    digitalWrite(SX1,LOW);
    digitalWrite(AX4,LOW);
    //---
    CONT=0;
  }
}

void Loop_S1(long T) {
  static long ultimo_cambio = 0;
  static int Estado_LED = LOW;

  long hora = millis();
  
  if (hora - ultimo_cambio > T) {
    ultimo_cambio =hora;
    Serial.println(hora);
    if (Estado_LED == LOW) {
      digitalWrite(AX1,LOW);
      Estado_LED = HIGH;
    } else {
      digitalWrite(AX1,HIGH);
      Estado_LED = LOW;
    }  
  }
  
}

void LED(int Foco,long T) {
  static long ultimo_cambio = 0;
  static int Estado_LED = LOW;
  long hora = millis();
  
  if (hora - ultimo_cambio > T) {
    ultimo_cambio =hora;
    Estado_LED = !Estado_LED;
      digitalWrite(Foco,Estado_LED);
  }
}
void LED2(int Foco,long T) {
  static long ultimo_cambio = 0;
  static int Estado_LED = LOW;
  long hora = millis();
  
  if (hora - ultimo_cambio > T) {
    ultimo_cambio =hora;
    Estado_LED = !Estado_LED;
      digitalWrite(Foco,Estado_LED);
  }
}
