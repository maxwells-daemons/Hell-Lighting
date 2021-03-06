#include "pattern_colorwheel.h"

void Pattern_Colorwheel::init() {
    clearLEDs();
    FastLED.setBrightness(BRIGHTNESS_MAX);
    pos = 0;
}

void Pattern_Colorwheel::loop() {
    for (int i = 0; i < NUM_LEDS_TOTAL; i++) {
      leds[transform(i)] = CHSV(map(i + pos, 0, NUM_LEDS_TOTAL, 0, 255), 255, 255);
    }

    pos += map(analogRead(PIN_POT), POT_MAX, 0, 0, 250);
    if (pos >= NUM_LEDS_TOTAL) pos -= NUM_LEDS_TOTAL;
    FastLED.show();
    delay(10);
}
