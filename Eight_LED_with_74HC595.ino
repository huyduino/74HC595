int latchPin = 5;
int clockPin = 6;
int dataPin = 4;

byte leds = 0;

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() 
{
  pattern(255);   // on all,      255 ~ 1 1 1 1 - 1 1 1 1
  pattern(0);     // off all,       0 ~ 0 0 0 0 - 0 0 0 0
  oneByOne();
  pattern(85);    // on all odd,   85 ~ 0 1 0 1 - 0 1 0 1
  pattern(170);   // on all even, 170 ~ 1 0 1 0 - 1 0 1 0
  onlyOne();
}

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}

void oneByOne()
{
  for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    updateShiftRegister();
    delay(500);
  }
}

void onlyOne()
{
  for (int i = 0; i < 8; i++)
  {
    leds = 0;
    bitSet(leds, i);
    updateShiftRegister();
    delay(500);
  }
}

void pattern(byte patternCode)
{
  leds = patternCode;
  updateShiftRegister();
  delay(500);
}

