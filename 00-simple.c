// compile 
// gcc 00-simple.c -o 00-simple -fno-stack-protector -m32 -g

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  int control;
  char buffer[64];

  printf("You win this game if you can change variable control'\n");

  control = 0;
  gets(buffer);

  if(control != 0) {
      printf("YOU WIN!!!\n");
  } else {
      printf("Try again...\n");
  }
}
