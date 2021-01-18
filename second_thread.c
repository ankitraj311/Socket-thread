#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>







int g = 0;
void* thread_fun(void *vargp)
{ 
  //Store the value argument passed to this thread
  //unsigned int *myid = (unsigned int *)vargp;
  int myid = *(int *)vargp;

  //Let us create a static variable to observe change
  static int s = 0;
  //Changes static and global
  ++s;
  ++g;
   while(1)
   {
     int i = 1;
   }
  //Print thar arguments, static, global varibale
  printf("Thread Id u: %d, Thread Id d: %d, Static: %d, Global: %d\n",myid,myid,++s,++g);
}


int main()
{
  int  i;
  pthread_t tid;

  //Let us create three Threads
  for(i = 0; i<3; i++)
  {
    //pthread_create(&tid, NULL, thread_fun, (void*)&tid);
    pthread_create(&tid, NULL, thread_fun, (void*)&i);
  }
    //pthread_join(tid, NULL);
    pthread_exit(NULL);
    return 0;
}
