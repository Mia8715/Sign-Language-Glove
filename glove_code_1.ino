void setup() {
  Serial.begin(9600); // Inicia la comunicación con la computadora
}

void loop() {
  // Leemos el valor bruto (de 0 a 1023) que da cada sensor analógico
  int val1 = analogRead(A0);
  int val2 = analogRead(A1);
  int val3 = analogRead(A2);
  int val4 = analogRead(A3);
  int val5 = analogRead(A4);

  // Imprimimos los valores en el Monitor Serial separados por tabulaciones
  Serial.print("D1: "); Serial.print(val1); Serial.print("\t");
  Serial.print("D2: "); Serial.print(val2); Serial.print("\t");
  Serial.print("D3: "); Serial.print(val3); Serial.print("\t");
  Serial.print("D4: "); Serial.print(val4); Serial.print("\t");
  Serial.print("D5: "); Serial.println(val5);

  delay(200); // Pequeña pausa para poder leer los números en la pantalla
}