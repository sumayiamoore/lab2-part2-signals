/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

volatile int alarms = 0; //number of SIGALRMs delivered
time_t start; //when the program started

void alarm_handler(int signum)
{ //SIGALRM handler
  alarms++;
  alarm(1); //schedule the next SIGALRM in 1 second
}

void int_handler(int signum)
{ //SIGINT handler (Ctrl-C)
  time_t end = time(NULL);
  printf("\nAlarms delivered: %d\n", alarms);
  printf("Total execution time: %ld seconds\n", (long)(end - start));
  exit(0);
}

int main(int argc, char * argv[])
{
  start = time(NULL);
  signal(SIGALRM,alarm_handler); //register SIGALRM handler
  signal(SIGINT,int_handler); //register SIGINT handler
  alarm(1); //first SIGALRM in 1 second
  while(1); //busy wait
  return 0; //never reached
}

