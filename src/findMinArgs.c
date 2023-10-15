#include <stdio.h>
#include <stdlib.h>

int findMinimum(int numbers[], int minNum);

int findMinimum(int numbers[], int minNum){
    int min = numbers[0];

    for(int i=1; i<minNum; i++){
        if(numbers[i] < min){
            min = numbers[i];
        }
    }
    return min;
}

int main(int argc, char *argv[]){
    int size;

    if(argc < 2){
        printf("ERROR : Insufficient Parameters.");
        return -1;
    }

    size = argc - 1;
    int numbers[size];

    for(int i = 0; i < size ; i++){
        numbers[i] = atoi(argv[i+1]);
    }

    findMinimum(numbers, size);

}