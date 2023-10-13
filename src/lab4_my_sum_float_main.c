#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>  
// To use the float types 

// OS_SS Lab 4: Aug 2023



// Demo of writing a portable code across different platforms 

extern float my_sum_int(int32_t num_args, ...);

static int my_sum_int_main_sint = 2000;

int32_t main(){

    printf("OS-Lab 4: Demo of differences in addresses of 32-bit and 64-bit apps\n");
	// Get the logical addresses of code and data of this program
    printf("my_sum_int_main: static var address: %p\n",
            &my_sum_int_main_sint);
    printf("my_sum_int_main: main() code address: %p\n",
            main);            
           

	int32_t num_params = 2;
	int32_t i = 20;
	int32_t j = 35;
	
    printf(  "Sum  = %lld\n",  (long long) my_sum_int(num_params,  i, j)  );

    //printf("I am going to run forever!!!\n");
	//while(1);

    
    return 0;
    
 } // end of main()

