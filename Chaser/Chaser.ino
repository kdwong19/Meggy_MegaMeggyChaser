#include <MeggyJrSimple.h>

struct Point
{
  int x;
  int y;
};
Point e1 = {7,7};

Point enemyarray[64] = {e1};


int px = 0; //player coords
int py = 0;
int turn = 0;
int marker = 1;
int counter = 0;

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
    counter++;
    if (counter > 2)
    {
      addEnemy();
      counter = 0;
    }
  }
  if (Button_Down)
  {
    py--;
    counter++;
    if (counter > 2)
    {
      addEnemy();
      counter = 0;
    }
  }
  if (Button_Right)
  {
    px++;
    counter++;
    if (counter > 2)
    {
      addEnemy();
      counter = 0;
    }
  }
  if (Button_Left)
  {
    px = px - 1;
    counter++;
    if (counter > 2)
    {
      addEnemy();
      counter = 0;
    }
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
  /* create a new Point enemy
  // creat x variable
  // create y variable

  while dupecheck(x,y) is true, ]
  create a new rndom vaolue for each
  */
  int x = random(8);
  int y = random(8);
  while (dupecheck(x,y) == true)
  {
    x = random(8);
    y = random(8);
  }
 
  Point temp = {x,y};
  // add it to array
  enemyarray[marker] = temp;
  // increase marker
  marker++;
}

boolean dupecheck(int x, int y)
{
  for (int i = 0; i < marker; i++)
  {
    if (enemyarray[i].x == x && enemyarray[i].y == y)
    {
      return true;
    }
    
    
  }
  return false;
}

void EMovement()
{
  for (int = 0; i < marker; i++)
  {
    if (enemyarray[i].x > px)
    {
      enemyarray[i].x--;
    }
  }
}

