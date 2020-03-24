#include <wiringPi.h>
#include <iostream>

#define ROWS 4
#define COLS 4

char pressedKey = '\0';
int rowPins[ROWS] = {22,23,24,25};
int colPins[COLS] = {2,3,4};

char keys[ROWS][COLS] = {
   {'1', '2', '3'},
   {'4', '5', '6'},
   {'7', '8', '9'},
   {'*', '0', '#'}
};

void init_keypad()
{
   for (int c = 0; c < COLS; c++)
   {
      pinMode(colPins[c], OUTPUT);
      digitalWrite(colPins[c], HIGH);
   }

   for (int r = 0; r < ROWS; r++)
   {
      pinMode(rowPins[0], INPUT);
      digitalWrite(rowPins[r], PUD_UP);
   }
}

int findLowRow()
{
   for (int r = 0; r < ROWS; r++)
   {
      if (digitalRead(rowPins[r]) == LOW)
         return r;
   }

   return -1;
}

char get_key()
{
   int rowIndex;

   for (int c = 0; c < COLS; c++)
   {
      digitalWrite(colPins[c], LOW);

      rowIndex = findLowRow();
      if (rowIndex > -1)
      {
         if (!pressedKey)
            pressedKey = keys[rowIndex][c];
         return pressedKey;
      }

      digitalWrite(colPins[c], HIGH);
   }

   pressedKey = '\0';

   return pressedKey;
}

int main(void)
{
   wiringPiSetup();

   init_keypad();

   while(1)
   {
      char x = get_key();

      if (x)
    	  cout<<"pressed:\n"<<x;
         //printf("pressed: %c\n", x);
      else
    	  cout<<"no key presses\n";
       //  printf("no key pressed\n");

      delay(250);
   }

   return 0;
}