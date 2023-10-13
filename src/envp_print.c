#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[], char * envp[])
{
    printf("Lab2: Print the envp[] contents ...\n");

    for(int i = 0; envp[i] != NULL; i++) {
//      printf("%s\n", envp[i]);
        if (strcmp(envp[i], "HOME")) {
            printf("Home : %s\n", envp[i]);
            break;
        }
        
    }
  
    return 0;
}
