#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
//what will be the differnece if i use single thread id multiple time,in this program or diff-diff id






void* myturn(void * arg)
{
  while(1)
  {
    sleep(1);
    printf("myturn\n");
  }
  return NULL;
}


void* yourturn(void * arg)
{
  while(1)
  {
    sleep(1);
    printf("yourturn\n\n");
  }
  return NULL;
}

int main()
{
  pthread_t thread_id, thread_id1;
  pthread_create(&thread_id,NULL,myturn,NULL);  //using same threadid multiple time
  pthread_create(&thread_id,NULL,yourturn,NULL);
  pthread_join(thread_id,NULL);
  pthread_join(thread_id,NULL);
  //yourturn();
}



















