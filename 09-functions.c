// sudo sysctl -w kernel.randomize_va_space=0
// gcc -g -o 09-functions 09-functions.c -m32

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void win()
{
  printf("Congratulations, you win!!! You successfully changed the code flow\n");
}

int main(int argc, char **argv)
{
  int (*fp)();
  char buffer[128];

  fp = 0;

  printf("***** BEFORE ATTACK *****\n");
  printf("Variable fp     : %p %p\n", &fp, fp);
  printf("Variable buffer : %p %s\n", &buffer, buffer);
  printf("Function win    : %p\n\n", &win);

  printf("You win this game if you are able to call the function win.'\n");

  gets(buffer);
  printf(buffer);

  printf("***** AFTER ATTACK *****\n");
  printf("Variable fp     : %p %p\n", &fp, fp);
  printf("Variable buffer : %p %s\n", &buffer, buffer);

  if(fp) {
      printf("calling function pointer, jumping to %p\n", fp);
      fp();
  }
}