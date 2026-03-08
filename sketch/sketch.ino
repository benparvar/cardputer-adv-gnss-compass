#include <M5Cardputer.h>
#include <TinyGPSPlus.h>

TinyGPSPlus gps;
HardwareSerial GNSS(1);

float headingFiltered = 0;

void setup() {

  auto cfg = M5.config();
  M5Cardputer.begin(cfg);

  Serial.begin(115200);

  GNSS.begin(9600, SERIAL_8N1, 18, 17);

  M5.Display.setRotation(1);
}

void loop() {

  while (GNSS.available()) {
    gps.encode(GNSS.read());
  }

  if (gps.course.isValid()) {

    float heading = gps.course.deg();

    // filtro para suavizar
    headingFiltered = headingFiltered * 0.8 + heading * 0.2;

    drawCompass(headingFiltered);

  }

}

void drawCompass(float heading){

  M5.Display.fillScreen(BLACK);

  int cx = 120;
  int cy = 70;
  int r = 50;

  M5.Display.drawCircle(cx,cy,r,WHITE);

  float rad = radians(heading);

  int x = cx + r * sin(rad);
  int y = cy - r * cos(rad);

  M5.Display.drawLine(cx,cy,x,y,RED);

  M5.Display.setCursor(10,10);
  M5.Display.printf("Heading: %.1f",heading);

}