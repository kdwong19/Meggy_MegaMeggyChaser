#include <MeggyJrSimple.h>

int px = 0
int py = 0

void setup() {
  // put your setup code here, to run once:
 MeggyJrSimpleSetup(); 
}

void loop() {
  // put your main code here, to run repeatedly:

Pmovement();
DisplaySlate();
ClearSlate();

}

void PMovement()
{
  CheckButtonsPress();
  if (Button_Up)
  {
    py++;
  }
  if (Button_Down)
  {
    py = py - 1;
  }
  if (Button_Right)
  {
    px++;
  }
  if (Button_Left)
  px = px - 1;
  if (px > 7)
  {
    px = 0;
  }
  if (py > 7)
  {
    py = 0;
  }
  if (px < 0)
  {
    px = 7;
  }
  if (py < 0)
  {
    py = 7;
  }
}

