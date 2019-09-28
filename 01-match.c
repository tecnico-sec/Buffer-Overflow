// compile
// gcc 01-match.c -o 01-match -fno-stack-protector -m32 -g

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
  int control;
  char buffer[64];

  printf("You win this game if you can change variable control to the value 0x61626364'\n");

  control = 0;
  gets(buffer);

  if(control == 0x61626364) {
      printf("Congratulations, you win!!! You correctly got the variable to the right value\n");
  } else {
      printf("Try again, you got 0x%08x\n, instead of 0x61626364", control);
  }
}
