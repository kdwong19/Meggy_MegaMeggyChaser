#include <MeggyJrSimple.h>

struct Point
{
  int x;
  int y;
};
Point e1 = {7,7};

Point enemyarray[32] = {e1};


int px = 0; //player coords
int py = 0;
int turn = 0;
int marker = 1;

void setup() {
  // put your setup code here, to run once:
 MeggyJrSimpleSetup(); 
}

void loop() 
{
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
    addEnemy();
  }
  if (Button_Down)
  {
    py--;
    addEnemy();
  }
  if (Button_Right)
  {
    px++;
    addEnemy();
  }
  if (Button_Left)
  {
    px = px - 1;
    addEnemy();
  }
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
    DrawPx(enemyarray[i].x, enemyarray[i].y, Red);
  }
}

void addEnemy()
{
  // create a new Point enemy
  Point temp = {random(8),random(8)};
  // add it to array
  enemyarray[marker] = temp;
  // increase marker
  marker++;
}

