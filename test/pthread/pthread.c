#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void test_thread(void* param)
{
  pthread_t tid;
  pid_t pid;
  pid = getpid();
  tid = pthread_self();
  printf("%u, %u\n", (unsigned int)pid, (unsigned int)tid);
  while (1) 
  {
    sleep(1);
    printf("!!!!!!!!!!\n");
  }
}

void init()
{
  int err;
  pthread_t tid;
  err = pthread_create(&tid, NULL, test_thread, NULL);
  if (err != 0)
  {
    printf("create thread error\n");
    return ;
  }
  
  //pthread_join(tid, NULL);
  return ;
}

int main(void)
{
  init();
  printf("finish\n");
  pause();
  return 0;
}
