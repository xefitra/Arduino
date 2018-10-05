//Script .ino para sensar posición con encoder incremental de 600 p/r
float temp, counter = 0;
int sentido = 0;
String sent;
float theta = 0;

void setup() {
  Serial.begin (9600);

  pinMode(2, INPUT_PULLUP); // Pin de entrada, cable blanco del encoder
  
  pinMode(3, INPUT_PULLUP); // Pin de entrada, cable verde del encoder

/*  En este caso se utiliza solo uno de los pines pues queremos evaluar la posición, 
 *  al utilizar los dos se tendría más resolución pero para la aplicación que se 
 *  planea esta resolución esta bien, posterior a este script estará uno para realizar 
 *  la medición de velocidad angular "omega" en el cual se medirá el tiempo entre interrupciones
 *  para calcular omega = theta/tiempo, theta = pasos * 2*pi / 600


*/
  attachInterrupt(0, ai0, RISING);
   
//  attachInterrupt(1, ai1, RISING);
  }
   
  void loop() {
  // Seteando el valor del contador
  if( counter != temp ){
  Serial.println (theta);

  // Si se quiere imprimir el sentido de giro se proponen las variables sentido y sent.
  
//  if(sentido==1)
//  {
//    sent = "Horario";
//    }
//    else
//    {
//      sent = "Antihorario";
//      }
//  Serial.println(sent);

  temp = counter;
  }
  }
   
  void ai0() {
  if(digitalRead(3)==LOW) {
  counter++;
  sentido=0;
  }else{
  counter--;
  sentido=1;
  }
  theta = (counter * 2 * 3.1416) / 600;
  }

