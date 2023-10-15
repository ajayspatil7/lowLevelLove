#include <stdio.h>
#include <stdlib.h>

int findAvg(int numbers[], int size);

int findAvg(int numbers[], int size){
    int total = 0;

    for (int i=0; i < size; i++) {
        total += numbers[i];
    }

    return total / size;
}

int main(int argc, char *argv[]){
    int size;

    if(argc < 2){
        printf("ERROR : Insufficient Parameters.");
        return -1;
    }

    size = argc - 1;
    int *numbers = malloc(size * sizeof(int));

    for(int i = 0; i < size ; i++){
        numbers[i] = atoi(argv[i+1]);
    }

    printf("Avg : %d", findAvg(numbers, size));
    free(numbers);

}
