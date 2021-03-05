/* Codigo de prueba, modificado a partir de CODIGO_RC 03-03-2021
 *  Funciones del codigo:
 *    Indicar el estado de conexion bluetooth. Con Led y Buzzer
 *  
 *  
 *  
 FALTA AÑADIR EL CODIGO DEL SENSOR DE PROXIMIDAD
 MODIFICAR LO QUE TIENE QUE HACER EL ALTAVOZ Y EL LED
 PERO EL CODIGO DE ESTAS DOS COSAS ESTA YA DENTRO CON OTRA FUNCION
*/

/*********** Pins & Variables **************/

 
// Leds RGB connected to Arduino UNO IN  PIN R G B
  const int R = 3;
  const int G = 5;
  const int B = 6;   
     
//Bluetooth (HC-05) State pin on pin 2 of Arduino
  const int BTState = 2;
   //lectura estado bluetooth
  int state= 'P';
  
// Buzzer pin 7, lib and var
  const int buzzer = 7 ;
  #include "pitches.h"
  // notes in the melody:
  int connecting_melody[] = {NOTE_D5, NOTE_C5,  NOTE_E5};
  int disconnecting_melody[] = {NOTE_D5, NOTE_C5,  NOTE_B5};
  int duration = 400;  // 400 miliseconds

//Useful Variables
  int i=0;
  int BluetoothConnectionState;
  int WasItConnected = false;
 


/************** SETUP LOOP **********/

void setup() {
    // Set pins as outputs:
    pinMode(R, OUTPUT); 
    pinMode(G, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(BTState, INPUT);    
    
    // Initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}


/*************** MAIN LOOP **************/

void loop() {

  // Read BTState to know if bluetooth is connected.
    BluetoothConnectionState = digitalRead(BTState); // High/Low (1/0)

    state = Serial.read();

  // When NOT connected:
  if(BluetoothConnectionState == 0) {

    // Set Led to red 
      analogWrite(R, 0);
      analogWrite(G, 0);
      analogWrite(B, 0);
      delay(200);
      

    // if disconnected:
      if(WasItConnected == true) {

        // Play disconecting sound
          for (int thisNote = 0; thisNote < 3; thisNote++) {
          // pin7 output the voice, every scale is 0.4 sencond
            tone(buzzer, disconnecting_melody[thisNote], duration);
          // Output the voice after several minutes
            delay(500);
            noTone(buzzer);
          }

        // New value for variable
          WasItConnected = false;
      }
    
  }

  // When already connected:
  if (BluetoothConnectionState == 1) {
    
              if(state='F'  || state='B'  state='L' || state='R' || state='G' || state='I' || state='H' || state='J' ){
            analogWrite(R, 255);
            analogWrite(G, 0);
            analogWrite(B, 0);
            delay(1000);
            analogWrite(R, 0);
            analogWrite(G, 0);
            analogWrite(B, 0);
            delay(1000);
              }
              else {
                analogWrite(R, 0);
                analogWrite(G, 255);
                analogWrite(B, 0);
                
              }

    // When first time connecting:
      if(WasItConnected == false) {
         if(state='F'  || state='B'  state='L' || state='R' || state='G' || state='I' || state='H' || state='J' ){
            analogWrite(R, 255);
            analogWrite(G, 0);
            analogWrite(B, 0);
            delay(1000);
            analogWrite(R, 0);
            analogWrite(G, 0);
            analogWrite(B, 0);
            delay(1000);
              }
              else {
                analogWrite(R, 0);
                analogWrite(G, 255);
                analogWrite(B, 0);
        
        // Play conecting sound
          for (int thisNote = 0; thisNote < 3; thisNote++) {
          // pin7 output the voice, every scale is 0.4 sencond
            tone(buzzer, connecting_melody[thisNote], duration);
          // Output the voice after several minutes
            delay(500);
            noTone(buzzer);
          }

        /

        // New value to variable
          WasItConnected = true;

          
            
      }
  }


/**************************************************/

  

    
/*
    
  //Stop car when connection lost or bluetooth disconnected
     if(digitalRead(BTState) == LOW) { state = 'y'; }

        Serial.print(digitalRead(BTState));
        
        
        
 //sonido READY TO DRIVE
     if (state == 'P'){
      
          for (int thisNote = 0; thisNote < 8; thisNote++) {
          // pin7 output the voice, every scale is 0.3 sencond
            tone(buzzer, melody[thisNote], duration);
          // Output the voice after several minutes
            delay(1000);
            noTone(buzzer);
          }
          
      state='n';  
    }

  //Save income data to variable 'state'
    if(Serial.available() > 0){     
      state = Serial.read();   
    }

   // TSAL
    if (state == 'P'){
      analogWrite(R, 0);
      analogWrite(G, 255);
      analogWrite(B, 0);
      }
    else if (state == 'n'){     //color VERDE
      analogWrite(R, 0);
      analogWrite(G, 255);
      analogWrite(B, 0);
      }
    else  {
      analogWrite(R, 255);
      analogWrite(G, 0);
      analogWrite(B, 0);            //color ROJO parpadeando a 2HZ
      delay(500);
      analogWrite(R, 255);
      analogWrite(G, 0);
      analogWrite(B, 0);
      }
    
         
  //Change speed if state is equal from 0 to 4. Values must be from 0 to 255 (PWM)
    if (state == '0'){
      vSpeed=0;}
    else if (state == '1'){
      vSpeed=100;}
    else if (state == '2'){
      vSpeed=180;}
    else if (state == '3'){
      vSpeed=200;}
    else if (state == '4'){
      vSpeed=255;}


 // Parte de mandar la informacion de state a motortes(H-bridge y servo)

          /****** FALTA ****/

 //

  
  /**********************Horn sound***************************/
 
  /************************Stop*****************************/
  
  /***********************Battery*****************************/
  
}
