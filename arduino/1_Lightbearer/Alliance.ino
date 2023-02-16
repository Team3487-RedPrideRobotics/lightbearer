void Alliance(bool red){
  if(red){
    for(int i=0; i < RGB_LED_NUM; i++) {
      LEDs[RGB_LED_NUM - 1 - i].setRGB(255, 0, 0);
    }
  }else{
    for(int i=0; i < RGB_LED_NUM; i++) {
      LEDs[RGB_LED_NUM - 1 - i].setRGB(0, 0, 255);
    }
  }
  FastLED.show();
}
