//Script .ino para sensar posición con encoder incremental de 600 p/r
float temp, counter = 0;
int pasos = 0;
int pasosAnt = 0;
int sentido;
String sent;
float theta = 0;
const int dirPin = 9;
const int stepPin = 13;
int dif;

int microPause = 1000;

void setup()
  {
    Serial.begin (9600);
    pinMode(2, INPUT_PULLUP); // Pin de entrada, cable blanco del encoder
    pinMode(3, INPUT_PULLUP); // Pin de entrada, cable verde del encoder

    pinMode(dirPin,OUTPUT);
    pinMode(stepPin,OUTPUT);

    attachInterrupt(0, ai0, RISING);
    attachInterrupt(1, ai1, RISING);
  }

  void loop()
  {
    pasos = (theta * 200) / (3.1416);
    
    
    if( counter != temp )
    {
      Serial.println (theta);
      Serial.println(pasos);
    }
    
    pasosAnt = pasos;
    temp = counter;
  }

  void ai0()
  {

    if(digitalRead(3)==LOW)
    {
      counter++;
      sentido=0;
    }
    else
    theta = (counter * 2 * 3.1416) / 600;


    pasos = (theta * 200) / (3.1416);
    if (sentido == 0)
        {
         antihorario();
        }
    else
        {
         horario();
        }
    temp = counter;
  }

  void ai1()
  {
    if(digitalRead(2)==LOW)
    {
      counter--;
      sentido = 1;
    }
    theta = (counter * 2 * 3.1416) / 600;

        pasos = (theta * 200) / (3.1416);
    if (sentido == 0)
        {
         antihorario();
        }
    else
        {
         horario();
        }
        temp = counter;
  }

  void horario()
  {
    digitalWrite(dirPin,HIGH);
    for (int x = pasosAnt; x<= pasos; x++)
    {
     digitalWrite(stepPin, HIGH);
     delayMicroseconds(microPause);
     digitalWrite(stepPin, LOW);
     delayMicroseconds(microPause);
    }
  }

  void antihorario()
  {
    digitalWrite(dirPin,LOW);
    for (int x = pasos; x <= pasosAnt; x--)
    {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(microPause);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(microPause);
    }
  }
