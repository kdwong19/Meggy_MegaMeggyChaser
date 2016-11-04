#include <MeggyJrSimple.h>

int px = 0;
int py = 0;
struct Point
{
  int x;
  int y;
};
Point e1 = {7,7};

Point enemyarray[] = {e1};


int marker = 1;

void setup() {
  // put your setup code here, to run once:
 MeggyJrSimpleSetup(); 
}

void loop() {
  // put your main code here, to run repeatedly:

PMovement();
DrawEnemy();
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
  DrawPx(px,py,7);
}

void DrawEnemy()
{
  for (int i = 0; i < marker; i++)
  {
    DrawPx(enemyarray[i].x, enemyarray[i].y,Red);
  }
}

