#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char * env_var;

void print_env_val(char * env_var, char * envp[]);

int main(int argc, char * argv[], char * envp[])
{
   env_var = "USER";
   printf("Lab2: Printing the content of the env var %s\n", env_var);
   print_env_val(env_var, envp);

   env_var = "OLDPWD";
   printf("Lab2: Printing the content of the env var %s\n", env_var);
   print_env_val(env_var, envp);
  
    return 0;
}

void print_env_val(char * env_var, char * envp[]){
    char *value = NULL;
    
    // Loop through each entry in the envp array
    for (int i = 0; envp[i] != NULL; i++) {
        // Check if the current entry starts with the environment variable name
        if (strncmp(env_var, envp[i], strlen(env_var)) == 0) {
            // Find the position of the equal sign (=) which separates name and value
            char *equal_sign = strchr(envp[i], '=');
            if (equal_sign != NULL) {
                // The value starts after the equal sign
                value = equal_sign + 1;
                break;
            }
        }
    }
    
    if (value != NULL) {
        printf("Value of %s: %s\n", env_var, value);
    } else {
        printf("Environment variable %s not found.\n", env_var);
    }
}
