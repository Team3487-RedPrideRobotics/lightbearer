void Disabled(int DelayDuration, int position) {
  byte *c;
  uint16_t i;

    for(i=0; i < RGB_LED_NUM; i++) {
      c = Wheel(((i * 256 / RGB_LED_NUM) + position) & 255);
      LEDs[RGB_LED_NUM - 1 - i].setRGB(*c, *(c+1), *(c+2));
    }
    FastLED.show();
   
}

byte *Wheel(byte WheelPosition) {
  static byte c[3];
 
  if(WheelPosition < 85) {
   c[0] = WheelPosition * 3;
   c[1] = 255 - WheelPosition * 3;
   c[2] = 0;
  }
  else if(WheelPosition < 170) {
   WheelPosition -= 85;
   c[0] = 255 - WheelPosition * 3;
   c[1] = 0;
   c[2] = WheelPosition * 3;
  }
  else {
   WheelPosition -= 170;
   c[0] = 0;
   c[1] = WheelPosition * 3;
   c[2] = 255 - WheelPosition * 3;
  }

  return c;
}
