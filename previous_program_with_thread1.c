#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>










//Why results are unpredictable in the program

void* myturn(void * arg)
{
  //sleep(1);
  printf("myturn\n");

  return NULL;
}


void yourturn()
{
  //sleep(1);
  printf("yourturn\n\n");
}

int main()
{
  pthread_t thread_id;
  pthread_create(&thread_id,NULL,myturn,NULL);
  //pthread_join(thread_id,NULL); 
  ///*if you are going to use pthread_join then it will going to produce unpredicatble result. It will you "yourturn" as join function to block the thread*/
  yourturn();
}

/*
 *
 * output with join
 *
 * myturn
 * yourturn
 *
 *
 * */


















