#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

char msg[] = "Hello, OS_SS Lab7 class ... lab7_join_exp1";

void *thread1_fn(void *arg);
void *thread2_fn(void *arg);
void *thread3_fn(void *arg);

int main() {
    int stat;
    pthread_t thread_id1;

    printf("Main: %s\n", msg);
    printf("Main: PID of the main process is %d\n", getpid());

    stat = pthread_create(&thread_id1, NULL, thread1_fn, NULL);

    if (stat != 0) {
        perror("Main: Error: Thread 1 creation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Main: Thread 1 created successfully\n");

    // Wait for thread1 to exit
    stat = pthread_join(thread_id1, NULL);

    if (stat != 0) {
        perror("Main: Thread1 join failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Main: Thread1 joined.\n");
    printf("Main process is going to exit.\n");

    return 0;
}

void *thread1_fn(void *arg) {
    int stat;
    pthread_t thread_id2;

    printf("Thread1: I am going to sleep now for 2 seconds ...\n");
    sleep(2);

    printf("Thread1: I woke up after 2 seconds and will create Thread2\n");

    stat = pthread_create(&thread_id2, NULL, thread2_fn, NULL);

    if (stat != 0) {
        perror("Thread1: Error: Thread 2 creation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Thread1: Thread 2 created successfully\n");

    // Wait for thread2 to exit
    stat = pthread_join(thread_id2, NULL);

    if (stat != 0) {
        perror("Thread1: Thread2 join failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Thread1: Thread2 joined.\n");
    printf("Thread1: I am going to exit.\n");

    pthread_exit(NULL);
}

void *thread2_fn(void *arg) {
    int stat;
    pthread_t thread_id3;

    printf("Thread2: I am going to sleep now for 2 seconds ...\n");
    sleep(2);

    printf("Thread2: I woke up after 2 seconds and will create Thread3\n");

    stat = pthread_create(&thread_id3, NULL, thread3_fn, NULL);

    if (stat != 0) {
        perror("Thread2: Error: Thread 3 creation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Thread2: Thread 3 created successfully\n");

    // Wait for thread3 to exit
    stat = pthread_join(thread_id3, NULL);

    if (stat != 0) {
        perror("Thread2: Thread3 join failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Thread2: Thread3 joined.\n");
    printf("Thread2: I am going to exit.\n");

    pthread_exit(NULL);
}

void *thread3_fn(void *arg) {
    printf("Thread3: I am going to sleep now for 5 seconds ...\n");
    sleep(5);

    printf("Thread3: I woke up after 5 seconds and will exit.\n");
    pthread_exit(NULL);
}
