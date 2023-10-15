#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define num 5 

void * thread_fn(void *arg);

typedef struct {
    int* arr;
    int num_elements;
} ThreadArgs;


int main(){

  int stat;
  int arr[num] = {15,5,9,25,30};
  ThreadArgs thread_args;
  thread_args.arr = arr;
  thread_args.num_elements = num;
  pthread_t thread_id;
  void *thread_result;
    
  printf("Main: PID of the main process is %d\n", getpid());
  
  stat = pthread_create(&thread_id, NULL, thread_fn, &thread_args);
  
  if(stat != 0){ 
    perror("Main: Error: Thread creation failed\n");
    exit(EXIT_FAILURE);
  }
  
  printf("Main: Thread created successfully\n");
  printf("Main: I'm sleeping for 10 seconds\n");
  sleep(10);
  printf("Main: I woke up after 10 seconds\n");
  printf("Main: I'm going to run forever\n");
  int count = 1;
  while(1)
  {
    printf("Main: %d. Message from Main\n",count);
    count++;
    sleep(10);
  }
} 
void * thread_fn(void *arg){
  ThreadArgs* thread_args = (ThreadArgs*)arg;
	
  printf("Thread: I'm created.\n");
  for (int i = 0; i < thread_args->num_elements; i++){
    printf("%d ",thread_args->arr[i]);
  }
  printf("\n");
  while(1)
  {
  int sum = 0;
        for (int i = 0; i < thread_args->num_elements; i++) {
            sum += thread_args->arr[i];
        }

        double average = (double)sum / thread_args->num_elements;
        printf("Average: %.2lf\n", average);
        sleep(5);

  }
  
  
}
