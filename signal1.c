/* signal1.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile int done = 0; //set by the handler, checked by main

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  done = 1; //tell main the signal arrived
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(5); //Schedule a SIGALRM for 5 seconds
  while(!done); //busy wait for signal to be delivered
  printf("Turing was right!\n");
  return 0;
}
