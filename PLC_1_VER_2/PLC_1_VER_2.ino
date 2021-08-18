#include <pt.h>
#include <EEPROM.h>
#include <stdio.h>
#include <TM1637Display.h>

// Module 1 connection pins (Digital Pins)
#define CLK1 A11
#define DIO1 A12

// Module 2 connection pins (Digital Pins)
#define CLK2 A9
#define DIO2 A10

// Module 2 connection pins (Digital Pins)
#define CLK3 A7
#define DIO3 A8

// Module 2 connection pins (Digital Pins)
#define CLK4 A5
#define DIO4 A6

TM1637Display display1(CLK1, DIO1);// define dispaly 1 object
TM1637Display display2(CLK2, DIO2);// define dispaly 1 object
TM1637Display display3(CLK3, DIO3);// define dispaly 1 object
TM1637Display display4(CLK4, DIO4);// define dispaly 1 object

uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };  // all segments clear    


struct pt hilo1;

struct pt hilo2;
struct pt hilo3;
struct pt hilo4;
struct pt hilo5;
struct pt hilo6;
struct pt hilo7;

/////////////////// ENTRADAS
/////////////////// ENTRADAS

int SENSOR  = 2;

int INTERRUPCIONX = 3;


const int INC_1 = 4;
const int DEC_1 = 5;
const int IZQ_1 = 53;
const int DER_1 = 51;
const int xxxxx = 52;

int INC_2 = 8;
int DEC_2 = 9;
int IZQ_2 = 11;
int DER_2 = 10;

int INC_3 = 12;
int DEC_3 = 13;
int IZQ_3 = 15;
int DER_3 = 14;

int INC_4 = 47;
int DEC_4 = 46;
int IZQ_4 = 44;
int DER_4 = 45;

///////////////// ENTRADAS PULSADOR TABLERO

int B_STAR  = 42; 
int B_STOP  = 43; 


//32-33-34-35-36-37
int B_ON_OFF_AIRE  = 35;//35//41;//35
int B_BAJA_TAPADO  = 36;//36//40;//34
int B_STOP_TAPADO  = 37;//37//39;//33

int B_ALINEAMIENTO = 32;//32//38;//32
int B_BAJA_LLENADO = 33;//33
int B_STOP_LLENADO = 34;//34


int B_ELT_1 = 41;//35;//41
int B_ELT_2 = 40;//34;//40
int B_ELT_3 = 39;//33;//39
int B_ELT_4 = 38;//32;//38

int AUTO_MANUAL = 68 ;    
int B_MOTOR_ON_OFF  = 69;

int B_DESCARGA  = 67; 


///////////////// SALIDAS
const int LED_VERDE = 31;
const int LED_ROJO = 30;

const int LLENADO_STOP_1_24V = 26;//29; //26
const int LLENADO_BAJA_2_24V = 25;//28; //25
const int LLENADO_ALINE_3_24V = 24;//27; //24

const int TAPADO_STOP_4_220V = 29;//26; //29
const int TAPADO_BAJA_5_220V = 28;//25; //28
const int TAPADO_AIRE_6_220V = 27;//24; //27

const int MOTOR_CINTA = 23;
const int RELE_10 = 22;
const int RELE_11 = 21;
const int RELE_12 = 20;
const int ELT_4_220V = 16;//19;//16
const int ELT_3_220V = 17;//17
const int ELT_2_220V = 18;//18
const int ELT_1_220V = 19;//19




////////////////////////////////  VARIABLES



int UNIDAD_1  = 1;
int DECENA_1  = 1;
int CENTENA_1 = 1;
int MIL_1     = 1;

int UNIDAD_2  = 1;
int DECENA_2  = 1;
int CENTENA_2 = 1;
int MIL_2     = 1;

int UNIDAD_3  = 1;
int DECENA_3  = 1;
int CENTENA_3 = 1;
int MIL_3     = 1;

int UNIDAD_4  = 1;
int DECENA_4  = 1;
int CENTENA_4 = 1;
int MIL_4     = 1;


int CONTADOR_MIL      =0;
int CONTADOR_CENTENA  =0;
int CONTADOR_DECENA   =0;
int CONTADOR_UNIDAD   =0;

int CONTADOR_CONFIG = 0;


int TEMP_1=0;

int HORIZONTE_1 = 1;
int HORIZONTE_2 = 1;
int HORIZONTE_3 = 1;
int HORIZONTE_4 = 1;

/*
////////////////////////////////////
int CONTADOR_MIL      =0;
int CONTADOR_CENTENA  =0;
int CONTADOR_DECENA   =0;
int CONTADOR_UNIDAD   =0;
*/

///////////////////////////////////////VARIABLES PARA LAS INTERRUPCIONES
volatile int DISPLAY_1 = 0;
volatile int DISPLAY_2 = 0;
volatile int DISPLAY_3 = 0;
volatile int DISPLAY_4 = 0;
volatile int DISPLAY_X = 0;

volatile int TIEMPO_1 = 0;
volatile int TIEMPO_2 = 0;
volatile int TIEMPO_3 = 0;
volatile int TIEMPO_4 = 0;
volatile int TIEMPO_5 = 0;
volatile int TIEMPO_6 = 0;
volatile int TIEMPO_7 = 0;
volatile int TIEMPO_8 = 0;
volatile int TIEMPO_9 = 0;

volatile int TEMPORAL_TIEMPO_1 = 0;
volatile int TEMPORAL_TIEMPO_2 = 0;
volatile int TEMPORAL_TIEMPO_3 = 0;
volatile int TEMPORAL_TIEMPO_4 = 0;
volatile int TEMPORAL_TIEMPO_5 = 0;
volatile int TEMPORAL_TIEMPO_6 = 0;
volatile int TEMPORAL_TIEMPO_7 = 0;
volatile int TEMPORAL_TIEMPO_8 = 0;
volatile int TEMPORAL_TIEMPO_9 = 0;


volatile int JOJO = 1;


volatile int t = 0;
volatile int t1 = 0;
volatile int t2 = 0;
volatile int t3 = 0;
volatile int t4 = 0;
volatile int t5 = 0;
volatile int t6 = 0;
volatile int t7 = 0;

///////////////////////////////////////VARIABLES PARA LAS INTERRUPCIONES


int DISPLAY_1_GUARDADO = 0;
int DISPLAY_2_GUARDADO = 0;
int DISPLAY_3_GUARDADO = 0;
int DISPLAY_4_GUARDADO = 0;


volatile int jojo;
volatile int BANDERA_LIBRE_AUTOMATIC= 1;
volatile int RUN_MOTOR=0;


volatile int BANDERA_MANUAL_INCIO = 1 ;
volatile int BANDERA_AUTOMATIC_INCIO = 1 ;

volatile int M_1 = 0;
volatile int M_2 = 0;

volatile int  M_3 = 0;
volatile int M_4 = 0;
volatile int M_5 = 0;
volatile int M_6 = 0;
volatile int M_7 = 0;
volatile int M_8 = 0;

volatile int CONTADOR_DE_PIEZAS = 0;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void SEPARAR_DISPLAY_1_A_CASILLAS();
void SEPARAR_DISPLAY_2_A_CASILLAS();
void SEPARAR_DISPLAY_3_A_CASILLAS();
void SEPARAR_DISPLAY_4_A_CASILLAS();


//---------------------------------
void INC_MENU_1();     
void DEC_MENU_1();
void IZQ_MENU_1();
void DER_MENU_1();
//--------------------------------
void INC_MENU_2();     
void DEC_MENU_2();
void IZQ_MENU_2();
void DER_MENU_2();
//--------------------------------
void INC_MENU_3();     
void DEC_MENU_3();
void IZQ_MENU_3();
void DER_MENU_3();
//--------------------------------
void INC_MENU_4();     
void DEC_MENU_4();
void IZQ_MENU_4();
void DER_MENU_4();

void FUNCION_DE_PRIMERA_VEZ_MANUAL();
void FUNCION_DE_PRIMERA_VEZ_AUTOMATIC();


void INC_MENU_TIEMPOS_1();
void DEC_MENU_TIEMPOS_1(); 
void IZQ_MENU_TIEMPOS_1();
void DER_MENU_TIEMPOS_1();   
                                
void INC_MENU_REGISTROS_TIEMPOS_2();                               
void DEC_MENU_REGISTROS_TIEMPOS_2();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  
void setup(){

 
  display1.setBrightness(0x0f);// set brightness of dispaly 1
  display2.setBrightness(0x0f);// set brightness of dispaly 1  
  display3.setBrightness(0x0f);// set brightness of dispaly 1
  display4.setBrightness(0x0f);// set brightness of dispaly 1  

 
  display1.setSegments(data);// fill display 1 with whatever data[] array has
  display2.setSegments(data);// // fill display 2 with whatever data[] array has  
  display3.setSegments(data);// // fill display 2 with whatever data[] array has  
  display4.setSegments(data);// // fill display 2 with whatever data[] array has  

  
  pinMode(SENSOR, INPUT);

  pinMode(INTERRUPCIONX, INPUT);
   
  pinMode(INC_1, INPUT);
  pinMode(DEC_1, INPUT);
  pinMode(IZQ_1, INPUT);
  pinMode(DER_1, INPUT);
  pinMode(xxxxx, INPUT);


  pinMode(INC_2, INPUT);
  pinMode(DEC_2, INPUT);
  pinMode(IZQ_2, INPUT);
  pinMode(DER_2, INPUT);

  pinMode(INC_3, INPUT);
  pinMode(DEC_3, INPUT);
  pinMode(IZQ_3, INPUT);
  pinMode(DER_3, INPUT);

  pinMode(INC_4, INPUT);
  pinMode(DEC_4, INPUT);
  pinMode(IZQ_4, INPUT);
  pinMode(DER_4, INPUT);

//////////////////////////////////////

  pinMode(B_STAR, INPUT);
  pinMode(B_STOP, INPUT);



  pinMode(B_ON_OFF_AIRE, INPUT);
  pinMode(B_STOP_TAPADO, INPUT);
  pinMode(B_BAJA_TAPADO, INPUT);
  pinMode(B_STOP_LLENADO, INPUT);
  pinMode(B_ALINEAMIENTO, INPUT);
  pinMode(B_BAJA_LLENADO, INPUT);


  pinMode(B_ELT_1, INPUT);
  pinMode(B_ELT_2, INPUT);
  pinMode(B_ELT_3, INPUT);
  pinMode(B_ELT_4, INPUT);

  pinMode(AUTO_MANUAL, INPUT);
  pinMode(B_MOTOR_ON_OFF, INPUT);

  pinMode(B_DESCARGA, INPUT);
/*
  pinMode(LIBRE_1, INPUT);
  pinMode(LIBRE_2, INPUT);
  pinMode(LIBRE_3, INPUT);
*/
/////////////////////////////////
  

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LLENADO_STOP_1_24V, OUTPUT);
  pinMode(LLENADO_BAJA_2_24V, OUTPUT);
  pinMode(LLENADO_ALINE_3_24V, OUTPUT);
  pinMode(TAPADO_STOP_4_220V, OUTPUT);
  pinMode(TAPADO_BAJA_5_220V, OUTPUT);
  pinMode(TAPADO_AIRE_6_220V, OUTPUT);
  
  pinMode(MOTOR_CINTA, OUTPUT);
  pinMode(RELE_10, OUTPUT);
  pinMode(RELE_11, OUTPUT);
  pinMode(RELE_12, OUTPUT);
  pinMode(ELT_4_220V, OUTPUT);
  pinMode(ELT_3_220V, OUTPUT);
  pinMode(ELT_2_220V, OUTPUT);
  pinMode(ELT_1_220V, OUTPUT);

          
            digitalWrite(LED_VERDE,HIGH); // ON LED VERDE
            digitalWrite(LED_ROJO,HIGH); // OFF LED ROJO
            digitalWrite(LLENADO_STOP_1_24V,HIGH); // ON LED VERDE
            digitalWrite(LLENADO_BAJA_2_24V,HIGH); // OFF LED ROJO
            digitalWrite(LLENADO_ALINE_3_24V,HIGH); // ON LED VERDE
            digitalWrite(TAPADO_STOP_4_220V,HIGH); // OFF LED ROJO
            digitalWrite(TAPADO_BAJA_5_220V,HIGH); // ON LED VERDE
            digitalWrite(TAPADO_AIRE_6_220V,HIGH); // OFF LED ROJO
          
            digitalWrite(MOTOR_CINTA,HIGH); // ON LED VERDE
            digitalWrite(RELE_10,HIGH); // OFF LED ROJO
            digitalWrite(RELE_11,HIGH); // ON LED VERDE
            digitalWrite(RELE_12,HIGH); // OFF LED ROJO
            digitalWrite(ELT_4_220V,HIGH); // ON LED VERDE
            digitalWrite(ELT_3_220V,HIGH); // OFF LED ROJO
            digitalWrite(ELT_2_220V,HIGH); // ON LED VERDE
            digitalWrite(ELT_1_220V,HIGH); // OFF LED ROJO


display1.clear();
display2.clear();
display3.clear();
display4.clear();
  
  pinMode(INTERRUPCIONX, INPUT);
  digitalWrite(INTERRUPCIONX, HIGH); //turn pullup resistor on 

//  attachInterrupt(digitalPinToInterrupt(INTERRUPCIONX), INTERRUPCION, RISING );      
  

/*
  EEPROM.put(0,1111);
  EEPROM.put(5,1111);
  EEPROM.put(10,1111);
  EEPROM.put(15,1111);
*/

EEPROM.get(0,DISPLAY_1);
EEPROM.get(5,DISPLAY_2);
EEPROM.get(10,DISPLAY_3);
EEPROM.get(15,DISPLAY_4);

 
DISPLAY_1_GUARDADO = DISPLAY_1;
DISPLAY_2_GUARDADO = DISPLAY_2;
DISPLAY_3_GUARDADO = DISPLAY_3;
DISPLAY_4_GUARDADO = DISPLAY_4;



EEPROM.get(30,TIEMPO_1);
EEPROM.get(35,TIEMPO_2);
EEPROM.get(40,TIEMPO_3);
EEPROM.get(45,TIEMPO_4);
EEPROM.get(50,TIEMPO_5);
EEPROM.get(55,TIEMPO_6);
EEPROM.get(60,TIEMPO_7);
EEPROM.get(65,TIEMPO_8);
EEPROM.get(70,TIEMPO_9);

TEMPORAL_TIEMPO_1 = TIEMPO_1;
TEMPORAL_TIEMPO_2 = TIEMPO_2;
TEMPORAL_TIEMPO_3 = TIEMPO_3;
TEMPORAL_TIEMPO_4 = TIEMPO_4;
TEMPORAL_TIEMPO_5 = TIEMPO_5;
TEMPORAL_TIEMPO_6 = TIEMPO_6;
TEMPORAL_TIEMPO_7 = TIEMPO_7;
TEMPORAL_TIEMPO_8 = TIEMPO_8;
TEMPORAL_TIEMPO_9 = TIEMPO_9;

////////////////////////////////////////////////////////////////////////////////////

  PT_INIT(&hilo1);

  
  PT_INIT(&hilo2);
  PT_INIT(&hilo3);  
  PT_INIT(&hilo4);  
  PT_INIT(&hilo5);  
  PT_INIT(&hilo6);
  PT_INIT(&hilo7);


}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() { 

INICIO:

RUN_MOTOR = 0;
  
digitalWrite(LED_VERDE,LOW); // ON LED VERDE
digitalWrite(LED_ROJO,HIGH); // OFF LED ROJO

      
display1.showNumberDecEx(DISPLAY_1,0b01000000, true); // Expect: 0301
display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301
display3.showNumberDecEx(DISPLAY_3,0b01000000, true); // Expect: 0301
display4.showNumberDecEx(DISPLAY_4,0b01000000, true); // Expect: 0301

BANDERA_MANUAL_INCIO = 1 ;
BANDERA_AUTOMATIC_INCIO = 1 ;

PROGRAMAX:  


///AUTO_MANUAL = 0   manual ///AUTO_MANUAL = 1   automatic
  if  (digitalRead(AUTO_MANUAL) == 0){
  goto MANUAL;  
  }
  else { 

        if (BANDERA_LIBRE_AUTOMATIC == 1){
        goto  AUTOMATIC;      
        }
        else { 
        goto  MANUAL;    
        } 
  
  }

 
 jojo = 0;
                                                      
goto PROGRAMAX;






////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MANUAL:
                        
                        ////////////////////////AL ESTAR EN MANUAL ESTE REINICIA LOS PROTOTREAD
                              PT_INIT(&hilo1); 
                              PT_INIT(&hilo2); 
                              PT_INIT(&hilo3); 
                              PT_INIT(&hilo4); 
                              PT_INIT(&hilo5); 
                              PT_INIT(&hilo6); 
                              PT_INIT(&hilo7);   
                        ////////////////////////AL ESTAR EN MANUAL ESTE REINICIA LOS PROTOTREAD
                        
                        
                         
                                      
                                      FUNCION_DE_PRIMERA_VEZ_MANUAL();
                                
                                      if  (digitalRead(B_DESCARGA) == 0){
                                      goto DESCONTAR; 
                                      }
                                      if  (digitalRead(B_STOP) == 0){
                                      goto PROCESO_STOP; 
                                      }
                                
                                
                                
                                
                                
                                      
                                ///////////////////////////////////////////////////////////
                                ////      ENCENDIDOS DE BOTONES MODO MANUAL
                                      if  (digitalRead(B_ELT_1) == 0){
                                      digitalWrite(ELT_1_220V,LOW); 
                                      }
                                      else {
                                      digitalWrite(ELT_1_220V,HIGH);      
                                      }
                                //////////////////////////////////////////////////////
                                      if  (digitalRead(B_ELT_2) == 0){
                                      digitalWrite(ELT_2_220V,LOW);       
                                      }
                                      else {
                                      digitalWrite(ELT_2_220V,HIGH);      
                                      }
                                //////////////////////////////////////////////////////
                                     if  (digitalRead(B_ELT_3) == 0){
                                      digitalWrite(ELT_3_220V,LOW); 
                                      }
                                      else {
                                      digitalWrite(ELT_3_220V,HIGH);
                                      }
                                //////////////////////////////////////////////////////
                                     if  (digitalRead(B_ELT_4) == 0){
                                      digitalWrite(ELT_4_220V,LOW); 
                                      }
                                      else {
                                      digitalWrite(ELT_4_220V,HIGH); 
                                      }
                                //////////////////////////////////////////////////////////
                                      if  (digitalRead(B_STOP_LLENADO) == 0){
                                      digitalWrite(LLENADO_STOP_1_24V,LOW);      
                                      }
                                      else {
                                      digitalWrite(LLENADO_STOP_1_24V,HIGH);       
                                      }
                                //////////////////////////////////////////////////////
                                     if  (digitalRead(B_BAJA_LLENADO) == 0){
                                      digitalWrite(LLENADO_BAJA_2_24V,LOW);       
                                      }
                                      else {
                                      digitalWrite(LLENADO_BAJA_2_24V,HIGH);      
                                      }
                                //////////////////////////////////////////////////////
                                     if  (digitalRead(B_ALINEAMIENTO) == 0){
                                      digitalWrite(LLENADO_ALINE_3_24V,LOW);       
                                      }
                                      else {
                                      digitalWrite(LLENADO_ALINE_3_24V,HIGH);        
                                      }
                                //////////////////////////////////////////////////////
                                     if  (digitalRead(B_STOP_TAPADO) == 0){
                                      digitalWrite(TAPADO_STOP_4_220V,LOW);       
                                      }
                                      else {
                                      digitalWrite(TAPADO_STOP_4_220V,HIGH);       
                                      }
                                //////////////////////////////////////////////////////
                                     if  (digitalRead(B_BAJA_TAPADO) == 0){
                                      digitalWrite(TAPADO_BAJA_5_220V,LOW);       
                                      }
                                      else {
                                      digitalWrite(TAPADO_BAJA_5_220V,HIGH);   
                                      }
                                //////////////////////////////////////////////////////
                                     if  (digitalRead(B_ON_OFF_AIRE) == 0){
                                      digitalWrite(TAPADO_AIRE_6_220V,LOW);       
                                      }
                                      else {
                                      digitalWrite(TAPADO_AIRE_6_220V,HIGH);         
                                      }
                                ////////////////////////////////////////////////////////////////////////////////////////////////
                        
                        
                                      if ( digitalRead(B_ELT_1) && digitalRead(B_ELT_2)  && digitalRead(B_ELT_3)  && digitalRead(B_ELT_4)  && digitalRead(B_STOP_LLENADO)  && digitalRead(B_BAJA_LLENADO) && digitalRead(B_ALINEAMIENTO)  && digitalRead(B_STOP_TAPADO) && digitalRead(B_BAJA_TAPADO) && digitalRead(B_ON_OFF_AIRE) ) {    
                                      BANDERA_LIBRE_AUTOMATIC = 1;
                        //              DISPLAY_1       = 1111;
                                      }
                                      else {
                                      BANDERA_LIBRE_AUTOMATIC = 0;        
                        //              DISPLAY_1       = 0000;
                                      }
                        
                       //B_MOTOR_ON_OFF/////////////////////////////////////////////
                       if (digitalRead(B_MOTOR_ON_OFF) == 0) { 
                                     while  (digitalRead(B_MOTOR_ON_OFF) == 0){
                                     delay (100);
                                     }
                       delay(100);                        // delay to debounce switch
                       RUN_MOTOR = !RUN_MOTOR;                // toggle running variable
                       if (RUN_MOTOR == 0){
                       digitalWrite(MOTOR_CINTA,HIGH);
                       DISPLAY_1    = RUN_MOTOR ;
                       }
                       else {
                            digitalWrite(MOTOR_CINTA,LOW);  
                            DISPLAY_1    = RUN_MOTOR ;
                            }                      
                       }      
                               
                              
                               DISPLAY_1       = RUN_MOTOR;
                                digitalWrite(LED_VERDE,LOW); // ON LED VERDE
                                digitalWrite(LED_ROJO,HIGH); // OFF LED ROJO
                        
                              
                                    display1.showNumberDecEx(DISPLAY_1,0b01000000, true); // Expect: 0301
                                    display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301
                                    display3.showNumberDecEx(DISPLAY_3,0b01000000, true); // Expect: 0301
                                    display4.showNumberDecEx(DISPLAY_4,0b01000000, true); // Expect: 0301

  
goto PROGRAMAX;
////////////////////////////////////////////////////////////////////////////////////












////////////////////////////////////////////////////////////////////////////////////
                              DESCONTAR:
                               
                                delay (100);
                              
                              //HABILITAR ELECTROVALVULAS
                                digitalWrite(ELT_1_220V,LOW);
                                digitalWrite(ELT_2_220V,LOW);
                                digitalWrite(ELT_3_220V,LOW);
                                digitalWrite(ELT_4_220V,LOW);
                               
                              DISPLAY_1 = DISPLAY_1_GUARDADO;
                              DISPLAY_2 = DISPLAY_2_GUARDADO;
                              DISPLAY_3 = DISPLAY_3_GUARDADO;
                              DISPLAY_4 = DISPLAY_4_GUARDADO;
                              
                                //HABILITAR INTERRUPCION
                                delay (100);
                                 
                                attachInterrupt(digitalPinToInterrupt(INTERRUPCIONX), INTERRUPCION, RISING );      
                                
                              BUCLE_DESCONTANDO: 
                              
                                if (DISPLAY_1 == 0){
                                digitalWrite(ELT_1_220V,HIGH);
                                }
                              
                                if (DISPLAY_2 == 0){
                                digitalWrite(ELT_2_220V,HIGH);
                                }
                              
                                if (DISPLAY_3 == 0){
                                digitalWrite(ELT_3_220V,HIGH);
                                }
                              
                                if (DISPLAY_4 == 0){
                                digitalWrite(ELT_4_220V,HIGH);
                                }
                                
                                    display1.showNumberDecEx(DISPLAY_1,0b01000000, true); // Expect: 0301
                                    display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301
                                    display3.showNumberDecEx(DISPLAY_3,0b01000000, true); // Expect: 0301
                                    display4.showNumberDecEx(DISPLAY_4,0b01000000, true); // Expect: 0301
                                
                                if(DISPLAY_1 == 0 && DISPLAY_2 == 0 && DISPLAY_3 == 0 && DISPLAY_4 == 0){
                                goto SALIR_DE_TIEMPO;
                                }
                              
                                if (digitalRead(B_DESCARGA) == 0){
                                goto  BUCLE_DESCONTANDO;
                                }
                                
                                delay (100);
                              
                              SALIR_DE_TIEMPO:
                              detachInterrupt(digitalPinToInterrupt(INTERRUPCIONX));   
                              
                              digitalWrite(ELT_1_220V,HIGH);
                              digitalWrite(ELT_2_220V,HIGH);
                              digitalWrite(ELT_3_220V,HIGH);
                              digitalWrite(ELT_4_220V,HIGH);
                              
                                    display1.showNumberDecEx(DISPLAY_1,0b01000000, true); // Expect: 0301
                                    display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301
                                    display3.showNumberDecEx(DISPLAY_3,0b01000000, true); // Expect: 0301
                                    display4.showNumberDecEx(DISPLAY_4,0b01000000, true); // Expect: 0301
                              
                              DISPLAY_1 = DISPLAY_1_GUARDADO;
                              DISPLAY_2 = DISPLAY_2_GUARDADO;
                              DISPLAY_3 = DISPLAY_3_GUARDADO;
                              DISPLAY_4 = DISPLAY_4_GUARDADO;
                              
                                while (digitalRead(B_DESCARGA) == 0){
                                delay (100);
                                }
                              
                                delay (100);
                              
                              goto PROGRAMAX;
////////////////////////////////////////////////////////////////////////////////////










////////////////////////////////////////////////////////////////////////////////////
              PROCESO_STOP:
              delay (100);
              while  (digitalRead(B_STOP) == 0){
              delay (100);

              
              }
              delay (100);

//            LA PRIMERA VEZ SE PONE A CERO 
              CONTADOR_CONFIG = 0;
              
              digitalWrite(LED_VERDE,HIGH); // ON LED VERDE
              digitalWrite(LED_ROJO,LOW); // OFF LED ROJO
             
              DISPLAY_1 = DISPLAY_1_GUARDADO;
              DISPLAY_2 = DISPLAY_2_GUARDADO;
              DISPLAY_3 = DISPLAY_3_GUARDADO;
              DISPLAY_4 = DISPLAY_4_GUARDADO;
            
                    SEPARAR_DISPLAY_1_A_CASILLAS();                            
                    SEPARAR_DISPLAY_2_A_CASILLAS();
                    SEPARAR_DISPLAY_3_A_CASILLAS();
                    SEPARAR_DISPLAY_4_A_CASILLAS();
            
            HORIZONTE_1 = 1;
            HORIZONTE_2 = 1;
            HORIZONTE_3 = 1;
            HORIZONTE_4 = 1;
                    
////////////////////////////////////////////////////////////////////
PROGRAMACION_DE_TIEMPO:

                  if  (digitalRead(INC_1) == 0){
                  INC_MENU_1();       
                  }
                  if  (digitalRead(DEC_1) == 0){
                  DEC_MENU_1();       
                  }
                  if  (digitalRead(IZQ_1) == 0){
                  IZQ_MENU_1();       
                  }
                  if  (digitalRead(DER_1) == 0){
                  DER_MENU_1();       
                  }
                  
                  
                  ///////////////////////////////////////////
                  if  (digitalRead(INC_2) == 0){
                  INC_MENU_2();      
                  }
                  if  (digitalRead(DEC_2) == 0){
                  DEC_MENU_2();        
                  }
                  if  (digitalRead(IZQ_2) == 0){
                  IZQ_MENU_2();          
                  }
                  if  (digitalRead(DER_2) == 0){
                  DER_MENU_2();     
                  }
                  
                  
                  ///////////////////////////////////////////
                  if  (digitalRead(INC_3) == 0){
                  INC_MENU_3();          
                  }
                  if  (digitalRead(DEC_3) == 0){
                  DEC_MENU_3();       
                  }
                  if  (digitalRead(IZQ_3) == 0){
                  IZQ_MENU_3();        
                  }
                  if  (digitalRead(DER_3) == 0){
                  DER_MENU_3();       
                  }
                  
                  
                  ///////////////////////////////////////////
                  if  (digitalRead(INC_4) == 0){
                  INC_MENU_4();      
                  }
                  if  (digitalRead(DEC_4) == 0){
                  DEC_MENU_4(); 
                  }
                  if  (digitalRead(IZQ_4) == 0){
                  IZQ_MENU_4();          
                  }
                  if  (digitalRead(DER_4) == 0){
                  DER_MENU_4();      
                  }
                  
                  
                  
                  /////////////////////////////////////////////////////////
                  
                  
                    // SALE DE LA PROGRAMACION DE TIEMPO PRECIONANDO UNA VEZ EL BOTON VERDE STAR
                  
                    if  (digitalRead(B_STAR) == 0){
                    delay (100);
                    while  (digitalRead(B_STAR) == 0){
                    delay (100);
                    }
                    delay (100);  
                  
                    
                    EEPROM.put(0,DISPLAY_1);
                    EEPROM.put(5,DISPLAY_2);
                    EEPROM.put(10,DISPLAY_3);
                    EEPROM.put(15,DISPLAY_4);
            
                    DISPLAY_1_GUARDADO = DISPLAY_1;
                    DISPLAY_2_GUARDADO = DISPLAY_2;
                    DISPLAY_3_GUARDADO = DISPLAY_3;
                    DISPLAY_4_GUARDADO = DISPLAY_4;           
                    
                    goto PROGRAMAX;
                    
                    }


                    //ACA PREGUNTARA DOS VECES PARA PODER IR AL OTRO MODO DE CONFIGURACION
                    if  (digitalRead(B_STOP) == 0){
                            while  (digitalRead(B_STOP) == 0){
                            delay (100);
                    }
                    delay (100);
                    CONTADOR_CONFIG++;
                          if (CONTADOR_CONFIG == 2){
                          digitalWrite(LED_ROJO,HIGH); // ON LED VERDE
                          delay(500);
                          digitalWrite(LED_ROJO,LOW); // OFF LED ROJO
                          delay(500);

                          goto CONFIG_TIME_PROCESO; 

                          }
                    }


                  
                  ////////////////////////////////////////////////
                  
                  
                  
                  display1.showNumberDecEx(DISPLAY_1,0b01000000, true); // Expect: 0301
                  display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301
                  display3.showNumberDecEx(DISPLAY_3,0b01000000, true); // Expect: 0301
                  display4.showNumberDecEx(DISPLAY_4,0b01000000, true); // Expect: 0301
                  
goto PROGRAMACION_DE_TIEMPO;
            







///////////////////////////////////////////////////////////////////////////////////
CONFIG_TIME_PROCESO:
CONTADOR_CONFIG = 0;



EEPROM.get(30,TIEMPO_1);
EEPROM.get(35,TIEMPO_2);
EEPROM.get(40,TIEMPO_3);
EEPROM.get(45,TIEMPO_4);
EEPROM.get(50,TIEMPO_5);
EEPROM.get(55,TIEMPO_6);
EEPROM.get(60,TIEMPO_7);
EEPROM.get(65,TIEMPO_8);
EEPROM.get(70,TIEMPO_9);

TEMPORAL_TIEMPO_1 = TIEMPO_1;
TEMPORAL_TIEMPO_2 = TIEMPO_2;
TEMPORAL_TIEMPO_3 = TIEMPO_3;
TEMPORAL_TIEMPO_4 = TIEMPO_4;
TEMPORAL_TIEMPO_5 = TIEMPO_5;
TEMPORAL_TIEMPO_6 = TIEMPO_6;
TEMPORAL_TIEMPO_7 = TIEMPO_7;
TEMPORAL_TIEMPO_8 = TIEMPO_8;
TEMPORAL_TIEMPO_9 = TIEMPO_9;


HORIZONTE_1 = 1;
HORIZONTE_2 = 1;

CONFIG_TIME_PROCESO_CONTANDO_XXXX:

              DISPLAY_1 = TIEMPO_1;
              DISPLAY_2 = 1;
              DISPLAY_X = 1111;
              DISPLAY_3 = 1;
              DISPLAY_4 = 1;              



                    SEPARAR_DISPLAY_1_A_CASILLAS();        
                    SEPARAR_DISPLAY_2_A_CASILLAS();
                    SEPARAR_DISPLAY_3_A_CASILLAS();
                    SEPARAR_DISPLAY_4_A_CASILLAS();
            
 
                    
////////////////////////////////////////////////////////////////////
                 
PROGRAMACION_DE_TIEMPOSS:
                                if  (digitalRead(INC_1) == 0){
                                INC_MENU_TIEMPOS_1();       
                                }
                                if  (digitalRead(DEC_1) == 0){
                                DEC_MENU_TIEMPOS_1();       
                                }
                                if  (digitalRead(IZQ_1) == 0){
                                IZQ_MENU_TIEMPOS_1();       
                                }
                                if  (digitalRead(DER_1) == 0){
                                DER_MENU_TIEMPOS_1();       
                                }
                                
                                
                                ///////////////////////////////////////////
                                if  (digitalRead(INC_2) == 0){
                                INC_MENU_REGISTROS_TIEMPOS_2();      
                                }
                                if  (digitalRead(DEC_2) == 0){
                                DEC_MENU_REGISTROS_TIEMPOS_2();        
                                }
                                
                                
              
                                
                                
                                
                                /////////////////////////////////////////////////////////
                                
                                
                                // SALE DE LA PROGRAMACION DE TIEMPO PRECIONANDO UNA VEZ EL BOTON VERDE STAR
                                
                                  if  (digitalRead(B_STAR) == 0){
                                  delay (100);
                                  while  (digitalRead(B_STAR) == 0){
                                  delay (100);
                                  }
                                  delay (100);  
                                

                                  TIEMPO_1 = TEMPORAL_TIEMPO_1;
                                  TIEMPO_2 = TEMPORAL_TIEMPO_2;
                                  TIEMPO_3 = TEMPORAL_TIEMPO_3;
                                  TIEMPO_4 = TEMPORAL_TIEMPO_4;           
                                  TIEMPO_5 = TEMPORAL_TIEMPO_5;
                                  TIEMPO_6 = TEMPORAL_TIEMPO_6;
                                  TIEMPO_7 = TEMPORAL_TIEMPO_7;
                                  TIEMPO_8 = TEMPORAL_TIEMPO_8;           
                                  TIEMPO_9 = TEMPORAL_TIEMPO_9;           
                                  
                                  EEPROM.put(30,TIEMPO_1);
                                  EEPROM.put(35,TIEMPO_2);
                                  EEPROM.put(40,TIEMPO_3);
                                  EEPROM.put(45,TIEMPO_4);
                                  EEPROM.put(50,TIEMPO_5);
                                  EEPROM.put(55,TIEMPO_6);
                                  EEPROM.put(60,TIEMPO_7);
                                  EEPROM.put(65,TIEMPO_8);
                                  EEPROM.put(70,TIEMPO_9);

                                  //////////////////////////////////////////////////////////////////////4564564564
                                  
                                  EEPROM.get(0,DISPLAY_1);
                                  EEPROM.get(5,DISPLAY_2);
                                  EEPROM.get(10,DISPLAY_3);
                                  EEPROM.get(15,DISPLAY_4);
                                  
                                   
                                  DISPLAY_1_GUARDADO = DISPLAY_1;
                                  DISPLAY_2_GUARDADO = DISPLAY_2;
                                  DISPLAY_3_GUARDADO = DISPLAY_3;
                                  DISPLAY_4_GUARDADO = DISPLAY_4;


                                  goto PROGRAMAX;
                                
                                  }

  
  
                                  //ACA PREGUNTARA UNA VEZ PARA PODER IR AL OTRO MODO DE CONFIGURACION
                                  if  (digitalRead(B_STOP) == 0){
                                  while  (digitalRead(B_STOP) == 0){
                                  delay (100);
                                  }
                                  delay (100);
                                  CONTADOR_CONFIG++;
                                          if (CONTADOR_CONFIG == 2){
                                          CONTADOR_CONFIG = 0;                                                                                          
                                          digitalWrite(LED_ROJO,HIGH); // ON LED VERDE
                                          delay(500);
                                          digitalWrite(LED_ROJO,LOW); // OFF LED ROJO
                                          delay(500);                                          
                                          goto PROCESO_STOP;                        
                                          }
                                  }

                                
                                display1.showNumberDecEx(DISPLAY_1,0b01000000, true); // Expect: 0301
                                display2.showNumberDecEx(DISPLAY_X,0b01000000, true); // Expect: 0301
                                display3.showNumberDecEx(DISPLAY_X,0b01000000, true); // Expect: 0301
                                display4.showNumberDecEx(DISPLAY_X,0b01000000, true); // Expect: 0301
                                
goto PROGRAMACION_DE_TIEMPOSS;







goto PROGRAMAX;








///*********************************************************XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AUTOMATIC:

FUNCION_DE_PRIMERA_VEZ_AUTOMATIC();

  CONTADOR(&hilo1);  
  LLENADORA_PRIMERA_PARADA(&hilo2);
  LLENADORA_SEGUNDA_PARADA(&hilo3);  
  LLENADORA_TERCERA_PARADA(&hilo4);  
  LLENADORA_CUARTA_PARADA(&hilo5);
  LLENADORA_QUINTA_PARADA(&hilo6);
  TAPADORA_PRIMER_PARADA(&hilo7);






goto PROGRAMAX;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} ///FIN DEL LOOP






///*//////////////////////////////////////////////

////////////////////////////////////////////////

//--------------------------------------------
void INC_MENU_TIEMPOS_1(){ 
  delay (100);
  while  (digitalRead(INC_1) == 0){
  delay (100);
  }
  delay (100);

  if (HORIZONTE_1 == 1) {
    if (UNIDAD_1 != 9) {
    UNIDAD_1++;   
    }
  }

  if(HORIZONTE_1 == 2) {
    if (DECENA_1 != 9) {
    DECENA_1++;   
    }
  }

  if (HORIZONTE_1 == 3) {
    if (CENTENA_1 != 9) {
    CENTENA_1++;   
    }
  }

  if (HORIZONTE_1 == 4) {
    if (MIL_1 != 9) {
    MIL_1++;   
    }
  }

  DISPLAY_1 = (MIL_1 * 1000)+(CENTENA_1 * 100)+(DECENA_1*10)+(UNIDAD_1);    
  
  if (UNIDAD_2==1){
  TEMPORAL_TIEMPO_1 = DISPLAY_1 ;  
  }
  if (UNIDAD_2==2){   
  TEMPORAL_TIEMPO_2 = DISPLAY_1;
  }
  if (UNIDAD_2==3){   
  TEMPORAL_TIEMPO_3 = DISPLAY_1;
  }
  if (UNIDAD_2==4){  
  TEMPORAL_TIEMPO_4 = DISPLAY_1; 
  }
  if (UNIDAD_2==5){   
  TEMPORAL_TIEMPO_5 = DISPLAY_1;  
  }
  if (UNIDAD_2==6){  
  TEMPORAL_TIEMPO_6 = DISPLAY_1;  
  }
  if (UNIDAD_2==7){
  TEMPORAL_TIEMPO_7 = DISPLAY_1;    
  }
  if (UNIDAD_2==8){
  TEMPORAL_TIEMPO_8 = DISPLAY_1;  
  }
  if (UNIDAD_2==9){   
  TEMPORAL_TIEMPO_9 = DISPLAY_1;
  }

  
  
}
//--------------------------------------------
//--------------------------------------------
void DEC_MENU_TIEMPOS_1(){ 
  delay (100);
  while  (digitalRead(DEC_1) == 0){
  delay (100);
  }
  delay (100);
  
  if (HORIZONTE_1 == 1) {
    if (UNIDAD_1 != 0) {
    UNIDAD_1--;   
    }
  }

  if (HORIZONTE_1 == 2) {
    if (DECENA_1 != 0) {
    DECENA_1--;   
    }
  }

  if (HORIZONTE_1 == 3) {
    if (CENTENA_1 != 0) {
    CENTENA_1--;   
    }
  }

  if (HORIZONTE_1 == 4) {
    if (MIL_1 != 0) {
    MIL_1--;   
    }
  }

  DISPLAY_1 = (MIL_1 * 1000)+(CENTENA_1 * 100)+(DECENA_1*10)+(UNIDAD_1);    

    
  if (UNIDAD_2==1){
  TEMPORAL_TIEMPO_1 = DISPLAY_1 ;  
  }
  if (UNIDAD_2==2){   
  TEMPORAL_TIEMPO_2 = DISPLAY_1;
  }
  if (UNIDAD_2==3){   
  TEMPORAL_TIEMPO_3 = DISPLAY_1;
  }
  if (UNIDAD_2==4){  
  TEMPORAL_TIEMPO_4 = DISPLAY_1; 
  }
  if (UNIDAD_2==5){   
  TEMPORAL_TIEMPO_5 = DISPLAY_1;  
  }
  if (UNIDAD_2==6){  
  TEMPORAL_TIEMPO_6 = DISPLAY_1;  
  }
  if (UNIDAD_2==7){
  TEMPORAL_TIEMPO_7 = DISPLAY_1;    
  }
  if (UNIDAD_2==8){
  TEMPORAL_TIEMPO_8 = DISPLAY_1;  
  }
  if (UNIDAD_2==9){   
  TEMPORAL_TIEMPO_9 = DISPLAY_1;
  }
  
}
//--------------------------------------------
//--------------------------------------------
void IZQ_MENU_TIEMPOS_1(){
   delay (100);
  while  (digitalRead(IZQ_1) == 0){
  delay (100);
  }
  delay (100);
  if (HORIZONTE_1 != 4){
    HORIZONTE_1++;
    
  } 
}
//--------------------------------------------
//--------------------------------------------
void DER_MENU_TIEMPOS_1(){
  delay (100);
  while  (digitalRead(DER_1) == 0){
  delay (100);
  }
  delay (100);  
  if (HORIZONTE_1 != 1){
  HORIZONTE_1--;
  } 
}
//--------------------------------------------
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////

//--------------------------------
void INC_MENU_REGISTROS_TIEMPOS_2(){     
  delay (100);
  while  (digitalRead(INC_2) == 0){
  delay (100);
  }
  delay (100);

  if (HORIZONTE_2 == 1) {
    if (UNIDAD_2 != 9) {
    UNIDAD_2++;   
    }
  }

 

  if (UNIDAD_2==1){
  DISPLAY_1 = TEMPORAL_TIEMPO_1 ;  
  }
  if (UNIDAD_2==2){   
  DISPLAY_1 = TEMPORAL_TIEMPO_2;
  }
  if (UNIDAD_2==3){   
  DISPLAY_1 = TEMPORAL_TIEMPO_3;
  }
  if (UNIDAD_2==4){  
  DISPLAY_1 = TEMPORAL_TIEMPO_4; 
  }
  if (UNIDAD_2==5){   
  DISPLAY_1 = TEMPORAL_TIEMPO_5;  
  }
  if (UNIDAD_2==6){  
  DISPLAY_1 = TEMPORAL_TIEMPO_6;  
  }
  if (UNIDAD_2==7){
  DISPLAY_1 = TEMPORAL_TIEMPO_7;    
  }
  if (UNIDAD_2==8){
  DISPLAY_1 = TEMPORAL_TIEMPO_8;  
  }
  if (UNIDAD_2==9){   
  DISPLAY_1 = TEMPORAL_TIEMPO_9;
  }

   
  DISPLAY_2 = (MIL_2 * 1000)+(CENTENA_2 * 100)+(DECENA_2*10)+(UNIDAD_2 * 1);    
  DISPLAY_X = DISPLAY_2 *1111;
  
  SEPARAR_DISPLAY_1_A_CASILLAS();        
}
//--------------------------------

//--------------------------------
void DEC_MENU_REGISTROS_TIEMPOS_2(){ 
  delay (100);
  while  (digitalRead(DEC_2) == 0){
  delay (100);
  }
  delay (100);
  
  if (HORIZONTE_2 == 1) {
    if (UNIDAD_2 != 1) {
    UNIDAD_2--;   
    }
  }

  if (UNIDAD_2==1){
  DISPLAY_1 = TEMPORAL_TIEMPO_1;   
  }
  if (UNIDAD_2==2){  
  DISPLAY_1 =  TEMPORAL_TIEMPO_2;  
  }
  if (UNIDAD_2==3){
  DISPLAY_1 =  TEMPORAL_TIEMPO_3;     
  }
  if (UNIDAD_2==4){
  DISPLAY_1 =  TEMPORAL_TIEMPO_4;  
  }
  if (UNIDAD_2==5){
  DISPLAY_1 =  TEMPORAL_TIEMPO_5;      
  }
  if (UNIDAD_2==6){
  DISPLAY_1 =  TEMPORAL_TIEMPO_6;
  }
  if (UNIDAD_2==7){
  DISPLAY_1 =  TEMPORAL_TIEMPO_7;  
  }
  if (UNIDAD_2==8){
  DISPLAY_1 =  TEMPORAL_TIEMPO_8;  
  }
  if (UNIDAD_2==9){
  DISPLAY_1 =  TEMPORAL_TIEMPO_9;  
  }


  DISPLAY_2 = (MIL_2 * 1000)+(CENTENA_2 * 100)+(DECENA_2*10)+(UNIDAD_2 * 1);    
  DISPLAY_X = DISPLAY_2 *1111;  

  SEPARAR_DISPLAY_1_A_CASILLAS();        

}
//--------------------------------




/////////////////////////////////////////////////////
/*
void parpadeo(struct pt *pt) {
  PT_BEGIN(pt);
  // void setup() {
  static long t = 0;
  do {
  // void loop() {
    digitalWrite(10, HIGH);
    t = millis();
    PT_WAIT_WHILE(pt, (millis()-t)<1000);
    
    digitalWrite(10, LOW);
    t = millis();
    PT_WAIT_UNTIL(pt, (millis()-t)>=1000);
  // }
  } while(true);
  PT_END(pt);
}
*/
/////////////////////////////////////////////////////



void CONTADOR(struct pt *pt) {
/////////////CONTADOR()
PT_BEGIN(pt);
//static unsigned long t = 0;
do {

    if (M_1 == 1){
      
       if ( digitalRead(SENSOR) == 0) {  
           while  (digitalRead(SENSOR) == 0){
            

            t = 10;
            while (t != 0 ){
//            DISPLAY_2 = t; 
//            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
            JOJO = 1;
            PT_YIELD(pt);                  
            }
//            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              

            PT_YIELD(pt);                  
            }
        


            t = 10;
            while (t != 0 ){
            DISPLAY_2 = t; 
//            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
            JOJO = 1;
            PT_YIELD(pt);                  
            }
//            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              


           CONTADOR_DE_PIEZAS++;
           display4.showNumberDecEx(CONTADOR_DE_PIEZAS,0b01000000, true); // Expect: 0301

           if (CONTADOR_DE_PIEZAS == 4 ){
           M_2 = 1; // ACTIVA SIGUIENTE PROCESO
           M_1 = 0; // DESACTIVA CONTADOR                     
           CONTADOR_DE_PIEZAS = 0 ; 
           }   
           PT_YIELD(pt);      
       }
       

    PT_YIELD(pt);  
    }

// SI M_1 = 0  DESACTIVA


    PT_YIELD(pt); 
} while(true);
PT_END(pt);
}

void LLENADORA_PRIMERA_PARADA(struct pt *pt) {
PT_BEGIN(pt); 
//static unsigned long t1 = 0;

do {
 
    if (M_2 == 1){
    
    digitalWrite(LLENADO_STOP_1_24V,LOW); ///   

                       
//             display3.showNumberDecEx(1111,0b01000000, true); // Expect: 0301              
            t1 = TIEMPO_1;
            while (t1 != 0 ){
//            DISPLAY_2 = t1; 
//            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
            JOJO = 1;
            PT_YIELD(pt);                  
            }
//            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301                          



                if (M_8==1){
                ///////////////// POR CUENTA DE MOTOR CINTA ESTA DISPLAY = 0 ES MOTOR OFF  /////  DISPLAY = 1 ES MOTOR ON
//              MOTOR_CINTA = 0;
                RUN_MOTOR = 0;
                digitalWrite(MOTOR_CINTA,HIGH); // APAGA EL MOTOR
                DISPLAY_1 = 0 ;                  
                display1.showNumberDecEx(DISPLAY_1,0b01000000, true); // Expect: 0301
                ///////////////// POR CUENTA DE MOTOR CINTA ESTA DISPLAY = 0 ES MOTOR OFF  /////  DISPLAY = 1 ES MOTOR ON         
        
                digitalWrite(LLENADO_ALINE_3_24V,LOW); // ON LED VERDE     
                       
                    display3.showNumberDecEx(2222,0b01000000, true); // Expect: 0301              
                    t1 = TIEMPO_2;
                    while (t1 != 0 ){
                    DISPLAY_2 = t1; 
                    display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
                    PT_YIELD(pt);                  
                    }
                    display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301                          
            
                M_2 = 0;
                M_8 = 0;
                M_3 = 1;
                
                PT_YIELD(pt);        
                }        
        
    PT_YIELD(pt);  
    }
    
    PT_YIELD(pt);  
} while(true);

PT_END(pt);    
}

void LLENADORA_SEGUNDA_PARADA(struct pt *pt) {
PT_BEGIN(pt);  
//static long t2 = 0;
do {

    if (M_3 == 1){      
          
    digitalWrite(LLENADO_BAJA_2_24V,LOW); // OFF LED ROJO   
    digitalWrite(TAPADO_BAJA_5_220V,LOW); // OFF LED ROJO

            display3.showNumberDecEx(3333,0b01000000, true); // Expect: 0301              
            t2 = TIEMPO_3;
            while (t2 != 0 ){
            DISPLAY_2 = t2; 
            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
            PT_YIELD(pt);                  
            }
            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
    

    
    M_3 = 0;

    M_4 = 1;

    PT_YIELD(pt); 
    }

 
PT_YIELD(pt); 
} while(true);
PT_END(pt);
}

void LLENADORA_TERCERA_PARADA(struct pt *pt) {
PT_BEGIN(pt);
//static long t3 = 0;
do {
  
    if (M_4 == 1){

    // PROCESO DE TAPADO 
    
    
    digitalWrite(TAPADO_AIRE_6_220V,LOW); // OFF LED ROJO   

            display3.showNumberDecEx(4444,0b01000000, true); // Expect: 0301              
            t3 = TIEMPO_4;
            while (t3 != 0 ){
            DISPLAY_2 = t3; 
            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
            PT_YIELD(pt);                  
            }
            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301                          
    
    digitalWrite(TAPADO_AIRE_6_220V,HIGH); // OFF LED ROJO   


            display3.showNumberDecEx(5555,0b01000000, true); // Expect: 0301              
            t3 = TIEMPO_5;
            while (t3 != 0 ){
            DISPLAY_2 = t3; 
            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
            PT_YIELD(pt);                  
            }
            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              



    
    /// PROCESO DE DESCARGA////////////////////////////////////////////////////////////
    /// PROCESO DE DESCARGA////////////////////////////////////////////////////////////
    /// PROCESO DE DESCARGA////////////////////////////////////////////////////////////

    
        
        //HABILITAR ELECTROVALVULAS
          digitalWrite(ELT_1_220V,LOW);
          digitalWrite(ELT_2_220V,LOW);
          digitalWrite(ELT_3_220V,LOW);
          digitalWrite(ELT_4_220V,LOW);

            t3 = 10;
            while (t3 != 0 ){
            DISPLAY_2 = t3; 
            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
            PT_YIELD(pt);                  
            }
            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              

        DISPLAY_1 = DISPLAY_1_GUARDADO;
        DISPLAY_2 = DISPLAY_2_GUARDADO;
        DISPLAY_3 = DISPLAY_3_GUARDADO;
        DISPLAY_4 = DISPLAY_4_GUARDADO;
        
          //HABILITAR INTERRUPCION
           
          attachInterrupt(digitalPinToInterrupt(INTERRUPCIONX), INTERRUPCION, RISING );      
          
        BUCLE_DESCONTANDO_2: 
        
          if (DISPLAY_1 == 0){
          digitalWrite(ELT_1_220V,HIGH);
          }
        
          if (DISPLAY_2 == 0){
          digitalWrite(ELT_2_220V,HIGH);
          }
        
          if (DISPLAY_3 == 0){
          digitalWrite(ELT_3_220V,HIGH);
          }
        
          if (DISPLAY_4 == 0){
          digitalWrite(ELT_4_220V,HIGH);
          }
          
              display1.showNumberDecEx(DISPLAY_1,0b01000000, true); // Expect: 0301
              display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301
              display3.showNumberDecEx(DISPLAY_3,0b01000000, true); // Expect: 0301
              display4.showNumberDecEx(DISPLAY_4,0b01000000, true); // Expect: 0301



      
          if(DISPLAY_1 == 0 && DISPLAY_2 == 0 && DISPLAY_3 == 0 && DISPLAY_4 == 0){
          goto SALIR_DE_TIEMPO_2;
          }

        ///AUTO_MANUAL = 0   manual ///AUTO_MANUAL = 1   automatic
          if (digitalRead(AUTO_MANUAL) == 1){
          goto  BUCLE_DESCONTANDO_2;
          }
          
        
SALIR_DE_TIEMPO_2:
        detachInterrupt(digitalPinToInterrupt(INTERRUPCIONX));   
        
        digitalWrite(ELT_1_220V,HIGH);
        digitalWrite(ELT_2_220V,HIGH);
        digitalWrite(ELT_3_220V,HIGH);
        digitalWrite(ELT_4_220V,HIGH);
        
              display1.showNumberDecEx(DISPLAY_1,0b01000000, true); // Expect: 0301
              display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301
              display3.showNumberDecEx(DISPLAY_3,0b01000000, true); // Expect: 0301
              display4.showNumberDecEx(DISPLAY_4,0b01000000, true); // Expect: 0301
        
        DISPLAY_1 = DISPLAY_1_GUARDADO;
        DISPLAY_2 = DISPLAY_2_GUARDADO;
        DISPLAY_3 = DISPLAY_3_GUARDADO;
        DISPLAY_4 = DISPLAY_4_GUARDADO;




          
    /// PROCESO DE DESCARGA////////////////////////////////////////////////////////////        
    /// PROCESO DE DESCARGA////////////////////////////////////////////////////////////
    /// PROCESO DE DESCARGA////////////////////////////////////////////////////////////
    attachInterrupt(digitalPinToInterrupt(INTERRUPCIONX), INTERRUPCION, RISING );      
    //delay(TIEMPO_X); TIEMPO DE GOTEO O CIERRRE DE LA ELTS
             
            display3.showNumberDecEx(6666,0b01000000, true); // Expect: 0301              
            t3 = TIEMPO_6;
            while (t3 != 0 ){
            DISPLAY_2 = t3; 
            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
            PT_YIELD(pt);                  
            }
            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
            
    M_4 = 0;
    M_5 = 1;

    PT_YIELD(pt);   
    }

           
PT_YIELD(pt); 
} while(true);
PT_END(pt);    
}

void LLENADORA_CUARTA_PARADA(struct pt *pt) { 
PT_BEGIN(pt); 
//static long t4 = 0;
do {

    if (M_5 == 1){
    digitalWrite(LLENADO_BAJA_2_24V,HIGH); // OFF LED ROJO   
    digitalWrite(LLENADO_STOP_1_24V,HIGH); ///   
    digitalWrite(LLENADO_ALINE_3_24V,HIGH); // ON LED VERDE            
    
    digitalWrite(TAPADO_STOP_4_220V,HIGH); // OFF LED ROJO            
    digitalWrite(TAPADO_BAJA_5_220V,HIGH); // ON LED VERDE

            display3.showNumberDecEx(7777,0b01000000, true); // Expect: 0301              
            t4 = TIEMPO_7;
            while (t4 != 0 ){
            DISPLAY_2 = t4; 
            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
            PT_YIELD(pt);                  
            }
            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
            
    M_5 = 0;
    M_6 = 1;
    
    PT_YIELD(pt);   
    }
           
PT_YIELD(pt); 
} while(true);
PT_END(pt);
}

void LLENADORA_QUINTA_PARADA(struct pt *pt) {
PT_BEGIN(pt);  
//static long t5 = 0;
do {
  
    if (M_6 == 1){      
   
    ///////////////// POR CUENTA DE MOTOR CINTA ESTA DISPLAY = 0 ES MOTOR OFF  /////  DISPLAY = 1 ES MOTOR ON
    digitalWrite(MOTOR_CINTA,LOW); // ENCIENDE MOTOR
    RUN_MOTOR = 1;
    DISPLAY_1 = 1 ;    // ENCENDIDO   
    display1.showNumberDecEx(DISPLAY_1,0b01000000, true); // Expect: 0301
    ///////////////// POR CUENTA DE MOTOR CINTA ESTA DISPLAY = 0 ES MOTOR OFF  /////  DISPLAY = 1 ES MOTOR ON         


    M_6 = 0;
    M_1 = 1;
    M_7 = 1;


    PT_YIELD(pt); 
    }

PT_YIELD(pt); 
} while(true);
PT_END(pt);    
}

void TAPADORA_PRIMER_PARADA(struct pt *pt) { 
PT_BEGIN(pt);  
//static long t6 = 0;
do {
  
    if (M_7 == 1){          

//    delay(TIEMPO_X);  /// ESPERA QUE SALGA DE LA TAPADORA LA ULTIMA BOTELLA
    // delay(TIEMPO_X); 
            display3.showNumberDecEx(8888,0b01000000, true); // Expect: 0301              
            t6 = TIEMPO_8;
            while (t6 != 0 ){
            DISPLAY_2 = t6; 
            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
            PT_YIELD(pt);                  
            }
            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
    
    digitalWrite(TAPADO_STOP_4_220V,LOW); // OFF LED ROJO            
    
//  delay(TIEMPO_X);  /// ESPERA QUE SE ACOMODEN LAS BOTELLAS 
    // delay(TIEMPO_X); 
            display3.showNumberDecEx(9999,0b01000000, true); // Expect: 0301              
            t6 = TIEMPO_9;
            while (t6 != 0 ){
            DISPLAY_2 = t6; 
            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
            PT_YIELD(pt);                  
            }
            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
            
    M_7 = 0;
    M_8 = 1;

    PT_YIELD(pt);  
    }


PT_YIELD(pt);
} while(true);
PT_END(pt);    
}


////////////////////////////////////////////////

//--------------------------------------------
          
void FUNCION_DE_PRIMERA_VEZ_MANUAL(){
      if (BANDERA_MANUAL_INCIO == 1  ){
      // APAGAR TODAS LAS ELT
                 digitalWrite(LED_VERDE,HIGH); // ON LED VERDE
                  digitalWrite(LED_ROJO,HIGH); // OFF LED ROJO            
                  digitalWrite(LLENADO_STOP_1_24V,HIGH); ///            
                  digitalWrite(LLENADO_BAJA_2_24V,HIGH); // OFF LED ROJO
                  digitalWrite(LLENADO_ALINE_3_24V,HIGH); // ON LED VERDE            
                  digitalWrite(TAPADO_STOP_4_220V,HIGH); // OFF LED ROJO            
                  digitalWrite(TAPADO_BAJA_5_220V,HIGH); // ON LED VERDE
                  digitalWrite(TAPADO_AIRE_6_220V,HIGH); // OFF LED ROJO
                
                  digitalWrite(MOTOR_CINTA,HIGH); // ON LED VERDE
                  
                  RUN_MOTOR = 0;  
                  
                  
                  digitalWrite(RELE_10,HIGH); // OFF LED ROJO
                  digitalWrite(RELE_11,HIGH); // ON LED VERDE
                  digitalWrite(RELE_12,HIGH); // OFF LED ROJO
                  digitalWrite(ELT_4_220V,HIGH); // ON LED VERDE
                  digitalWrite(ELT_3_220V,HIGH); // OFF LED ROJO
                  digitalWrite(ELT_2_220V,HIGH); // ON LED VERDE
                  digitalWrite(ELT_1_220V,HIGH); // OFF LED ROJO           
      
                                    
      //delay 1S  para asegurar cambio
      BANDERA_MANUAL_INCIO = 0 ;
      BANDERA_AUTOMATIC_INCIO = 1;

                      M_1 = 1 ;
                      M_2 = 0 ;              
                      M_3 = 0 ;
                      M_4 = 0 ;
                      M_5 = 0 ;
                      M_6 = 0 ;
                      M_7 = 0 ;
                      M_8 = 1 ;


        detachInterrupt(digitalPinToInterrupt(INTERRUPCIONX));   

                    CONTADOR_CONFIG = 0;

EEPROM.get(0,DISPLAY_1);
EEPROM.get(5,DISPLAY_2);
EEPROM.get(10,DISPLAY_3);
EEPROM.get(15,DISPLAY_4);

 
DISPLAY_1_GUARDADO = DISPLAY_1;
DISPLAY_2_GUARDADO = DISPLAY_2;
DISPLAY_3_GUARDADO = DISPLAY_3;
DISPLAY_4_GUARDADO = DISPLAY_4;

      
      }

}
////////////////////////////////////////////////

//--------------------------------------------


////////////////////////////////////////////////

//--------------------------------------------

void FUNCION_DE_PRIMERA_VEZ_AUTOMATIC(){
        if (BANDERA_AUTOMATIC_INCIO == 1  ){
        // 
        
        
                    digitalWrite(LED_VERDE,HIGH); // ON LED VERDE
                    digitalWrite(LED_ROJO,HIGH); // OFF LED ROJO
                    digitalWrite(LLENADO_STOP_1_24V,LOW); // ON LED VERDE///////////EMPIEZA ACTIVADO
                    digitalWrite(LLENADO_BAJA_2_24V,HIGH); // OFF LED ROJO
                    digitalWrite(LLENADO_ALINE_3_24V,HIGH); // ON LED VERDE
                    digitalWrite(TAPADO_STOP_4_220V,LOW); // OFF LED ROJO ///////////EMPIEZA ACTIVADO
                    digitalWrite(TAPADO_BAJA_5_220V,HIGH); // ON LED VERDE
                    digitalWrite(TAPADO_AIRE_6_220V,HIGH); // OFF LED ROJO
                  
//                    digitalWrite(MOTOR_CINTA,LOW); // ON LED VERDE  ///////////EMPIEZA ACTIVADO 
                    digitalWrite(RELE_10,HIGH); // OFF LED ROJO
                    digitalWrite(RELE_11,HIGH); // ON LED VERDE
                    digitalWrite(RELE_12,HIGH); // OFF LED ROJO
                    digitalWrite(ELT_4_220V,HIGH); // ON LED VERDE
                    digitalWrite(ELT_3_220V,HIGH); // OFF LED ROJO
                    digitalWrite(ELT_2_220V,HIGH); // ON LED VERDE
                    digitalWrite(ELT_1_220V,HIGH); // OFF LED ROJO           
        
                    
                    CONTADOR_DE_PIEZAS = 0 ; 

                    
                      M_1 = 1 ;
                      M_2 = 0 ;              
                      M_3 = 0 ;
                      M_4 = 0 ;
                      M_5 = 0 ;
                      M_6 = 0 ;
                      M_7 = 0 ;
                      M_8 = 1 ;

            DISPLAY_1 = 0;                       
            DISPLAY_4 = 0; 
            DISPLAY_2 = 0; 
            DISPLAY_3 = 0; 
            display1.showNumberDecEx(DISPLAY_1,0b01000000, true); // Expect: 0301              
            display2.showNumberDecEx(DISPLAY_2,0b01000000, true); // Expect: 0301              
            display3.showNumberDecEx(DISPLAY_3,0b01000000, true); // Expect: 0301              
            display4.showNumberDecEx(DISPLAY_4,0b01000000, true); // Expect: 0301              

/*********************************************                      
// LA PRIMERA VEZ
// MOTOR_ON 
// ELT TAPA STOP ON
// ELT LLENA STOP ON
         
// CONTADOR DESABILITADO
// ELT LLENA STOP ON

// DESPUES DE HABER CERRADO CERRADO INMEDIATO(ELT LLENADO STOP) EL T1 ESPERA
// QUE EL PISTON LLEGE HACIA ADELANTE 
TIEMPO_1 = 100;     // 1SEC

// DESPUES DE LA CONFIRMACION(CINTA DETENIDA TAMBIEN) DE M_8 ESTE ACTIVA ALINEADO
// LA CONFIRMACION INDICA MOTOR DETENIDO, AHORA EL TIEMPO_2
// ESPERA A QUE EL PISTON SE EXTIENDA, ES LENTO X LO GRAL
TIEMPO_2 = 400;     // 4SEC

// UNA VEZ EXTENDIDO ALINEADO, LUEGO EN AMBAS PARTES LLENADO Y TAPADO
// BAJAN PARA TRABAJAR, EL TIEMPO3 ESPERA QUE SE EXTIENDAN LOS PISTONES 
TIEMPO_3 = 400;     // 4SEC


//EL TIEMPO 4 Y 5 SON ON Y OFF PARA EL TAPADO DE AIRE, AL SER POCO TIEMPO
// NO HAY NECESIDAD DE INICIAR EL PROCESO DE LLENADO AL MISMO TIEMPO
// PRIMERO TERMINA ESTE PROCESO LUEGO A LLENADO
TIEMPO_4 = 200;     // 2SEC  ON
TIEMPO_5 = 200;     // 2SEC  OFF

// EL TIEMPO 6, UNA VEZ DESCARGAO EL PRODUCTO ESTE ESPERA 2SEC PROMEDIO
// PARA LUEGO SUBIR EL PISTON
TIEMPO_6 = 200;     // 2SEC

// UNA VEZ QUE YA SE TAPO ATRAS EN T5 T6 Y SE HAYA LLENADO EL PRODUCTO
// ESTE LIBERA TODO PARA PODER ENCENDER LA CINTA, EL T7 ESPERA QUE TODOS SE HAYAN REGRESADO
// LOS PISTONES, LUEGO SE ENCIENDE LA CINTA Y HABILITA EL CONTADOR
TIEMPO_7 = 500;     // 5SEC

// ENCIENDE EL MOTOR ON

//AL ENCENDERCE LA CINTA EL T8 ESPERA QUE EL ULTIMO PRODUCTO SALGA, LUEGO
// ESPERA EN T9 PARA RECIBIR Y ACOMODAR LOS NUEVOS PRODUCTOS QUE LLEGAN DE LA LLENADORA

// ESPERA QUE SALGA DE LA TAPADORA LA ULTIMA BOTELLA
TIEMPO_8 = 600;     // 6SEC
// ESPERA QUE SE ACOMODEN LAS BOTELLAS LAS NUEVAS BOTELLAS
TIEMPO_9 = 300;     // 3SEC
//  UNA VEZ QUE SE HAYA ACOMODADO LA OBTELLA EN TAPA ESTE HABILITA PARA PARAR EL MOTOR M8 = 1

*///////////////////
        ///////////////// POR CUENTA DE MOTOR CINTA ESTA DISPLAY = 0 ES MOTOR OFF  /////  DISPLAY = 1 ES MOTOR ON
        DISPLAY_1 = 0 ;                  
        display1.showNumberDecEx(DISPLAY_1,0b01000000, true); // Expect: 0301
        ///////////////// POR CUENTA DE MOTOR CINTA ESTA DISPLAY = 0 ES MOTOR OFF  /////  DISPLAY = 1 ES MOTOR ON         
        RUN_MOTOR = 0;        
        digitalWrite(MOTOR_CINTA,HIGH); // ON LED VERDE  ///////////EMPIEZA ACTIVADO 
        
                    delay(1000);

        RUN_MOTOR = 1;
        ///////////////// POR CUENTA DE MOTOR CINTA ESTA DISPLAY = 0 ES MOTOR OFF  /////  DISPLAY = 1 ES MOTOR ON
        DISPLAY_1 = 1 ;                  
        display1.showNumberDecEx(DISPLAY_1,0b01000000, true); // Expect: 0301
        ///////////////// POR CUENTA DE MOTOR CINTA ESTA DISPLAY = 0 ES MOTOR OFF  /////  DISPLAY = 1 ES MOTOR ON         
        
        digitalWrite(MOTOR_CINTA,LOW); // ON LED VERDE  ///////////EMPIEZA ACTIVADO 

                    
        //delay 1S  para asegurar cambio
        
        BANDERA_MANUAL_INCIO = 1 ;
        BANDERA_AUTOMATIC_INCIO = 0;  


EEPROM.get(30,TIEMPO_1);
EEPROM.get(35,TIEMPO_2);
EEPROM.get(40,TIEMPO_3);
EEPROM.get(45,TIEMPO_4);
EEPROM.get(50,TIEMPO_5);
EEPROM.get(55,TIEMPO_6);
EEPROM.get(60,TIEMPO_7);
EEPROM.get(65,TIEMPO_8);
EEPROM.get(70,TIEMPO_9);

TEMPORAL_TIEMPO_1 = TIEMPO_1;
TEMPORAL_TIEMPO_2 = TIEMPO_2;
TEMPORAL_TIEMPO_3 = TIEMPO_3;
TEMPORAL_TIEMPO_4 = TIEMPO_4;
TEMPORAL_TIEMPO_5 = TIEMPO_5;
TEMPORAL_TIEMPO_6 = TIEMPO_6;
TEMPORAL_TIEMPO_7 = TIEMPO_7;
TEMPORAL_TIEMPO_8 = TIEMPO_8;
TEMPORAL_TIEMPO_9 = TIEMPO_9;

        attachInterrupt(digitalPinToInterrupt(INTERRUPCIONX), INTERRUPCION, RISING );           
          
        }
        
}
////////////////////////////////////////////////

//--------------------------------------------







////////////////////////////////////////////////

//--------------------------------------------
void INC_MENU_1(){ 
  delay (100);
  while  (digitalRead(INC_1) == 0){
  delay (100);
  }
  delay (100);

  if (HORIZONTE_1 == 1) {
    if (UNIDAD_1 != 9) {
    UNIDAD_1++;   
    }
  }

  if(HORIZONTE_1 == 2) {
    if (DECENA_1 != 9) {
    DECENA_1++;   
    }
  }

  if (HORIZONTE_1 == 3) {
    if (CENTENA_1 != 9) {
    CENTENA_1++;   
    }
  }

  if (HORIZONTE_1 == 4) {
    if (MIL_1 != 9) {
    MIL_1++;   
    }
  }

  DISPLAY_1 = (MIL_1 * 1000)+(CENTENA_1 * 100)+(DECENA_1*10)+(UNIDAD_1);    
}
//--------------------------------------------
//--------------------------------------------
void DEC_MENU_1(){ 
  delay (100);
  while  (digitalRead(DEC_1) == 0){
  delay (100);
  }
  delay (100);
  
  if (HORIZONTE_1 == 1) {
    if (UNIDAD_1 != 0) {
    UNIDAD_1--;   
    }
  }

  if (HORIZONTE_1 == 2) {
    if (DECENA_1 != 0) {
    DECENA_1--;   
    }
  }

  if (HORIZONTE_1 == 3) {
    if (CENTENA_1 != 0) {
    CENTENA_1--;   
    }
  }

  if (HORIZONTE_1 == 4) {
    if (MIL_1 != 0) {
    MIL_1--;   
    }
  }

  DISPLAY_1 = (MIL_1 * 1000)+(CENTENA_1 * 100)+(DECENA_1*10)+(UNIDAD_1);    
}
//--------------------------------------------
//--------------------------------------------
void IZQ_MENU_1(){
   delay (100);
  while  (digitalRead(IZQ_1) == 0){
  delay (100);
  }
  delay (100);
  if (HORIZONTE_1 != 4){
    HORIZONTE_1++;
    
  } 
}
//--------------------------------------------
//--------------------------------------------
void DER_MENU_1(){
  delay (100);
  while  (digitalRead(DER_1) == 0){
  delay (100);
  }
  delay (100);  
  if (HORIZONTE_1 != 1){
  HORIZONTE_1--;
  } 
}
//--------------------------------------------
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////

//--------------------------------
void INC_MENU_2(){     
  delay (100);
  while  (digitalRead(INC_2) == 0){
  delay (100);
  }
  delay (100);

  if (HORIZONTE_2 == 1) {
    if (UNIDAD_2 != 9) {
    UNIDAD_2++;   
    }
  }

  if (HORIZONTE_2 == 2) {
    if (DECENA_2 != 9) {
    DECENA_2++;   
    }
  }

  if (HORIZONTE_2 == 3) {
    if (CENTENA_2 != 9) {
    CENTENA_2++;   
    }
  }

  if (HORIZONTE_2 == 4) {
    if (MIL_2 != 9) {
    MIL_2++;   
    }
  }

  DISPLAY_2 = (MIL_2 * 1000)+(CENTENA_2 * 100)+(DECENA_2*10)+(UNIDAD_2);    
}
//--------------------------------

//--------------------------------
void DEC_MENU_2(){ 
  delay (100);
  while  (digitalRead(DEC_2) == 0){
  delay (100);
  }
  delay (100);
  
  if (HORIZONTE_2 == 1) {
    if (UNIDAD_2 != 0) {
    UNIDAD_2--;   
    }
  }

  if (HORIZONTE_2 == 2) {
    if (DECENA_2 != 0) {
    DECENA_2--;   
    }
  }

  if (HORIZONTE_2 == 3) {
    if (CENTENA_2 != 0) {
    CENTENA_2--;   
    }
  }

  if (HORIZONTE_2 == 4) {
    if (MIL_2 != 0) {
    MIL_2--;   
    }
  }

  DISPLAY_2 = (MIL_2 * 1000)+(CENTENA_2 * 100)+(DECENA_2*10)+(UNIDAD_2);    
}
//--------------------------------

//--------------------------------
void IZQ_MENU_2(){
   delay (100);
  while  (digitalRead(IZQ_2) == 0){
  delay (100);
  }
  delay (100);
  if (HORIZONTE_2 != 4){
    HORIZONTE_2++;
    
  } 
}
//--------------------------------

//--------------------------------
void DER_MENU_2(){
  delay (100);
  while  (digitalRead(DER_2) == 0){
  delay (100);
  }
  delay (100);  
  if (HORIZONTE_2 != 1){
  HORIZONTE_2--;
  } 
}
//--------------------------------
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
//--------------------------------
void INC_MENU_3(){     
  delay (100);
  while  (digitalRead(INC_3) == 0){
  delay (100);
  }
  delay (100);

  if (HORIZONTE_3 == 1) {
    if (UNIDAD_3 != 9) {
    UNIDAD_3++;   
    }
  }

  if (HORIZONTE_3 == 2) {
    if (DECENA_3 != 9) {
    DECENA_3++;   
    }
  }

  if (HORIZONTE_3 == 3) {
    if (CENTENA_3 != 9) {
    CENTENA_3++;   
    }
  }

  if (HORIZONTE_3 == 4) {
    if (MIL_3 != 9) {
    MIL_3++;   
    }
  }

  DISPLAY_3 = (MIL_3 * 1000)+(CENTENA_3 * 100)+(DECENA_3*10)+(UNIDAD_3);    
}
//--------------------------------

//--------------------------------
void DEC_MENU_3(){ 
  delay (100);
  while  (digitalRead(DEC_3) == 0){
  delay (100);
  }
  delay (100);
  
  if (HORIZONTE_3 == 1) {
    if (UNIDAD_3 != 0) {
    UNIDAD_3--;   
    }
  }

  if (HORIZONTE_3 == 2) {
    if (DECENA_3 != 0) {
    DECENA_3--;   
    }
  }

  if (HORIZONTE_3 == 3) {
    if (CENTENA_3 != 0) {
    CENTENA_3--;   
    }
  }

  if (HORIZONTE_3 == 4) {
    if (MIL_3 != 0) {
    MIL_3--;   
    }
  }

  DISPLAY_3 = (MIL_3* 1000)+(CENTENA_3*100)+(DECENA_3*10)+(UNIDAD_3);    
}
//--------------------------------

//--------------------------------
void IZQ_MENU_3(){
  delay (100);
  while  (digitalRead(IZQ_3) == 0){
  delay (100);
  }
  delay (100);
  if (HORIZONTE_3 != 4){
    HORIZONTE_3++;
    
  } 
}
//--------------------------------

//--------------------------------
void DER_MENU_3(){
  delay (100);
  while  (digitalRead(DER_3) == 0){
  delay (100);
  }
  delay (100);  
  if (HORIZONTE_3 != 1){
  HORIZONTE_3--;
  } 
}
//--------------------------------
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
//--------------------------------
void INC_MENU_4(){     
  delay (100);
  while  (digitalRead(INC_4) == 0){
  delay (100);
  }
  delay (100);

  if (HORIZONTE_4 == 1) {
    if (UNIDAD_4 != 9) {
    UNIDAD_4++;   
    }
  }

  if (HORIZONTE_4 == 2) {
    if (DECENA_4 != 9) {
    DECENA_4++;   
    }
  }

  if (HORIZONTE_4 == 3) {
    if (CENTENA_4 != 9) {
    CENTENA_4++;   
    }
  }

  if (HORIZONTE_4 == 4) {
    if (MIL_4 != 9) {
    MIL_4++;   
    }
  }

  DISPLAY_4 = (MIL_4 * 1000)+(CENTENA_4 * 100)+(DECENA_4*10)+(UNIDAD_4);    
}
//--------------------------------

//--------------------------------
void DEC_MENU_4(){ 
 delay (100);
  while  (digitalRead(DEC_4) == 0){
  delay (100);
  }
  delay (100);
  
  if (HORIZONTE_4 == 1) {
    if (UNIDAD_4 != 0) {
    UNIDAD_4--;   
    }
  }

  if (HORIZONTE_4 == 2) {
    if (DECENA_4 != 0) {
    DECENA_4--;   
    }
  }

  if (HORIZONTE_4 == 3) {
    if (CENTENA_4 != 0) {
    CENTENA_4--;   
    }
  }

  if (HORIZONTE_4 == 4) {
    if (MIL_4 != 0) {
    MIL_4--;   
    }
  }

  DISPLAY_4 = (MIL_4* 1000)+(CENTENA_4*100)+(DECENA_4*10)+(UNIDAD_4);    
}
//--------------------------------

//--------------------------------
void IZQ_MENU_4(){
  delay (100);
  while  (digitalRead(IZQ_4) == 0){
  delay (100);
  }
  delay (100);
  if (HORIZONTE_4 != 4){
    HORIZONTE_4++;
    
  } 
}
//--------------------------------

//--------------------------------
void DER_MENU_4(){
  delay (100);
  while  (digitalRead(DER_4) == 0){
  delay (100);
  }
  delay (100);  
  if (HORIZONTE_4 != 1){
  HORIZONTE_4--;
  } 
}
//--------------------------------

////////////////////////////////////////////






////////////////////////////////////////////
void SEPARAR_DISPLAY_1_A_CASILLAS(){
TEMP_1 = DISPLAY_1;

CONTADOR_MIL      =0;
CONTADOR_CENTENA  =0;
CONTADOR_DECENA   =0;
CONTADOR_UNIDAD   =0;



MIL_XX:
  if(TEMP_1 >= 1000){
  CONTADOR_MIL++;  
  TEMP_1 = TEMP_1 - 1000;
  goto MIL_XX;
  }
    
  MIL_1 = CONTADOR_MIL;
  
  CENTENA_XX:
    if (TEMP_1 >= 100){
    CONTADOR_CENTENA++;  
    TEMP_1 = TEMP_1 - 100;
    goto CENTENA_XX;  
    }
  
  CENTENA_1 = CONTADOR_CENTENA;
  DECENA_XX:
        if (TEMP_1 >= 10){
        CONTADOR_DECENA++;  
        TEMP_1 = TEMP_1 - 10;
        goto DECENA_XX;       
        }
        DECENA_1 = CONTADOR_DECENA;  
                       
              UNIDAD_1 = TEMP_1;  
              
}

////////////////////////////////////////////

////////////////////////////////////////////
void SEPARAR_DISPLAY_2_A_CASILLAS(){
TEMP_1 = DISPLAY_2;

CONTADOR_MIL      =0;
CONTADOR_CENTENA  =0;
CONTADOR_DECENA   =0;
CONTADOR_UNIDAD   =0;



MIL_XX2:
if (TEMP_1 >= 1000){
  CONTADOR_MIL++;  
  TEMP_1 = TEMP_1 - 1000;
  goto MIL_XX2;
  }
  MIL_2 = CONTADOR_MIL;
  
  CENTENA_XX2:
    if (TEMP_1 >= 100){
    CONTADOR_CENTENA++;  
    TEMP_1 = TEMP_1 - 100;
    goto CENTENA_XX2;  
    }
    CENTENA_2 = CONTADOR_CENTENA;
  
  DECENA_XX2:
        if (TEMP_1 >= 10){
        CONTADOR_DECENA++;  
        TEMP_1 = TEMP_1 - 10;
        goto DECENA_XX2;       
        }
        DECENA_2 = CONTADOR_DECENA;  
                       
              UNIDAD_2 = TEMP_1;  
              
}


////////////////////////////////////////////
void SEPARAR_DISPLAY_3_A_CASILLAS(){
TEMP_1 = DISPLAY_3;

CONTADOR_MIL      =0;
CONTADOR_CENTENA  =0;
CONTADOR_DECENA   =0;
CONTADOR_UNIDAD   =0;



MIL_XX3:
if (TEMP_1 >= 1000){
  CONTADOR_MIL++;  
  TEMP_1 = TEMP_1 - 1000;
  goto MIL_XX3;
  }
  MIL_3 = CONTADOR_MIL;
  
  CENTENA_XX3:
    if (TEMP_1 >= 100){
    CONTADOR_CENTENA++;  
    TEMP_1 = TEMP_1 - 100;
    goto CENTENA_XX3;  
    }
    CENTENA_3 = CONTADOR_CENTENA;
  
  DECENA_XX3:
        if (TEMP_1 >= 10){
        CONTADOR_DECENA++;  
        TEMP_1 = TEMP_1 - 10;
        goto DECENA_XX3;       
        }
        DECENA_3 = CONTADOR_DECENA;  
                       
              UNIDAD_3 = TEMP_1;  
              
}


////////////////////////////////////////////
void SEPARAR_DISPLAY_4_A_CASILLAS(){
TEMP_1 = DISPLAY_4;

CONTADOR_MIL      =0;
CONTADOR_CENTENA  =0;
CONTADOR_DECENA   =0;
CONTADOR_UNIDAD   =0;



MIL_XX4:
if (TEMP_1 >= 1000){
  CONTADOR_MIL++;  
  TEMP_1 = TEMP_1 - 1000;
  goto MIL_XX4;
  }
  MIL_4 = CONTADOR_MIL;
  
  CENTENA_XX4:
    if (TEMP_1 >= 100){
    CONTADOR_CENTENA++;  
    TEMP_1 = TEMP_1 - 100;
    goto CENTENA_XX4;  
    }
    CENTENA_4 = CONTADOR_CENTENA;
  
  DECENA_XX4:
        if (TEMP_1 >= 10){
        CONTADOR_DECENA++;  
        TEMP_1 = TEMP_1 - 10;
        goto DECENA_XX4;       
        }
        DECENA_4 = CONTADOR_DECENA;  
                       
              UNIDAD_4 = TEMP_1;  
              
}


void INTERRUPCION(){
 if (DISPLAY_1 != 0 ){
 DISPLAY_1--;      
 }
 if (DISPLAY_2 != 0 ){
 DISPLAY_2--;   
}
if (DISPLAY_3 != 0 ){
 DISPLAY_3--;   
}
if (DISPLAY_4 != 0 ){
 DISPLAY_4--;   
}

if (t != 0 ){
 t--;   
}
if (t1 != 0 ){
t1--;   
}
if (t2 != 0 ){
t2--;   
}
if (t3 != 0 ){
t3--;   
}
if (t4 != 0 ){
t4--;   
}
if (t5 != 0 ){
t5--;   
}
if (t6 != 0 ){
 t6--;   
}

}








                  
