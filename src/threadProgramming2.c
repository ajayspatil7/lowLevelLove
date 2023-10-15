#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define num 10

void * thread_fn(void *arg);



int main(){

  int stat;
  void *thread1_result;
  pthread_t thread_id_arr[num];
  int value[num] ={100,200,300,400,500,600,700,800,900,1000};
    
  printf("Main: PID of the main process is %d\n", getpid());
  
  for(int i=0;i<num;i++)
  {
  stat = pthread_create(&thread_id_arr[i], NULL, thread_fn, &value[i] );
  
  if(stat != 0){ 
    perror("Main: Error: Thread creation failed\n");
    exit(EXIT_FAILURE);
  }
  
  printf("Main: Thread %d created successfully\n",i+1);
  }
  for(int i=0;i<num;i++)
  {
    stat = pthread_join(thread_id_arr[i], &thread1_result);
  
  if(stat != 0){ // thread join has failed
    perror("Main: Thread1 join failed\n");
    exit(EXIT_FAILURE);    
  }

  printf("Main: Thread %d joined.\n", i+1);
  }

  printf("Main: I'm exiting\n");
  

} 
void * thread_fn(void *arg){
  int *val = (int *)arg;

  printf("Thread %d: I'm created.\n", (*val/100));
  printf("Thread %d: The value i received is %d\n",(*val/100),*val);
  printf("Thread %d: I'm sleeping for %d seconds\n",(*val/100),(*val/100));
  sleep((*val/100));
  printf("Thread %d: I'm exiting\n",(*val/100));
  pthread_exit(0);

  
}
