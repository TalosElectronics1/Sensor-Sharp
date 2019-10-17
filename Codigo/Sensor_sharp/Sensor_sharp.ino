/*
 * Ing Rafael Lozano Rolon
 * www.taloselectronics.com
 */
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27, 16, 2); //

void setup() {
  // Comunicación seria a 9600 baudios
  Serial.begin(9600);
  // Inicializar el LCD
  lcd.init();
  //Encender la luz de fondo.
  lcd.backlight();
}


void loop() {

  int D_cm = distancia(40); //lectura de distancia promedio de 40

  lcd.setCursor(0, 0);//ir a la posicion x0,y0
  lcd.print(D_cm);//imprimir la distancia 
  lcd.print("cm  ");
  delay(100);//Esperar 100ms antes de medir de nuevo
}

float distancia(int muestras)
{
  long suma = 0;
  for (int i = 0; i < muestras; i++)
  {
    suma = suma + analogRead(A0);
  }
  float adc = suma / muestras;//Promedio de lectura ADC
  float distancia_cm = 17569.7 * pow(adc, -1.2062);
  return (distancia_cm);
}
