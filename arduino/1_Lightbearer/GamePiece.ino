void GamePiece(bool cube){
  if(cube){
    for(int i=0; i < RGB_LED_NUM; i++) {
      LEDs[RGB_LED_NUM - 1 - i].setRGB(204, 51, 255);
    }
  }else{
    for(int i=0; i < RGB_LED_NUM; i++) {
      LEDs[RGB_LED_NUM - 1 - i].setRGB(224, 75, 0);
    }
  }
  FastLED.show();  
}
