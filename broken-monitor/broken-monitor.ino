#include <Adafruit_NeoPixel.h>

#define PIN TX
#define NUM_PIXELS_ALL 27
#define NUM_PIXELS_MON_01 15
#define NUM_PIXELS_MON_02 12

#define SPEED 5

#define RAND_MON_01 30
#define RAND_MON_02 20

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS_ALL, PIN, NEO_GRB + NEO_KHZ800);
int LED_STATS[NUM_PIXELS_ALL];

int stay_mon01 = 0;
int stay_mon01_current = 0;

int stay_mon02 = 0;
int stay_mon02_current = 0;

void setup() {
  Serial.begin(9600);
  strip.begin();
  clearMon01();
  clearMon02();
  randomSeed(analogRead(0));
  delay(1000);
}


void loop() {
  mon01();
  mon02();
  strip.show();
  delay(SPEED);
}

void mon01() {
  if (stay_mon01 > stay_mon01_current) {
    stay_mon01_current++;
  } else {
    if (random(0, RAND_MON_01) == RAND_MON_01 - 1) {
      for (int count = 0; count < NUM_PIXELS_MON_01; count++) {
        if (random( 0, 5) > 2) {
          strip.setPixelColor(count, 0, 0, 0);
        } else {
          int brightness = random (5, 110);
          if (random(0,40) > 37) {
            strip.setPixelColor(count, brightness, brightness, brightness);
          } else {
            strip.setPixelColor(count, 0, brightness, 0);
          }
        }
      }
      int state = random(0,10);
      
      if (state <= 3) {
        stay_mon01 = random(2, 20); 
      } else if (state <= 7) {
        stay_mon01 = random(10, 60);
      } else if (state <= 9) {
        stay_mon01 = random(20, 90);
      } else if (state <= 10) {
        stay_mon01 = random(100, 200);
      }
      
      stay_mon01_current = 0;
    } else {
      clearMon01();
    }
  }
}

void mon02() {
  if (stay_mon02 > stay_mon02_current) {
    stay_mon02_current++;
  } else {
    if (random(0, RAND_MON_02) == RAND_MON_02 - 1) {
      for (int count = NUM_PIXELS_MON_01; count < NUM_PIXELS_ALL; count++) {
        if (random( 0, 5) > 2) {
          strip.setPixelColor(count, 0, 0, 0);
        } else {
          int brightness = random (5, 110);
          if (random(0,40) > 37) {
            strip.setPixelColor(count, brightness, brightness, brightness);
          } else {
            strip.setPixelColor(count, 0, brightness, 0);
          }
        }
      }
      int state = random(0,10);
      
      if (state <= 3) {
        stay_mon02 = random(2, 20); 
      } else if (state <= 7) {
        stay_mon02 = random(10, 60);
      } else if (state <= 9) {
        stay_mon02 = random(20, 90);
      } else if (state <= 10) {
        stay_mon02 = random(100, 200);
      }
      
      stay_mon02_current = 0;
    } else {
      clearMon02();
    }
  }
}


void clearMon01() {
  for (int i = 0; i < NUM_PIXELS_MON_01; i++){
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
  }
}


void clearMon02() {
  for (int i = NUM_PIXELS_MON_01; i < NUM_PIXELS_MON_02; i++){
    strip.setPixelColor(i, 0, 0, 0);
    strip.show();
  }
}
