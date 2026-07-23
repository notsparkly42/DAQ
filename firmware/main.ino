const int PIN_APPS_1 = A0;
const int PIN_APPS_2 = A1;
const int PIN_SALIDA_SEGURIDAD = 13; 

unsigned long tiempoInicioFalla = 0;
bool fallaPersistente = false;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_APPS_1, INPUT);
  pinMode(PIN_APPS_2, INPUT);
  pinMode(PIN_SALIDA_SEGURIDAD, OUTPUT);
  digitalWrite(PIN_SALIDA_SEGURIDAD, HIGH); 
  Serial.println("--- Sistema APPS FSAE Iniciado ---");
}

void loop() {
  int lectura1 = analogRead(PIN_APPS_1);
  int lectura2 = analogRead(PIN_APPS_2);

  float porcentaje_apps1 = (lectura1 / 1023.0) * 100.0;
  float porcentaje_apps2 = (lectura2 / 1023.0) * 100.0;

  float desviacion = abs(porcentaje_apps1 - porcentaje_apps2);

  if (desviacion > 10.0) {
    if (tiempoInicioFalla == 0) {
      tiempoInicioFalla = millis();
    } else if (millis() - tiempoInicioFalla >= 100) {
      fallaPersistente = true;
    }
  } else {
    tiempoInicioFalla = 0;
    fallaPersistente = false;
  }

  if (fallaPersistente) {
    digitalWrite(PIN_SALIDA_SEGURIDAD, LOW);
    Serial.println("ALERTA CRITICA: Desacuerdo APPS > 10% por mas de 100ms - Traccion Cortada");
  } else {
    digitalWrite(PIN_SALIDA_SEGURIDAD, HIGH);
  }

  delay(10);
}
