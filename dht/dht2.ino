/*
 * Lectura simple de sensor DHT11 a ESP32-CAM
 * Por: Paloma Vilchis
 * Fecha: 03 de agosto de 2021
 * Modificado por: Gabriel Espinosa Burguete
 * 
 * Este programa imprime valores de temperatura capturados
 * por el DHT11 tanto en Fahrenheit como Celsius. El fin
 * de este ejercicio es que se integré con otros programas
 * para ampliarlo a un dashboard de node-red.
 * 
 * El único pin usado del ESP32-CAM es el GPIO 12 para
 * recibir los valores de temperatura.
 * 
 * Componente     PinESP32CAM
 * DHTPIN-----------GPIO 12
 */
#include "DHT.h"
#define DHTPIN 12   // Pin de ESP32-CAM a usar
#define DHTTYPE DHT11   // Tipo de DHT a usar

// Instancia de DHT para inicializarlo
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200); // Transmision de datos a 115200 bps

  // Se imprime mensaje de inicio, la funcion F() crea un tipo de dato especial
  // que se carga desde memoria FLASH y ocupa menos recursos. Más info:
  // https://www.aranacorp.com/es/anadir-la-funcion-f-a-un-archivo-ino-con-python/
  // https://forum.arduino.cc/t/what-does-the-f-do-exactly/89384/5
  Serial.println(F("Prueba de coenxion")); 

  dht.begin(); // Inicializa el dht
}

void loop() {
  delay(2000); // Retraso de 2s para no perder lecturas

  float t = dht.readTemperature(); // Lee y almacena la temperatura en Celsius
  float f = dht.readTemperature(true); // Lee y almacena la temperatura en Fahrenheit
  
  // En caso de leer nada, se imprime mensaje de que no hay conexion y reinicia ciclo
  if ( isnan(t) || isnan(f)) {
    Serial.println(F("No hay conexion"));
    return;
  }

 
  // Imprime mensajes con respectivos valores de temperatura
  Serial.print(F("Temperatura en °C: "));
  Serial.println(t);
  Serial.print(F("Temperatura en °F: "));
  Serial.println(f);
  
}
