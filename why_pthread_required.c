//Let us suppose their are the two function named as MyTurn, YourTurn and we have to run  them concurrently then what will you going to do?
//pthread header class is #include<pthread.h>








/*
 *DESCRIPTION
       POSIX.1  specifies  a  set  of  interfaces  (functions,  header  files)  for threaded programming commonly known as POSIX threads, or
       Pthreads.  A single process can contain multiple threads, all of which are executing the same program.  These threads share the  same
       global memory (data and heap segments), but each thread has its own stack (automatic variables).
*/

//parameters of pthread_create are :- 
//int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start)(void *), void *arg);
/*
 *
PARAMETERS :- 
thread
Is the location where the ID of the newly created thread should be stored, or NULL if the thread ID is not required.

attr
Is the thread attribute object specifying the attributes for the thread that is being created. If attr is NULL, the thread is created with default attributes.

start
Is the main function for the thread; the thread begins executing user code at this address.

arg
Is the argument passed to start.*/




#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void myturn()
{
  while(1)
    {
      sleep(1);
      printf("Myturn\n");  
    }
}


void yourturn()
{
  while(1)
  {
    sleep(1);
    printf("yourturn\n");  
  }
}

int main()
{
  myturn();	
  yourturn();	
}





/*
 * OutPut will be
 * Myturn
Myturn
Myturn
Myturn
Myturn
Myturn
so on......infinity
*/
















