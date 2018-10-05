//Script .ino para sensar posición con encoder incremental de 600 p/r
float temp, counter = 0;
    
void setup() {
  Serial.begin (9600);

  pinMode(2, INPUT_PULLUP); // Pin de entrada, cable blanco del encoder
  
  pinMode(3, INPUT_PULLUP); // Pin de entrada, cable verde del encoder
  // Para calcular los pasos se procede a establecer funciones de interupccion en los pines de entrada
  
  attachInterrupt(0, ai0, RISING);
   
//  attachInterrupt(1, ai1, RISING);
  }
   
  void loop() {
  // Seteando el valor del contador
  if( counter != temp ){
  Serial.println (counter);
  temp = counter;
  }
  }
   
  void ai0() {
  // Se activa la funcion por la señal en el pin 2
  // Se verifica la condicion del pin 3 pra establecer la direccion
  if(digitalRead(3)==LOW) {
  counter++;
  }else{
  counter--;
  }

  }
   
//  void ai1() {
//  // Se activa la funcion por la señal en el pin 3 
//  // Se verifica la condicion del pin 2 para establecer la direccion
//  if(digitalRead(2)==LOW) {
//  counter--;
//  }else{
//  counter++;
//  }
// }
