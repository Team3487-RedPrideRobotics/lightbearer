#include "FastLED.h"
#include "pixeltypes.h"
#define RGB_PIN           6              // LED DATA PIN
#define RGB_LED_NUM    92           // 10 LEDs [0...9]
#define BRIGHTNESS       150           // brightness range [0..255]
#define CHIP_SET       WS2812B      // types of RGB LEDs
#define COLOR_CODE    GRB          //sequence of colors in data stream

// Define the array of LEDs
CRGB LEDs[RGB_LED_NUM];
uint8_t hue = 0;

#define UPDATES_PER_SECOND 100

byte iByte = 0x49;
int j = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("WS2812B LEDs strip Initialize");
  Serial.println("Please enter value.");
  FastLED.addLeds<CHIP_SET, RGB_PIN, COLOR_CODE>(LEDs, RGB_LED_NUM).setCorrection(TypicalLEDStrip);
  randomSeed(analogRead(0));
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();

}
// 
void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    iByte = Serial.read();
  }
  if(iByte == 0x49){
    Disabled(50, j);
  } else if(iByte == 0x42){
      Alliance(false);
  } else if(iByte == 0x52){
      Alliance(true);
  } else if(iByte == 0x53){
    FastLED.clear();
    FastLED.show();
  } else if(iByte == 0x43){
    Celebrate();  
  } else if(iByte == 0x50){
        GamePiece(true);
  } else if(iByte == 0x59){
        GamePiece(false);
  }
   j++;
   delay(50);

  
}
