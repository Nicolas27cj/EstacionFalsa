#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

float tempdht;
float humedad;
float presion;
float tempat;
float humat;
void setup() {
  // put your setup code here, to run once:

}
void ImagenWifi(uint16_t color) {
  // Coordenadas del símbolo WiFi
  int x = tft.width() - 10;
  int y = 0;

  
  tft.fillRect(x, y, 10, 10, TFT_BLACK);    // Borra el área del símbolo antes de dibujarlo 

  // Dibuja un símbolo de WiFi simple usando líneas y arcos dentro de un área de 10x10
  tft.drawPixel(x + 5, y + 8, color);                  // Punto central (señal)       
  tft.drawLine(x + 3, y + 6, x + 7, y + 6, color);     // Primera línea
  tft.drawLine(x + 2, y + 4, x + 8, y + 4, color);     // Segunda línea
  tft.drawLine(x + 1, y + 2, x + 9, y + 2, color);     // Tercera línea
}

void TemAmbiente(){
  
  tempdht = 28.7;
  humedad = 51;
  presion = 1011;
  tft.setTextColor(TFT_RED);
  tft.setCursor(26, 55);
  tft.setTextFont(7);
  tft.print(tempdht);

  tft.setTextColor(TFT_ORANGE);
  tft.setCursor(26, 150);
  tft.setTextFont(4);
  tft.print("Hum: ");
  tft.print(humedad);
  tft.println("%");

  tft.setTextColor(TFT_VIOLET);
  tft.setCursor(26, 180);
  tft.setTextFont(4);
  tft.print("hPa: ");
  tft.print(presion, 2);
}

void Atmosferico(){
  humat = 30;
  tempat = 33;
  tft.setTextColor(TFT_GREEN);
  tft.setCursor(47, 15);       
  tft.setTextFont(4);
  tft.print("TEMPERLEY");
  tft.setTextColor(TFT_ORANGE);
  tft.setCursor(26, 150);
  tft.setTextFont(4);
  tft.print("Humedad: ");
  tft.print(humat);
  tft.println("%");
  tft.setTextColor(TFT_RED);
  tft.setCursor(26, 55);
  tft.setTextFont(7);
  tft.print(tempat);
  delay(10000);
 
}
void loop() {
 ImagenWifi(TFT_GREEN);
 TemAmbiente();
 delay(10000);
 Atmosferico();

}
