// include the library code:
#include "config.h"
#include "gfx.h"

long timer = 0;
byte displayMemory[8];
int k;

void setup() {
  pinMode(REG_LATCH, OUTPUT);
  pinMode(REG_CLOCK, OUTPUT);
  pinMode(REG_DATA, OUTPUT);
  
  k = 4;
  
  loadToMemory(testImg);
}

void loop() {
  if (millis() - timer > 100) {
    timer = millis();
    update();
  }
  drawDisplayMemory();
}

void update()
{ 
  for (int i = 7; i > 0; i--) {
    displayMemory[i] = displayMemory[i - 1];
  }
  int r = random(0,5);
  if (r == 0 && k > 0) k--;
  if (r == 2 && k < 7) k++;
  displayMemory[0] = 1 << k;
}

void drawDisplayMemory()
{
  for (int i = 0; i < 8; i++) {
    displayData(0);
    displayData(0);
    displayData(1 << (7 - i));
    displayData(~displayMemory[i]);
    delay(1);
  }
}

void clearDisplayMemory()
{
  for (int i = 0; i < 8; i++) {
    displayMemory[i] = 0;
  }
}

void setPixel(byte x, byte y, byte p)
{
  if (p > 0) {
    displayMemory[y] = bitSet(displayMemory[y], x);
  } else {
    displayMemory[y] = bitClear(displayMemory[y], x);
  }
}

void loadToMemory(byte data[])
{
  for (int i = 0; i < 8; i++) {
    displayMemory[i] = data[i];
  }
}

void displayData(int data)
{
  digitalWrite(REG_LATCH, LOW);
  shiftOut(REG_DATA, REG_CLOCK, LSBFIRST, data);   
  digitalWrite(REG_LATCH, HIGH);
}

