#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>






unsigned long sum[4];
void* addall(void * arg)
{
  long id = (long)arg;
  int start = id*250000000;
  int i = 1;
  while(i<=250000000)
  {
    sum[id] += (i + start);
    i++;
  }
  return NULL;
}

int main()
{
  clock_t start, end; //execution time calculation
  double cpu_time_used;//execution time calculation
  start = clock();//execution time calculation

  pthread_t id1, id2, id3, id4;//thread_id creation

  pthread_create(&id1,NULL,addall,(void *)0);
  pthread_create(&id2,NULL,addall,(void *)1);
  pthread_create(&id3,NULL,addall,(void *)2);
  pthread_create(&id4,NULL,addall,(void *)3);
  pthread_join(id1,NULL);
  pthread_join(id2,NULL);
  pthread_join(id3,NULL);
  pthread_join(id4,NULL);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Sum of the numbers till 100 Crore %lu and Time taken by Program with thread is %f\n",sum[0]+sum[1]+sum[2]+sum[3],cpu_time_used);
/*  printf("Sum is s[0] is %lu\n",sum[0]);
  printf("Sum is s[1] is %lu\n",sum[1]);
  printf("Sum is s[2] is %lu\n",sum[2]);
  printf("Sum is s[3] is %lu\n",sum[3]);*/
}
