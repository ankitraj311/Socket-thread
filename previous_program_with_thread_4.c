#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>





//What is requirment of pthread_join, why program is not working without join in it, or some other program calling should be their/

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
  pthread_create(&thread_id,NULL,myturn,NULL);
  pthread_create(&thread_id1,NULL,yourturn,NULL);
  pthread_join(thread_id,NULL);
  pthread_join(thread_id1,NULL);
  //yourturn();
}



















