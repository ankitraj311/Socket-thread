#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>







void* myturn(void * arg)
{
  while(1)
  {
    sleep(1);
    printf("myturn\n");
  }

  return NULL;
}

void yourturn()
{
 // while(1)
  //{
    sleep(1);
    printf("yourturn\n\n");
  //}
}
int main()
{
  pthread_t thread_id;
  pthread_create(&thread_id,NULL,myturn,NULL);
  pthread_join(thread_id,NULL);
  yourturn();
}



















