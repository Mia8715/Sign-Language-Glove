// Pines de los segmentos del Display (A-G)
int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int F = 7;
int G = 8;

// Variables para los grados de cada dedo
int dedo1, dedo2, dedo3, dedo4, dedo5;

void setup() { 
  Serial.begin(9600);
  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {
  // 1. Leer y mapear los 5 sensores flex (Recuerda poner aquí tus valores de calibración)
  dedo1 = map(analogRead(A0), 787, 389, 0, 180); // Pulgar
  dedo2 = map(analogRead(A1), 787, 389, 0, 180); // Índice
  dedo3 = map(analogRead(A2), 787, 389, 0, 180); // Medio
  dedo4 = map(analogRead(A3), 787, 389, 0, 180); // Anular
  dedo5 = map(analogRead(A4), 787, 389, 0, 180); // Meñique

  int umbral = 90;

  // 2. Reconocimiento automático de señas
  // NÚMERO 1: Solo Índice abierto
  if (dedo1 > umbral && dedo2 < 40 && dedo3 > umbral && dedo4 > umbral && dedo5 > umbral) {
    mostrarNumero(1);
  }
  // NÚMERO 2: Índice y Medio abiertos
  else if (dedo1 > umbral && dedo2 < 40 && dedo3 < 40 && dedo4 > umbral && dedo5 > umbral) {
    mostrarNumero(2);
  }
  // NÚMERO 3: Pulgar, Índice y Medio abiertos
  else if (dedo1 < 40 && dedo2 < 40 && dedo3 < 40 && dedo4 > umbral && dedo5 > umbral) {
    mostrarNumero(3);
  }
  // NÚMERO 4: Todos abiertos excepto el Pulgar
  else if (dedo1 > umbral && dedo2 < 40 && dedo3 < 40 && dedo4 < 40 && dedo5 < 40) {
    mostrarNumero(4);
  }
  // NÚMERO 5: Todos los dedos cerrados (Puño)
  else if (dedo1 < umbral && dedo2 < umbral && dedo3 < umbral && dedo4 < umbral && dedo5 < umbral) {
    mostrarNumero(5);
  }
  // NÚMERO 6: Pulgar y Meñique cerrados, el resto abiertos
  else if (dedo1 > umbral && dedo2 < 40 && dedo3 < 40 && dedo4 < 40 && dedo5 > umbral) {
    mostrarNumero(6);
  }
  // NÚMERO 7: Pulgar y Anular cerrados, el resto abiertos
  else if (dedo1 > umbral && dedo2 < 40 && dedo3 < 40 && dedo4 > umbral && dedo5 < 40) {
    mostrarNumero(7);
  }
  // NÚMERO 8: Pulgar y Medio cerrados, el resto abiertos
  else if (dedo1 > umbral && dedo2 < 40 && dedo3 > umbral && dedo4 < 40 && dedo5 < 40) {
    mostrarNumero(8);
  }
  // NÚMERO 9: Pulgar e Índice cerrados, el resto abiertos
  else if (dedo1 > umbral && dedo2 > umbral && dedo3 < 40 && dedo4 < 40 && dedo5 < 40) {
    mostrarNumero(9);
  }

  delay(100); // Pequeña pausa para evitar parpadeos y estabilizar lecturas
}

void mostrarNumero(int num) {
  switch (num) {
    case 1:
      digitalWrite(A, LOW);  digitalWrite(B, HIGH); digitalWrite(C, HIGH);
      digitalWrite(D, LOW);  digitalWrite(E, LOW);  digitalWrite(F, LOW);  digitalWrite(G, LOW);
      break;
    case 2:
      digitalWrite(A, HIGH); digitalWrite(B, HIGH); digitalWrite(C, LOW);
      digitalWrite(D, HIGH); digitalWrite(E, HIGH); digitalWrite(F, LOW);  digitalWrite(G, HIGH);
      break;
    case 3:
      digitalWrite(A, HIGH); digitalWrite(B, HIGH); digitalWrite(C, HIGH);
      digitalWrite(D, HIGH); digitalWrite(E, LOW);  digitalWrite(F, LOW);  digitalWrite(G, HIGH);
      break;
    case 4:
      digitalWrite(A, LOW);  digitalWrite(B, HIGH); digitalWrite(C, HIGH);
      digitalWrite(D, LOW);  digitalWrite(E, LOW);  digitalWrite(F, HIGH); digitalWrite(G, HIGH);
      break;
    case 5:
      digitalWrite(A, HIGH); digitalWrite(B, LOW);  digitalWrite(C, HIGH);
      digitalWrite(D, HIGH); digitalWrite(E, LOW);  digitalWrite(F, HIGH); digitalWrite(G, HIGH);
      break;
    case 6:
      digitalWrite(A, HIGH); digitalWrite(B, LOW);  digitalWrite(C, HIGH);
      digitalWrite(D, HIGH); digitalWrite(E, HIGH); digitalWrite(F, HIGH); digitalWrite(G, HIGH);
      break;
    case 7:
      digitalWrite(A, HIGH); digitalWrite(B, HIGH); digitalWrite(C, HIGH);
      digitalWrite(D, LOW);  digitalWrite(E, LOW);  digitalWrite(F, LOW);  digitalWrite(G, LOW);
      break;
    case 8:
      digitalWrite(A, HIGH); digitalWrite(B, HIGH); digitalWrite(C, HIGH);
      digitalWrite(D, HIGH); digitalWrite(E, HIGH); digitalWrite(F, HIGH); digitalWrite(G, HIGH);
      break;
    case 9:
      digitalWrite(A, HIGH); digitalWrite(B, HIGH); digitalWrite(C, HIGH);
      digitalWrite(D, HIGH); digitalWrite(E, LOW);  digitalWrite(F, HIGH); digitalWrite(G, HIGH);
      break;
  }
}