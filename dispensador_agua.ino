const int trigPin = 9;
const int echoPin = 10;
const int trigPinDos = 13;
const int echoPinDos = 12;
const int ledPrincipal = 11;
const int buzzerPin = 7;
const int pumpPin = 3;

long duracion;
long duracionDos;
int distancia;
int distanciaDos;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPinDos, OUTPUT);
  pinMode(echoPinDos, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  pinMode(ledPrincipal, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(pumpPin, LOW);
  Serial.begin(9600);
}

void loop() {
  // Generar un pulso en el pin del sensor ultrasónico

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duracion = pulseIn(echoPin, HIGH);

  

  distancia = duracion * 0.034 / 2;
  


  delay(100);

  digitalWrite(trigPinDos, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinDos, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinDos, LOW);
  duracionDos = pulseIn(echoPinDos, HIGH);

  

  distanciaDos = duracionDos * 0.034 / 2;
  
  
  while(distancia <= 5){
    digitalWrite(buzzerPin, HIGH);
    tone(pumpPin, 1600);
    digitalWrite(ledPrincipal, HIGH);
    if(distanciaDos <= 15){
      
      digitalWrite(buzzerPin, LOW);
      digitalWrite(pumpPin, LOW);  
      digitalWrite(ledPrincipal, LOW);
      delay(10000);
      break;
    }
    break;
  }
   
}
