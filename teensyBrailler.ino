#include <Bounce2.h>
#define NUM_BUTTONS 10
#define NUM_FINGERS 5

#define LEFT_HANDED TRUE

#define UP LOW          //Swap these if the buttons are pull down
#define DOWN HIGH

Bounce brailleCells[NUM_BUTTONS];

void setup() {
  //We assume Pin 6 (teensy++ LED) is available via a 1K pullup
  for (i = 0; i < NUM_BUTTONS; i = i + 1) {
    brailleCells[i] = Bounce();
    brailleCells[i].attach(i);
    brailCells[i].interval(5);
    pinMode(i, INPUT_PULLUP);
  }
}

void loop() {
  for (i=0; i< NUM_BUTTONS; i=i+1) {
    brailleCells[i].update();
    
    
    
