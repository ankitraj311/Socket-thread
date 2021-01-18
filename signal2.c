/*Signals Detailsi*/
/*#define SIGHUP  1*/   /* Hangup the process */ 
/*#define SIGINT  2*/   /* Interrupt the process */ 
/*#define SIGQUIT 3*/   /* Quit the process */ 
/*#define SIGILL  4*/   /* Illegal instruction. */ 
/*#define SIGTRAP 5*/   /* Trace trap. */ 
/*#define SIGABRT 6*/   /* Abort. */




//to Terminate a process fire command "kill -TERM process_id"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int); //prototype

int main ()
{
   signal(SIGINT, sighandler);

   while(1) 
   {
      printf("Going to sleep for a second...\n");
      sleep(1); 
   }
   return(0);
}
void sighandler(int signum) 
{
   printf("Caught signal %d, coming out...\n", signum);
   //exit(1); //without exit program will not exit
}
