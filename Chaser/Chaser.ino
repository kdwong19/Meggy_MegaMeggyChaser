#include <MeggyJrSimple.h>

struct Point
{
  int x;
  int y;
  int wx;
  int wy;
};
Point e1 = {7,7};

Point enemyarray[64] = {e1};

Point wallarray[64];

int wmarker = 0;
int px = 4; //player coords
int py = 4;
int turn = 0;
int marker = 1;
int counter = 0;

boolean gg = false;

void setup() {
  // put your setup code here, to run once:
 MeggyJrSimpleSetup(); 
 Serial.begin(9600);
}

void loop() 
{
  if (gg == false)
  {
   PMovement();
   DrawEnemy();
   EPColision();
   DisplaySlate();
   
   ClearSlate();
   //EEcolision();
   Wallcreate();
   
  }
 else
 {
  death();
 }
 
}

void PMovement()
{
  CheckButtonsPress();
  if (Button_Up)
  {
    py++;
    counter++;
    YEMovement();
    XEMovement();
    //FEMovement();
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
    YEMovement();
    XEMovement();
    //FEMovement();
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
    YEMovement();
    XEMovement();
    //FEMovement();
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
    YEMovement();
    XEMovement();
    //FEMovement();
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

void XEMovement()
{
  for (int i = 0; i < marker; i++)
  {
    if (enemyarray[i].x > px)
    {
      enemyarray[i].x--;
    }
    if (enemyarray[i].x < px)
    {
      enemyarray[i].x++;
    }
  }
}

void YEMovement()
{
  Serial.print("function called");
  for (int i = 0; i < marker; i++)
  {
    if (enemyarray[i].y > py)
    {
      enemyarray[i].y--;
    }
    if (enemyarray[i].y < py)
    {
      enemyarray[i].y++;
    }
  }
}

void FEMovement() //temp removed this script from the loop because it was
//making the AI inconsistent
{
  for (int i = 0; i < marker; i++)
  {
    if (abs(px - enemyarray[i].x) >= abs(py - enemyarray[i].y))
    {
      XEMovement();
    }
    else
    {
     YEMovement();
    }
  }
}

void EPColision()
{
  for (int i = 0; i < marker; i++)
  {
    if (px == enemyarray[i].x && py == enemyarray[i].y)
    {
      gg = true;
    }
  }
}

void death()
{
  DrawPx(0,0,Yellow);
  DrawPx(1,1,Yellow);
  DrawPx(2,2,Yellow);
  DrawPx(3,3,Yellow);
  DrawPx(4,4,Yellow);
  DrawPx(5,5,Yellow);
  DrawPx(6,6,Yellow);
  DrawPx(7,7,Yellow);
  DrawPx(7,0,Yellow);
  DrawPx(6,1,Yellow);
  DrawPx(5,2,Yellow);
  DrawPx(4,3,Yellow);
  DrawPx(3,4,Yellow);
  DrawPx(2,5,Yellow);
  DrawPx(1,6,Yellow);
  DrawPx(0,7,Yellow);
  DisplaySlate();
  delay(2000);
}

void EEcolision() //temp removed this script because it causes crashes
{
  for (int i = 0; i < marker; i++)
  {
    if (dupecheck == true)
    {

     int x = enemyarray[i].x;
     int y = enemyarray[i].y;
     Point temp = {x,y};
     wallarray[wmarker] = temp;
     wmarker++; 
    }
  }
}

void Wallcreate()
{
  for (int i = 0; i < wmarker; i++)
  {
    DrawPx(wallarray[i].wx,wallarray[i].wy,2);
  }
}

