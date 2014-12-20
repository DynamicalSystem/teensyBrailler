#include <Bounce2.h>
#define NUM_BUTTONS 10
#define NUM_FINGERS 5

#define LEFT_HANDED TRUE

Bounce brailleCells[NUM_BUTTONS];

void setup() {
  //We assume Pin 6 (teensy++ LED) is available via a 1K pullup
  for (int i = 0; i < NUM_BUTTONS; i = i + 1) {
    brailleCells[i] = Bounce();
    brailleCells[i].attach(i);
    brailleCells[i].interval(5);
    pinMode(i, INPUT_PULLUP);
  }
}

void loop() {
  String down = "Down : ";
  String up = "Up   : ";
  
  for (int i = 0; i < NUM_BUTTONS; i = i + 1) {
    brailleCells[i].update();
    if (brailleCells[i].fell()){
      Keyboard.println(down + i);
    }
    if (brailleCells[i].rose()) {
      Keyboard.println(up + i);
    }
  }
}
