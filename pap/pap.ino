// Código para el control de motor pap utilizando el driver A4988 y un motor Nema 17 de 1.8° y 0,4 amperios

const int dirPin = 9;
const int stepPin = 13;
 
const int steps = 400;
int microPausa = 1000;
void setup() {
 pinMode(dirPin, OUTPUT);
 pinMode(stepPin, OUTPUT);
}
 
void loop() {
 digitalWrite(dirPin, HIGH);  // Establezco una dirección

 for (int x = 0; x < steps; x++) {
   digitalWrite(stepPin, HIGH);
   delayMicroseconds(microPausa);
   digitalWrite(stepPin, LOW);
   delayMicroseconds(microPausa);
 }
 delay(200);
 
 digitalWrite(dirPin, LOW);  // Cambio la dirección

 for(int x = 0; x< steps ; x++) {
   digitalWrite(stepPin, HIGH);
   delayMicroseconds(microPausa);
   digitalWrite(stepPin, LOW);
   delayMicroseconds(microPausa);
 }
 delay(200);

}
